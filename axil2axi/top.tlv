\m4_TLV_version 1d: tl-x.org
\SV
/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilxbar.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilsafety.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axi2axi3.v'])
m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axil2axis.v'])
/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */               
   // =========================================
   // Welcome!  Try the tutorials via the menu.
   // =========================================

   // Default Makerchip TL-Verilog Code Template
   
   // Macro providing required top-level module definition, random
   // stimulus support, and Verilator config.
   m4_makerchip_module   // (Expanded in Nav-TLV pane.)
\TLV
   |axil
      
      @0
 
         m4_define(['M4_AXI_ADDR_WIDTH'], 4)
         m4_define(['M4_C_AXI_DATA_WIDTH'],32)
         m4_define(['M4_C_AXIS_DATA_WIDTH'],16)
         
         $reset = *reset;
         $S_AXI_AWVALID = *S_AXI_AWVALID;
         $S_AXI_AWREADY = *S_AXI_AWREADY;
         $S_AXI_AWADDR[C_AXI_ADDR_WIDTH-1:0] = *S_AXI_AWADDR;
         $S_AXI_AWPROT[2:0] = *S_AXI_AWPROT;
         
         $S_AXI_WVALID = *S_AXI_WVALID;
         $S_AXI_WREADY = *S_AXI_WREADY;
         $S_AXI_WDATA[C_AXI_DATA_WIDTH-1:0] = *S_AXI_WDATA
         $S_AXI_WSTRB[C_AXI_DATA_WIDTH/8-1:0] = *S_AXI_WSTRB
         $S_AXI_RVALID = *S_AXI_RVALID;
         $S_AXI_RREADY = *S_AXI_RREADY;
         $S_AXI_RDATA[C_AXI_DATA_WIDTH-1:0] = *S_AXI_RDATA;
         $M_AXIS_TREADY = *M_AXIS_TREADY;
         $M_AXIS_TDATA[C_AXI_DATA_WIDTH-1:0] = *M_AXIS_TDATA;
         

         
         $M_AXIS_TVALID = *M_AXIS_TVALID;
         
         
      @5
         *S_AXI_AWVALID = $S_AXI_AWVALID;         
         *S_AXI_AWREADY = $S_AXI_AWREADY;
         
         *S_AXI_AWADDR = $S_AXI_AWADDR[C_AXI_ADDR_WIDTH-1:0];
         *S_AXI_AWPROT = $S_AXI_AWPROT[2:0];
         *S_AXI_WVALID = $S_AXI_WVALID;
         *S_AXI_WREADY = $S_AXI_WREADY;
         *S_AXI_WDATA = $S_AXI_WDATA[C_AXI_DATA_WIDTH-1:0];
         *S_AXI_WSTRB = $S_AXI_WSTRB[C_AXI_DATA_WIDTH/8-1:0];
         *S_AXI_RVALID = $S_AXI_RVALID;
         *S_AXI_RREADY = $S_AXI_RREADY;
         *S_AXI_RDATA = $S_AXI_RDATA[C_AXI_DATA_WIDTH-1:0];
         *M_AXIS_TREADY = $M_AXIS_TREADY;
         *M_AXIS_TDATA = $M_AXIS_TDATA[C_AXI_DATA_WIDTH-1:0];

         
         
         
         *M_AXIS_TVALID = $M_AXIS_TVALID;
         
         
         
         
         
         
         
         
         
       
         

   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule
