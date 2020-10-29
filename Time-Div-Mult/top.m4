\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
   `include "sqrt32.v";
   
   // =============================================
   // Time-Division Multiplexer and De-multiplexing
   // =============================================

   // A wide vector, at a 1/4 "frequency" (1 valid cycle, followed by 3 invalid ones)
   // is time-division multiplexed (TDM) into a narrow vector, carrying one of n pieces per cycle,
   // (1st, least-significant flit in stage 0, 2nd in stage 2, etc.)
   // and this is de-multiplexed into a stream similar to the original in the same pipeline.
   // This is a useful design pattern for reducing wire routing.

   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
\TLV
   
   // Stimulus
   |in
      @0
         // Control signals
!        $reset = *reset;
         $cnt[1:0] = $reset ? 0 : >>1$cnt + 1;
         $valid = $cnt == 0 && ! $reset;
      // Random wide input vector, valid every nth cycle.
      ?$valid
         @0
            $packet_in[15:0] = *RW_rand_vect[(0 + (0)) % 257 +: 16];
      // TDM the wide vector into narrow pieces.
      @0
      
         // LAB PART 1
         // FILL IN THIS LINE:
         // $flit[3:0] = ...;  // HINT: Use ? : ? : ...
         
      // Reassemble (de-multiplex) the data into its original wide form in a
      // different pipeline.
      @4  // 3 or more. Increase to add transit time.
         ?$valid
         
            // LAB PART 2
            // FILL IN THIS LINE:
            // $packet_out[15:0] = ...;  // HINT: Use { , , ...}

         // Print & check
         \always_comb
            if ($valid)
               \$display("\%h became \%h", $packet_in, $packet_out);
         $error = $reset ? 0 : >>1$error || ($valid && ($packet_in != $packet_out));
   
   
         // Assert these to end simulation (before Makerchip cycle limit).
         *passed = *cyc_cnt > 40;
         *failed = *cyc_cnt > 30 && $valid && $error;

\SV
   endmodule
