\m4_TLV_version 1d: tl-x.org
\SV
module ha ( input   a, b,
            output  sum, cout);

  assign sum  = a ^ b;
  assign cout = a & b;
endmodule

module my_design
	#(parameter N=4)
		(	input [N-1:0] a, b,
			output [N-1:0] sum, cout);

	// Declare a temporary loop variable to be used during
	// generation and won't be available during simulation
	genvar i;

	// Generate for loop to instantiate N times
	generate
		for (i = 0; i < N; i = i + 1) begin
          ha u0 (a[i], b[i], sum[i], cout[i]);
		end
	endgenerate
endmodule

module tb;
	parameter N = 2;
  reg  [N-1:0] a, b;
  wire [N-1:0] sum, cout;

  // Instantiate top level design with N=2 so that it will have 2
  // separate instances of half adders and both are given two separate
  // inputs
  my_design #(.N(N)) md( .a(a), .b(b), .sum(sum), .cout(cout));

  initial begin
    a <= 0;
    b <= 0;

    //$monitor ("a=0x%0h b=0x%0h sum=0x%0h cout=0x%0h", a, b, sum, cout);

    //#10 a <= 'h2;
    		b <= 'h3;
    //#20 b <= 'h4;
    //#10 a <= 'h5;
  end
endmodule
   // =========================================
   // Welcome!  Try the tutorials via the menu.
   // =========================================

   // Default Makerchip TL-Verilog Code Template
   
   // Macro providing required top-level module definition, random
   // stimulus support, and Verilator config.
   m4_makerchip_module   // (Expanded in Nav-TLV pane.)
\TLV
   $reset = *reset;
   
   |pipe
      @0
         /* verilator lint_off IMPLICIT */ 
         $a = a ;
         $b = b;
         //$c = c;
         /* verilator lint_off IMPLICIT */  
      @5
         *a = $a;
         *b = $b;
         //*c= $c;

   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule
