`line 2 "top.tlv" 0 //_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV
module dimmer(i_clk, o_led);
  input  wire i_clk;
  output wire o_led;

reg [26:0] counter;
always @(posedge i_clk)
  counter <= counter + 1'b1;

always @(posedge i_clk)
  o_led <= (counter[3:0] < counter[26:23]);



//_\SV
   endmodule
