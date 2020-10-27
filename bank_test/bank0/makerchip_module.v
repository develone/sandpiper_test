// The standard makerchip module definition. This should match what is generated by
// m4_makerchip_module, but without the m4_rand support (which might be TLV-version-specific).
module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);
   /* verilator lint_off WIDTH */
   /* verilator lint_off UNOPTFLAT */
