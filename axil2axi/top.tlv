\m4_TLV_version 1d: tl-x.org
\SV
/*
Copyright (c) 2018, Steve Hoover
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
m4_include_url(['https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/fundamentals_lib.tlv'])
m4_include_url(['https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflow_lib.tlv'])

/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilxbar.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilsafety.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axi2axi3.v'])
m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/skidbuffer.v'])
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
m4_define_hier(M4_RING_STOP, 4, 0)                
\TLV
   $reset = *reset;
   
   // DUT
   /M4_RING_STOP_HIER
      |axil
      
         @0
 
            m4_define(['M4_AXI_ADDR_WIDTH'], 4)
            m4_define(['M4_C_AXI_DATA_WIDTH'],32)
            m4_define(['M4_C_AXIS_DATA_WIDTH'],16)
         
            m4_define(['M4_OPT_LOWPOWER'],0)
            m4_define(['M4_OPT_OUTREG'],1)
            m4_define(['M4_OPT_PASSTHROUGH'],0)
            m4_define(['M4_DW'],8)
         
         
         
            $S_AXI_AWVALID = *S_AXI_AWVALID;
            $S_AXI_AWREADY = *S_AXI_AWREADY;
            $S_AXI_AWADDR[C_AXI_ADDR_WIDTH-1:0] = *S_AXI_AWADDR;
            $S_AXI_AWPROT[2:0] = *S_AXI_AWPROT;
         /*
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
         
         $i_valid = *i_valid;
         $o_ready = *o_ready;
         $i_data[DW-1:0] = *i_data;
         $o_valid = *o_valid;
         $i_ready = *i_ready;
         $o_data[DW-1:0] = *o_data;
         */
         @5
            *S_AXI_AWVALID = $S_AXI_AWVALID;         
            *S_AXI_AWREADY = $S_AXI_AWREADY;
         
            *S_AXI_AWADDR = $S_AXI_AWADDR[C_AXI_ADDR_WIDTH-1:0];
         /*
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
         
         
         *i_valid = $i_valid;
         *o_ready = $o_ready;
         *i_data = $i_data[DW-1:0];
         *o_valid = $o_valid;
         *i_ready = $i_ready;
         *o_data = $o_data[DW-1:0];
         
         */
   /*      
   /ring_stop[*]
      m4+arb2(/ring_stop, |ring_out, @4, |bypass, @1, |arb_out, @1, /trans)
      // FIFO2
      // To use BaseJump STL, this line:
      //m4+simple_bypass_fifo_v2(/ring_stop, |arb_out, @1, |fifo2_out, @1, 4, 100, /trans)        
      // Becomes:
      //----------------      
      |arb_out
         @1
            \SV_plus
               bsg_fifo_1r1w_small #(.width_p(100)) my_fifo(
                  *clk, $reset,
                  $avail, $$ready, /trans$ANY,
                  /ring_stop|fifo2_out<>0$$avail, /ring_stop|fifo2_out/trans<>0$$ANY, /ring_stop|fifo2_out<>0$accepted
               );
            $blocked = ! $ready;
      //----------------
   // Testbench
   m4+router_testbench(/top, /ring_stop, |stall0, @1, |fifo2_out, @1, /trans, /top<>0$reset)   
   */      
       
         

   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule
 