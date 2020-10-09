\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
module	blinky(i_clk, i_btn, o_ledg, o_ledr);
	parameter	CBITS = 27;
	input			i_clk;
	input		[1:0]	i_btn;
	output	wire	[1:0]	o_ledg;
	output	wire		o_ledr;

	// A counter--just to set things off and get things blinking.
	reg [(CBITS-1):0]	ctr;
	initial ctr = 0;
	always @(posedge i_clk)
		ctr <= ctr + 1'b1;

	// LED 0 ... Only turns on when button #1 is pressed.
	assign	o_ledg[0] = ((!ctr[CBITS-1]) & (i_btn[1]==1));

	// LED 1 ... always blinking, unless button #0 is pressed.
	assign	o_ledg[1] = (( ctr[CBITS-1]) & (i_btn[0]==0));

	// RED LED ... always ever blinks whenever either button is pressed
	assign	o_ledr = (i_btn[0])|(i_btn[1]);

\SV
   endmodule
