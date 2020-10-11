\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
module	ppio(i_dir, io_data, i_data, o_data);
   parameter	W=8;
	input			i_dir;
	inout	[(W-1):0]	io_data;
	input	[(W-1):0]	i_data;
	output	[(W-1):0]	o_data;
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
   //m4_makerchip_module   // (Expanded in Nav-TLV pane.)
\TLV
   //$reset = *reset;
   $i_dir = *i_dir;

   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule