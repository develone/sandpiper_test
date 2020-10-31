\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
   // This code can be found in: https://github.com/stevehoover/VSDOpen2020_TLV_RISC-V_Tutorial
   
   // Included URL: "https://raw.githubusercontent.com/stevehoover/VSDOpen2020_TLV_RISC-V_Tutorial/da942f09ddf780e5da5ee0466c72a610f07aa73f/lib/shell.tlv"// Included URL: "https://raw.githubusercontent.com/stevehoover/warp-v_includes/2d6d36baa4d2bc62321f982f78c8fe1456641a43/risc-v_defs.tlv"

\SV
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // (Expanded in Nav-TLV pane.)
   /* verilator lint_on WIDTH */

\TLV

   // /====================\
   // | Sum 1 to 9 Program |
   // \====================/
   //
   // Program for MYTH Workshop to test RV32I
   // Add 1,2,3,...,9 (in that order).
   //
   // Regs:
   //  r10 (a0): In: 0, Out: final sum
   //  r12 (a2): 10
   //  r13 (a3): 1..10
   //  r14 (a4): Sum
   // 
   // External to function:
   // Inst #0: ADD,r10,r0,r0             // Initialize x10 to 0.
   // Function:
   // Inst #1: ADD,r14,r10,r0            // Initialize sum register x14 with 0x0
   // Inst #2: ADDI,r12,r10,1010         // Store count of 10 in register x12.
   // Inst #3: ADD,r13,r10,r0            // Initialize intermediate sum register x13 with 0
   // Loop:
   // Inst #4: ADD,r14,r13,r14           // Incremental addition
   // Inst #5: ADDI,r13,r13,1            // Increment intermediate register by 1
   // Inst #6: BLT,r13,r12,1111111111000 // If x13 is less than x12, branch to <loop>
   // Inst #7: ADD,r10,r14,r0            // Store final result to register x10 so that it can be read by main program
   
   
   //m4_define(['TBD'], [''0'])
   //m4_define(['TBDX'], [''])
   
   
   
   |view
      @0
         `BOGUS_USE($pc[4:0])
   // Lab: PC
   $pc[31:0] = >>1$reset        ? 32'0 :
               >>1$taken_branch ? >>1$br_target_pc :    // (initially $taken_branch == 0)
                                  >>1$pc + 32'b100;
   
   
   // Lab: Fetch
   $imem_rd_addr[2:0] = $pc[4:2];
   $instr[31:0] = $imem_rd_data;
   
   
   // Lab: Instruction Types Decode
   $is_i_instr = $instr[6:5] == 2'b00;
   $is_r_instr = $instr[6:5] == 2'b01 || $instr[6:5] == 2'b10;
   $is_b_instr = $instr[6:5] == 2'b11;
   
   
   // Lab: Instruction Immediate Decode
   $imm[31:0]  = $is_i_instr ? { {21{$instr[31]}}, $instr[30:20] } :   // I-type
                 $is_b_instr ? { {20{$instr[31]}},$instr[7],$instr[30:25],$instr[11:8],1'b0 } :    // B-type
                 32'b0;   // Default (unused)
   
   
   // Lab: Instruction Field Decode
   $rs2[4:0]    = $instr[24:20];
   $rs1[4:0]    = $instr[19:15];
   $funct3[2:0] = $instr[14:12];
   $rd[4:0]     = $instr[11:7];
   $opcode[6:0] = $instr[6:0];
   
   
   // Lab: Register Validity Decode
   $rs1_valid = $is_r_instr || $is_i_instr || $is_b_instr;
   $rs2_valid = $is_r_instr || $is_b_instr;
   $rd_valid  = $is_r_instr || $is_i_instr;
   
   
   // Lab: Instruction Decode
   $dec_bits[9:0] = {$funct3, $opcode};
   $is_blt  = $dec_bits == 10'b100_1100011;
   $is_addi = $dec_bits == 10'b000_0010011;
   $is_add  = $dec_bits == 10'b000_0110011;
   
   
   // Lab: Register File Read
   $rf_rd_en1         = $rs1_valid;
   $rf_rd_en2         = $rs2_valid;
   $rf_rd_index1[4:0] = $rs1;
   $rf_rd_index2[4:0] = $rs2;
   
   $src1_value[31:0] = $rf_rd_data1;
   $src2_value[31:0] = $rf_rd_data2;
   
   
   // Lab: ALU
   $result[31:0] = $is_addi ? $src1_value + $imm :    // ADDI: src1 + imm
                   $is_add  ? $src1_value + $src2_value :   // ADD: src1 + src2
                              32'b0;   // Default (unused)
   
   
   // Lab: Register File Write
   $rf_wr_en         = $rd_valid /* && $rd != 5'b0 */;
   $rf_wr_index[4:0] = $rd;
   $rf_wr_data[31:0] = $result;
   
   
   // Lab: Branch Condition
   $taken_branch = $is_blt ?  ($src1_value < $src2_value) /* ^ ($src1_value[31] != $src2_value[31]) */  : 1'b0;
   
   
   // Lab: Branch Target
   $br_target_pc[31:0] = $pc + $imm;
   // $taken_branch and $br_target_pc control the PC mux.
   
   
   
   \source /raw.githubusercontent.com/stevehoover/VSDOpen2020TLVRISCVTutorial/da942f09ddf780e5da5ee0466c72a610f07aa73f/lib/shell.tlv 16   // Instantiated from top.tlv, 123 as: m4+shell()
      // =======================================================================================================
      // THIS CODE IS PROVIDED. NO NEED TO LOOK BEHIND THE CURTAIN. LEARN MORE USING THE MAKERCHIP TUTORIALS.
      
      
      
      
      $reset = *reset;
      
      // Instruction Memory containing program defined by m4_asm(...) instantiations.
      \SV_plus
         // The program in an instruction memory.
         logic [31:0] instrs [0:8-1];
         assign instrs = '{
            {7'b0000000, 5'd0, 5'd0, 3'b000, 5'd10, 7'b0110011}, {7'b0000000, 5'd0, 5'd10, 3'b000, 5'd14, 7'b0110011}, {12'b1010, 5'd10, 3'b000, 5'd12, 7'b0010011}, {7'b0000000, 5'd0, 5'd10, 3'b000, 5'd13, 7'b0110011}, {7'b0000000, 5'd14, 5'd13, 3'b000, 5'd14, 7'b0110011}, {12'b1, 5'd13, 3'b000, 5'd13, 7'b0010011}, {1'b1, 6'b111111, 5'd12, 5'd13, 3'b100, 4'b1100, 1'b1, 7'b1100011}, {7'b0000000, 5'd0, 5'd14, 3'b000, 5'd10, 7'b0110011}
         };
      /imem[7:0]
         $instr[31:0] = *instrs\[#imem\];
      $imem_rd_data[31:0] = /imem[$imem_rd_addr]$instr;
      `BOGUS_USE($imem_rd_data)
      
      // Reg File
      /xreg[31:0]
         $wr = /top$rf_wr_en && (/top$rf_wr_index != 5'b0) && (/top$rf_wr_index == #xreg);
         $value[31:0] = /top$reset ? 32'b0           :
                        $wr        ? /top$rf_wr_data :
                                     $RETAIN;
      $rf_rd_data1[31:0] = /xreg[$rf_rd_index1]>>1$value;
      $rf_rd_data2[31:0] = /xreg[$rf_rd_index2]>>1$value;
      `BOGUS_USE($rf_rd_data1 $rf_rd_data2)
      
      // Assert these to end simulation (before Makerchip cycle limit).
      *passed = /xreg[10]>>1$value == (1+2+3+4+5+6+7+8+9);
      *failed = *cyc_cnt > 50;
      
      
      |view
         @0
            // String representations of the instructions for debug.
            \SV_plus
               logic [40*8-1:0] instr_strs [0:8];
               assign instr_strs = '{ "(R) ADD r10,r0,r0                       ",  "(R) ADD r14,r10,r0                      ",  "(I) ADDI r12,r10,1010                   ",  "(R) ADD r13,r10,r0                      ",  "(R) ADD r14,r13,r14                     ",  "(I) ADDI r13,r13,1                      ",  "(B) BLT r13,r12,1111111111000           ",  "(R) ADD r10,r14,r0                      ",  "END                                     "};
            $ANY = /top<>0$ANY;
            /imem[7:0]
               $ANY = /top/imem<>0$ANY;
               $instr_str[40*8-1:0] = *instr_strs[imem];
   
            $mnemonic[10*8-1:0] = $is_blt  ? "BLT       " :
                                  $is_addi ? "ADDI      " :
                                  $is_add  ? "ADD       " :  "UNKNOWN   ";
            $valid = ! $reset;
            `BOGUS_USE($pc[4:0])  // Bug workaround to pull lower bits.
            $fetch_instr_str[40*8-1:0] = *instr_strs\[$pc[\$clog2(8+1)+1:2]\];
    \end_source


\SV
   endmodule
