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
   |tx
      @0
         $o_uart_tx = *o_uart_tx;
         $o_data[7:0] = *o_data;
         $r_busy = *r_busy;
         $lcl_data[7:0] = *lcl_data;
        
         
      @1
         //?!$r_busy_a0 
            //$lcl_data[1:1] = 1`b1 : $r_busy_a0;
         $o_uart_tx_a0;
      @2
         $lcl_data[2:2];
         $o_uart_tx_a1;
      @3
         $lcl_data[3:3];
         $o_uart_tx_a2;
      @4
         $lcl_data[4:4];
         $o_uart_tx_a3;
      @5
         $lcl_data[5:5];
         $o_uart_tx_a4;
      @6
         $lcl_data[6:6];
         $o_uart_tx_a5;
      @7
         $lcl_data[7:7];
         $o_uart_tx_a6;
      @8
         $lcl_data[0:0] = 1`b1;

   |rx
      @0
         $i_uart_rx = *i_uart_rx;
         $lcl_data = 1`b0;
         $i_data[7:0] = *i_data;
         
   

   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule
