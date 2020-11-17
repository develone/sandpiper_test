\m4_TLV_version 1d: tl-x.org
\SV
   // A simple example of a SV testbench and a TLV DUT.
   // Note that Verilator (compiler/simulator) only supports synthesizable SystemVerilog.

   // Testbench.
   m4_makerchip_module  // Expanded in Nav-TLV pane.
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
