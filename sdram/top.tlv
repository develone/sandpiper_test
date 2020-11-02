\m4_TLV_version 1d: tl-x.org
\SV

   // =========================================
   // Welcome!  Try the tutorials via the menu.
   // =========================================

   // Default Makerchip TL-Verilog Code Template
   
   // Macro providing required top-level module definition, random
   // stimulus support, and Verilator config.
   m4_makerchip_module   // (Expanded in Nav-TLV pane.)
\TLV
   $reset = *reset;
   
   |sdram
      @0
         localparam	NCA=9, NRA=13, AW=(NCA+NRA+2)-1, DW=32;
          
         //$need_refresh = *need_refresh;
         //$refresh_cmd = *refresh_cmd;
         
   
         
         /*$in_data[DW-1:0] = *in_data;
         //$out_data[DW-1:0] = *out_data;
         //$in_add[AW-1:0] = *in_add;
         //$bs[1:0] = *bs;
         //$dqm[1:0] = *dqm;
         //$cs = *cs;
         //$ras = *ras;
         //$cas = *cas;
         //$we = *we; */
 
         
         $refresh_clk[9:0] = reset ? 10'd25 : >>1$refresh_clk[9:0] - 1;
         
         /wr
            
         /rd
         /refresh
            //!cs && we
            
            
      @1
         //example
         //                                if true        true             false
         //assign  o_dbgwires_scope[2:0] = (o_ram_we_n)? i_ram_data[2:0] : o_ram_data[2:0];
         //                   if true   true                          false
         //$refresh_clk[9:0] = 10'd0 ? 10'd25 : >> $refresh_clk[9:0] : >> $refresh_clk[9:0]; 
          
      @5
         //*in_data = $in_data[DW-1:0];
         //*out_data = $out_data[DW-1:0];
         //*in_add = $in_add[AW-1];
         //*we = $we;
         //*bs[1:0] = $bs[1:0];
         //*cas = $cas;
         //*ras = $ras;
         //*dqm[1:0] = $dqm[1:0];
         //*cs = $cs;
         //*need_refresh = $need_refresh;
         //*refresh_cmd = $refresh_cmd;
         /* verilator lint_off IMPLICIT */
         *refresh_clk = $refresh_clk[9:0];
         /* verilator lint_off IMPLICIT */
         
         
   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule