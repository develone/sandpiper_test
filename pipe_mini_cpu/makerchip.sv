//`include "sp_default.vh" //_\SV

// Provides Makerchip context in which user's module is invoked.
// Instantiates design as code(.*) so user's module need only define the desired signals from
// those available, which are:
//   clk,
//   reset
//   cyc_cnt
// sim_main.cpp drives clk and reset_async.
// Simulation is ended on max cycles argument below, or assertion of passed/failed signal.
// Additional testbench functionality can be added here, or within design using TLV.

module makerchip(input logic clk, input logic reset_async, output logic passed, output logic failed);

logic reset;
//logic clk, reset_async;      // Generated in this module for DUT.
//logic passed, failed;  // Returned from DUT to this module.  Passed must assert before
                       //   max cycles, without failed having asserted.  Failed can be undriven.
logic [31:0] cyc_cnt;

always_ff @(posedge clk) begin
   reset <= reset_async;
   cyc_cnt <= reset ? 32'b1 : cyc_cnt + 32'b1;
end

// Instantiate main module.
top top(.*);

endmodule
