\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
	genvar	k;
	generate for(k=0; k<W; k = k+1)
	begin : GEN_INOUT
		SB_IO #(.PULLUP(1'b0),
			.PIN_TYPE(6'b101001))
			theio(
				.OUTPUT_ENABLE(!i_dir),
				.PACKAGE_PIN(io_data[k]),
				.D_OUT_0(i_data[k]),
				.D_IN_0( o_data[k])
			);
	end endgenerate
   // =========================================
   // Welcome!  Try the tutorials via the menu.
   // =========================================

   // Default Makerchip TL-Verilog Code Template
   
   // Macro providing required top-level module definition, random
   // stimulus support, and Verilator config.
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // (Expanded in Nav-TLV pane.)
\TLV
   $in_dir = *in_dir
   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule
