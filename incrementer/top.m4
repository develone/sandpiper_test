\TLV_version [\source top.tlv] 1d: tl-x.org
\SV

   // ===========
   // Incrementer
   // ===========

   // An incrementer implemented bit-level using hierarchy for the bit slice.
   // Testbench compares with result of + operator.

   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
\TLV
   
   
   // The incrementer
   /slice[8-1:0]
      // Get carry in from previous slice (or 1 into slice 0).
      $carry_in = (#slice == 0) ? 1'b1
                                : /slice[(#slice - 1) % 8]$carry_out;
!     $Value <= *reset ? 1'b0    // reset to zero
                       : $Value ^ $carry_in;
      $carry_out = $Value && $carry_in;
   
   // Combine output bits into a vector.
   $value[8-1:0] = /slice[*]$Value;
   
   
   // Testbench
   /tb
!     $Value[8-1:0] <= *reset ? 8'b0 : $Value + 8'b1;
      $error = /top$value != $Value;
   
      // End simulation
!     *failed = ! *reset && $error;
!     *passed = $Value == 8'd30 && *cyc_cnt >= 32'd30;
\SV
   endmodule
