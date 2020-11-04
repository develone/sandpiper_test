\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
   // This code can be found in: https://github.com/stevehoover/RISC-V_MYTH_Workshop
   
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
   
   // Optional:
   // m4_asm(JAL, r7, 00000000000000000000) // Done. Jump to itself (infinite loop). (Up to 20-bit signed immediate plus implicit 0 bit (unlike JALR) provides byte address; last immediate bit should also be 0)
   

   |cpu
      @0
         $reset = *reset;



      // YOUR CODE HERE
      // ...

      // Note: Because of the magic we are using for visualisation, if visualisation is enabled below,
      //       be sure to avoid having unassigned signals (which you might be using for random inputs)
      //       other than those specifically expected in the labs. You'll get strange errors for these.

   
   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
   
   // Macro instantiations for:
   //  o instruction memory
   //  o register file
   //  o data memory
   //  o CPU visualization
   |cpu
      \source /raw.githubusercontent.com/stevehoover/RISCVMYTHWorkshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlvlib/riscvshelllib.tlv 16   // Instantiated from top.tlv, 64 as: m4+imem(@1)    // Args: (read stage)
         // Instruction Memory containing program defined by m4_asm(...) instantiations.
         @1
            \SV_plus
               // The program in an instruction memory.
               logic [31:0] instrs [0:8-1];
               assign instrs = '{
                  {7'b0000000, 5'd0, 5'd0, 3'b000, 5'd10, 7'b0110011}, {7'b0000000, 5'd0, 5'd10, 3'b000, 5'd14, 7'b0110011}, {12'b1010, 5'd10, 3'b000, 5'd12, 7'b0010011}, {7'b0000000, 5'd0, 5'd10, 3'b000, 5'd13, 7'b0110011}, {7'b0000000, 5'd14, 5'd13, 3'b000, 5'd14, 7'b0110011}, {12'b1, 5'd13, 3'b000, 5'd13, 7'b0010011}, {1'b1, 6'b111111, 5'd12, 5'd13, 3'b100, 4'b1100, 1'b1, 7'b1100011}, {7'b0000000, 5'd0, 5'd14, 3'b000, 5'd10, 7'b0110011}
               };
            /imem[7:0]
               $instr[31:0] = *instrs\[#imem\];
            ?$imem_rd_en
               $imem_rd_data[31:0] = /imem[$imem_rd_addr]$instr;
          
      \end_source    // Args: (read stage)
      \source /raw.githubusercontent.com/stevehoover/RISCVMYTHWorkshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlvlib/riscvshelllib.tlv 33   // Instantiated from top.tlv, 65 as: m4+rf(@1, @1)  // Args: (read stage, write stage) - if equal, no register bypass is required
         // Reg File
         @1
            /xreg[31:0]
               $wr = |cpu$rf_wr_en && (|cpu$rf_wr_index != 5'b0) && (|cpu$rf_wr_index == #xreg);
               $value[31:0] = |cpu$reset ?   #xreg           :
                              $wr        ?   |cpu$rf_wr_data :
                                             $RETAIN;
         @1
            ?$rf_rd_en1
               $rf_rd_data1[31:0] = /xreg[$rf_rd_index1]>>1$value;
            ?$rf_rd_en2
               $rf_rd_data2[31:0] = /xreg[$rf_rd_index2]>>1$value;
            `BOGUS_USE($rf_rd_data1 $rf_rd_data2) 
      \end_source  // Args: (read stage, write stage) - if equal, no register bypass is required
      \source /raw.githubusercontent.com/stevehoover/RISCVMYTHWorkshop/c1719d5b338896577b79ee76c2f443ca2a76e14f/tlvlib/riscvshelllib.tlv 50   // Instantiated from top.tlv, 66 as: m4+dmem(@4)    // Args: (read/write stage)
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
