\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
   // A simple example of a SV testbench and a TLV DUT.
   // Note that Verilator (compiler/simulator) only supports synthesizable SystemVerilog.

   // Testbench.
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */  // Expanded in Nav-TLV pane.
      logic run;          // Assert to start the series.
      logic [31:0] val;   // The value from the Fibonacci Series.

      assign run = cyc_cnt >= 5;
      dut dut(clk, reset, run, val);

      // Pass if Fibinocci value is correct after hardcoded # cycles; fail o/w.
      assign passed = cyc_cnt == 32'h10 && val == 32'h179;
      assign failed = cyc_cnt >  32'h10;
   endmodule


   // DUT.
   module dut(input logic clk, input logic reset, input logic run, output logic [31:0] val);
\TLV
   $reset = *reset;

   // Fibonacci.
   $val[31:0] = ($reset || ! *run) ? 1 : >>1$val + >>2$val;
   *val = $val;
\SV
   endmodule
