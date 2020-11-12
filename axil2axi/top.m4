\TLV_version [\source top.tlv] 1d: tl-x.org
\SV
/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilxbar.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilsafety.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axi2axi3.v'])
// Included URL: "https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axil2axis.v"
/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */               
   // =========================================
   // Welcome!  Try the tutorials via the menu.
   // =========================================

   // Default Makerchip TL-Verilog Code Template
   
   // Macro providing required top-level module definition, random
   // stimulus support, and Verilator config.
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // (Expanded in Nav-TLV pane.)
\TLV
   |axil
      
      @0
 
         
         
         
         
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
