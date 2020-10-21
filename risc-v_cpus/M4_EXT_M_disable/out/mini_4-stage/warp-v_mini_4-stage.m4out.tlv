\TLV_version [\source warp-v_mini_4-stage.tlv] 1d --noline: tl-x.org

\source warp-v_mini_4-stage.tlv 5
\SV
   // Include WARP-V.
   // Included URL: "./warp-v.tlv"
\SV
module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
\source warp-v_mini_4-stage.tlv 9
\TLV
   \source ./warpv.tlv 3556   // Instantiated from warp-v_mini_4-stage.tlv, 11 as: m4+warpv()
      // =================
      //
      //    THE MODEL
      //
      // =================
      
   
      \source ./warpv.tlv 2814   // Instantiated from warp-v_mini_4-stage.tlv, 3564 as: m4+cpu(/top)
         // Generated logic
         \source <builtin> 1   // Instantiated from warp-v_mini_4-stage.tlv, 2816 as: m4+indirect(M4_isa['_gen'])
            \source ./warpv.tlv 1021   // Instantiated from built-in definition.
               // No M4-generated code for mini.
            \end_source
         \end_source
      
         // Instruction memory and fetch of $raw.
         \source <builtin> 1   // Instantiated from warp-v_mini_4-stage.tlv, 2819 as: m4+indirect(M4_IMEM_MACRO_NAME, M4_PROG_NAME)
            \source ./warpv.tlv 1012   // Instantiated from built-in definition.
               \source <builtin> 1   // Instantiated from warp-v_mini_4-stage.tlv, 1013 as: m4+indirect(['mini_']cnt10['_prog'])
                  \source ./warpv.tlv 971   // Instantiated from built-in definition.
                     \SV_plus
                        
                        
                        // The program in an instruction memory.
                        logic [39:0] instrs [0:13-1];
                        
                        // /=====================\
                        // | Count to 10 Program |
                        // \=====================/
                        //
                        // (The program I wrote in the language I created in the CPU I wrote in a language I created.)
                        
                        // Add 1,2,3,...,9 (in that order).
                        // Store incremental results in memory locations 1..9. (1, 3, 6, 10, ..., 45)
                        //
                        // Regs:
                        // b: cnt
                        // c: nine
                        // d: out
                        // e: tmp
                        // f: offset
                        // g: store addr
                        
                        assign instrs = '{
                           "g=0~0", //     store_addr = 0
                           "b=0~1", //     cnt = 1
                           "c=1~1", //     nine = 9
                           "d=0~0", //     out = 0
                           "f=0-6", //     offset = -6
                           "d=d+b", //  -> out += cnt
                           "b=b+1", //     cnt ++
                           "g=g+1", //     store_addr++
                           
                           "0=d;g",  //    store out at store_addr, 
                           "e=c-b", //     tmp = nine - cnt
                           "p=f?e", //     branch back if tmp >= 0
                           "e=0)c", //     load the final value into tmp
                           "P=0-1"  //     TERMINATE by jumping to -1
                        }; 
                  \end_source
               \end_source
               \source ./warpv.tlv 3641   // Instantiated from warp-v_mini_4-stage.tlv, 1014 as: m4+instrs_for_viz()
                  
                  
                     
                        
                        
                        
                        
                        
                           
                              
                              
                              
                        
                           
                        
                        
                           
                           
                           
                           
                           
                           
                  
               \end_source
               |fetch
                  /instr
                     @0
                        ?$fetch
                           $raw[39:0] = *instrs\[$Pc[3:0]\];
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
                       & ((>>0$second_issue && !(1'b0) && $GoodPathMask[0]) ? {{3{1'b1}}, {1{1'b0}}} : {4{1'b1}}) & ((>>0$NoFetch && !(1'b0 || >>0$second_issue) && $GoodPathMask[0]) ? {{3{1'b1}}, {1{1'b0}}} : {4{1'b1}}) & ((>>2$replay && !(1'b0 || >>2$second_issue || >>2$NoFetch) && $GoodPathMask[2]) ? {{1{1'b1}}, {3{1'b0}}} : {4{1'b1}}) & ((>>2$jump && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {{2{1'b1}}, {2{1'b0}}} : {4{1'b1}}) & ((>>2$mispred_branch && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {{2{1'b1}}, {2{1'b0}}} : {4{1'b1}}) & ((>>3$non_pipelined && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {{1{1'b1}}, {3{1'b0}}} : {4{1'b1}}) & ((>>3$aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {{0{1'b1}}, {4{1'b0}}} : {4{1'b1}}) & ((>>3$non_aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay || >>3$aborting_trap) && $GoodPathMask[3]) ? {{1{1'b1}}, {3{1'b0}}} : {4{1'b1}}),
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
                  $pc_inc[9:0] = $Pc + 10'b1;
                  // Current parsing does not allow concatenated state on left-hand-side, so, first, a non-state expression.
                  {$next_pc[9:0], $next_no_fetch} =
                     $reset ? {10'b0, 1'b0} :
                     // ? : terms for each condition (order does matter)
                     (>>3$non_aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay || >>3$aborting_trap) && $GoodPathMask[3]) ? {>>3$trap_target, 1'b0} : (>>3$aborting_trap && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {>>3$trap_target,1'b0} : (>>3$non_pipelined && !(1'b0 || >>3$second_issue || >>3$NoFetch || >>3$replay) && $GoodPathMask[3]) ? {>>3$Pc,1'b1} : (>>2$mispred_branch && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {>>2$branch_redir_pc,1'b0} : (>>2$jump && !(1'b0 || >>2$second_issue || >>2$NoFetch || >>2$replay) && $GoodPathMask[2]) ? {>>2$jump_target,1'b0} : (>>2$replay && !(1'b0 || >>2$second_issue || >>2$NoFetch) && $GoodPathMask[2]) ? {>>2$Pc,1'b0} : (>>0$NoFetch && !(1'b0 || >>0$second_issue) && $GoodPathMask[0]) ? {>>0$Pc,1'b1} : (>>0$second_issue && !(1'b0) && $GoodPathMask[0]) ? {>>0$second_issue_ld ? $Pc : $pc_inc,1'b0} :         
                                ({$pc_inc, 1'b0});
                  // Then as state.
                  $Pc[9:0] <= $next_pc;
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
                  \source <builtin> 1   // Instantiated from warp-v_mini_4-stage.tlv, 3013 as: m4+indirect(M4_isa['_decode'])
                     \source ./warpv.tlv 1035   // Instantiated from built-in definition.
                        // Characters
                        $dest_char[7:0] = $raw[39:32];
                        /src[2:1]
                           $char[7:0] = (#src == 1) ? /instr$raw[23:16] : /instr$raw[7:0];
                        $op_char[7:0] = $raw[15:8];
                     
                        // Dest
                        $dest_is_reg = ($dest_char >= "a" && $dest_char <= "h") || $second_issue;
                        $dest_reg_valid = $dest_is_reg;
                        $fetch_instr_dest_reg[7:0] = $dest_char - "a";
                        $dest_reg[2:0] = $second_issue ? /orig_inst$dest_reg : $fetch_instr_dest_reg[2:0];
                        $jump = $dest_char == "P";
                        $branch = $dest_char == "p";
                        $no_dest = $dest_char == "0";
                        $write_pc = $jump || $branch;
                        $div_mul = 1'b0;
                        $dest_valid = $write_pc || $dest_is_reg;
                        $illegal_dest = !($dest_is_reg || 
                                          (($branch || $jump || $no_dest) && ! $ld));  // Load must have reg dest.
                     
                        /src[*]
                           // Src1
                           $is_reg = $char >= "a" && $char <= "h";
                           $reg_tmp[7:0] = $char - "a";
                           $reg[2:0] = $reg_tmp[2:0];
                           $is_imm = $char >= "0" && $char < "8";
                           $imm_tmp[7:0] = $char - "0";
                           $imm_value[11:0] = {9'b0, $imm_tmp[2:0]};
                           $illegal = !($is_reg || $is_imm);
                     
                        // Opcode:
                        /op
                           $char[7:0] = /instr$op_char;
                           // Arithmetic
                           $add = $char == "+";
                           $sub = $char == "-";
                           $mul = $char == "*";
                           $div = $char == "/";
                           // Compare and bool (w/ 1 bit rslt)
                           $eq = $char == "=";
                           $ne = $char == "!";
                           $lt = $char == "<";
                           $gt = $char == ">";
                           $le = $char == "[";
                           $ge = $char == "]";
                           $and = $char == "&";
                           $or = $char == "|";
                           // Wide Immediate
                           $wide_imm = $char == "~";
                           $combine = $char == ",";
                           // Conditional
                           $conditional = $char == "?";
                           // Memory
                           $ld = $char == ")";
                           $st = $char == "(";
                           // Opcode classes:
                           $arith = $add || $sub || $mul || $div;
                           $compare = $eq || $ne || $lt || $gt || $le || $ge;
                           $bitwise = $and || $or;
                           $full = $arith || $bitwise || $wide_imm || $combine || $conditional;
                           //$op3 = $compare || $full;
                           $mem = $ld || $st;
                           $illegal = !($compare || $full || $mem);
                        $op_compare = /op$compare;
                        $op_full = /op$full;
                        $ld = /op$ld;
                        $spec_ld = $ld;
                        $st = /op$st;
                        $illegal = $illegal_dest || (| /src[*]$illegal) || /op$illegal;
                     
                        // Branch instructions with a condition (that might be worth predicting).
                        //$branch_predict = $branch && /op$conditional;
                        $conditional_branch = $branch;  // All branches (any instruction with "p" dest) is conditional (where condition is that result != 0).
                     \end_source
                  \end_source
               \source <builtin> 1   // Instantiated from warp-v_mini_4-stage.tlv, 3014 as: m4+indirect(['branch_pred_']M4_BRANCH_PRED)
                  \source ./warpv.tlv 2528   // Instantiated from built-in definition.
                     @1
                        $pred_taken = 1'b0;
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
                  /regs[7:0]
                  /src[2:1]
                     $is_reg_condition = $is_reg && /instr$valid_decode;  // Note: $is_reg can be set for RISC-V sr0.
                     ?$is_reg_condition
                        {$reg_value[11:0], $pending} =
                           
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
               \source <builtin> 1   // Instantiated from warp-v_mini_4-stage.tlv, 3099 as: m4+indirect(M4_isa['_exe'], @M4_EXECUTE_STAGE, @M4_RESULT_STAGE)
                  \source ./warpv.tlv 1113   // Instantiated from built-in definition.
                     @1
                        /src[*]
                           $valid = /instr$valid_decode && ($is_reg || $is_imm);
                           ?$valid
                              $value[11:0] = $is_reg ? $reg_value :
                                                                $imm_value;
                     // Note that some result muxing is performed in @2, and the rest in @2.
                     @2
                        ?$op_compare
                           $compare_rslt =
                              /op$eq ? /src[1]$value == /src[2]$value :
                              /op$ne ? /src[1]$value != /src[2]$value :
                              /op$lt ? /src[1]$value < /src[2]$value :
                              /op$gt ? /src[1]$value > /src[2]$value :
                              /op$le ? /src[1]$value <= /src[2]$value :
                              /op$ge ? /src[1]$value >= /src[2]$value :
                                       1'b0;
                        ?$op_full
                           $op_full_rslt[11:0] =
                              /op$add ? /src[1]$value + /src[2]$value :
                              /op$sub ? /src[1]$value - /src[2]$value :
                              /op$mul ? /src[1]$value * /src[2]$value :
                              /op$div ? /src[1]$value * /src[2]$value :
                              /op$and ? /src[1]$value & /src[2]$value :
                              /op$or ? /src[1]$value | /src[2]$value :
                              /op$wide_imm ? {6'b0, /src[1]$value[2:0], /src[2]$value[2:0]} :
                              /op$combine ? {/src[1]$value[5:0], /src[2]$value[5:0]} :
                              /op$conditional ? (/src[2]$value[11] ? 12'b0 : /src[1]$value) :
                                                12'b0;
                        ?$valid_st
                           $st_value[11:0] = /src[1]$value;
                  
                        $valid_ld_st = $valid_ld || $valid_st;
                        ?$valid_ld_st
                           $addr[11:0] = $ld ? (/src[1]$value + /src[2]$value) : /src[2]$value;
                        // Always predict taken; mispredict if jump or unconditioned branch or
                        //   conditioned branch with positive condition.
                        ?$branch
                           $taken = $rslt != 12'b0;
                        $st_mask[0:0] = 1'b1;
                        $non_aborting_isa_trap = 1'b0;
                        $aborting_isa_trap = 1'b0;
                     @2
                        ?$dest_valid
                           $rslt[11:0] =
                              $second_issue ? /orig_inst$ld_value :  // (Only loads are issued twice.)
                              $st ? /src[1]$value :
                              $op_full ? $op_full_rslt :
                              $op_compare ? {12{$compare_rslt}} :
                                    12'b0;
                           
                        // Jump (Dest = "P") and Branch (Dest = "p") Targets.
                        ?$jump
                           $jump_target[9:0] = $rslt[9:0];
                     @2
                        ?$branch
                           $branch_target[9:0] = $Pc + 10'b1 + $rslt[9:0];
                  \end_source
               \end_source
               
               @1
                  
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
                     $branch_redir_pc[9:0] =
                        // If fallthrough predictor, branch mispred always redirects taken, otherwise PC+1 for not-taken.
                        
                        $branch_target;
      
                  $trap_target[9:0] = $replay_trap ? $Pc : {10{1'b1}};  // TODO: What should this be? Using ones to terminate test for now.
                  
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
      
         \source ./warpv.tlv 2464   // Instantiated from warp-v_mini_4-stage.tlv, 3158 as: m4+fixed_latency_fake_memory(/top, 0)
            // This macro assumes little-endian.
            
            |fetch
               /instr
                  // ====
                  // Load
                  // ====
                  @3
                     /bank[1-1:0]
                        $ANY = /instr$ANY; // Find signal from outside of /bank.
                        /mem[31:0]
                        ?$spec_ld
                           $ld_value[(12 / 1) - 1 : 0] = /mem[$addr[4 + 0 : 0]]$Value;
                  
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
                                 /mem[$addr[4 + 0 : 0]]<<0$$Value[(12 / 1) - 1 : 0] <= $st_value[(#bank + 1) * (12 / 1) - 1: #bank * (12 / 1)];
                           end
                     // Combine $ld_value per bank, assuming little-endian.
                     //$ld_value[M4_WORD_RANGE] = /bank[*]$ld_value;
                     // Unfortunately formal verification tools can't handle multiple packed dimensions produced by the expression above, so we
                     // build the concatination.
                     $ld_value[11:0] = {/bank[0]$ld_value};
         
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
                           /regs[$dest_reg]<<0$$value[11:0] <= $rslt;
                     end
                  
                  // Write $pending along with $value, but coded differently because it must be reset.
                  /regs[*]
                     <<1$pending = ! /instr$reset && (((#regs == /instr$dest_reg) && /instr$valid_dest_reg_valid) ? /instr$reg_wr_pending : $pending);
                   
                  
                  
                  
                  
                  
                     
                        
                           
                     
                  
                  
                  
                     
                    
                  
                  
               @3
                  `BOGUS_USE(/orig_inst/src[2]$dummy) // To pull $dummy through $ANY expressions, avoiding empty expressions.
      \end_source
      
      
      
   \end_source
\SV
   endmodule
