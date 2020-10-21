\TLV_version [\source warp-v_risc-v_4-stage_retime.tlv] 1d --noline: tl-x.org

\source warp-v_risc-v_4-stage_retime.tlv 7
\SV
   // Include WARP-V.
   // Included URL: "./warp-v.tlv"// Included URL: "https://raw.githubusercontent.com/stevehoover/warp-v_includes/5100bc4424dd272ffd495dcb7d9653fb6b200e88/risc-v_defs.tlv"
`include "out/sv_url_inc/picorv32_pcpi_div.sv"  // From: "https://raw.githubusercontent.com/stevehoover/warp-v_includes/master/divmul/picorv32_pcpi_div.sv"
`include "out/sv_url_inc/picorv32_pcpi_fast_mul.sv"  // From: "https://raw.githubusercontent.com/stevehoover/warp-v_includes/master/divmul/picorv32_pcpi_fast_mul.sv"
\SV
module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
\source warp-v_risc-v_4-stage_retime.tlv 11
\TLV
   \source ./warpv.tlv 3556   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+warpv()
      // =================
      //
      //    THE MODEL
      //
      // =================
      
   
      \source ./warpv.tlv 2814   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 3564 as: m4+cpu(/top)
         // Generated logic
         \source <builtin> 1   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 2816 as: m4+indirect(M4_isa['_gen'])
            \source /raw.githubusercontent.com/stevehoover/warpvincludes/5100bc4424dd272ffd495dcb7d9653fb6b200e88/riscvdefs.tlv 222   // Instantiated from built-in definition.
            
               
               // v---------------------
               // Instruction characterization
            
               // M4 ugliness for instruction characterization.
               
               // For each opcode[6:2]
               // (User ISA Manual 2.2, Table 19.1)
               // Associate opcode[6:2] ([1:0] are 2'b11) with mnemonic and instruction type.
               // Instruction type is not in the table, but there seems to be a single instruction type for each of these,
               // so that is mapped here as well.
               // op5(bits, type, mnemonic)
               \SV_plus
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                    // (R-type, but rs2 = const for some, based on funct7 which doesn't exist for I-type?? R-type w/ ignored R2?)
                  
                  
                  
                  
                  
                  
                  
                  
                    // (R-type, but rs2 = const for some, based on funct7 which doesn't exist for I-type?? R-type w/ ignored R2?)
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
               \SV_plus
                  
                  
               \SV_plus
                  // Instruction characterization.
                  // (User ISA Manual 2.2, Table 19.2)
                  // instr(type,  // (this is simply verified vs. op5)
                  //       |  bit-width,
                  //       |  |   extension, 
                  //       |  |   |  opcode[6:2],  // (aka op5)
                  //       |  |   |  |      func3,   // (if applicable)
                  //       |  |   |  |      |    mnemonic)
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  //m4_instr(_, 32, I, 00011, 000, FENCE)
                  //m4_instr(_, 32, I, 00011, 001, FENCE_I)
                  //m4_instr(_, 32, I, 11100, 000, ECALL_EBREAK)  // Two instructions distinguished by an immediate bit, treated as a single instruction.
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
                  
               // ^---------------------
            \end_source
         \end_source
      
         // Instruction memory and fetch of $raw.
         \source <builtin> 1   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 2819 as: m4+indirect(M4_IMEM_MACRO_NAME, M4_PROG_NAME)
            \source ./warpv.tlv 1289   // Instantiated from built-in definition.
               \source <builtin> 1   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 1290 as: m4+indirect(['riscv_']divmul_test['_prog'])
                  \source ./warpv.tlv 1209   // Instantiated from built-in definition.
                     // /==========================\
                     // | M-extension Test Program |
                     // \==========================/
                     //
                     //3 MULs followed by 3 DIVs, check r11-r15 for correct results
                  
                     // Inst #0: ORI,r8,r0,1011
                     // Inst #1: ORI,r9,r0,1010
                     // Inst #2: ORI,r10,r0,10101010
                     // Inst #3: MUL,r11,r8,r9
                     // Inst #4: ORI,r6,r0,0
                     // Inst #5: SW,r6,r11,0
                     // Inst #6: MUL,r12,r9,r10
                     // Inst #7: LW,r4,r6,0
                     // Inst #8: ADDI,r6,r6,100
                     // Inst #9: SW,r6,r12,0
                     // Inst #10: MUL,r13,r8,r10
                     // Inst #11: DIV,r14,r11,r8
                     // Inst #12: DIV,r15,r13,r10
                     // Inst #13: LW,r5,r6,0
                     // Inst #14: ADDI,r4,r0,101101
                     // Inst #15: BGE,r8,r9,111111111110
                  \end_source
               \end_source
               \source ./warpv.tlv 3641   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 1291 as: m4+instrs_for_viz()
                  
                  
                     
                        
                        
                        
                        
                        
                           
                              
                              
                              
                        
                           
                        
                        
                           
                           
                           
                           
                           
                           
                  
               \end_source
               
               // ==============
               // IMem and Fetch
               // ==============
               
               
               
               // For implementation
               // ------------------
               
               // A Vivado-friendly, hard-coded instruction memory (without a separate mem file). Verilator does not like this.
               |fetch
                  /instr_mem[16-1:0]
                     @0
                        // This instruction is selected from all instructions, based on #instr_mem. Not sure if this will synthesize well.
                        $instr[31:0] =
                            (#instr_mem == 0) ? {12'b1011, 5'd0, 3'b110, 5'd8, 7'b0010011} : (#instr_mem == 1) ? {12'b1010, 5'd0, 3'b110, 5'd9, 7'b0010011} : (#instr_mem == 2) ? {12'b10101010, 5'd0, 3'b110, 5'd10, 7'b0010011} : (#instr_mem == 3) ? {7'b0000001, 5'd9, 5'd8, 3'b000, 5'd11, 7'b0110011} : (#instr_mem == 4) ? {12'b0, 5'd0, 3'b110, 5'd6, 7'b0010011} : (#instr_mem == 5) ? {7'b0000000, 5'd11, 5'd6, 3'b010, 5'b00000, 7'b0100011} : (#instr_mem == 6) ? {7'b0000001, 5'd10, 5'd9, 3'b000, 5'd12, 7'b0110011} : (#instr_mem == 7) ? {12'b0, 5'd6, 3'b010, 5'd4, 7'b0000011} : (#instr_mem == 8) ? {12'b100, 5'd6, 3'b000, 5'd6, 7'b0010011} : (#instr_mem == 9) ? {7'b0000000, 5'd12, 5'd6, 3'b010, 5'b00000, 7'b0100011} : (#instr_mem == 10) ? {7'b0000001, 5'd10, 5'd8, 3'b000, 5'd13, 7'b0110011} : (#instr_mem == 11) ? {7'b0000001, 5'd8, 5'd11, 3'b100, 5'd14, 7'b0110011} : (#instr_mem == 12) ? {7'b0000001, 5'd10, 5'd13, 3'b100, 5'd15, 7'b0110011} : (#instr_mem == 13) ? {12'b0, 5'd6, 3'b010, 5'd5, 7'b0000011} : (#instr_mem == 14) ? {12'b101101, 5'd0, 3'b000, 5'd4, 7'b0010011} : (#instr_mem == 15) ? {1'b0, 6'b111111, 5'd9, 5'd8, 3'b101, 4'b1111, 1'b1, 7'b1100011} : 32'b0;
                  /instr
                     @0
                        ?$fetch
                           // Fetch the raw instruction from program memory.
                           $raw[31:0] = |fetch/instr_mem[$Pc[5:2]]$instr;
               
               
               
               
               
               
               
                  
                  
                  
                  
                  
                     
                  
                  
                  
                  
            
               
                  
                     
                        
                           
               
               
               
               
               
               
               
                  
                     
                        
                           
               
               
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
                  $second_issue = $second_issue_ld || $second_issue_div_mul ;
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
                        $ANY = |fetch/instr$second_issue_ld ? |fetch/instr/orig_load_inst$ANY : |fetch/instr$second_issue_div_mul ? |fetch/instr/hold_inst>>3$ANY :  |fetch/instr/orig_load_inst$ANY;
                        /src[2:1]
                           $ANY = |fetch/instr$second_issue_ld ? |fetch/instr/orig_load_inst/src$ANY : |fetch/instr$second_issue_div_mul ? |fetch/instr/hold_inst/src>>3$ANY :  |fetch/instr/orig_load_inst/src$ANY;
                  
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
               
               @0
      
                  // ======
                  // DECODE
                  // ======
      
                  // Decode of the fetched instruction
                  $valid_decode = $fetch;  // Always decode if we fetch.
                  $valid_decode_branch = $valid_decode && $branch;
                  // A load that will return later.
                  //$split_ld = $spec_ld && 1'b['']M4_INJECT_RETURNING_LD;
                  \source <builtin> 1   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 3013 as: m4+indirect(M4_isa['_decode'])
                     \source ./warpv.tlv 1498   // Instantiated from built-in definition.
                        // TODO: ?$valid_<stage> conditioning should be replaced by use of m4_prev_instr_valid_through(..).
                        ?$valid_decode
                           // =================================
                     
                           // Extract fields of $raw (instruction) into $raw_<field>[x:0].
                           {$raw_funct7[6:0], $raw_rs2[4:0], $raw_rs1[4:0], $raw_funct3[2:0], $raw_rd[4:0], $raw_op5[4:0], $raw_op2[1:0]} = $raw;
                           `BOGUS_USE($raw_op2)  // Delete once it's used.
                           // Extract immediate fields into type-specific signals.
                           // (User ISA Manual 2.2, Fig. 2.4)
                           $raw_i_imm[31:0] = {{21{$raw[31]}}, $raw[30:20]};
                           $raw_s_imm[31:0] = {{21{$raw[31]}}, $raw[30:25], $raw[11:7]};
                           $raw_b_imm[31:0] = {{20{$raw[31]}}, $raw[7], $raw[30:25], $raw[11:8], 1'b0};
                           $raw_u_imm[31:0] = {$raw[31:12], {12{1'b0}}};
                           $raw_j_imm[31:0] = {{12{$raw[31]}}, $raw[19:12], $raw[20], $raw[30:21], 1'b0};
                           // Extract other type/instruction-specific fields.
                           $raw_shamt[6:0] = $raw[26:20];
                           $raw_aq = $raw[26];
                           $raw_rl = $raw[25];
                           $raw_rs3[4:0] = $raw[31:27];
                           $raw_rm[2:0] = $raw_funct3;
                           `BOGUS_USE($raw_shamt $raw_aq $raw_rl $raw_rs3 $raw_rm)  // Avoid "unused" messages. Remove these as they become used.
                     
                           // Instruction type decode
                           \SV_plus
                              assign $$is_i_type = (((0 | (1 << 5'b00000) | (1 << 5'b00001) | (1 << 5'b00100) | (1 << 5'b00110) | (1 << 5'b11001) | (1 << 5'b11100)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_r_type = (((0 | (1 << 5'b01011) | (1 << 5'b01100) | (1 << 5'b01110) | (1 << 5'b10100)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_r2_type = (((0) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_r4_type = (((0 | (1 << 5'b10000) | (1 << 5'b10001) | (1 << 5'b10010) | (1 << 5'b10011)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_s_type = (((0 | (1 << 5'b01000) | (1 << 5'b01001)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_b_type = (((0 | (1 << 5'b11000)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_j_type = (((0 | (1 << 5'b11011)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is_u_type = (((0 | (1 << 5'b00101) | (1 << 5'b01101)) >> $raw_op5) & 32'b1) != 32'b0; assign $$is___type = (((0 | (1 << 5'b00010) | (1 << 5'b00011) | (1 << 5'b00111) | (1 << 5'b01010) | (1 << 5'b01111) | (1 << 5'b10101) | (1 << 5'b10110) | (1 << 5'b10111) | (1 << 5'b11010) | (1 << 5'b11101) | (1 << 5'b11110) | (1 << 5'b11111)) >> $raw_op5) & 32'b1) != 32'b0; 
                     
                           // Instruction decode.
                           \source ./warpv.tlv 1478   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 1526 as: m4+riscv_decode_expr()
                              $is_lui_instr = $raw_op5 == 5'b01101;
                              $is_auipc_instr = $raw_op5 == 5'b00101;
                              $is_jal_instr = $raw_op5 == 5'b11011;
                              $is_jalr_instr = $raw_op5 == 5'b11001 && $raw_funct3 == 3'b000;
                              $is_beq_instr = $raw_op5 == 5'b11000 && $raw_funct3 == 3'b000;
                              $is_bne_instr = $raw_op5 == 5'b11000 && $raw_funct3 == 3'b001;
                              $is_blt_instr = $raw_op5 == 5'b11000 && $raw_funct3 == 3'b100;
                              $is_bge_instr = $raw_op5 == 5'b11000 && $raw_funct3 == 3'b101;
                              $is_bltu_instr = $raw_op5 == 5'b11000 && $raw_funct3 == 3'b110;
                              $is_bgeu_instr = $raw_op5 == 5'b11000 && $raw_funct3 == 3'b111;
                              $is_lb_instr = $raw_op5 == 5'b00000 && $raw_funct3 == 3'b000;
                              $is_lh_instr = $raw_op5 == 5'b00000 && $raw_funct3 == 3'b001;
                              $is_lw_instr = $raw_op5 == 5'b00000 && $raw_funct3 == 3'b010;
                              $is_lbu_instr = $raw_op5 == 5'b00000 && $raw_funct3 == 3'b100;
                              $is_lhu_instr = $raw_op5 == 5'b00000 && $raw_funct3 == 3'b101;
                              $is_sb_instr = $raw_op5 == 5'b01000 && $raw_funct3 == 3'b000;
                              $is_sh_instr = $raw_op5 == 5'b01000 && $raw_funct3 == 3'b001;
                              $is_sw_instr = $raw_op5 == 5'b01000 && $raw_funct3 == 3'b010;
                              $is_addi_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b000;
                              $is_slti_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b010;
                              $is_sltiu_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b011;
                              $is_xori_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b100;
                              $is_ori_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b110;
                              $is_andi_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b111;
                              $is_slli_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b001 && $raw_funct7[6:1] == 6'b000000;
                              $is_srli_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b101 && $raw_funct7[6:1] == 6'b000000;
                              $is_srai_instr = $raw_op5 == 5'b00100 && $raw_funct3 == 3'b101 && $raw_funct7[6:1] == 6'b010000;
                              $is_add_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b000 && $raw_funct7[6:0] == 7'b0000000;
                              $is_sub_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b000 && $raw_funct7[6:0] == 7'b0100000;
                              $is_sll_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b001 && $raw_funct7[6:0] == 7'b0000000;
                              $is_slt_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b010 && $raw_funct7[6:0] == 7'b0000000;
                              $is_sltu_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b011 && $raw_funct7[6:0] == 7'b0000000;
                              $is_xor_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b100 && $raw_funct7[6:0] == 7'b0000000;
                              $is_srl_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b101 && $raw_funct7[6:0] == 7'b0000000;
                              $is_sra_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b101 && $raw_funct7[6:0] == 7'b0100000;
                              $is_or_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b110 && $raw_funct7[6:0] == 7'b0000000;
                              $is_and_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b111 && $raw_funct7[6:0] == 7'b0000000;
                              $is_csrrw_instr = $raw_op5 == 5'b11100 && $raw_funct3 == 3'b001;
                              $is_csrrs_instr = $raw_op5 == 5'b11100 && $raw_funct3 == 3'b010;
                              $is_csrrc_instr = $raw_op5 == 5'b11100 && $raw_funct3 == 3'b011;
                              $is_csrrwi_instr = $raw_op5 == 5'b11100 && $raw_funct3 == 3'b101;
                              $is_csrrsi_instr = $raw_op5 == 5'b11100 && $raw_funct3 == 3'b110;
                              $is_csrrci_instr = $raw_op5 == 5'b11100 && $raw_funct3 == 3'b111;
                              $is_mul_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b000 && $raw_funct7[6:0] == 7'b0000001;
                              $is_mulh_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b001 && $raw_funct7[6:0] == 7'b0000001;
                              $is_mulhsu_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b010 && $raw_funct7[6:0] == 7'b0000001;
                              $is_mulhu_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b011 && $raw_funct7[6:0] == 7'b0000001;
                              $is_div_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b100 && $raw_funct7[6:0] == 7'b0000001;
                              $is_divu_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b101 && $raw_funct7[6:0] == 7'b0000001;
                              $is_rem_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b110 && $raw_funct7[6:0] == 7'b0000001;
                              $is_remu_instr = $raw_op5 == 5'b01100 && $raw_funct3 == 3'b111 && $raw_funct7[6:0] == 7'b0000001;
                              
                           \end_source
                           
                           
                           // Instruction requires integer mul/div unit and is long-latency.
                           $divtype_instr = ($is_div_instr || $is_divu_instr || $is_rem_instr || $is_remu_instr);
                           $multype_instr = ($is_mul_instr || $is_mulh_instr || $is_mulhsu_instr || $is_mulhu_instr);
                           $div_mul       = ($multype_instr || $divtype_instr);
                           
                           
                           
                           
                           
                     
                           
                           
                           
                           
                           
                           
                           
                           
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                           
                           
                                                    
                                                    
                                                    
                                                    
                           
                           
                                             
                                             
                                             
                                             
                                             
                                             
                                             
                                             
                                             
                           
                           
                           
                           
                     
                           $is_srli_srai_instr = $is_srli_instr || $is_srai_instr;
                           // Some I-type instructions have a funct7 field rather than immediate bits, so these must factor into the illegal instruction expression explicitly.
                           $illegal_itype_with_funct7 = ( $is_srli_srai_instr  ) && | {$raw_funct7[6], $raw_funct7[4:0]};
                           $illegal = ($illegal_itype_with_funct7 && ! $is_lui_instr && ! $is_auipc_instr && ! $is_jal_instr && ! $is_jalr_instr && ! $is_beq_instr && ! $is_bne_instr && ! $is_blt_instr && ! $is_bge_instr && ! $is_bltu_instr && ! $is_bgeu_instr && ! $is_lb_instr && ! $is_lh_instr && ! $is_lw_instr && ! $is_lbu_instr && ! $is_lhu_instr && ! $is_sb_instr && ! $is_sh_instr && ! $is_sw_instr && ! $is_addi_instr && ! $is_slti_instr && ! $is_sltiu_instr && ! $is_xori_instr && ! $is_ori_instr && ! $is_andi_instr && ! $is_slli_instr && ! $is_srli_instr && ! $is_srai_instr && ! $is_add_instr && ! $is_sub_instr && ! $is_sll_instr && ! $is_slt_instr && ! $is_sltu_instr && ! $is_xor_instr && ! $is_srl_instr && ! $is_sra_instr && ! $is_or_instr && ! $is_and_instr && ! $is_csrrw_instr && ! $is_csrrs_instr && ! $is_csrrc_instr && ! $is_csrrwi_instr && ! $is_csrrsi_instr && ! $is_csrrci_instr && ! $is_mul_instr && ! $is_mulh_instr && ! $is_mulhsu_instr && ! $is_mulhu_instr && ! $is_div_instr && ! $is_divu_instr && ! $is_rem_instr && ! $is_remu_instr) ||
                                      ($raw[1:0] != 2'b11); // All legal instructions have opcode[1:0] == 2'b11. We ignore these bits in decode logic.
                           $conditional_branch = $is_b_type;
                        $jump = $is_jal_instr;  // "Jump" in RISC-V means unconditional. (JALR is a separate redirect condition.)
                        $branch = $is_b_type;
                        $indirect_jump = $is_jalr_instr;
                        ?$valid_decode
                           $ld = $raw[6:3] == 4'b0;
                           $st = $is_s_type;
                           $ld_st = $ld || $st;
                           $ld_st_word = $ld_st && ($raw_funct3[1] == 1'b1);
                           $ld_st_half = $ld_st && ($raw_funct3[1:0] == 2'b01);
                           //$ld_st_byte = $ld_st && ($raw_funct3[1:0] == 2'b00);
                           `BOGUS_USE($is___type $is_u_type)
                     
                           // Output signals.
                           /src[2:1]
                              // Reg valid for this source, based on instruction type.
                              $is_reg = /instr$is_r_type || /instr$is_r4_type || (/instr$is_i_type && (#src == 1)) || /instr$is_r2_type || /instr$is_s_type || /instr$is_b_type;
                              $reg[4:0] = (#src == 1) ? /instr$raw_rs1 : /instr$raw_rs2;
                              
                           // For debug.
                           $mnemonic[10*8-1:0] = $is_lui_instr ? "LUI       " : $is_auipc_instr ? "AUIPC     " : $is_jal_instr ? "JAL       " : $is_jalr_instr ? "JALR      " : $is_beq_instr ? "BEQ       " : $is_bne_instr ? "BNE       " : $is_blt_instr ? "BLT       " : $is_bge_instr ? "BGE       " : $is_bltu_instr ? "BLTU      " : $is_bgeu_instr ? "BGEU      " : $is_lb_instr ? "LB        " : $is_lh_instr ? "LH        " : $is_lw_instr ? "LW        " : $is_lbu_instr ? "LBU       " : $is_lhu_instr ? "LHU       " : $is_sb_instr ? "SB        " : $is_sh_instr ? "SH        " : $is_sw_instr ? "SW        " : $is_addi_instr ? "ADDI      " : $is_slti_instr ? "SLTI      " : $is_sltiu_instr ? "SLTIU     " : $is_xori_instr ? "XORI      " : $is_ori_instr ? "ORI       " : $is_andi_instr ? "ANDI      " : $is_slli_instr ? "SLLI      " : $is_srli_instr ? "SRLI      " : $is_srai_instr ? "SRAI      " : $is_add_instr ? "ADD       " : $is_sub_instr ? "SUB       " : $is_sll_instr ? "SLL       " : $is_slt_instr ? "SLT       " : $is_sltu_instr ? "SLTU      " : $is_xor_instr ? "XOR       " : $is_srl_instr ? "SRL       " : $is_sra_instr ? "SRA       " : $is_or_instr ? "OR        " : $is_and_instr ? "AND       " : $is_csrrw_instr ? "CSRRW     " : $is_csrrs_instr ? "CSRRS     " : $is_csrrc_instr ? "CSRRC     " : $is_csrrwi_instr ? "CSRRWI    " : $is_csrrsi_instr ? "CSRRSI    " : $is_csrrci_instr ? "CSRRCI    " : $is_mul_instr ? "MUL       " : $is_mulh_instr ? "MULH      " : $is_mulhsu_instr ? "MULHSU    " : $is_mulhu_instr ? "MULHU     " : $is_div_instr ? "DIV       " : $is_divu_instr ? "DIVU      " : $is_rem_instr ? "REM       " : $is_remu_instr ? "REMU      " :  "ILLEGAL   ";
                           `BOGUS_USE($mnemonic)
                        // Condition signals must not themselves be conditioned (currently).
                        $dest_reg[4:0] = $second_issue_div_mul ? |fetch/instr/hold_inst>>3$dest_reg :
                                                         $second_issue_ld ? |fetch/instr/orig_inst$dest_reg : $raw_rd;
                        $dest_reg_valid =  (($valid_decode && ! $is_s_type && ! $is_b_type) || $second_issue) &&
                                          | $dest_reg;   // r0 not valid.
                        
                        
                        
                        
                           
                           
                              
                              
                              
                              
                        
                                                         
                        
                        
                        
                        // Actually load.
                        $spec_ld = $valid_decode && $ld;
                        
                        // CSR decode.
                        $is_csr_write = $is_csrrw_instr || $is_csrrwi_instr;
                        $is_csr_set   = $is_csrrs_instr || $is_csrrsi_instr;
                        $is_csr_clear = $is_csrrc_instr || $is_csrrci_instr;
                        $is_csr_instr = $is_csr_write ||
                                        $is_csr_set   ||
                                        $is_csr_clear;
                        $valid_csr = 1'b0 || $is_csr_cycle || $is_csr_cycleh || $is_csr_time || $is_csr_timeh || $is_csr_instret || $is_csr_instreth;
                        $csr_trap = $is_csr_instr && ! $valid_csr;
                     \end_source
                  \end_source
               \source <builtin> 1   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 3014 as: m4+indirect(['branch_pred_']M4_BRANCH_PRED)
                  \source ./warpv.tlv 2532   // Instantiated from built-in definition.
                     @0
                        ?$branch
                           $pred_taken = >>1$BranchState[1];
                     @0
                        $branch_or_reset = ($branch && $commit) || $reset;
                        ?$branch_or_reset
                           $BranchState[1:0] <=
                              $reset ? 2'b01 :
                              $taken ? ($BranchState == 2'b11 ? $RETAIN : $BranchState + 2'b1) :
                                       ($BranchState == 2'b00 ? $RETAIN : $BranchState - 2'b1);
                  \end_source
               \end_source
               
               @0
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
                           ($reg == 5'b0) ? {32'b0, 1'b0} :  // Read r0 as 0 (not pending).
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
                        ($dest_reg == 5'b0) ? 1'b0 :  // Read r0 as 0 (not pending). Not actually necessary, but it cuts off read of non-existent rs0, which might be an issue for formal verif tools.
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
               \source <builtin> 1   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 3099 as: m4+indirect(M4_isa['_exe'], @M4_EXECUTE_STAGE, @M4_RESULT_STAGE)
                  \source ./warpv.tlv 1641   // Instantiated from built-in definition.
                     // if M_EXT is enabled, this handles the stalling logic
                     
                     \source ./warpv.tlv 2570   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+m_extension()
                     
                        // RISC-V M-Extension instructions in WARP-V are fixed latency
                        // As of today, to handle those instructions, WARP-V pipeline is stalled for the given latency, and the
                        // results are written back through a second issue at the end of stalling duration.
                        // Verilog modules are inherited from PicoRV32, and are located in the ./muldiv directory.
                        // Since the modules have a fixed latency, their valid signals are instantiated as valid decode for M-type
                        // instructions is detected, and results are put in /orig_inst scope to be used in second issue.
                     
                        // This macro handles the stalling logic using a counter, and triggers second issue accordingly.
                     
                        // latency for division is different for ALTOPS case
                        
                             
                        
                               // latency for multiplication is 2 cycles in case of ALTOPS,
                                                               // but we flop it for 5 cycles (in rslt_mux) to augment the normal
                                                               // second issue behavior
                     
                        // Relative to typical 1-cycle latency instructions.
                     
                        @0
                           $second_issue_div_mul = >>3$trigger_next_pc_div_mul_second_issue;
                        @0
                           {$div_stall, $mul_stall, $stall_cnt[5:0]} =    $reset ? '0 :
                                                                          $second_issue_div_mul ? '0 :
                                                                          ($commit && $div_mul) ? {$divtype_instr, $multype_instr, 6'b1} :
                                                                          >>1$div_stall ? {1'b1, 1'b0, >>1$stall_cnt + 6'b1} :
                                                                          >>1$mul_stall ? {1'b0, 1'b1, >>1$stall_cnt + 6'b1} :
                                                                          '0;
                                                                          
                           $stall_cnt_upper_mul = ($stall_cnt == 5);
                           $stall_cnt_upper_div = ($stall_cnt == 37);
                           $trigger_next_pc_div_mul_second_issue = ($div_stall && $stall_cnt_upper_div) || ($mul_stall && $stall_cnt_upper_mul);
                     \end_source
                     
                  
                     // if F_EXT is enabled, this handles the stalling logic
                     
                     
                     
                     @0
                        ?$valid_decode_branch
                           $branch_target[31:2] = $Pc[31:2] + $raw_b_imm[31:2];
                           $misaligned_pc = | $raw_b_imm[1:0];
                        ?$jump  // (JAL, not JALR)
                           $jump_target[31:2] = $Pc[31:2] + $raw_j_imm[31:2];
                           $misaligned_jump_target = $raw_j_imm[1];
                     @0
                        // Execution.
                        $valid_exe = $valid_decode; // Execute if we decoded.
                        
                        // Verilog instantiation must happen outside when conditions' scope
                        $divblk_valid = $divtype_instr && $commit;
                        $mulblk_valid = $multype_instr && $commit;
                        /* verilator lint_off WIDTH */
                        /* verilator lint_off CASEINCOMPLETE */   
                        \source ./warpv.tlv 2607   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+warpv_mul(|fetch/instr,/mul1, $mulblock_rslt, $wrm, $waitm, $readym, $clk, $resetn, $mul_in1, $mul_in2, $instr_type_mul, $mulblk_valid)
                           /mul1      
                              
                              // instr type is one hot encoding of the required M type instruction
                              // the idea is to concatenate is_*_instr from WARP-V and pass on to this module
                                 
                              $opcode[2:0] = (|fetch/instr$instr_type_mul == 4'b0001) ? 3'b000 : // mull 
                                             (|fetch/instr$instr_type_mul == 4'b0010) ? 3'b001 : // mulh
                                             (|fetch/instr$instr_type_mul == 4'b0100) ? 3'b010 : // mulhsu
                                             (|fetch/instr$instr_type_mul == 4'b1000) ? 3'b011 : // mulhu
                                                                              3'b000 ; // default to mul, but this case 
                                                                                       // should not be encountered ideally
                        
                              $mul_insn[31:0] = {7'b0000001,10'b0011000101,$opcode,5'b00101,7'b0110011};
                                             // {  funct7  ,{rs2, rs1} (X), funct3, rd (X),  opcode  }   
                              // this module is located in ./muldiv/picorv32_pcpi_fast_mul.sv
                              \SV_plus      
                                    picorv32_pcpi_fast_mul #(.EXTRA_MUL_FFS(1), .EXTRA_INSN_FFS(1), .MUL_CLKGATE(0)) mul(
                                          .clk           (|fetch/instr$clk), 
                                          .resetn        (|fetch/instr$resetn),
                                          .pcpi_valid    (|fetch/instr$mulblk_valid),
                                          .pcpi_insn     ($mul_insn),
                                          .pcpi_rs1      (|fetch/instr$mul_in1),
                                          .pcpi_rs2      (|fetch/instr$mul_in2),
                                          .pcpi_wr       (|fetch/instr$$wrm),
                                          .pcpi_rd       (|fetch/instr$$mulblock_rslt[31:0]),
                                          .pcpi_wait     (|fetch/instr$$waitm),
                                          .pcpi_ready    (|fetch/instr$$readym)
                                    );
                           
                        \end_source
                        \source ./warpv.tlv 2637   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+warpv_div(|fetch/instr,/div1, $divblock_rslt, $wrd, $waitd, $readyd, $clk, $resetn, $div_in1, $div_in2, $instr_type_div, >>1$div_stall)
                           /div1
                              
                              // instr type is one hot encoding of the required M type instruction
                              // the idea is to concatenate is_*_instr from WARP-V and pass on to this module
                                 
                              $opcode[2:0] = (|fetch/instr$instr_type_div == 4'b0001 ) ? 3'b100 : // div
                                             (|fetch/instr$instr_type_div == 4'b0010 ) ? 3'b101 : // divu
                                             (|fetch/instr$instr_type_div == 4'b0100 ) ? 3'b110 : // rem
                                             (|fetch/instr$instr_type_div == 4'b1000 ) ? 3'b111 : // remu
                                                                               3'b100 ; // default to div, but this case 
                                                                                        // should not be encountered ideally
                              $div_insn[31:0] = {7'b0000001,10'b0011000101,3'b000,5'b00101,7'b0110011} | ($opcode << 12);
                                             // {  funct7  ,{rs2, rs1} (X), funct3, rd (X),  opcode  }   
                              // this module is located in ./muldiv/picorv32_div_opt.sv
                              \SV_plus
                                    picorv32_pcpi_div div(
                                          .clk           (|fetch/instr$clk), 
                                          .resetn        (|fetch/instr$resetn),
                                          .pcpi_valid    (|fetch/instr>>1$div_stall),
                                          .pcpi_insn     ($div_insn),
                                          .pcpi_rs1      (|fetch/instr$div_in1),
                                          .pcpi_rs2      (|fetch/instr$div_in2),
                                          .pcpi_rd       (|fetch/instr$$divblock_rslt[31:0]),
                                          .pcpi_wait     (|fetch/instr$$waitd),
                                          .pcpi_wr       (|fetch/instr$$wrd),
                                          .pcpi_ready    (|fetch/instr$$readyd)
                                       );
                        \end_source
                        // for the division module, the valid signal must be asserted for the entire computation duration, hence >>1$div_stall is used for this purpose
                        // for multiplication it is just a single cycle pulse to start operating
                  
                        /* verilator lint_on CASEINCOMPLETE */
                        /* verilator lint_on WIDTH */
                        // use $ANY for passing attributes from long-latency div/mul instructions into the pipeline 
                        // stall_cnt_upper_div indicates that the results for div module are ready. The second issue of the instruction takes place
                        // M4_NON_PIPELINED_BUBBLES after this point (depending on pipeline depth)
                        // retain till next M-type instruction, to be used again at second issue
                        
                   
                        
                        
                  
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        // hold_inst scope is not needed when long latency instructions are disabled
                        
                        // ORed with 1'b0 for maintaining correct behavior for all 3 combinations of F & M, only F and only M 
                        /hold_inst
                           $ANY = 1'b0  || (|fetch/instr$mulblk_valid || (|fetch/instr$div_stall && |fetch/instr$commit))  ? |fetch/instr$ANY : >>1$ANY;
                           /src[2:1]
                              $ANY = 1'b0  || (|fetch/instr$mulblk_valid || (|fetch/instr$div_stall && |fetch/instr$commit))  ? |fetch/instr/src$ANY : >>1$ANY;
                        
                        // Compute results for each instruction, independent of decode (power-hungry, but fast).
                        ?$valid_exe
                           $equal = /src[1]$reg_value == /src[2]$reg_value;
                        ?$branch
                           $taken =
                              $is_j_type ||
                              ($is_beq_instr && $equal) ||
                              ($is_bne_instr && ! $equal) ||
                              (($is_blt_instr || $is_bltu_instr || $is_bge_instr || $is_bgeu_instr) &&
                               (($is_bge_instr || $is_bgeu_instr) ^
                                (({($is_blt_instr ^ /src[1]$reg_value[31]), /src[1]$reg_value[31-1:0]} <
                                  {($is_blt_instr ^ /src[2]$reg_value[31]), /src[2]$reg_value[31-1:0]}
                                 ) ^ ((/src[1]$reg_value[31] != /src[2]$reg_value[31]) & $is_bge_instr)
                                )
                               )
                              );
                        ?$indirect_jump  // (JALR)
                           $indirect_jump_full_target[31:0] = /src[1]$reg_value + $raw_i_imm;
                           $indirect_jump_target[31:2] = $indirect_jump_full_target[31:2];
                           $misaligned_indirect_jump_target = $indirect_jump_full_target[1];
                        ?$valid_exe
                           // Compute each individual instruction result, combined per-instruction by a macro.
                           // TODO: Could provide some macro magic to specify combined instructions w/ a single result and mux select.
                           //       This would reduce code below and probably improve implementation.
                           
                           $lui_rslt[31:0]   = {$raw_u_imm[31:12], 12'b0};
                           $auipc_rslt[31:0] = {$Pc, 2'b0} + $raw_u_imm;
                           $jal_rslt[31:0]   = {$Pc, 2'b0} + 4;
                           $jalr_rslt[31:0]  = {$Pc, 2'b0} + 4;
                           // Load instructions. If returning ld is enabled, load instructions write no meaningful result, so we use zeros.
                           
                           $lb_rslt[31:0]    = 32'b0;
                           $lh_rslt[31:0]    = 32'b0;
                           $lw_rslt[31:0]    = 32'b0;
                           $lbu_rslt[31:0]   = 32'b0;
                           $lhu_rslt[31:0]   = 32'b0;
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           $addi_rslt[31:0]  = /src[1]$reg_value + $raw_i_imm;  // TODO: This has its own adder; could share w/ add/sub.
                           $xori_rslt[31:0]  = /src[1]$reg_value ^ $raw_i_imm;
                           $ori_rslt[31:0]   = /src[1]$reg_value | $raw_i_imm;
                           $andi_rslt[31:0]  = /src[1]$reg_value & $raw_i_imm;
                           $slli_rslt[31:0]  = /src[1]$reg_value << $raw_i_imm[5:0];
                           $srli_intermediate_rslt[31:0] = /src[1]$reg_value >> $raw_i_imm[5:0];
                           $srai_intermediate_rslt[31:0] = /src[1]$reg_value[31] ? $srli_intermediate_rslt | ((32'b0 - 1) << (32 - $raw_i_imm[5:0]) ): $srli_intermediate_rslt;
                           $srl_rslt[31:0]   = /src[1]$reg_value >> /src[2]$reg_value[4:0];
                           $sra_rslt[31:0]   = /src[1]$reg_value[31] ? $srl_rslt | ((32'b0 - 1) << (32 - /src[2]$reg_value[4:0]) ): $srl_rslt;
                           $slti_rslt[31:0]  =  (/src[1]$reg_value[31] == $raw_i_imm[31]) ? $sltiu_rslt : {31'b0,/src[1]$reg_value[31]};
                           $sltiu_rslt[31:0] = (/src[1]$reg_value < $raw_i_imm) ? 1 : 0;
                           $srai_rslt[31:0]  = $srai_intermediate_rslt;
                           $srli_rslt[31:0]  = $srli_intermediate_rslt;
                           $add_sub_rslt[31:0] = ($raw_funct7[5] == 1) ?  /src[1]$reg_value - /src[2]$reg_value : /src[1]$reg_value + /src[2]$reg_value;
                           $add_rslt[31:0]   = $add_sub_rslt;
                           $sub_rslt[31:0]   = $add_sub_rslt;
                           $sll_rslt[31:0]   = /src[1]$reg_value << /src[2]$reg_value[4:0];
                           $slt_rslt[31:0]   = (/src[1]$reg_value[31] == /src[2]$reg_value[31]) ? $sltu_rslt : {31'b0,/src[1]$reg_value[31]};
                           $sltu_rslt[31:0]  = (/src[1]$reg_value < /src[2]$reg_value) ? 1 : 0;
                           $xor_rslt[31:0]   = /src[1]$reg_value ^ /src[2]$reg_value;
                           $or_rslt[31:0]    = /src[1]$reg_value | /src[2]$reg_value;
                           $and_rslt[31:0]   = /src[1]$reg_value & /src[2]$reg_value;
                           // CSR read instructions have the same result expression. Counting on synthesis to optimize result mux.
                           $csrrw_rslt[31:0]  = $is_csr_instreth ? {{0{1'b0}},$csr_instreth} : $is_csr_instret ? {{0{1'b0}},$csr_instret} : $is_csr_timeh ? {{0{1'b0}},$csr_timeh} : $is_csr_time ? {{0{1'b0}},$csr_time} : $is_csr_cycleh ? {{0{1'b0}},$csr_cycleh} : $is_csr_cycle ? {{0{1'b0}},$csr_cycle} : 32'bx;
                           $csrrs_rslt[31:0]  = $csrrw_rslt;
                           $csrrc_rslt[31:0]  = $csrrw_rslt;
                           $csrrwi_rslt[31:0] = $csrrw_rslt;
                           $csrrsi_rslt[31:0] = $csrrw_rslt;
                           $csrrci_rslt[31:0] = $csrrw_rslt;
                           
                           // "M" Extension.
                           
                           
                           // for Verilog modules instantiation
                           $clk = *clk;
                           $resetn = !(*reset);
                  
                           $instr_type_mul[3:0]    = $reset ? '0 : $mulblk_valid ? {$is_mulhu_instr,$is_mulhsu_instr,$is_mulh_instr,$is_mul_instr} : $RETAIN;
                           $mul_in1[31:0] = $reset ? '0 : $mulblk_valid ? /src[1]$reg_value : $RETAIN;
                           $mul_in2[31:0] = $reset ? '0 : $mulblk_valid ? /src[2]$reg_value : $RETAIN;
                           
                           $instr_type_div[3:0]    = $reset ? '0 : $divblk_valid ? {$is_remu_instr,$is_rem_instr,$is_divu_instr,$is_div_instr} : $RETAIN;
                           $div_in1[31:0] = $reset ? '0 : $divblk_valid ? /src[1]$reg_value : $RETAIN;
                           $div_in2[31:0] = $reset ? '0 : $divblk_valid ? /src[2]$reg_value : $RETAIN;
                           
                           // result signals for div/mul can be pulled down to 0 here, as they are assigned only in the second issue
                  
                           $mul_rslt[31:0]      = 32'b0;
                           $mulh_rslt[31:0]     = 32'b0;
                           $mulhsu_rslt[31:0]   = 32'b0;
                           $mulhu_rslt[31:0]    = 32'b0;
                           $div_rslt[31:0]      = 32'b0;
                           $divu_rslt[31:0]     = 32'b0;
                           $rem_rslt[31:0]      = 32'b0;
                           $remu_rslt[31:0]     = 32'b0;
                           `BOGUS_USE ($wrm $wrd $readyd $readym $waitm $waitd)
                           
                        
                           // "F" Extension.
                           
                           
                           
                           
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                           
                           
                           
                  
                           
                           
                           
                           
                           
                           
                                                 
                                                 
                                                 
                                                 
                                                 
                           
                  
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                     // CSR logic
                     // ---------
                     \source ./warpv.tlv 1394   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 1894 as: m4+riscv_csrs((m4_csrs))
                        
                        \source ./warpv.tlv 1352   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+riscv_csr(m4_echo(['m4_csr_']csr['_args']))
                           //--------------
                           // CSR CYCLE
                           //--------------
                           @0
                              $is_csr_cycle = $raw[31:20] == 12'hC00;
                           @0
                              // CSR update. Counting on synthesis to optimize each bit, based on {32{1'b1}}.
                              // Conditionally include code for h/w and s/w write based on side_effect param (0 - s/w, 1 - s/w + h/w, RO - neither).
                              
                              
                              
                              // hw_wr_mask conditioned by hw_wr.
                              $csr_cycle_hw_wr_en_mask[31:0] = {32{$csr_cycle_hw_wr}} & $csr_cycle_hw_wr_mask;
                              // The CSR value, updated by side-effect writes.
                              $upd_csr_cycle[31:0] =
                                   ($csr_cycle_hw_wr_en_mask & $csr_cycle_hw_wr_value) | (~ $csr_cycle_hw_wr_en_mask & $csr_cycle);
                              
                              
                              
                              
                              
                              
                              
                              // Next value of the CSR.
                              $csr_cycle_masked_wr_value[31:0] =
                                   $csr_wr_value[31:0] & {32{1'b1}};
                              <<1$csr_cycle[31:0] =
                                   $reset ? 32'b0 :
                                   ! $commit
                                          ? $upd_csr_cycle :
                                   $is_csr_write && $is_csr_cycle
                                          ? $csr_cycle_masked_wr_value | ($upd_csr_cycle & ~ {32{1'b1}}) :
                                   $is_csr_set   && $is_csr_cycle
                                          ? $upd_csr_cycle |   $csr_cycle_masked_wr_value :
                                   $is_csr_clear && $is_csr_cycle
                                          ? $upd_csr_cycle & ~ $csr_cycle_masked_wr_value :
                                   // No CSR instruction update, only h/w side-effects.
                                            $upd_csr_cycle;
                              
                        \end_source
                        
                        \source ./warpv.tlv 1352   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+riscv_csr(m4_echo(['m4_csr_']csr['_args']))
                           //--------------
                           // CSR CYCLEH
                           //--------------
                           @0
                              $is_csr_cycleh = $raw[31:20] == 12'hC80;
                           @0
                              // CSR update. Counting on synthesis to optimize each bit, based on {32{1'b1}}.
                              // Conditionally include code for h/w and s/w write based on side_effect param (0 - s/w, 1 - s/w + h/w, RO - neither).
                              
                              
                              
                              // hw_wr_mask conditioned by hw_wr.
                              $csr_cycleh_hw_wr_en_mask[31:0] = {32{$csr_cycleh_hw_wr}} & $csr_cycleh_hw_wr_mask;
                              // The CSR value, updated by side-effect writes.
                              $upd_csr_cycleh[31:0] =
                                   ($csr_cycleh_hw_wr_en_mask & $csr_cycleh_hw_wr_value) | (~ $csr_cycleh_hw_wr_en_mask & $csr_cycleh);
                              
                              
                              
                              
                              
                              
                              
                              // Next value of the CSR.
                              $csr_cycleh_masked_wr_value[31:0] =
                                   $csr_wr_value[31:0] & {32{1'b1}};
                              <<1$csr_cycleh[31:0] =
                                   $reset ? 32'b0 :
                                   ! $commit
                                          ? $upd_csr_cycleh :
                                   $is_csr_write && $is_csr_cycleh
                                          ? $csr_cycleh_masked_wr_value | ($upd_csr_cycleh & ~ {32{1'b1}}) :
                                   $is_csr_set   && $is_csr_cycleh
                                          ? $upd_csr_cycleh |   $csr_cycleh_masked_wr_value :
                                   $is_csr_clear && $is_csr_cycleh
                                          ? $upd_csr_cycleh & ~ $csr_cycleh_masked_wr_value :
                                   // No CSR instruction update, only h/w side-effects.
                                            $upd_csr_cycleh;
                              
                        \end_source
                        
                        \source ./warpv.tlv 1352   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+riscv_csr(m4_echo(['m4_csr_']csr['_args']))
                           //--------------
                           // CSR TIME
                           //--------------
                           @0
                              $is_csr_time = $raw[31:20] == 12'hC01;
                           @0
                              // CSR update. Counting on synthesis to optimize each bit, based on {32{1'b1}}.
                              // Conditionally include code for h/w and s/w write based on side_effect param (0 - s/w, 1 - s/w + h/w, RO - neither).
                              
                              
                              
                              // hw_wr_mask conditioned by hw_wr.
                              $csr_time_hw_wr_en_mask[31:0] = {32{$csr_time_hw_wr}} & $csr_time_hw_wr_mask;
                              // The CSR value, updated by side-effect writes.
                              $upd_csr_time[31:0] =
                                   ($csr_time_hw_wr_en_mask & $csr_time_hw_wr_value) | (~ $csr_time_hw_wr_en_mask & $csr_time);
                              
                              
                              
                              
                              
                              
                              
                              // Next value of the CSR.
                              $csr_time_masked_wr_value[31:0] =
                                   $csr_wr_value[31:0] & {32{1'b1}};
                              <<1$csr_time[31:0] =
                                   $reset ? 32'b0 :
                                   ! $commit
                                          ? $upd_csr_time :
                                   $is_csr_write && $is_csr_time
                                          ? $csr_time_masked_wr_value | ($upd_csr_time & ~ {32{1'b1}}) :
                                   $is_csr_set   && $is_csr_time
                                          ? $upd_csr_time |   $csr_time_masked_wr_value :
                                   $is_csr_clear && $is_csr_time
                                          ? $upd_csr_time & ~ $csr_time_masked_wr_value :
                                   // No CSR instruction update, only h/w side-effects.
                                            $upd_csr_time;
                              
                        \end_source
                        
                        \source ./warpv.tlv 1352   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+riscv_csr(m4_echo(['m4_csr_']csr['_args']))
                           //--------------
                           // CSR TIMEH
                           //--------------
                           @0
                              $is_csr_timeh = $raw[31:20] == 12'hC81;
                           @0
                              // CSR update. Counting on synthesis to optimize each bit, based on {32{1'b1}}.
                              // Conditionally include code for h/w and s/w write based on side_effect param (0 - s/w, 1 - s/w + h/w, RO - neither).
                              
                              
                              
                              // hw_wr_mask conditioned by hw_wr.
                              $csr_timeh_hw_wr_en_mask[31:0] = {32{$csr_timeh_hw_wr}} & $csr_timeh_hw_wr_mask;
                              // The CSR value, updated by side-effect writes.
                              $upd_csr_timeh[31:0] =
                                   ($csr_timeh_hw_wr_en_mask & $csr_timeh_hw_wr_value) | (~ $csr_timeh_hw_wr_en_mask & $csr_timeh);
                              
                              
                              
                              
                              
                              
                              
                              // Next value of the CSR.
                              $csr_timeh_masked_wr_value[31:0] =
                                   $csr_wr_value[31:0] & {32{1'b1}};
                              <<1$csr_timeh[31:0] =
                                   $reset ? 32'b0 :
                                   ! $commit
                                          ? $upd_csr_timeh :
                                   $is_csr_write && $is_csr_timeh
                                          ? $csr_timeh_masked_wr_value | ($upd_csr_timeh & ~ {32{1'b1}}) :
                                   $is_csr_set   && $is_csr_timeh
                                          ? $upd_csr_timeh |   $csr_timeh_masked_wr_value :
                                   $is_csr_clear && $is_csr_timeh
                                          ? $upd_csr_timeh & ~ $csr_timeh_masked_wr_value :
                                   // No CSR instruction update, only h/w side-effects.
                                            $upd_csr_timeh;
                              
                        \end_source
                        
                        \source ./warpv.tlv 1352   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+riscv_csr(m4_echo(['m4_csr_']csr['_args']))
                           //--------------
                           // CSR INSTRET
                           //--------------
                           @0
                              $is_csr_instret = $raw[31:20] == 12'hC02;
                           @0
                              // CSR update. Counting on synthesis to optimize each bit, based on {32{1'b1}}.
                              // Conditionally include code for h/w and s/w write based on side_effect param (0 - s/w, 1 - s/w + h/w, RO - neither).
                              
                              
                              
                              // hw_wr_mask conditioned by hw_wr.
                              $csr_instret_hw_wr_en_mask[31:0] = {32{$csr_instret_hw_wr}} & $csr_instret_hw_wr_mask;
                              // The CSR value, updated by side-effect writes.
                              $upd_csr_instret[31:0] =
                                   ($csr_instret_hw_wr_en_mask & $csr_instret_hw_wr_value) | (~ $csr_instret_hw_wr_en_mask & $csr_instret);
                              
                              
                              
                              
                              
                              
                              
                              // Next value of the CSR.
                              $csr_instret_masked_wr_value[31:0] =
                                   $csr_wr_value[31:0] & {32{1'b1}};
                              <<1$csr_instret[31:0] =
                                   $reset ? 32'b0 :
                                   ! $commit
                                          ? $upd_csr_instret :
                                   $is_csr_write && $is_csr_instret
                                          ? $csr_instret_masked_wr_value | ($upd_csr_instret & ~ {32{1'b1}}) :
                                   $is_csr_set   && $is_csr_instret
                                          ? $upd_csr_instret |   $csr_instret_masked_wr_value :
                                   $is_csr_clear && $is_csr_instret
                                          ? $upd_csr_instret & ~ $csr_instret_masked_wr_value :
                                   // No CSR instruction update, only h/w side-effects.
                                            $upd_csr_instret;
                              
                        \end_source
                        
                        \source ./warpv.tlv 1352   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 13 as: m4+riscv_csr(m4_echo(['m4_csr_']csr['_args']))
                           //--------------
                           // CSR INSTRETH
                           //--------------
                           @0
                              $is_csr_instreth = $raw[31:20] == 12'hC82;
                           @0
                              // CSR update. Counting on synthesis to optimize each bit, based on {32{1'b1}}.
                              // Conditionally include code for h/w and s/w write based on side_effect param (0 - s/w, 1 - s/w + h/w, RO - neither).
                              
                              
                              
                              // hw_wr_mask conditioned by hw_wr.
                              $csr_instreth_hw_wr_en_mask[31:0] = {32{$csr_instreth_hw_wr}} & $csr_instreth_hw_wr_mask;
                              // The CSR value, updated by side-effect writes.
                              $upd_csr_instreth[31:0] =
                                   ($csr_instreth_hw_wr_en_mask & $csr_instreth_hw_wr_value) | (~ $csr_instreth_hw_wr_en_mask & $csr_instreth);
                              
                              
                              
                              
                              
                              
                              
                              // Next value of the CSR.
                              $csr_instreth_masked_wr_value[31:0] =
                                   $csr_wr_value[31:0] & {32{1'b1}};
                              <<1$csr_instreth[31:0] =
                                   $reset ? 32'b0 :
                                   ! $commit
                                          ? $upd_csr_instreth :
                                   $is_csr_write && $is_csr_instreth
                                          ? $csr_instreth_masked_wr_value | ($upd_csr_instreth & ~ {32{1'b1}}) :
                                   $is_csr_set   && $is_csr_instreth
                                          ? $upd_csr_instreth |   $csr_instreth_masked_wr_value :
                                   $is_csr_clear && $is_csr_instreth
                                          ? $upd_csr_instreth & ~ $csr_instreth_masked_wr_value :
                                   // No CSR instruction update, only h/w side-effects.
                                            $upd_csr_instreth;
                              
                        \end_source
                        
                     \end_source
                     @0
                        \source ./warpv.tlv 1399   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 1896 as: m4+riscv_csr_logic()
                           
                           // CSR write value for CSR write instructions.
                           $csr_wr_value[31:0] = $raw_funct3[2] ? {27'b0, $raw_rs1} : /src[1]$reg_value;
                           
                        
                           // Counter CSR
                           //
                           
                           // Count within time unit. This is not reset on writes to time CSR, so time CSR is only accurate to time unit.
                           $RemainingCyclesWithinTimeUnit[30-1:0] <=
                                ($reset || $time_unit_expires) ?
                                       30'd999999999 :
                                       $RemainingCyclesWithinTimeUnit - 30'b1;
                           $time_unit_expires = !( | $RemainingCyclesWithinTimeUnit);  // reaches zero
                           
                           $full_csr_cycle_hw_wr_value[63:0]   = {$csr_cycleh,   $csr_cycle  } + 64'b1;
                           $full_csr_time_hw_wr_value[63:0]    = {$csr_timeh,    $csr_time   } + 64'b1;
                           $full_csr_instret_hw_wr_value[63:0] = {$csr_instreth, $csr_instret} + 64'b1;
                           
                           
                           
                           
                           
                           
                           
                           
                           // CSR h/w side-effect write signals.
                           $csr_cycle_hw_wr = 1'b1;
                           $csr_cycle_hw_wr_mask[31:0] = {32{1'b1}};
                           $csr_cycle_hw_wr_value[31:0] = $full_csr_cycle_hw_wr_value[31:0];
                           $csr_cycleh_hw_wr = 1'b1;
                           $csr_cycleh_hw_wr_mask[31:0] = {32{1'b1}};
                           $csr_cycleh_hw_wr_value[31:0] = $full_csr_cycle_hw_wr_value[63:32];
                           $csr_time_hw_wr = $time_unit_expires;
                           $csr_time_hw_wr_mask[31:0] = {32{1'b1}};
                           $csr_time_hw_wr_value[31:0] = $full_csr_time_hw_wr_value[31:0];
                           $csr_timeh_hw_wr = $time_unit_expires;
                           $csr_timeh_hw_wr_mask[31:0] = {32{1'b1}};
                           $csr_timeh_hw_wr_value[31:0] = $full_csr_time_hw_wr_value[63:32];
                           $csr_instret_hw_wr = $commit;
                           $csr_instret_hw_wr_mask[31:0] = {32{1'b1}};
                           $csr_instret_hw_wr_value[31:0] = $full_csr_instret_hw_wr_value[31:0];
                           $csr_instreth_hw_wr = $commit;
                           $csr_instreth_hw_wr_mask[31:0] = {32{1'b1}};
                           $csr_instreth_hw_wr_value[31:0] = $full_csr_instret_hw_wr_value[63:32];
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           // For multicore CSRs:
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                           
                        \end_source
                        
                        // Memory inputs.
                        ?$valid_exe
                           $unnatural_addr_trap = ($ld_st_word && ($addr[1:0] != 2'b00)) || ($ld_st_half && $addr[0]);
                        $ld_st_cond = $ld_st && $valid_exe;
                        ?$ld_st_cond
                           $addr[31:0] = /src[1]$reg_value + ($ld ? $raw_i_imm : $raw_s_imm);
                           
                           // Hardware assumes natural alignment. Otherwise, trap, and handle in s/w (though no s/w provided).
                        $st_cond = $st && $valid_exe;
                        ?$st_cond
                           // Provide a value to store, naturally-aligned to memory, that will work regardless of the lower $addr bits.
                           $st_reg_value[31:0] = 
                                                                          /src[2]$reg_value;
                           $st_value[31:0] =
                                $ld_st_word ? $st_reg_value :            // word
                                $ld_st_half ? {2{$st_reg_value[15:0]}} : // half
                                              {4{$st_reg_value[7:0]}};   // byte
                           $st_mask[3:0] =
                                $ld_st_word ? 4'hf :                     // word
                                $ld_st_half ? ($addr[1] ? 4'hc : 4'h3) : // half
                                              (4'h1 << $addr[1:0]);      // byte
                  
                        // Swizzle bytes for load result (assuming natural alignment) and pass to /orig_load_inst scope
                        ?$second_issue_ld
                           /orig_load_inst
                              $spec_ld_cond = $spec_ld;
                              ?$spec_ld_cond
                                 // (Verilator didn't like indexing $ld_value by signal math, so we do these the long way.)
                                 $sign_bit =
                                    ! $raw_funct3[2] && (  // Signed && ...
                                       $ld_st_word ? $ld_value[31] :
                                       $ld_st_half ? ($addr[1] ? $ld_value[31] : $ld_value[15]) :
                                                     (($addr[1:0] == 2'b00) ? $ld_value[7] :
                                                      ($addr[1:0] == 2'b01) ? $ld_value[15] :
                                                      ($addr[1:0] == 2'b10) ? $ld_value[23] :
                                                                              $ld_value[31]
                                                     )
                                    );
                                 {$ld_rslt[31:0], $ld_mask[3:0]} =
                                      $ld_st_word ? {$ld_value, 4'b1111} :
                                      $ld_st_half ? {{16{$sign_bit}}, $addr[1] ? {$ld_value[31:16], 4'b1100} :
                                                                                 {$ld_value[15:0] , 4'b0011}} :
                                                    {{24{$sign_bit}}, ($addr[1:0] == 2'b00) ? {$ld_value[7:0]  , 4'b0001} :
                                                                      ($addr[1:0] == 2'b01) ? {$ld_value[15:8] , 4'b0010} :
                                                                      ($addr[1:0] == 2'b10) ? {$ld_value[23:16], 4'b0100} :
                                                                                              {$ld_value[31:24], 4'b1000}};
                                 `BOGUS_USE($ld_mask) // It's only for formal verification.
                        // ISA-specific trap conditions:
                        // I can't see in the spec which of these is to commit results. I've made choices that make riscv-formal happy.
                        $non_aborting_isa_trap = ($branch && $taken && $misaligned_pc) ||
                                                 ($jump && $misaligned_jump_target) ||
                                                 ($indirect_jump && $misaligned_indirect_jump_target);
                        $aborting_isa_trap =     ($ld_st && $unnatural_addr_trap) ||
                                                 $csr_trap;
                        
                     @0
                        // Mux the correct result.
                        \source ./warpv.tlv 1481   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 1955 as: m4+riscv_rslt_mux_expr()
                           // in case of second issue, the results are pulled out of the /orig_inst or /load_inst scope. 
                           // no alignment is needed as the rslt mux and the long latency results both appear in the same pipestage.
                        
                           // in the case of second isssue for multiplication with ALTOPS enabled (or running formal checks for M extension), 
                           // the module gives out the result in two cycles but we explicitly flop the $mul_rslt 
                           // (by alignment with 3+NON_PIPELINED_BUBBLES to augment the 5 cycle behavior of the mul operation
                        
                           $rslt[31:0] =
                                 $second_issue_ld ? /orig_load_inst$ld_rslt : 
                                 ($second_issue_div_mul && |fetch/instr>>3$stall_cnt_upper_div) ? |fetch/instr$divblock_rslt : 
                                 ($second_issue_div_mul && |fetch/instr>>3$stall_cnt_upper_mul) ? |fetch/instr$mulblock_rslt :
                                  
                                 
                                 
                                 32'b0 |
                               ({32{$is_lui_instr}} & $lui_rslt) |
                               ({32{$is_auipc_instr}} & $auipc_rslt) |
                               ({32{$is_jal_instr}} & $jal_rslt) |
                               ({32{$is_jalr_instr}} & $jalr_rslt) |
                               ({32{$is_lb_instr}} & $lb_rslt) |
                               ({32{$is_lh_instr}} & $lh_rslt) |
                               ({32{$is_lw_instr}} & $lw_rslt) |
                               ({32{$is_lbu_instr}} & $lbu_rslt) |
                               ({32{$is_lhu_instr}} & $lhu_rslt) |
                               ({32{$is_addi_instr}} & $addi_rslt) |
                               ({32{$is_slti_instr}} & $slti_rslt) |
                               ({32{$is_sltiu_instr}} & $sltiu_rslt) |
                               ({32{$is_xori_instr}} & $xori_rslt) |
                               ({32{$is_ori_instr}} & $ori_rslt) |
                               ({32{$is_andi_instr}} & $andi_rslt) |
                               ({32{$is_slli_instr}} & $slli_rslt) |
                               ({32{$is_srli_instr}} & $srli_rslt) |
                               ({32{$is_srai_instr}} & $srai_rslt) |
                               ({32{$is_add_instr}} & $add_rslt) |
                               ({32{$is_sub_instr}} & $sub_rslt) |
                               ({32{$is_sll_instr}} & $sll_rslt) |
                               ({32{$is_slt_instr}} & $slt_rslt) |
                               ({32{$is_sltu_instr}} & $sltu_rslt) |
                               ({32{$is_xor_instr}} & $xor_rslt) |
                               ({32{$is_srl_instr}} & $srl_rslt) |
                               ({32{$is_sra_instr}} & $sra_rslt) |
                               ({32{$is_or_instr}} & $or_rslt) |
                               ({32{$is_and_instr}} & $and_rslt) |
                               ({32{$is_csrrw_instr}} & $csrrw_rslt) |
                               ({32{$is_csrrs_instr}} & $csrrs_rslt) |
                               ({32{$is_csrrc_instr}} & $csrrc_rslt) |
                               ({32{$is_csrrwi_instr}} & $csrrwi_rslt) |
                               ({32{$is_csrrsi_instr}} & $csrrsi_rslt) |
                               ({32{$is_csrrci_instr}} & $csrrci_rslt) |
                               ({32{$is_mul_instr}} & $mul_rslt) |
                               ({32{$is_mulh_instr}} & $mulh_rslt) |
                               ({32{$is_mulhsu_instr}} & $mulhsu_rslt) |
                               ({32{$is_mulhu_instr}} & $mulhu_rslt) |
                               ({32{$is_div_instr}} & $div_rslt) |
                               ({32{$is_divu_instr}} & $divu_rslt) |
                               ({32{$is_rem_instr}} & $rem_rslt) |
                               ({32{$is_remu_instr}} & $remu_rslt);
                           
                        \end_source
                     
                  \end_source
               \end_source
               
               @0
                  $pred_taken_branch = $pred_taken && $branch;
               @0
      
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
                  
                  // For the retiming experiments, $commit is determined too late, and it is inconvenient to make the $GoodPathMask
                  // logic retimable. Let's drive it to 1'b1 for now, and give synthesis the benefit of the doubt.
                  $commit = 1'b1 && ! $abort;
                  
                  
                  // Conditions that commit results.
                  $valid_dest_reg_valid = ($dest_reg_valid && $commit) || ($second_issue  );
      
                  
                  
                  
                  $valid_ld = $ld && $commit;
                  $valid_st = $st && $commit;
      
         \source ./warpv.tlv 2464   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 3158 as: m4+fixed_latency_fake_memory(/top, 0)
            // This macro assumes little-endian.
            
            |fetch
               /instr
                  // ====
                  // Load
                  // ====
                  @0
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
                  @0
                     $ANY = /top|fetch/instr>>0$ANY;
                     /src[2:1]
                        $ANY = /top|fetch/instr/src>>0$ANY;
         \end_source
         |fetch
            /instr
               @0
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
                   
                  
                  
                  
                  
                  
                     
                        
                           
                     
                  
                  
                  
                     
                    
                  
                  
               @0
                  `BOGUS_USE(/orig_inst/src[2]$dummy) // To pull $dummy through $ANY expressions, avoiding empty expressions.
      \end_source
      
      
      
   \end_source
   \source ./warpv.tlv 3196   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 14 as: m4+warpv_makerchip_cnt10_tb()
      |fetch
         /instr
            @0
               // Assert these to end simulation (before Makerchip cycle limit).
               $ReachedEnd <= $reset ? 1'b0 : $ReachedEnd || $Pc == {30{1'b1}};
               $Reg4Became45 <= $reset ? 1'b0 : $Reg4Became45 || ($ReachedEnd && /regs[4]$value == 32'd45);
               $passed = ! $reset && $ReachedEnd && $Reg4Became45;
               $failed = ! $reset && (*cyc_cnt > 200 || (*cyc_cnt > 5 && $commit && $illegal));
   \end_source
   \source ./warpv.tlv 4013   // Instantiated from warp-v_risc-v_4-stage_retime.tlv, 15 as: m4+makerchip_pass_fail()
      |done
         @0
            // Assert these to end simulation (before Makerchip cycle limit).
            *passed = & /top|fetch/instr>>0$passed;
            *failed = | /top|fetch/instr>>0$failed;
   \end_source
\SV
   endmodule
