\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
\TLV
   
   // Verilog arithmetic operators: +, -, *, /, %, etc.
   $out[7:0] = ($num1[3:0] + $num2[3:0]) - 1;
   
\SV
endmodule
