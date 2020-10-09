\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
module dimmer(i_clk, o_led);
  input  wire i_clk;
  output wire o_led;

reg [26:0] counter;
always @(posedge i_clk)
  counter <= counter + 1'b1;

always @(posedge i_clk)
  o_led <= (counter[3:0] < counter[26:23]);



\SV
   endmodule
