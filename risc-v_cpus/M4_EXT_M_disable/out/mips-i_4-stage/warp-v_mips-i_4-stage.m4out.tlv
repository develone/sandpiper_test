\TLV_version [\source warp-v_mips-i_4-stage.tlv] 1d --noline: tl-x.org

\source warp-v_mips-i_4-stage.tlv 5
\SV
   // Include WARP-V.
   // Included URL: "./warp-v.tlv"
\SV
module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
\source warp-v_mips-i_4-stage.tlv 9
\TLV
   \source ./warpv.tlv 3556   // Instantiated from warp-v_mips-i_4-stage.tlv, 11 as: m4+warpv()
      // =================
      //
      //    THE MODEL
      //
      // =================
      
   
      \source ./warpv.tlv 2814   // Instantiated from warp-v_mips-i_4-stage.tlv, 3564 as: m4+cpu(/top)
         // Generated logic
         \source <builtin> 1   // Instantiated from warp-v_mips-i_4-stage.tlv, 2816 as: m4+indirect(M4_isa['_gen'])
            \source ./warpv.tlv 2010   // Instantiated from built-in definition.
               // No M4-generated code for MIPS I.
            \end_source
         \end_source
      
         // Instruction memory and fetch of $raw.
         \source <builtin> 1   // Instantiated from warp-v_mips-i_4-stage.tlv, 2819 as: m4+indirect(M4_IMEM_MACRO_NAME, M4_PROG_NAME)
            \source ./warpv.tlv 2002   // Instantiated from built-in definition.
               \source <builtin> 1   // Instantiated from warp-v_mips-i_4-stage.tlv, 2003 as: m4+indirect(['mipsi_']cnt10['_prog'])
                  \source ./warpv.tlv 1966   // Instantiated from built-in definition.
                     \SV_plus
                        
                        
                        // The program in an instruction memory.
                        logic [31:0] instrs [0:11-1];
                        
                        // /=====================\
                        // | Count to 10 Program |
                        // \=====================/
                        
                        // Add 1,2,3,...,9 (in that order).
                        // Store incremental results in memory locations 1..9. (1, 3, 6, 10, ..., 45)
                        //
                        // Regs:
                        // 1: cnt
                        // 2: ten
                        // 3: out
                        // 4: tmp
                        // 5: offset
                        // 6: store addr
                        
                        assign instrs = '{
                          {6'd13, 5'd0, 5'd6, 16'd0},             //    store_addr = 0
                          {6'd13, 5'd0, 5'd1, 16'd1},             //    cnt = 1
                          {6'd13, 5'd0, 5'd2, 16'd10},            //    ten = 10
                          {6'd13, 5'd0, 5'd3, 16'd0},             //    out = 0
                          {6'd0,  5'd1, 5'd3, 5'd3, 5'd0, 6'd32}, // -> out += cnt
                          {6'd43, 5'd6, 5'd3, 16'd0},             //    store out at store_addr
                          {6'd8,  5'd1, 5'd1, 16'd1},             //    cnt ++
                          {6'd8,  5'd6, 5'd6, 16'd4},             //    store_addr++
                          {6'd5,  5'd1, 5'd2, (~ 16'd4)},         // ^- branch back if cnt != ten
                          {6'd35, 5'd6, 5'd4, (~ 16'd3)},         //    load the final value into tmp
                          {6'd0,  26'd13}                         //    BREAK
                        };
                  \end_source
               \end_source
               |fetch
                  /instr
                     @0
                        ?$fetch
                           $raw[31:0] = *instrs\[$Pc[5:2]\];
            \end_source
         \end_source
      
      
         // /=========\
         // | The CPU |
         // \=========/
      
         |fetch
            /instr
               
               
               // Provide a longer reset to cover the pipeline depth.
               @-1
                  $soft_reset = (1'b0) || *reset;
                  $Cnt[7:0] <= $soft_reset   ? 8'b0 :       // reset
                               $Cnt == 8'hFF ? 8'hFF :      // max out to avoid wrapping
                                               $Cnt + 8'b1; // increment
                  $reset = $soft_reset || $Cnt < 10;
               @0
                  $fetch = ! $reset && ! $NoFetch;
                  // (M4_IMEM_MACRO_NAME instantiation produces ?$fetch$raw.)
               @0
                  
                  // ========
                  // Overview
                  // ========
                  
                  // Terminology:
                  //
                  // Instruction: An instruction, as viewed by the CPU pipeline (i.e. ld and returning_ld are separate instructions,
                  //              and the returning_ld and the instruction it clobbers are one in the same).
                  // ISA Instruction: An instruction, as defined by the ISA.
                  // Good-Path (vs. Bad-Path): On the proper flow of execution of the program, excluding aborted instructions.
                  // Path (of an instruction): The sequence of instructions that led to a particular instruction.
                  // Current Path: The sequence of instructions fetched by next-PC logic that are not known to be bad-path.
                  // Redirect: Adjust the PC from the predicted next-PC.
                  // Redirect Shadow: Between the instruction causing the redirect and the redirect target instruction.
                  // Bubbles: The cycles in the redirect shadow.
                  // Commit: Results are made visible to subsequent instructions.
                  // Abort: Do not commit. All aborts are also redirects and put the instruction on bad path. Non-aborting
                  //        redirects do not mark the triggering instruction as bad-path. Aborts mask future redirects on the
                  //        aborted instruction.
                  // Retire: Commit results of an ISA instruction.
                  
                  // Control flow:
                  //
                  // Redirects include (earliest to latest):
                  //   o Returning load: (aborting) A returning load clobbers an instruction and takes its slot, resulting in a
                  //                     one-cycle redirect to repeat the clobbered instruction.
                  //   o Predict-taken branch: A predicted-taken branch must determine the target before it can redirect the PC.
                  //                           (This might be followed up by a mispredition.)
                  //   o Replay: (aborting) Replay the same instruction (because a source register is pending (awaiting a long-latency/2nd issuing instruction))
                  //   o Jump: A jump instruction.
                  //   o Mispredicted branch: A branch condition was mispredicted.
                  //   o Aborting traps: (aborting) illegal instructions, others?
                  //   o Non-aborting traps: misaligned PC target
                  
                  // ==============
                  // Redirect Logic
                  // ==============
                                  
                  // PC logic will redirect the PC for conditions on current-path instructions. PC logic keeps track of which
                  // instructions are on the current path with a $GoodPathMask. $GoodPathMask[n] of an instruction indicates
                  // whether the instruction n instructions prior to this instruction is on its path.
                  //
                  //                 $GoodPathMask for Redir'edX => {o,X,o,o,y,y,o,o} == {1,1,1,1,0,0,1,1}
                  // Waterfall View: |
                  //                 V
                  // 0)       oooooooo                  Good-path
                  // 1) InstX  ooooooXo  (Non-aborting) Good-path
                  // 2)         ooooooxx
                  // 3) InstY    ooYyyxxx  (Aborting)
                  // 4) InstZ     ooyyxZxx
                  // 5) Redir'edY  oyyxxxxx
                  // 6) TargetY     ooxxxxxx
                  // 7) Redir'edX    oxxxxxxx
                  // 8) TargetX       oooooooo          Good-path
                  // 9) Not redir'edZ  oooooooo         Good-path
                  //
                  // Above depicts a waterfall diagram where three triggering redirection conditions X, Y, and Z are detected on three different
                  // instructions. A trigger in the 1st depicted stage, M4_NEXT_PC_STAGE, results in a zero-bubble redirect so it would be
                  // a condition that is factored directly into the next-PC logic of the triggering instruction, and it would have
                  // no impact on the $GoodPathMask.
                  //
                  // Waveform View:
                  //
                  //   Inst 0123456789
                  //        ---------- /
                  // GPM[7]        ooxxxxxxoo
                  // GPM[6]       oXxxxxxxoo
                  // GPM[5]      oooxZxxxoo
                  // GPM[4]     oooyxxxxoo
                  // GPM[3]    oooyyxxxoo
                  // GPM[2]   oooYyyxxoo
                  // GPM[1]  oooooyoxoo
                  // GPM[0] oooooooooo
                  //          /
                  //         Triggers for InstY
                  //
                  // In the waveform view, the mask shifts up each cycle, as instructions age, and trigger conditions mask instructions
                  // in the shadow, down to the redirect target (GPM[0]).
                  //
                  // Terminology:
                  //   Triggering instruction: The instruction on which the condition is detected.
                  //   Redirected instruction: The instruction whose next PC is redirected.
                  //   Redirection target instruction: The first new-path instruction resulting from the redirection.
                  //
                  // Above, Y redirects first, though it is for a later instruction than X. The redirections for X and Y are taken
                  // because their instructions are on the path of the redirected instructions. Z is not on the path of its
                  // potentially-redirected instruction, so no redirection happens.
                  //
                  // For simultaneous conditions on different instructions, the PC must redirect to the earlier instruction's
                  // redirect target, so later-stage redirects take priority in the PC-mux.
                  //
                  // Aborting redirects result in the aborting instruction being marked as bad-path. Aborted instructions will
                  // not commit. Subsequent redirect conditions on aborting instructions are ignored. (For conditions within the
                  // same stage, this is accomplished by the PC-mux prioritization.)
                  
                  
                  // Macros are defined elsewhere based on the ordered set of conditions that generate code here.
                  
                  // Redirect Shadow
                  // A mask of stages ahead of this one (older) in which instructions are on the path of this instruction.
                  // Index 1 is ahead by 1, etc.
                  // In the example above, $GoodPathMask for Redir'edX == {0,0,0,0,1,1,0,0}
                  //     (Looking up in the waterfall diagram from its first "o", in reverse order {o,X,o,o,y,y,o,o}.)
                  // The LSB is fetch-valid. It only exists for m4_prev_instr_valid_through macro.
                  $next_good_path_mask[3+1:0] =
                     // Shift up and mask w/ redirect conditions.
                     {$GoodPathMask[3:0]
                      // & terms for each condition (order doesn't matter since masks are the same within a cycle)
                       & ((>>0$second_issue && !(1'b0) && $GoodPathMask[0]) ? {{3{1'b1}}, {1{1'b0}}} : {4{1'b1}}) & ((>>0$NoFetch && !(1'b0 || >>0$second_issue) && $GoodPathMask[0]) ? {{3{1'b1}}, {1{1'b0}}} : {4{1'b1}}) & ((>>1$pred_taken_branch && !(1'b0 || >>1$second_issue || >>1$NoFetch) && $GoodPathMask[1]) ? {{3{1'b1}}, {1{1'b0}}} : {4{1'b1}}) & ((>>2$replay && !(1'b0 || >>2$second_issue || >>2$NoFetch) && $GoodPathMask[2]) ? {{1{1'b1}}, {3{1'b0}}} : {4{1'b1}}) & ((>>2$jump && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {{2{1'b1}}, {2{1'b0}}} : {4{1'b1}}) & ((>>2$mispred_branch && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {{2{1'b1}}, {2{1'b0}}} : {4{1'b1}}) & ((>>2$indirect_jump && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {{2{1'b1}}, {2{1'b0}}} : {4{1'b1}}) & ((>>3$non_pipelined && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {{1{1'b1}}, {3{1'b0}}} : {4{1'b1}}) & ((>>3$aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {{0{1'b1}}, {4{1'b0}}} : {4{1'b1}}) & ((>>3$non_aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay || >>3$aborting_trap) && $GoodPathMask[3]) ? {{1{1'b1}}, {3{1'b0}}} : {4{1'b1}}),
                      1'b1}; // Shift in 1'b1 (fetch-valid).
                  
                  $GoodPathMask[3+1:0] <=
                     <<1$reset ? 5'b0 :  // All bad-path (through self) on reset (next mask based on next reset).
                     $next_good_path_mask;
                  
                  
                  
                  
                  
                     
                      
                      
                  
                     
                     
                  
                  
                  
                  // A returning load clobbers the instruction.
                  // (Could do this with lower latency. Right now it goes through memory pipeline $ANY, and
                  //  it is non-speculative. Both could easily be fixed.)
                  $second_issue_ld = /top|mem/data>>4$valid_ld && 1'b1;
                  $second_issue = $second_issue_ld  ;
                  // Recirculate returning load or the div_mul_result from /orig_inst scope
                  
                  ?$second_issue_ld
                     // This scope holds the original load for a returning load.
                     /orig_load_inst
                        $ANY = /top|mem/data>>4$ANY;
                        /src[2:1]
                           $ANY = /top|mem/data/src>>4$ANY;
                  ?$second_issue
                     /orig_inst
                        // pull values from /orig_load_inst or /hold_inst depending on which second issue
                        $ANY = |fetch/instr$second_issue_ld ? |fetch/instr/orig_load_inst$ANY :   |fetch/instr/orig_load_inst$ANY;
                        /src[2:1]
                           $ANY = |fetch/instr$second_issue_ld ? |fetch/instr/orig_load_inst/src$ANY :   |fetch/instr/orig_load_inst/src$ANY;
                  
                  // Next PC
                  $pc_inc[31:2] = $Pc + 30'b1;
                  // Current parsing does not allow concatenated state on left-hand-side, so, first, a non-state expression.
                  {$next_pc[31:2], $next_no_fetch} =
                     $reset ? {30'b0, 1'b0} :
                     // ? : terms for each condition (order does matter)
                     (>>3$non_aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay || >>3$aborting_trap) && $GoodPathMask[3]) ? {>>3$trap_target, 1'b0} : (>>3$aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {>>3$trap_target,1'b0} : (>>3$non_pipelined && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {>>3$Pc,1'b1} : (>>2$indirect_jump && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {>>2$indirect_jump_target,1'b0} : (>>2$mispred_branch && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {>>2$branch_redir_pc,1'b0} : (>>2$jump && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {>>2$jump_target,1'b0} : (>>2$replay && !(1'b0 || >>2$second_issue || >>2$NoFetch) && $GoodPathMask[2]) ? {>>2$Pc,1'b0} : (>>1$pred_taken_branch && !(1'b0 || >>1$second_issue || >>1$NoFetch) && $GoodPathMask[1]) ? {>>1$branch_target,1'b0} : (>>0$NoFetch && !(1'b0 || >>0$second_issue) && $GoodPathMask[0]) ? {>>0$Pc,1'b1} : (>>0$second_issue && !(1'b0) && $GoodPathMask[0]) ? {>>0$second_issue_ld ? $Pc : $pc_inc,1'b0} :           
                                ({$pc_inc, 1'b0});
                  // Then as state.
                  $Pc[31:2] <= $next_pc;
                  $NoFetch <= $next_no_fetch;
               
               @1
      
                  // ======
                  // DECODE
                  // ======
      
                  // Decode of the fetched instruction
                  $valid_decode = $fetch;  // Always decode if we fetch.
                  $valid_decode_branch = $valid_decode && $branch;
                  // A load that will return later.
                  //$split_ld = $spec_ld && 1'b['']M4_INJECT_RETURNING_LD;
                  \source <builtin> 1   // Instantiated from warp-v_mips-i_4-stage.tlv, 3013 as: m4+indirect(M4_isa['_decode'])
                     \source ./warpv.tlv 2024   // Instantiated from built-in definition.
                        // TODO: ?$valid_<stage> conditioning should be replaced by use of m4_prev_instr_valid_through(..).
                        ?$valid_decode
                     
                           // Extract fields of $raw (instruction) into $raw_<field>[x:0].
                           {$raw_opcode[5:0], $raw_rs[4:0], $raw_rt[4:0], $raw_rd[4:0], $raw_shamt[4:0], $raw_funct[5:0]} = $raw;
                           $raw_immediate[15:0] = $raw[15:0];
                           $raw_address[25:0] = $raw[25:0];
                           
                           // Instruction Format
                           $rtype = $raw_opcode == 6'b000000;
                           $jtype = $raw_opcode == 6'b000010 || $raw_opcode == 6'b000011;
                           $itype = ! $rtype && ! $jtype;
                           
                           // Load/Store
                           //$is_lb  = $raw_opcode == 6'b100000;
                           $is_lh  = $raw_opcode == 6'b100001;
                           //$is_lwl = $raw_opcode == 6'b100010;
                           //$is_lw  = $raw_opcode == 6'b100011;
                           $is_lbu = $raw_opcode == 6'b100100;
                           $is_lhu = $raw_opcode == 6'b100101;
                           //$is_lwr = $raw_opcode == 6'b100110;
                           //$is_sb  = $raw_opcode == 6'b101000;
                           $is_sh  = $raw_opcode == 6'b101001;
                           //$is_swl = $raw_opcode == 6'b101010;
                           //$is_sw  = $raw_opcode == 6'b101011;
                           //$is_swr = $raw_opcode == 6'b101100;
                           
                           // ALU
                           $is_add   = $rtype && $raw_funct == 6'b100000;
                           $is_addu  = $rtype && $raw_funct == 6'b100001;
                           $is_sub   = $rtype && $raw_funct == 6'b100010;
                           $is_subu  = $rtype && $raw_funct == 6'b100011;
                           $is_and   = $rtype && $raw_funct == 6'b100100;
                           $is_or    = $rtype && $raw_funct == 6'b100101;
                           $is_xor   = $rtype && $raw_funct == 6'b100110;
                           $is_nor   = $rtype && $raw_funct == 6'b100111;
                           $is_slt   = $rtype && $raw_funct == 6'b101010;
                           $is_sltu  = $rtype && $raw_funct == 6'b101011;
                           $is_addi  = $raw_opcode == 6'b001000;
                           $is_addiu = $raw_opcode == 6'b001001;
                           $is_slti  = $raw_opcode == 6'b001010;
                           $is_sltiu = $raw_opcode == 6'b001011;
                           $is_andi  = $raw_opcode == 6'b001100;
                           $is_ori   = $raw_opcode == 6'b001101;
                           $is_xori  = $raw_opcode == 6'b001110;
                           $is_lui   = $raw_opcode == 6'b001111;
                           
                           // Shift
                           $is_sll  = $rtype && $raw_funct == 6'b000000;
                           $is_srl  = $rtype && $raw_funct == 6'b000010;
                           $is_sra  = $rtype && $raw_funct == 6'b000011;
                           $is_sllv = $rtype && $raw_funct == 6'b000100;
                           $is_srlv = $rtype && $raw_funct == 6'b000110;
                           $is_srav = $rtype && $raw_funct == 6'b000111;
                           
                           /*
                           // Mul/Div
                           $is_mfhi  = $rtype && $raw_funct == 6'b010000;
                           $is_mthi  = $rtype && $raw_funct == 6'b010001;
                           $is_mflo  = $rtype && $raw_funct == 6'b010010;
                           $is_mtlo  = $rtype && $raw_funct == 6'b010011;
                           $is_mult  = $rtype && $raw_funct == 6'b011000;
                           $is_multu = $rtype && $raw_funct == 6'b011001;
                           $is_div   = $rtype && $raw_funct == 6'b011010;
                           $is_divu  = $rtype && $raw_funct == 6'b011011;
                           */
                           $div_mul = 1'b0;
                           
                           // Jump/Branch
                           $is_jr     = $rtype && $raw_funct == 6'b001000;
                           $is_jalr   = $rtype && $raw_funct == 6'b001001;
                           $is_bltz   = $raw_opcode == 6'b000001 && $raw_rt[4] == 1'b0 && $raw_rt[0] == 1'b0;
                           $is_bgez   = $raw_opcode == 6'b000001 && $raw_rt[4] == 1'b0 && $raw_rt[0] == 1'b1;
                           $is_bltzal = $raw_opcode == 6'b000001 && $raw_rt[4] == 1'b1 && $raw_rt[0] == 1'b0;
                           $is_bgezal = $raw_opcode == 6'b000001 && $raw_rt[4] == 1'b1 && $raw_rt[0] == 1'b1;
                           $is_j      = $raw_opcode == 6'b000010;
                           $is_jal    = $raw_opcode == 6'b000011;
                           $is_beq    = $raw_opcode == 6'b000100;
                           $is_bne    = $raw_opcode == 6'b000101;
                           $is_blez   = $raw_opcode == 6'b000110;
                           $is_bgtz   = $raw_opcode == 6'b000111;
                           
                           // Exception
                           $is_syscall = $rtype && $raw_funct == 6'b001100;
                           $is_break   = $rtype && $raw_funct == 6'b001101;
                           
                           // FPU
                           // TODO: NOT IMPLEMENTED
                           
                           
                           $illegal = 1'b0;  // MIPS I doesn't have an illegal instruction exception, just UNPREDICTABLE behavior.
                           $conditional_branch = $raw_opcode == 6'b000001 || $raw_opcode[5:2] == 4'b0001;
                     
                           
                           // Special-Case Formats
                           $link_reg = $is_bltzal && $is_bgezal && $is_jal;
                           $unsigned_imm = $is_addiu || $is_sltiu;
                           $jump = $is_j || $is_jal;
                           $indirect_jump = $is_jr || $is_jalr;
                           $branch_or_jump = ($raw_opcode[5:3] == 3'b000) && ! $rtype;  // (does not include syscall & break)
                           $ld = $raw_opcode[5:3] == 3'b100;
                           $st = $raw_opcode[5:3] == 3'b101;
                           $ld_st = $ld || $st;
                           $ld_st_word = $ld_st && $raw_opcode[1] == 1'b1;
                           $ld_st_half = $is_lh || $is_lhu || $is_sh;
                           //$ld_st_byte = ...;
                     
                           // Output signals.
                           /src[2:1]
                              // Reg valid for this source, based on instruction type.
                              $is_reg =
                                  (#src == 1) ? ! /instr$jtype :
                                                /instr$rtype || /instr$st || /instr$is_beq || /instr$is_bne;
                              $reg[4:0] =
                                  (#src == 1) ? /instr$raw_rs :
                                                /instr$raw_rt;
                           $imm_value[31:0] = {{16{$raw_immediate[15] && ! $unsigned_imm}}, $raw_immediate[15:0]};
                           
                        // Condition signals must not themselves be conditioned (currently).
                        $dest_reg[4:0] = $second_issue ? /orig_inst$dest_reg : $link_reg ? 5'b11111 : $itype ? $raw_rt : $raw_rd;
                        $dest_reg_valid = (($valid_decode && ! ((($is_j || $conditional_branch) && ! $link_reg) || $st || $is_syscall || $is_break)) || $second_issue) &&
                                          | $dest_reg;   // r0 not valid.
                                          // Note that load is considered to have a valid dest (which may be marked pending).
                        $branch = $valid_decode && $conditional_branch;   // (Should be $decode_valid_branch, but keeping consistent with other ISAs.)
                        $decode_valid_jump = $valid_decode && $jump;
                        $decode_valid_indirect_jump = $valid_decode && $indirect_jump;
                        // Actually load.
                        $spec_ld = $valid_decode && $ld;   // (Should be $decode_valid_ld, but keeping consistent with other ISAs.)
                     \end_source
                  \end_source
               \source <builtin> 1   // Instantiated from warp-v_mips-i_4-stage.tlv, 3014 as: m4+indirect(['branch_pred_']M4_BRANCH_PRED)
                  \source ./warpv.tlv 2532   // Instantiated from built-in definition.
                     @1
                        ?$branch
                           $pred_taken = >>2$BranchState[1];
                     @2
                        $branch_or_reset = ($branch && $commit) || $reset;
                        ?$branch_or_reset
                           $BranchState[1:0] <=
                              $reset ? 2'b01 :
                              $taken ? ($BranchState == 2'b11 ? $RETAIN : $BranchState + 2'b1) :
                                       ($BranchState == 2'b00 ? $RETAIN : $BranchState - 2'b1);
                  \end_source
               \end_source
               
               @1
                  // Pending value to write to dest reg. Loads (not replaced by returning ld) write pending.
                  $reg_wr_pending = $ld && ! $second_issue && 1'b1;
                  `BOGUS_USE($reg_wr_pending)  // Not used if no bypass and no pending.
                  
                  // ======
                  // Reg Rd
                  // ======
                  
                  // Obtain source register values and pending bit for source registers. Bypass up to 3
                  // stages.
                  // It is not necessary to bypass pending, as we could delay the replay, but we implement
                  // bypass for performance.
                  // Pending has an additional read for the dest register as we need to replay for write-after-write
                  // hazard as well as write-after-read. To replay for dest write with the same timing, we must also
                  // bypass the dest reg's pending bit.
                  /regs[31:1]
                  /src[2:1]
                     $is_reg_condition = $is_reg && /instr$valid_decode;  // Note: $is_reg can be set for RISC-V sr0.
                     ?$is_reg_condition
                        {$reg_value[31:0], $pending} =
                           
                           // Bypass stages. Both register and pending are bypassed.
                           // Bypassed registers must be from instructions that are good-path as of this instruction or are 2nd issuing.
                           (/instr>>1$dest_reg_valid && (/instr$GoodPathMask[1] || /instr>>1$second_issue) && (/instr>>1$dest_reg == $reg)) ? {/instr>>1$rslt, /instr>>1$reg_wr_pending} :
                           (/instr>>2$dest_reg_valid && (/instr$GoodPathMask[2] || /instr>>2$second_issue) && (/instr>>2$dest_reg == $reg)) ? {/instr>>2$rslt, /instr>>2$reg_wr_pending} :
                           
                           {/instr/regs[$reg]>>2$value, /instr/regs[$reg]>>2$pending};
                     // Replay if this source register is pending.
                     $replay = $is_reg_condition && $pending;
                     $dummy = 1'b0;  // Dummy signal to pull through $ANY expressions when not building verification harness (since SandPiper currently complains about empty $ANY).
                  // Also replay for pending dest reg to keep writes in order. Bypass dest reg pending to support this.
                  $is_dest_condition = $dest_reg_valid && /instr$valid_decode;  // Note, $dest_reg_valid is 0 for RISC-V sr0.
                  ?$is_dest_condition
                     $dest_pending =
                        
                        // Bypass stages. Both register and pending are bypassed.
                        (>>1$dest_reg_valid && ($GoodPathMask[1] || /instr>>1$second_issue) && (>>1$dest_reg == $dest_reg)) ? >>1$reg_wr_pending :
                        (>>2$dest_reg_valid && ($GoodPathMask[2] || /instr>>2$second_issue) && (>>2$dest_reg == $dest_reg)) ? >>2$reg_wr_pending :
                        
                        /regs[$dest_reg]>>2$pending;
                  // Combine replay conditions for pending source or dest registers.
                  $replay_int = | /src[*]$replay || ($is_dest_condition && $dest_pending);
                  
                  
                  
                  
                  
                  
                  
                  
                  
                     
                     
                        
                           
                           
                           
                           
                           
                           
                           
                     
                     
      
                  
                  
                  
                     
                        
                        
                        
                        
                        
                        
                  
                  
                  
                  $replay = $replay_int ;
               
               // =======
               // Execute
               // =======
               \source <builtin> 1   // Instantiated from warp-v_mips-i_4-stage.tlv, 3099 as: m4+indirect(M4_isa['_exe'], @M4_EXECUTE_STAGE, @M4_RESULT_STAGE)
                  \source ./warpv.tlv 2157   // Instantiated from built-in definition.
                     @1
                        // TODO: Branch delay slot not implemented.
                        // (PC is an instruction address, not a byte address.)
                        ?$valid_decode_branch
                           $branch_target[31:2] = $pc_inc + $imm_value[29:0];
                        ?$decode_valid_jump  // (JAL, not JALR)
                           $jump_target[31:2] = {$Pc[31:28], $raw_address[25:0]};
                     @2
                        // Execution.
                        $valid_exe = $valid_decode; // Execute if we decoded.
                        
                        ?$valid_exe
                           // Mux immediate values with register values. (Could be REG_RD or EXE stage.)
                           // Mux register value and immediate to produce operand 2.
                           $op2_value[31:0] = ($raw_opcode[5:3] == 3'b001) ? $imm_value : /src[2]$reg_value;
                           // Mux RS[4:0] and SHAMT to produce shift amount.
                           $shift_amount[4:0] = ($is_sllv || $is_srlv || $is_srav) ? /src[2]$reg_value[4:0] : $raw_shamt;
                           
                           $equal = /src[1]$reg_value == /src[2]$reg_value;
                           $equal_zero = ! | /src[1]$reg_value;
                           $ltz = /src[1]$reg_value[31];
                           $gtz = ! $ltz && ! $equal_zero;
                        ?$branch
                           $taken =
                              $jtype ||
                              ($is_jr || $is_jalr) ||
                              ($is_beq  &&   $equal) ||
                              ($is_bne  && ! $equal) ||
                              (($is_bltz || $is_bltzal) &&   $ltz) ||
                              (($is_bgez || $is_bgezal) && ! $ltz) ||
                              ($is_blez && ! $gtz) ||
                              ($is_bgtz &&   $gtz);
                        ?$decode_valid_indirect_jump  // (JR/JALR)
                           $indirect_jump_target[31:2] = /src[1]$reg_value[31:2];
                        ?$valid_exe
                           // Compute each individual instruction result, combined per-instruction by a macro.
                           
                           // Load/Store
                           // Load instructions. If returning ld is enabled, load instructions write no meaningful result, so we use zeros.
                           $ld_rslt[31:0] = 32'b0;
                           
                           $add_sub_rslt[31:0] = ($is_sub || $is_subu) ? /src[1]$reg_value - $op2_value : /src[1]$reg_value + $op2_value;
                           $is_add_sub = $is_add || $is_sub || $is_addu || $is_subu || $is_addi || $is_addiu;
                           $compare_rslt[31:0] = {31'b0, (/src[1]$reg_value < $op2_value) ^ /src[1]$reg_value[31] ^ $op2_value[31]};
                           $is_compare = $is_slt || $is_sltu || $is_slti || $is_sltiu;
                           $logical_rslt[31:0] =
                                   ({32{$is_and || $is_andi}} & (/src[1]$reg_value & $op2_value)) |
                                   ({32{$is_or  || $is_ori }} & (/src[1]$reg_value | $op2_value)) |
                                   ({32{$is_xor || $is_xori}} & (/src[1]$reg_value ^ $op2_value)) |
                                   ({32{$is_nor            }} & (/src[1]$reg_value | ~ /src[2]$reg_value));
                           $is_logical = $is_and || $is_andi || $is_or || $is_ori || $is_xor || $is_xori || $is_nor;
                           $shift_rslt[31:0] =
                                   ({32{$is_sll || $is_sllv}} & (/src[1]$reg_value << $shift_amount)) |
                                   ({32{$is_srl || $is_srlv}} & (/src[1]$reg_value >> $shift_amount)) |
                                   ({32{$is_sra || $is_srav}} & (/src[1]$reg_value << $shift_amount));
                           $is_shift = $is_sll || $is_srl || $is_sra || $is_sllv || $is_srlv || $is_srav;
                           $lui_rslt[31:0] = {$raw_immediate, 16'b0}; 
                           
                     @2
                        ?$valid_exe
                           $rslt[31:0] =
                                $second_issue ? /orig_inst$ld_rslt :
                                   ({32{$spec_ld}}    & $ld_rslt) |
                                   ({32{$is_add_sub}} & $add_sub_rslt) |
                                   ({32{$is_compare}} & $compare_rslt) |
                                   ({32{$is_logical}} & $logical_rslt) |
                                   ({32{$is_shift}}   & $shift_rslt) |
                                   ({32{$is_lui}}     & $lui_rslt) |
                                   ({32{$branch_or_jump}} & {$pc_inc, 2'b0});   // (no delay slot)
                           
                           
                           
                        // Memory inputs.
                        // TODO: Logic for load/store is cut-n-paste from RISC-V, blindly assuming it is spec'ed the same for MIPS I?
                        //       Load/Store half instructions unique vs. RISC-V and are not treated properly.
                        ?$valid_exe
                           $unnatural_addr_trap = ($ld_st_word && ($addr[1:0] != 2'b00)) || ($ld_st_half && $addr[0]);
                        $ld_st_cond = $ld_st && $valid_exe;
                        ?$ld_st_cond
                           $addr[31:0] = /src[1]$reg_value + $imm_value;
                           
                           // Hardware assumes natural alignment. Otherwise, trap, and handle in s/w (though no s/w provided).
                        $st_cond = $st && $valid_exe;
                        ?$st_cond
                           // Provide a value to store, naturally-aligned to memory, that will work regardless of the lower $addr bits.
                           $st_reg_value[31:0] = /src[2]$reg_value;
                           $st_value[31:0] =
                                $ld_st_word ? $st_reg_value :            // word
                                $ld_st_half ? {2{$st_reg_value[15:0]}} : // half
                                              {4{$st_reg_value[7:0]}};   // byte
                           $st_mask[3:0] =
                                $ld_st_word ? 4'hf :                     // word
                                $ld_st_half ? ($addr[1] ? 4'hc : 4'h3) : // half
                                              (4'h1 << $addr[1:0]);      // byte
                        // Swizzle bytes for load result (assuming natural alignment).
                        ?$second_issue
                           /orig_inst
                              // (Verilator didn't like indexing $ld_value by signal math, so we do these the long way.)
                              $sign_bit =
                                 ! ($is_lbu || $is_lhu) && (  // Signed && ...
                                    $ld_st_word ? $ld_value[31] :
                                    $ld_st_half ? ($addr[1] ? $ld_value[31] : $ld_value[15]) :
                                                  (($addr[1:0] == 2'b00) ? $ld_value[7] :
                                                   ($addr[1:0] == 2'b01) ? $ld_value[15] :
                                                   ($addr[1:0] == 2'b10) ? $ld_value[23] :
                                                                           $ld_value[31]
                                                  )
                                 );
                              $ld_rslt[31:0] =
                                   $ld_st_word ? $ld_value :
                                   $ld_st_half ? {{16{$sign_bit}}, $addr[1] ? $ld_value[31:16] :
                                                                              $ld_value[15:0] } :
                                                 {{24{$sign_bit}}, ($addr[1:0] == 2'b00) ? $ld_value[7:0]   :
                                                                   ($addr[1:0] == 2'b01) ? $ld_value[15:8]  :
                                                                   ($addr[1:0] == 2'b10) ? $ld_value[23:16] :
                                                                                           $ld_value[31:24]};
                        
                        
                        // ISA-specific trap conditions:
                        $non_aborting_isa_trap = $is_break || $is_syscall;
                        $aborting_isa_trap =     ($ld_st && $unnatural_addr_trap);
                  \end_source
               \end_source
               
               @1
                  $pred_taken_branch = $pred_taken && $branch;
               @2
      
                  // =======
                  // Control
                  // =======
                  
                  // Execute stage redirect conditions.
                  $non_pipelined = $div_mul ;
                  $replay_trap = 1'b0;
                  $aborting_trap = $replay_trap || $illegal || $aborting_isa_trap;
                  $non_aborting_trap = $non_aborting_isa_trap;
                  $mispred_branch = $branch && ! ($conditional_branch && ($taken == $pred_taken));
                  ?$valid_decode_branch
                     $branch_redir_pc[31:2] =
                        // If fallthrough predictor, branch mispred always redirects taken, otherwise PC+1 for not-taken.
                        (! $taken) ? $Pc + 30'b1 :
                        $branch_target;
      
                  $trap_target[31:2] = $replay_trap ? $Pc : {30{1'b1}};  // TODO: What should this be? Using ones to terminate test for now.
                  
                  // Determine whether the instruction should commit it's result.
                  //
                  // Abort: Instruction triggers a condition causing a no-commit.
                  // Commit: Ultimate decision to commit results of this instruction, considering aborts and
                  //         prior-instruction redirects (good-path)
                  //
                  // Treatment of loads:
                  //    Loads will commit. They write a garbage value and "pending" to the register file.
                  //    Returning loads clobber an instruction. This instruction is $abort'ed (as is the
                  //    returning load, since they are one in the same). Returning load must explicitly
                  //    write results.
                  //
                  
                  $abort = 1'b0 || $second_issue || $NoFetch || $replay || $aborting_trap;  // Note that register bypass logic requires that abort conditions also redirect.
                  // $commit = m4_prev_instr_valid_through(M4_MAX_REDIRECT_BUBBLES + 1), where +1 accounts for this
                  // instruction's redirects. However, to meet timing, we consider this instruction separately, so,
                  // commit if valid as of the latest redirect from prior instructions and not abort of this instruction.
                  
                  // Normal case:
                  $commit = (! $reset && >>-2$next_good_path_mask[3]) && ! $abort;
                  
                  
                  // Conditions that commit results.
                  $valid_dest_reg_valid = ($dest_reg_valid && $commit) || ($second_issue  );
      
                  
                  
                  
                  $valid_ld = $ld && $commit;
                  $valid_st = $st && $commit;
      
         \source ./warpv.tlv 2464   // Instantiated from warp-v_mips-i_4-stage.tlv, 3158 as: m4+fixed_latency_fake_memory(/top, 0)
            // This macro assumes little-endian.
            
            |fetch
               /instr
                  // ====
                  // Load
                  // ====
                  @3
                     /bank[4-1:0]
                        $ANY = /instr$ANY; // Find signal from outside of /bank.
                        /mem[31:0]
                        ?$spec_ld
                           $ld_value[(32 / 4) - 1 : 0] = /mem[$addr[4 + 2 : 2]]$Value;
                  
                        // Array writes are not currently permitted to use assignment
                        // syntax, so \always_comb is used, and this must be outside of
                        // when conditions, so we need to use if. <<1 because no <= support
                        // in this context. (This limitation will be lifted.)
         
                        // =====
                        // Store
                        // =====
         
                        \SV_plus
                           always @ (posedge clk) begin
                              if ($valid_st && $st_mask[#bank])
                                 /mem[$addr[4 + 2 : 2]]<<0$$Value[(32 / 4) - 1 : 0] <= $st_value[(#bank + 1) * (32 / 4) - 1: #bank * (32 / 4)];
                           end
                     // Combine $ld_value per bank, assuming little-endian.
                     //$ld_value[M4_WORD_RANGE] = /bank[*]$ld_value;
                     // Unfortunately formal verification tools can't handle multiple packed dimensions produced by the expression above, so we
                     // build the concatination.
                     $ld_value[31:0] = {/bank[3]$ld_value, /bank[2]$ld_value, /bank[1]$ld_value, /bank[0]$ld_value};
         
            // Return loads in |mem pipeline. We just hook up the |mem pipeline to the |fetch pipeline w/ the
            // right alignment.
            |mem
               /data
                  @3
                     $ANY = /top|fetch/instr>>0$ANY;
                     /src[2:1]
                        $ANY = /top|fetch/instr/src>>0$ANY;
         \end_source
         |fetch
            /instr
               @3
                  // =========
                  // Reg Write
                  // =========
      
                  $reg_write = $reset ? 1'b0 : $valid_dest_reg_valid;
                  \SV_plus
                     always @ (posedge clk) begin
                        if ($reg_write)
                           /regs[$dest_reg]<<0$$value[31:0] <= $rslt;
                     end
                  
                  // Write $pending along with $value, but coded differently because it must be reset.
                  /regs[*]
                     <<1$pending = ! /instr$reset && (((#regs == /instr$dest_reg) && /instr$valid_dest_reg_valid) ? /instr$reg_wr_pending : $pending);
                   
                  
                  
                  
                  
                  
                     
                        
                           
                     
                  
                  
                  
                     
                    
                  
                  
               @3
                  `BOGUS_USE(/orig_inst/src[2]$dummy) // To pull $dummy through $ANY expressions, avoiding empty expressions.
      \end_source
      
      
      
   \end_source
   \source ./warpv.tlv 3196   // Instantiated from warp-v_mips-i_4-stage.tlv, 12 as: m4+warpv_makerchip_cnt10_tb()
      |fetch
         /instr
            @3
               // Assert these to end simulation (before Makerchip cycle limit).
               $ReachedEnd <= $reset ? 1'b0 : $ReachedEnd || $Pc == {30{1'b1}};
               $Reg4Became45 <= $reset ? 1'b0 : $Reg4Became45 || ($ReachedEnd && /regs[4]$value == 32'd45);
               $passed = ! $reset && $ReachedEnd && $Reg4Became45;
               $failed = ! $reset && (*cyc_cnt > 200 || (*cyc_cnt > 5 && $commit && $illegal));
   \end_source
   \source ./warpv.tlv 4013   // Instantiated from warp-v_mips-i_4-stage.tlv, 13 as: m4+makerchip_pass_fail()
      |done
         @0
            // Assert these to end simulation (before Makerchip cycle limit).
            *passed = & /top|fetch/instr>>3$passed;
            *failed = | /top|fetch/instr>>3$failed;
   \end_source
\SV
   endmodule
