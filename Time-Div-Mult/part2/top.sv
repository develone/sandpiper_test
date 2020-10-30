`line 2 "top.tlv" 0 //_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV
  // `include "sqrt32.v";
   
   // =============================================
   // Time-Division Multiplexer and De-multiplexing
   // =============================================

   // A wide vector, at a 1/4 "frequency" (1 valid cycle, followed by 3 invalid ones)
   // is time-division multiplexed (TDM) into a narrow vector, carrying one of n pieces per cycle,
   // (1st, least-significant flit in stage 0, 2nd in stage 2, etc.)
   // and this is de-multiplexed into a stream similar to the original in the same pipeline.
   // This is a useful design pattern for reducing wire routing.

   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
`include "top_gen.sv" //_\TLV
   
   // Stimulus
   //_|in
      //_@0
         // Control signals
         assign IN_reset_a0 = reset;
         assign IN_cnt_a0[1:0] = IN_reset_a0 ? 0 : IN_cnt_a1 + 1;
         assign IN_valid_a0 = IN_cnt_a0 == 0 && ! IN_reset_a0;
      // Random wide input vector, valid every nth cycle.
      //_?$valid
         //_@0
            assign IN_packet_in_a0[15:0] = RW_rand_vect[(0 + (0)) % 257 +: 16];
      // TDM the wide vector into narrow pieces.
      //_@0
         assign IN_flit_a0[3:0] = IN_valid_a0 ? IN_packet_in_a0[3:0] :
                      IN_valid_a1 ? IN_packet_in_a1[7:4] :
                      IN_valid_a2 ? IN_packet_in_a2[11:8] :
                                  IN_packet_in_a3[15:12];
      // Reassemble (de-multiplex) the data into its original wide form in a
      // different pipeline.
      //_@4  // 3 or more. Increase to add transit time.
         //_?$valid
            assign IN_packet_out_a4[15:0] = {IN_flit_a1, IN_flit_a2, IN_flit_a3, IN_flit_a4};

         // Print & check
         always_comb begin
            if (IN_valid_a4)
               $display("%h became %h", IN_packet_in_a4, IN_packet_out_a4); end
         assign IN_error_a4 = IN_reset_a4 ? 0 : IN_error_a5 || (IN_valid_a4 && (IN_packet_in_a4 != IN_packet_out_a4));
   
   
         // Assert these to end simulation (before Makerchip cycle limit).
         assign passed = cyc_cnt > 40;
         assign failed = cyc_cnt > 30 && IN_valid_a4 && IN_error_a4; endgenerate

//_\SV
   endmodule
