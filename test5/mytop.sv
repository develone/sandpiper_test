`line 2 "top.tlv" 0 //_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV
// -----------------------------------------------------------------------------
// Copyright (c) 2017, Redwood EDA
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Redwood EDA nor the names of its contributors
//       may be used to endorse or promote products derived from this software
//       without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// -----------------------------------------------------------------------------


// A dirt-simple CPU for educational purposes.



// The ISA:

// What's interesting about this ISA?
//   o It's super small.
//   o It's easy to play with and learn from.
//   o Instructions are short, kind-of-readable strings, so no assembler is needed.
//     They would map directly to a denser (~17-bit) encoding if desired.
//   o The only instruction formats are op, load, and store.
//   o Branch/Jump: There is no special format for control-flow instructions. Any
//     instruction can write the PC (relative or absolute). A conditional branch
//     will typically utilize a condition operation that provides a (relative) branch
//     target or zero.
//
// Branch prediction ISA considerations:
//   Typical branch predication techniques can be utilized for conditional branches
//   with an immediate offset (eg p=4?c), though the immediate is VERY limited
//   (small, positive). The immediate could also be used to predicate off subsequent
//   instructions. By convention, b is a branch target register, so it is
//   reasonable to predict the target of "p=b?c", using a stale side copy of b.
//
// ISA Machine Arch:
//   o Single stage "pipeline".
//   o 8 registers.
//   o A word is 12 bits wide.
//   o Operators operate on and produce words as signed or unsigned values and
//     booleans (all-zero/one)
//
//
// Instruction Set:
//
// Instructions are 5-character strings: "D=1o2"
//
// =: Appears in every instruction (just for readability).
// D, 2, 1: "a" - "h" for registers;
//          "0" - "7" for immediate constants (sources, or "0" for unused dest);
//          "P" for absolute dest PC (jump);
//          "p" for relative dest PC (branch), PC = PC + 1 + result(signed).
//
// o: operator
//   Op: (D = 1 o 2) (Eg: "c=a+b"):
//     Arithmetic:
//       +, -, *, /: *, / are unsigned.
//     Compare: (D = (1 o 2) ? all-1s : 0)
//       =, !, <, >, [, ]: ] is >=, [ is <=
//          (On booleans these are XNOR, XOR, !1&2, 1&!2, !1|2, 1|!2)
//     Bitwise:
//       &, |: (Can be used on booleans as well as vectors.)
//     (There are no operators for NAND and NOR and unary !.)
//     Concatination:
//       ~: Extended constant (D = {1[2:0], 2[2:0]})
//       ,: Combine (D = {1[5:0], 2[5:0]})
//     Conditional:
//       ?: (D = 2 ? `0 : 1)
//   Load (Eg: "c=a{b"):
//     {: Load (D = [1 + 2] (typically 1 would be an immediate offset)
//   Store (Eg: "0=a}b"):
//     }: Store ([2] = D = 1) (typically D would be "0" (no dest))
//
// A full-width immediate load sequence, to load octal 2017 is:
//   a=2~0
//   b=1~7
//   a=a,b

// A typical local conditional branch sequence is:
//   a=0-6  // offset
//   c=c-1  // decrementing loop counter
//   p=a?c  // branch by a (to PC+1-6) if c is non-negative (MSB==0)



// The CPU

// The code is parameterized, using the M4 macro preprocessor, for adjustable pipeline
// depth.
//
// Overview:
//   o One instruction traverses the single free-flowing CPU pipeline per cycle.
//   o There is no branch or condition or target prediction.
//   o Instructions are in-order, but the uarch supports loads that return their
//     data out of order (though, they don't).
//
// Replays:
//
// The PC is redirected, and inflight instructions are squashed (their results are
// not committed) for:
//   o jumps (go to jump target)
//   o unconditioned and non-negative-conditioned branches (go to branch target)
//   o instructions that consume a pending register (replay instruction immediately)
//     (See "Loads", below.)
//   o loads that write to a pending register (replay instruction immediately)
//     (See "Loads", below.)
//
// Loads:
//
// Load destination registers are marked "pending", and reads of pending
// registers are replayed. (This could again result in a read of the same
// pending register, to repeat until the load returns.) Writes to pending registers
// are also replayed, so there can be at most one oustanding load to any given
// register. This way, out-of-order loads are supported (though loads are implemented
// to have a fixed latency). A returning load reserves a slot at the beginning
// of the pipeline to reserve a register write port. The returning load writes its
// result and clears the destination register's pending flag.
//
// To support L1 and L2 caches, it would be reasonable to delay register write (if
// necessary) to wait for L1 hits (extending the bypass window), and mark "pending"
// for L1 misses.
//
// Bypass:
//
// Register bypass is provided if one instruction's result is not written to the
// register file in time for the next instruction's read. An additional bypass is
// provided for each additional cycle between read and write.



// /============\
// | Parameters |
// \============/

// Adjust the parameters below to define the pipeline depth and staging.

// Pipeline stages for each piece of logic:









// Feedback latencies:

  // +1 or +0. +0 aligns PC_MUX with EXECUTE
  // +0 aligns PC_MUX with BRANCH_TARGET_CALC. Must be either equal to or one greater than JUMP_LATENCY.
   // From load to returning load


// Machine parameters:
  // (Must match program exactly.)



module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
/* verilator lint_on WIDTH */  // Let's be strict about bit widths.
   logic [39:0] instrs [0:13-1];


   // /=============\
   // | The Program |
   // \=============/

   // Add 1,2,3,...,10 (in that order).
   // Store incremental results in memory locations 0..9. (1, 3, 6, 10, ...)
   //
   // Regs:
   // b: cnt
   // c: ten
   // d: out
   // e: tmp
   // f: offset
   // g: store addr

   assign instrs = '{
      "g=0~0", //     store_addr = 0
      "b=0~1", //     cnt = 1
      "c=1~2", //     ten = 10
      "d=0~0", //     out = 0
      "f=0-6", //     offset = -6
      "d=d+b", //  -> out += cnt
      "0=d}g", //     store out at store_addr
      "b=b+1", //     cnt ++
      "g=g+1", //     store_addr++
      "e=c-b", //     tmp = 10 - cnt
      "p=f?e", //  ^- branch back if tmp >= 0
      "h=0{c", //     load the final value
      "P=0-1"  //     TERMINATE by jumping to -1
   };


`include "mytop_gen.sv" //_\TLV
   
   // /=========\
   // | The CPU |
   // \=========/
   
   assign L0_reset_a0 = reset;

   //_|fetch
      //_/instr
         //_@0
            assign FETCH_Instr_reset_a0 = L0_reset_a0;

         //_@0
            //?$fetch  // We'll need this once there are invalid cycles.

            // =====
            // Fetch
            // =====

            assign FETCH_Instr_raw_a0[39:0] = instrs[FETCH_Instr_Pc_a0[3:0]];
            
         // A returning load clobbers the instruction.
         //_@0
            assign FETCH_Instr_returning_ld_a0 = FETCH_Instr_valid_ld_a4;
         //_@1
            assign FETCH_Instr_returning_ld_reg_a1[2:0] = FETCH_Instr_dest_reg_a5;
         
         //_@0
            // =======
            // Next PC
            // =======
            
            //?$fetch_or_reset
            assign FETCH_Instr_Pc_n1[11:0] =
               FETCH_Instr_reset_a0 ? 0 :
               FETCH_Instr_valid_mispred_branch_a3 ? FETCH_Instr_branch_target_a3 :
               FETCH_Instr_valid_jump_a2 ? FETCH_Instr_jump_target_a2 :
               FETCH_Instr_replay_a2 ? FETCH_Instr_Pc_a2 :
               FETCH_Instr_returning_ld_a0 ? FETCH_Instr_Pc_a0[11:0] :  // Returning load, so next PC is the previous next PC (unless there was a branch that wasn't visible yet)
                        FETCH_Instr_Pc_a0 + 12'b1;

         //_@1

            // ======
            // DECODE
            // ======

            // Characters
            assign FETCH_Instr_dest_char_a1[7:0] = FETCH_Instr_raw_a1[39:32];
            for (src = 1; src <= 2; src++) begin : L1_FETCH_Instr_Src logic [7:0] L1_char_a1; //_/src
               assign L1_char_a1[7:0] = (src == 1) ? FETCH_Instr_raw_a1[23:16] : FETCH_Instr_raw_a1[7:0]; end
            assign FETCH_Instr_op_char_a1[7:0] = FETCH_Instr_raw_a1[15:8];

            // Dest
            assign FETCH_Instr_dest_is_reg_a1 = (FETCH_Instr_dest_char_a1 >= "a" && FETCH_Instr_dest_char_a1 <= "h") || FETCH_Instr_returning_ld_a1;
            assign FETCH_Instr_dest_tmp_a1[7:0] = FETCH_Instr_dest_char_a1 - "a";
            assign FETCH_Instr_dest_reg_a1[2:0] = FETCH_Instr_returning_ld_a1 ? FETCH_Instr_returning_ld_reg_a1 : FETCH_Instr_dest_tmp_a1[2:0];
            assign FETCH_Instr_jump_a1 = FETCH_Instr_dest_char_a1 == "P";
            assign FETCH_Instr_branch_a1 = FETCH_Instr_dest_char_a1 == "p";
            assign FETCH_Instr_no_dest_a1 = FETCH_Instr_dest_char_a1 == "0";
            assign FETCH_Instr_write_pc_a1 = FETCH_Instr_jump_a1 || FETCH_Instr_branch_a1;
            assign FETCH_Instr_dest_valid_a1 = FETCH_Instr_write_pc_a1 || FETCH_Instr_dest_is_reg_a1;
            assign FETCH_Instr_illegal_dest_a1 = !(FETCH_Instr_dest_is_reg_a1 || 
                              ((FETCH_Instr_branch_a1 || FETCH_Instr_jump_a1 || FETCH_Instr_no_dest_a1) && ! FETCH_Instr_ld_a1));  // Load must have reg dest.

            for (src = 1; src <= 2; src++) begin : L1b_FETCH_Instr_Src logic [7:0] L1_imm_tmp_a1; logic [2:0] L1_imm_value_a1; logic L1_is_imm_a1; logic L1_is_reg_a1; logic [2:0] L1_reg_a1; logic [7:0] L1_reg_tmp_a1; //_/src
               // Src1
               assign L1_is_reg_a1 = L1_FETCH_Instr_Src[src].L1_char_a1 >= "a" && L1_FETCH_Instr_Src[src].L1_char_a1 <= "h";
               assign L1_reg_tmp_a1[7:0] = L1_FETCH_Instr_Src[src].L1_char_a1 - "a";
               assign L1_reg_a1[2:0] = L1_reg_tmp_a1[2:0];
               assign L1_is_imm_a1 = L1_FETCH_Instr_Src[src].L1_char_a1 >= "0" && L1_FETCH_Instr_Src[src].L1_char_a1 < "8";
               assign L1_imm_tmp_a1[7:0] = L1_FETCH_Instr_Src[src].L1_char_a1 - "0";
               assign L1_imm_value_a1[2:0] = L1_imm_tmp_a1[2:0];
               assign FETCH_Instr_Src_illegal_a1[src] = !(L1_is_reg_a1 || L1_is_imm_a1); end

            // Opcode:
            //_/op
               assign FETCH_Instr_Op_char_a1[7:0] = FETCH_Instr_op_char_a1;
               // Arithmetic
               assign FETCH_Instr_Op_add_a1 = FETCH_Instr_Op_char_a1 == "+";
               assign FETCH_Instr_Op_sub_a1 = FETCH_Instr_Op_char_a1 == "-";
               assign FETCH_Instr_Op_mul_a1 = FETCH_Instr_Op_char_a1 == "*";
               assign FETCH_Instr_Op_div_a1 = FETCH_Instr_Op_char_a1 == "/";
               // Compare and bool (w/ 1 bit rslt)
               assign FETCH_Instr_Op_eq_a1 = FETCH_Instr_Op_char_a1 == "=";
               assign FETCH_Instr_Op_ne_a1 = FETCH_Instr_Op_char_a1 == "!";
               assign FETCH_Instr_Op_lt_a1 = FETCH_Instr_Op_char_a1 == "<";
               assign FETCH_Instr_Op_gt_a1 = FETCH_Instr_Op_char_a1 == ">";
               assign FETCH_Instr_Op_le_a1 = FETCH_Instr_Op_char_a1 == "[";
               assign FETCH_Instr_Op_ge_a1 = FETCH_Instr_Op_char_a1 == "]";
               assign FETCH_Instr_Op_and_a1 = FETCH_Instr_Op_char_a1 == "&";
               assign FETCH_Instr_Op_or_a1 = FETCH_Instr_Op_char_a1 == "|";
               // Wide Immediate
               assign FETCH_Instr_Op_wide_imm_a1 = FETCH_Instr_Op_char_a1 == "~";
               assign FETCH_Instr_Op_combine_a1 = FETCH_Instr_Op_char_a1 == ",";
               // Conditional
               assign FETCH_Instr_Op_conditional_a1 = FETCH_Instr_Op_char_a1 == "?";
               // Memory
               assign FETCH_Instr_Op_ld_a1 = FETCH_Instr_Op_char_a1 == "{";
               assign FETCH_Instr_Op_st_a1 = FETCH_Instr_Op_char_a1 == "}";
               // Opcode classes:
               assign FETCH_Instr_Op_arith_a1 = FETCH_Instr_Op_add_a1 || FETCH_Instr_Op_sub_a1 || FETCH_Instr_Op_mul_a1 || FETCH_Instr_Op_div_a1;
               assign FETCH_Instr_Op_compare_a1 = FETCH_Instr_Op_eq_a1 || FETCH_Instr_Op_ne_a1 || FETCH_Instr_Op_lt_a1 || FETCH_Instr_Op_gt_a1 || FETCH_Instr_Op_le_a1 || FETCH_Instr_Op_ge_a1;
               assign FETCH_Instr_Op_bitwise_a1 = FETCH_Instr_Op_and_a1 || FETCH_Instr_Op_or_a1;
               assign FETCH_Instr_Op_full_a1 = FETCH_Instr_Op_arith_a1 || FETCH_Instr_Op_bitwise_a1 || FETCH_Instr_Op_wide_imm_a1 || FETCH_Instr_Op_combine_a1 || FETCH_Instr_Op_conditional_a1;
               //$op3 = $compare || $full;
               assign FETCH_Instr_Op_mem_a1 = FETCH_Instr_Op_ld_a1 || FETCH_Instr_Op_st_a1;
               assign FETCH_Instr_Op_illegal_a1 = !(FETCH_Instr_Op_compare_a1 || FETCH_Instr_Op_full_a1 || FETCH_Instr_Op_mem_a1);
            assign FETCH_Instr_op_compare_a1 = FETCH_Instr_Op_compare_a1;
            assign FETCH_Instr_op_full_a1 = FETCH_Instr_Op_full_a1;
            assign FETCH_Instr_ld_a1 = FETCH_Instr_Op_ld_a1;
            assign FETCH_Instr_st_a1 = FETCH_Instr_Op_st_a1;
            assign FETCH_Instr_illegal_a1 = FETCH_Instr_illegal_dest_a1 || (| FETCH_Instr_Src_illegal_a1) || FETCH_Instr_Op_illegal_a1;
            
            // Branch instructions with a condition (that might be worth predicting).
            assign FETCH_Instr_conditional_branch_a1 = FETCH_Instr_branch_a1 && FETCH_Instr_Op_conditional_a1;
            
         //_@1
            // ======
            // Reg Rd
            // ======
            
            //_/regs
            for (src = 1; src <= 2; src++) begin : L1c_FETCH_Instr_Src logic L1_is_reg_condition_a1; logic [11:0] L1_reg_value_a1; logic L1_valid_a1, L1_valid_a2; logic [11:0] L1_value_a1, L1_value_a2, L1_value_a3; //_/src
               assign L1_is_reg_condition_a1 = L1b_FETCH_Instr_Src[src].L1_is_reg_a1;
               //_?$is_reg_condition
                  assign L1_reg_value_a1[11:0] =
                     // Bypass stages:
                     (FETCH_Instr_dest_is_reg_a2 && (FETCH_Instr_dest_reg_a2 == L1b_FETCH_Instr_Src[src].L1_reg_a1)) ? FETCH_Instr_rslt_a2 :
                     (FETCH_Instr_dest_is_reg_a3 && (FETCH_Instr_dest_reg_a3 == L1b_FETCH_Instr_Src[src].L1_reg_a1)) ? FETCH_Instr_rslt_a3 :
                     
                     FETCH_Instr_Regs_Value_a3[L1b_FETCH_Instr_Src[src].L1_reg_a1];
               assign L1_valid_a1 = !FETCH_Instr_Src_illegal_a1[src];
               //_?$valid
                  assign L1_value_a1[11:0] = L1b_FETCH_Instr_Src[src].L1_is_reg_a1 ? L1_reg_value_a1 :
                                           {9'b0, L1b_FETCH_Instr_Src[src].L1_imm_value_a1}; // $is_imm
               assign FETCH_Instr_Src_replay_a1[src] = L1b_FETCH_Instr_Src[src].L1_is_reg_a1 && FETCH_Instr_Regs_next_pending_a2[L1b_FETCH_Instr_Src[src].L1_reg_a1]; end
            assign FETCH_Instr_replay_a1 = | FETCH_Instr_Src_replay_a1 || (FETCH_Instr_dest_is_reg_a1 && FETCH_Instr_Regs_next_pending_a2[FETCH_Instr_dest_reg_a1]);
            
         //_@2
            // =======
            // Execute
            // =======
            
            //_?$op_compare
               assign FETCH_Instr_compare_rslt_a2 =
                  FETCH_Instr_Op_eq_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 == L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_ne_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 != L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_lt_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 < L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_gt_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 > L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_le_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 <= L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_ge_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 >= L1c_FETCH_Instr_Src[2].L1_value_a2 :
                           1'b0;
            //_?$op_full
               assign FETCH_Instr_op_full_rslt_a2[11:0] =
                  FETCH_Instr_Op_add_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 + L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_sub_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 - L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_mul_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 * L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_div_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 * L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_and_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 & L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_or_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 | L1c_FETCH_Instr_Src[2].L1_value_a2 :
                  FETCH_Instr_Op_wide_imm_a2 ? {6'b0, L1c_FETCH_Instr_Src[1].L1_value_a2[2:0], L1c_FETCH_Instr_Src[2].L1_value_a2[2:0]} :
                  FETCH_Instr_Op_combine_a2 ? {L1c_FETCH_Instr_Src[1].L1_value_a2[5:0], L1c_FETCH_Instr_Src[2].L1_value_a2[5:0]} :
                  FETCH_Instr_Op_conditional_a2 ? (L1c_FETCH_Instr_Src[2].L1_value_a2[11] ? 12'b0 : L1c_FETCH_Instr_Src[1].L1_value_a2) :
                                    12'b0;
            //_?$dest_valid
               assign FETCH_Instr_rslt_a2[11:0] =
                  FETCH_Instr_returning_ld_a2 ? FETCH_Instr_ld_rslt_a6 :
                  FETCH_Instr_st_a2 ? L1c_FETCH_Instr_Src[1].L1_value_a2 :
                  FETCH_Instr_op_full_a2 ? FETCH_Instr_op_full_rslt_a2 :
                  FETCH_Instr_op_compare_a2 ? {12{FETCH_Instr_compare_rslt_a2}} :
                  //$ld ? $ld_rslt :
                        12'b0;
               
         //_@2
            // =========
            // Target PC
            // =========
            
            // Jump (Dest = "P") and Branch (Dest = "p") Targets.
            //_?$jump
               assign FETCH_Instr_jump_target_a2[11:0] = FETCH_Instr_rslt_a2;
            // Always predict taken; mispredict if jump or unconditioned branch or
            //   conditioned branch with positive condition.
            assign FETCH_Instr_mispred_branch_a2 = FETCH_Instr_branch_a2 && ! (FETCH_Instr_conditional_branch_a2 && L1c_FETCH_Instr_Src[2].L1_value_a2[11]);
            assign FETCH_Instr_valid_jump_a2 = FETCH_Instr_jump_a2 && ! FETCH_Instr_squash_a2;
            assign FETCH_Instr_valid_mispred_branch_a2 = FETCH_Instr_mispred_branch_a2 && ~FETCH_Instr_squash_a2;
            assign FETCH_Instr_valid_ld_a2 = FETCH_Instr_ld_a2 && ! FETCH_Instr_squash_a2;
            assign FETCH_Instr_valid_st_a2 = FETCH_Instr_st_a2 && ! FETCH_Instr_squash_a2;
            assign FETCH_Instr_valid_illegal_a2 = FETCH_Instr_illegal_a2 && ! FETCH_Instr_squash_a2;
            // Squash. Keep a count of the number of cycles remaining in the shadow of a mispredict.
            assign FETCH_Instr_squash_a2 = | FETCH_Instr_SquashCnt_a2 || FETCH_Instr_returning_ld_a2 || FETCH_Instr_replay_a2;
            assign FETCH_Instr_SquashCnt_a1[2:0] =
               FETCH_Instr_reset_a2                ? 3'b0 :
               FETCH_Instr_valid_mispred_branch_a2 ? 3 :
               FETCH_Instr_valid_jump_a2           ? 2 :
               FETCH_Instr_replay_a2               ? 3 - 3'b1:
               FETCH_Instr_SquashCnt_a2 == 3'b0    ? 3'b0 :
                                       FETCH_Instr_SquashCnt_a2 - 3'b1;
         //_@3
            //_?$branch
               assign FETCH_Instr_branch_target_a3[11:0] = FETCH_Instr_Pc_a3 + 12'b1 + FETCH_Instr_rslt_a3;
            
            
            // ====
            // Load
            // ====
            
            //_/mem
         //_?$ld
            //_@2
               assign FETCH_Instr_addr_a2[11:0] = L1c_FETCH_Instr_Src[1].L1_value_a2 + L1c_FETCH_Instr_Src[2].L1_value_a2;
            //_@3
               assign FETCH_Instr_ld_rslt_a3[11:0] = FETCH_Instr_Mem_Word_a3[FETCH_Instr_addr_a3[4:0]];
         
         // Array writes are not currently permitted to use assignment
         // syntax, so \always_comb is used, and this must be outside of
         // when conditions, so we need to use if. <<1 because no <= support
         // in this context. (This limitation will be lifted.)

         //_@3
            // =====
            // Store
            // =====

            always_comb begin
               if (FETCH_Instr_valid_st_a3)
                  FETCH_Instr_Mem_Word_a2[L1c_FETCH_Instr_Src[2].L1_value_a3[4:0]][11:0] = L1c_FETCH_Instr_Src[1].L1_value_a3; end

         //_@3
            // =========
            // Reg Write
            // =========

            assign FETCH_Instr_reg_write_a3 = (FETCH_Instr_dest_is_reg_a3 && ! FETCH_Instr_squash_a3) || FETCH_Instr_returning_ld_a3;
            always_comb begin
               if (FETCH_Instr_reg_write_a3)
                  FETCH_Instr_Regs_Value_a2[FETCH_Instr_dest_reg_a3][11:0] = FETCH_Instr_reset_a3 ? 12'h0 : FETCH_Instr_rslt_a3; end
         
         // There's no bypass on pending, so we must write the same cycle we read.
         //_@2
            for (regs = 0; regs <= 7; regs++) begin : L1b_FETCH_Instr_Regs logic L1_reg_match_a2; //_/regs
               assign L1_reg_match_a2 = FETCH_Instr_dest_reg_a2 == regs;
               assign FETCH_Instr_Regs_next_pending_a2[regs] =  // Should be state, but need to consume prior to flop, which SandPiper doesn't support, yet.
                  FETCH_Instr_reset_a2 ? 1'b0 :
                  // set for loads
                  FETCH_Instr_valid_ld_a2 && L1_reg_match_a2   ? 1'b1 :
                  // clear when load returns
                  FETCH_Instr_returning_ld_a2 && L1_reg_match_a2 ? 1'b0 :
                               FETCH_Instr_Regs_next_pending_a3[regs]; end

         
   // Assert these to end simulation (before Makerchip cycle limit).
   assign passed = ! reset && FETCH_Instr_Pc_a5 == 12'hfff;
   assign failed = ! reset && (cyc_cnt > 1000 || (! FETCH_Instr_reset_a3 && FETCH_Instr_valid_illegal_a6)); endgenerate
//_\SV
   endmodule
