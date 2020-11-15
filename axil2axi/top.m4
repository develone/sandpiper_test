\TLV_version [\source top.tlv] 1d: tl-x.org
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
// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/fundamentals_lib.tlv"
// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflow_lib.tlv"

/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilxbar.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axilsafety.v'])
//m4_include_url(['https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/axi2axi3.v'])
// Included URL: "https://raw.githubusercontent.com/develone/sandpiper_test/master/axil2axi/rtl/skidbuffer.v"
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
   $reset = *reset;
   
   // DUT
   /ring_stop[3:0]
      |axil
      
         @0
 
            
            
            
         
            
            
            
            
         
         
         
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
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 150   // Instantiated from top.tlv, 133 as: m4+arb2(/ring_stop, |ring_out, @4, |bypass, @1, |arb_out, @1, /trans)
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 151 as: m4+flow_interface(/ring_stop, [' |ring_out, @4, |bypass, @1'], [' |arb_out, @1'], )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |ring_out, @4, |bypass, @1'], )
               // Avail/Blocked Input:
               |ring_out
                  @4
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in = $reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 133 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |ring_out, @4, |bypass, @1))), m4_quote(m4_shift(_resets)))
                  // Avail/Blocked Input:
                  |bypass
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 133 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift(|bypass,@1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |arb_out, @1'])
               // Avail/Blocked Output:
               |arb_out
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 133 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |arb_out, @1))))
                  
               \end_source
               
            \end_source
         \end_source
         
         // In1 is blocked if output is blocked.
         |ring_out
            @4
               $blocked = /ring_stop|arb_out>>-3$blocked;
         // In2 is blocked if output is blocked or in1 is available.
         |bypass
            @1
               $blocked = /ring_stop|arb_out>>0$blocked ||
                          /ring_stop|ring_out>>3$avail;
         // Output comes from in1 if available, otherwise, in2.
         |arb_out
            @1
               $reset = /ring_stop|ring_out>>3$reset_in;
               // Output is available if either input is available.
               $avail = /ring_stop|ring_out>>3$avail ||
                        /ring_stop|bypass>>0$avail;
               ?$avail
                  /trans
                     $ANY = /ring_stop|ring_out>>3$avail ? /ring_stop|ring_out/trans>>3$ANY :
                                                                                /ring_stop|bypass/trans>>0$ANY;
         
      \end_source
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
   \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 1305   // Instantiated from top.tlv, 150 as: m4+router_testbench(/top, /ring_stop, |stall0, @1, |fifo2_out, @1, /trans, /top<>0$reset)   
        // Otherwise we can have a cyclic reset loop through flow.
      /ring_stop[*]
         // Define flow interface. Note that router ins are tb outs and outs are ins.
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 1309 as: m4+flow_interface(/ring_stop, [' |fifo2_out, @1'], [' |stall0, @1'], /top<>0$reset)
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |fifo2_out, @1'], /top<>0$reset)
               // Avail/Blocked Input:
               |fifo2_out
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in =  /top<>0$reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 150 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |fifo2_out, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |stall0, @1'])
               // Avail/Blocked Output:
               |stall0
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 150 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall0, @1))))
                  
               \end_source
               
            \end_source
         \end_source
      
      
      
   
      /tb
         |count
            @1
               $CycCount[15:0] <= /top/ring_stop[0]|stall0>>1$reset
                                     ? 16'b0 :
                                       $CycCount + 1;
               \SV_plus
                  always_ff @(posedge clk) begin
                     \$display("Cycle: %0d", $CycCount);
                  end
         /ring_stop[3:0]
            // STIMULUS
            |send
               @1
                  // Generate a transaction to inject sometimes (if needed)
                  $reset = /ring_stop|receive2>>0$reset;
                  $valid_in = /tb|count<>0$CycCount == 3;
                  ?$valid_in
                     /gen_trans
                        $cyc_cnt[15:0] = /tb|count<>0$CycCount;
                        $response_debug = 1'b0;  // Not a response (for debug)
                        $sender[1:0] = #ring_stop;
                        //m4_rand($size, M4_PACKET_SIZE-1, 0, #m4_port) // unused
                        $dest_tmp[1:0] = *RW_rand_vect[(0 + (ring_stop)) % 257 +: 2];
                        $dest[1:0] = $dest_tmp % 4;
                        //$dest[M4_['']M4_PORT['']_INDEX_RANGE] = #m4_port;
                        //$packet_valid = #m4_port == 0 ? 1'b1 : 1'b0; // valid for only first port - unused
                  $avail = $valid_in || /ring_stop|receive2>>0$valid_request;
                  ?$avail
                     /trans_out
                        // Loopback requests as responses or use gen_trans.
                        $ANY = /ring_stop|receive2>>0$valid_request
                                    ? /ring_stop|receive2/trans>>0$ANY :
                                      |send/gen_trans$ANY;
                        
                        \SV_plus
                           always_ff @(posedge clk) begin
                              if (! |send$reset && ! *reset && /top/ring_stop|stall0<>0$accepted) begin
                                 \$display("\|send[%0d]", #ring_stop);
                                 \$display("Sender: %0d, Orig. Cyc: %0d, Dest: %0d, Resp: %0d", $sender, $cyc_cnt, $dest, $response_debug);
                              end
                           end
            // Hook router out to |receive1 and determine transaction response routing (within the transaction).
            |receive1
               @1
                  $avail = /top/ring_stop|fifo2_out<>0$avail;
                  $reset = /top/ring_stop|fifo2_out<>0$reset_in;
                  ?$accepted
                     /trans
                        $response_debug = 1'b1; // Turn this around as a response.
                        $request = $sender != #ring_stop;  // Arrived as request?
                        $response = $sender == #ring_stop; // Arrived as response?
                        $ANY = /top/ring_stop|fifo2_out/trans<>0$ANY;
                        $dest[1:0] = $request ? $sender : $dest;
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 342   // Instantiated from top.tlv, 1368 as: m4+bp_stage(/ring_stop, |receive1, @1, |receive2, @1, /trans)
               
               
               
               
               
               
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 349 as: m4+flow_interface(/ring_stop, [' |receive1, @1'], [' |receive2, @1'], )
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |receive1, @1'], )
                     // Avail/Blocked Input:
                     |receive1
                        @1
                           $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                           $reset_in = $reset;
                           `BOGUS_USE($accepted $reset_in)
                     \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 150 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |receive1, @1))), m4_quote(m4_shift(_resets)))
                        
                     \end_source
                     
                  \end_source
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |receive2, @1'])
                     // Avail/Blocked Output:
                     |receive2
                        @1
                           `BOGUS_USE($reset) // Output pipes must provide $reset.
                     \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 150 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |receive2, @1))))
                        
                     \end_source
                     
                  \end_source
               \end_source
               |receive2
                  @0
                     $reset = /ring_stop|receive1>>1$reset_in;
                     
                     $avail = $reset ? 1'b0 :
                                       (>>1$avail && >>1$blocked) ||  // Recirc'ed or
                                       // Above is recomputation of $recirc to avoid a flop.
                                       // For SELF, its in the same stage, and is redundant computation.
                                       /ring_stop|receive1>>1$avail; // Incoming available
                     //$first_avail = $avail && ! >>1$blocked;  // Transaction is newly available.
                  @0
                     ?$avail  // Physically, $first_avail && *reset_b for functional gating in
                              // place of recirculation.
                        /trans
                           $ANY =
                              |receive2>>1$recirc ? >>1$ANY
                                                   : /ring_stop|receive1/trans>>1$ANY;
                  @1
                     $recirc = $avail && $blocked;  // Available transaction that is blocked; must recirc.
               |receive1
                  @1
                     $blocked = /ring_stop|receive2>>0$recirc;
                     // This trans is blocked (whether valid or not) if the next stage is recirculating.
               
               
               
               
               
               
            \end_source
            // A one-cycle backpressured stage to avoid 0-cycle loopback.
            |receive2
               @1
                  $valid_request = $accepted && /trans$request;
                  $valid_response = $accepted && /trans$response;
                  // Block requests that cannot loopback a response .
                  $blocked = $valid_request && /top/ring_stop|stall0>>0$blocked;
                  $accepted = $avail && ! $blocked;
                  $generated_request =   /top/ring_stop|stall0>>0$accepted &&
                                       ! /top/ring_stop|stall0/trans>>0$response_debug;
                  $OutstandingPackets[16-1:0] <=
                       $reset ? '0 :
                         ($OutstandingPackets +
                          ($generated_request ? 16'b1 : '0) -
                          ($valid_response ? 16'b1 : '0)
                         );
            |passed  // Aligned to |receive2, but given a new pipeline name to provide a cleaner interface for this $passed output.
               @1
                  $passed = ! /ring_stop|receive2<>0$reset && /ring_stop|receive2<>0$OutstandingPackets == '0 && /tb|count>>0$CycCount > 12;
      // Connect with DUT.
      /ring_stop[3:0]
         |stall0
            @1
               $avail = ! $reset && /top/tb/ring_stop|send<>0$avail;
               ?$avail
                  /trans
                     $ANY = /top/tb/ring_stop|send/trans_out<>0$ANY;
               $reset = /top/tb/ring_stop|receive2>>0$reset;
         |fifo2_out
            @1
               $blocked = /top/tb/ring_stop|receive1<>0$blocked;
            /trans
      
      
   \end_source   
   */      
       
         

   //...

   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 40;
   *failed = 1'b0;
\SV
   endmodule
 
