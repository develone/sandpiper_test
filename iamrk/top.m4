\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
 
   // Included URL: "https://raw.githubusercontent.com/stevehoover/RISC-V_MYTH_Workshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlv_lib/risc-v_shell_lib.tlv"// Included URL: "https://raw.githubusercontent.com/stevehoover/warp-v_includes/2d6d36baa4d2bc62321f982f78c8fe1456641a43/risc-v_defs.tlv"

\SV
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // (Expanded in Nav-TLV pane.)
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
   // Inst #0: ADD,r10,r0,r0             // Initialize r10 (a0) to 0.
   // Function:
   // Inst #1: ADD,r14,r10,r0            // Initialize sum register a4 with 0x0
   // Inst #2: ADDI,r12,r10,1010         // Store count of 10 in register a2.
   // Inst #3: ADD,r13,r10,r0            // Initialize intermediate sum register a3 with 0
   // Loop:
   // Inst #4: ADD,r14,r13,r14           // Incremental addition
   // Inst #5: ADDI,r13,r13,1            // Increment intermediate register by 1
   // Inst #6: BLT,r13,r12,1111111111000 // If a3 is less than a2, branch to label named <loop>
   // Inst #7: ADD,r10,r14,r0            // Store final result to register a0 so that it can be read by main program
   // Inst #8: SW,r0,r10,100
   // Inst #9: LW,r15,r0,100
   // Optional:
   // m4_asm(JAL, r7, 00000000000000000000) // Done. Jump to itself (infinite loop). (Up to 20-bit signed immediate plus implicit 0 bit (unlike JALR) provides byte address; last immediate bit should also be 0)
   
   |cpu
      @0
         $reset = *reset;
         //$pc[31:0] = >>1$reset ? 32'd0 : >>1$taken_br ? >>1$br_tgt_pc  : >>1$inc_pc;
         $pc[31:0] = >>1$reset ? 32'd0 :
                     >>3$valid_taken_br ? >>3$br_tgt_pc  :
                     >>3$valid_ld ? >>3$inc_pc :
                     >>3$valid_jump && >>3$is_jal ? >>3$br_tgt_pc:
                     >>3$valid_jump && >>3$is_jalr ? >>3$jalr_tgt_pc : 
                     >>1$inc_pc;
         //Start and Valid signals
         //$start = >>1$reset && !($reset);
         //$valid = $reset ? 0 : ( $start ? 1 : >>3$valid );         
      @1
         $inc_pc[31:0] = $pc[31:0] + 32'd4;
         //`BOGUS_USE($is_beq $is_bne $is_blt $is_bge $is_bltu $is_bgeu $is_addi $is_add)
         $imem_rd_addr[4-1:0] = $pc[4+1:2];
         $imem_rd_en = !$reset;
         $instr[31:0] = $imem_rd_data[31:0];
         //Intruction Type Decode Logic for Immediate Instruction types
         $is_i_instr = $instr[6:2] ==? 5'b0000x || $instr[6:2] ==? 5'b001x0 || $instr[6:2] ==? 5'b11001 || $instr[6:2] ==? 5'b11100; 
         $is_u_instr = $instr[6:2] ==? 5'b0x101;
         $is_s_instr = $instr[6:2] ==? 5'b0100x;
         $is_r_instr = $instr[6:2] ==? 5'b01011 || $instr[6:2] ==? 5'b011x0 || $instr[6:2] ==? 5'b10100;
         $is_b_instr = $instr[6:2] ==? 5'b11000;
         $is_j_instr = $instr[6:2] ==? 5'b11011;
         //Extraction of immediate instruction field
         $imm[31:0] = $is_i_instr ? { {21{$instr[31]}}, $instr[30:20] } :
                      $is_s_instr ? { {21{$instr[31]}}, $instr[30:25], $instr[11:7] } :
                      $is_b_instr ? { {20{$instr[31]}}, $instr[7], $instr[30:25], $instr[11:8], 1'b0 } :
                      $is_u_instr ? { $instr[31:12], 12'b0 } :
                      $is_j_instr ? { {12{$instr[31]}}, $instr[19:12], $instr[20], $instr[30:21], 1'b0 } :
                      32'b0;
         //Extraction of other instruction field
         $rs2_valid = $is_r_instr || $is_s_instr || $is_b_instr;
         ?$rs2_valid
            $rs2[4:0] = $instr[24:20];
         
         $rs1_valid = $is_i_instr || $is_r_instr || $is_s_instr || $is_b_instr;
         ?$rs1_valid
            $rs1[4:0] = $instr[19:15];
         
         $funct3_valid = $is_i_instr || $is_r_instr || $is_s_instr || $is_b_instr;
         ?$funct3_valid
            $funct3[2:0] = $instr[14:12];
         
         $funct7_valid = $is_r_instr;
         ?$funct7_valid
            $funct7[6:0] = $instr[31:25];
         
         //Instruction Decode
         $opcode[6:0] = $instr[6:0];
      @2
         $dec_bits[10:0] = { $funct7[5] , $funct3 , $opcode };
         $is_beq = $dec_bits ==? 11'bx_000_1100011;
         $is_bne = $dec_bits ==? 11'bx_001_1100011;
         $is_blt = $dec_bits ==? 11'bx_100_1100011;
         $is_bge = $dec_bits ==? 11'bx_101_1100011;
         
         $is_bltu = $dec_bits ==? 11'bx_110_1100011;
         $is_bgeu = $dec_bits ==? 11'bx_111_1100011;
         $is_addi = $dec_bits ==? 11'bx_000_0010011;
         
         $is_add = $dec_bits ==? 11'b0_000_0110011;
         
         //Remaining instructions
         $is_sub = $dec_bits ==? 11'b1_000_0110011;
         $is_sll = $dec_bits ==? 11'b0_001_0110011;
         $is_slt = $dec_bits ==? 11'b0_010_0110011;
         $is_sltu = $dec_bits ==? 11'b0_011_0110011;
         
         $is_xor = $dec_bits ==? 11'b0_100_0110011;
         $is_srl = $dec_bits ==? 11'b0_101_0110011;
         $is_sra = $dec_bits ==? 11'b1_101_0110011;
         
         $is_or = $dec_bits ==? 11'b0_110_0110011;
         $is_and = $dec_bits ==? 11'b0_111_0110011;
         
         $is_load = $opcode ==  7'b0000011;
         $is_lui = $opcode ==  7'b0110111;
         $is_auipc = $opcode ==  7'b0010111;
         
         $is_jal = $opcode ==  7'b1101111;
         $is_jalr = $dec_bits ==? 11'bx_000_1100111;
         
         $is_sb = $dec_bits ==? 11'bx_000_0100011;
         $is_sh = $dec_bits ==? 11'bx_001_0100011;
         $is_sw = $dec_bits ==? 11'bx_010_0100011;
         
         $is_slti = $dec_bits ==? 11'bx_010_0010011;
         $is_sltiu = $dec_bits ==? 11'bx_011_0010011;
         
         $is_xori = $dec_bits ==? 11'bx_100_0010011;
         $is_ori = $dec_bits ==? 11'bx_110_0010011;
         $is_andi = $dec_bits ==? 11'bx_111_0010011;
         
         $is_slli = $dec_bits ==? 11'b0_001_0010011;
         $is_srli = $dec_bits ==? 11'b0_101_0010011;
         $is_srai = $dec_bits ==? 11'b1_101_0010011;
               
         //Assigning source register values to Regiter file Read (Rf_rd)
         $rd_valid = $is_i_instr || $is_r_instr || $is_u_instr || $is_j_instr;
         ?$rd_valid
            $rd[4:0] = $instr[11:7];
            
         $rf_rd_en1 = $rs1_valid;
         ?$rf_rd_en1
            $rf_rd_index1[4:0] = $rs1;
            
         $rf_rd_en2 = $rs2_valid;
         ?$rf_rd_en2
            $rf_rd_index2[4:0] = $rs2;
         //[UPDATE: RF BYPASSED]Assigning inputs of ALU with Rf_rd Outputs <<Note:rd means read>>
         $src1_value[31:0] = ((>>1$rf_wr_index == $rf_rd_index1) && >>1$rf_wr_en) ? >>1$result : $rf_rd_data1;
         $src2_value[31:0] = ((>>1$rf_wr_index == $rf_rd_index2) && >>1$rf_wr_en) ? >>1$result : $rf_rd_data2;
         
         //Compute $br_tgt_pc (PC + imm)
         $br_tgt_pc[31:0] = $pc + $imm ;
         // added $jalr_target_pc
         $jalr_tgt_pc[31:0] = $src1_value + $imm;
      @3   
         //Intermediate signals
         $sltu_result = $src1_value + $src2_value;
         $sltiu_result = $src1_value < $imm;
         //Assign the ALU $results
         $result[31:0] = $is_addi ? $src1_value + $imm :
                         $is_add ? $src1_value + $src2_value :
                         $is_load ? $src1_value + $imm :
                         $is_s_instr ? $src1_value + $imm :
                         $is_andi ? $src1_value && $imm :
                         $is_ori ? $src1_value || $imm :
                         $is_xori ? $src1_value ^ $imm :
                         $is_slli ? $src1_value << $imm[5:0] :
                         $is_srli ? $src1_value >> $imm[5:0] :
                         $is_and ? $src1_value && $src2_value :
                         $is_or ? $src1_value || $src2_value :
                         $is_xor ? $src1_value ^ $src2_value :
                         $is_sub ? $src1_value - $src2_value :
                         $is_sll ? $src1_value << $src2_value[4:0] :
                         $is_srl ? $src1_value >> $src2_value[4:0] :
                         $is_sltu ? $src1_value < $src2_value :
                         $is_sltiu ? $src1_value < $imm :
                         $is_lui ? { $imm[31:12],12'b0 } :
                         $is_auipc ? $pc + $imm :
                         $is_jal ? $pc + $imm :
                         $is_jalr ? $pc + $imm :
                         $is_slt ? (($src1_value[31] == $src2_value[31]) ? $sltu_result : { 31'b0 , $src1_value[31] } ) :
                         $is_slti ? (($src1_value[31] == $imm[31]) ? $sltiu_result : { 31'b0 , $src1_value[31] } ) :
                         $is_sra ? { {32{$src1_value[31]}}, $src1_value } >> $src2_value[4:0] :
                         $is_srai ? { {32{$src1_value[31]}}, $src1_value } >> $imm[4:0] : 
                         32'bx;
         
         //Register File Write (Rf_wr) //Modification wrt load
         ?$valid
            $rf_wr_data[31:0] = !$valid ? >>2$ld_data : $result ;
            //$rf_wr_data[31:0] = $valid ? $result : >>2$ld_data ;
            //$rf_wr_data[31:0] = $result;
            //$rf_wr_data[31:0] = >>2$valid_ld ? >>2$ld_data : $result;
         
         $rf_wr_en = ( ($rd != 5'b0) && $rd_valid && $valid ) || >>2$valid_ld ;
         ?$rf_wr_en
            $rf_wr_index[4:0] = >>2$valid_ld ? >>2$rd: $rd ;
         
         //Taken Branch determined
         $taken_br = $is_beq ? $src1_value == $src2_value :
                     $is_bne ? $src1_value != $src2_value :
                     $is_blt ? ($src1_value < $src2_value) ^ ($src1_value[31] != $src2_value[31]) :
                     $is_bge ? ($src1_value >= $src2_value) ^ ($src1_value[31] != $src2_value[31]) :
                     $is_bltu ? $src1_value < $src2_value :
                     $is_bgeu ? $src1_value >= $src2_value :
                     1'b0;         
         //New valid.
         //$valid = $reset ? 0 : ( $start ? 1 : !(>>1$valid_taken_br || >>2$valid_taken_br || >>1$valid_ld || >>2$valid_ld));
         $valid = $reset ? 0 : !(>>1$valid_taken_br || >>2$valid_taken_br || >>1$valid_ld || >>2$valid_ld);
         //$valid = !(>>1$valid_taken_br || >>2$valid_taken_br || >>1$valid_ld || >>2$valid_ld);
         $valid_ld = $valid && $is_load ;
         //Introducing $valid_taken_br
         $valid_taken_br = $valid && $taken_br;
         
         //Adding Jump branching instructions
         $is_jump = $is_jal || $is_jalr ;
         $valid_jump = $valid && $is_jump ; 
         
      @4 
         $dmem_wr_en = $is_s_instr && $valid;
         $dmem_rd_en = $is_load;
         $dmem_addr[3:0] = $result[5:2];
         $dmem_wr_data[31:0] = $src2_value;
      // Note: Because of the magic we are using for visualisation, if visualisation is enabled below,
      //       be sure to avoid having unassigned signals (which you might be using for random inputs)
      //       other than those specifically expected in the labs. You'll get strange errors for these.
      @5
         $ld_data[31:0] = $dmem_rd_data;
   // Assert these to end simulation (before Makerchip cycle limit).
   //*passed = *cyc_cnt > 107;
   *passed = |cpu/xreg[15]>>5$value == (1+2+3+4+5+6+7+8+9);
   *failed = 1'b0;
   
   // Macro instantiations for:
   //  o instruction memory
   //  o register file
   //  o data memory
   //  o CPU visualization
   |cpu
      \source /raw.githubusercontent.com/stevehoover/RISCVMYTHWorkshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlvlib/riscvshelllib.tlv 16   // Instantiated from top.tlv, 243 as: m4+imem(@1)    // Args: (read stage)
         // Instruction Memory containing program defined by m4_asm(...) instantiations.
         @1
            \SV_plus
               // The program in an instruction memory.
               logic [31:0] instrs [0:10-1];
               assign instrs = '{
                  {7'b0000000, 5'd0, 5'd0, 3'b000, 5'd10, 7'b0110011}, {7'b0000000, 5'd0, 5'd10, 3'b000, 5'd14, 7'b0110011}, {12'b1010, 5'd10, 3'b000, 5'd12, 7'b0010011}, {7'b0000000, 5'd0, 5'd10, 3'b000, 5'd13, 7'b0110011}, {7'b0000000, 5'd14, 5'd13, 3'b000, 5'd14, 7'b0110011}, {12'b1, 5'd13, 3'b000, 5'd13, 7'b0010011}, {1'b1, 6'b111111, 5'd12, 5'd13, 3'b100, 4'b1100, 1'b1, 7'b1100011}, {7'b0000000, 5'd0, 5'd14, 3'b000, 5'd10, 7'b0110011}, {7'b0000000, 5'd10, 5'd0, 3'b010, 5'b00100, 7'b0100011}, {12'b100, 5'd0, 3'b010, 5'd15, 7'b0000011}
               };
            /imem[9:0]
               $instr[31:0] = *instrs\[#imem\];
            ?$imem_rd_en
               $imem_rd_data[31:0] = /imem[$imem_rd_addr]$instr;
          
      \end_source    // Args: (read stage)
      \source /raw.githubusercontent.com/stevehoover/RISCVMYTHWorkshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlvlib/riscvshelllib.tlv 33   // Instantiated from top.tlv, 244 as: m4+rf(@2, @3)  // Args: (read stage, write stage) - if equal, no register bypass is required
         // Reg File
         @3
            /xreg[31:0]
               $wr = |cpu$rf_wr_en && (|cpu$rf_wr_index != 5'b0) && (|cpu$rf_wr_index == #xreg);
               $value[31:0] = |cpu$reset ?   #xreg           :
                              $wr        ?   |cpu$rf_wr_data :
                                             $RETAIN;
         @2
            ?$rf_rd_en1
               $rf_rd_data1[31:0] = /xreg[$rf_rd_index1]>>2$value;
            ?$rf_rd_en2
               $rf_rd_data2[31:0] = /xreg[$rf_rd_index2]>>2$value;
            `BOGUS_USE($rf_rd_data1 $rf_rd_data2) 
      \end_source  // Args: (read stage, write stage) - if equal, no register bypass is required
      \source /raw.githubusercontent.com/stevehoover/RISCVMYTHWorkshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlvlib/riscvshelllib.tlv 50   // Instantiated from top.tlv, 245 as: m4+dmem(@4)    // Args: (read/write stage)
         // Data Memory
         @4
            /dmem[15:0]
               $wr = |cpu$dmem_wr_en && (|cpu$dmem_addr == #dmem);
               $value[31:0] = |cpu$reset ?   #dmem :
                              $wr        ?   |cpu$dmem_wr_data :
                                             $RETAIN;
                                        
            ?$dmem_rd_en
               $dmem_rd_data[31:0] = /dmem[$dmem_addr]>>1$value;
            `BOGUS_USE($dmem_rd_data)
      \end_source    // Args: (read/write stage)

   //m4+cpu_viz(@4)    // For visualisation, argument should be at least equal to the last stage of CPU logic
                       // @4 would work for all labs
\SV
   endmodule
