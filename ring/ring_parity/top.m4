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
module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */

\TLV
   
   $reset = *reset;
   
      // Defines constants for /port[3:0].
   
   
   //-------------
   // DUT
   // ------------
   
   // DUT Flow (FIFO and ring)
   /port[3:0]   // (becomes /port[3:0])
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 774   // Instantiated from top.tlv, 50 as: m4+simple_bypass_fifo_v2(/port, |fifo_in, @1, |ring_in, @1, 4, 100, /trans)
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 775 as: m4+flow_interface(/port, [' |fifo_in, @1'], [' |ring_in, @1'], )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/port, [' |fifo_in, @1'], )
               // Avail/Blocked Input:
               |fifo_in
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in = $reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 50 as: m4+flow_inputs(/port, m4_quote(m4_shift(m4_shift( |fifo_in, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/port, [' |ring_in, @1'])
               // Avail/Blocked Output:
               |ring_in
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 50 as: m4+flow_outputs(/port, m4_quote(m4_shift(m4_shift( |ring_in, @1))))
                  
               \end_source
               
            \end_source
         \end_source
         |fifo_in
            /trans
            @1
               $out_blocked = /port|ring_in>>0$blocked;
               $blocked = (/port|fifo_in/fifo>>0$cnt >= 4) && $out_blocked;
               /fifo
                  simple_bypass_fifo #(.WIDTH(100), .DEPTH(4))
                     fifo(.clk(clk), .reset(|fifo_in$reset_in),
                          .push(|fifo_in$accepted),
                          .data_in(|fifo_in/trans$ANY),
                          .pop(|fifo_in$accepted),
                          .data_out(/port|ring_in/trans>>0$$ANY),
                          .cnt($$cnt[\$clog2(4)-1:0]));
         |ring_in
            /trans
            @1
               $avail = /port|fifo_in/fifo>>0$cnt != '0 || /port|fifo_in>>0$avail;
               $reset = /port|fifo_in>>0$reset_in;
      \end_source
   \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 1017   // Instantiated from top.tlv, 51 as: m4+simple_ring(/port, |ring_in, @1, |ring_out, @1, /top<>0$reset, |rg, /trans)
      
      
      
      
      
      
      // Logic
      /port[*]
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 1026 as: m4+flow_interface(/port, [' |ring_in, @1'], [' |ring_out, @1'], /top<>0$reset)
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/port, [' |ring_in, @1'], /top<>0$reset)
               // Avail/Blocked Input:
               |ring_in
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in =  /top<>0$reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 51 as: m4+flow_inputs(/port, m4_quote(m4_shift(m4_shift( |ring_in, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/port, [' |ring_out, @1'])
               // Avail/Blocked Output:
               |ring_out
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 51 as: m4+flow_outputs(/port, m4_quote(m4_shift(m4_shift( |ring_out, @1))))
                  
               \end_source
               
            \end_source
         \end_source
         |default
            @0
               \SV_plus
                  int prev_hop = (port + 4 - 1) % 4;
         |ring_in
            @1
               $blocked = /port|rg<>0$passed_on;
         |rg
            @1
               $passed_on = /port[prev_hop]|rg>>1$pass_on;
               $valid = ! /port|ring_in<>0$reset_in &&
                        ($passed_on || /port|ring_in<>0$avail);
               $pass_on = $valid && ! /port|ring_out>>0$trans_valid;
               $dest[1:0] =
                  $passed_on
                     ? /port[prev_hop]|rg>>1$dest
                     : /port|ring_in/trans<>0$dest;
            @1
               ?$valid
                  /trans
                     $ANY =
                       |rg$passed_on
                           ? /port[prev_hop]|rg/trans>>1$ANY
                           : /port|ring_in/trans<>0$ANY;
         |ring_out
            // Ring out
            @1
               $avail = /port|rg>>0$valid && (/port|rg>>0$dest == #port);
               //$blocked = 1'b0;
               $trans_valid = $avail; // && ! $blocked;
               $reset = /port|ring_in>>0$reset_in;
            ?$trans_valid
               @1
                  /trans
                     $ANY = /port|rg/trans>>0$ANY;
      
      
      
      
      
   \end_source
   
   // Transaction logic.
   /port[*]
      |fifo_in
         @1
            ?$accepted
               /trans
                  $data[7:0] = *cyc_cnt[7:0];
                  // Compute parity
                  $parity = ^ {$data, $dest};
      
      |ring_out
         @2
            ?$trans_valid
               /trans
                  `BOGUS_USE($data)
               
                  // Check parity.
                  $parity_error = $parity != ^ {$data, $dest};

   //--------------
   // Testbench
   \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 1305   // Instantiated from top.tlv, 74 as: m4+router_testbench(/top, /port, |fifo_in, @1, |ring_out, @1, /trans, /top<>0$reset)
        // Otherwise we can have a cyclic reset loop through flow.
      /port[*]
         // Define flow interface. Note that router ins are tb outs and outs are ins.
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 1309 as: m4+flow_interface(/port, [' |ring_out, @1'], [' |fifo_in, @1'], /top<>0$reset)
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/port, [' |ring_out, @1'], /top<>0$reset)
               // Avail/Blocked Input:
               |ring_out
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in =  /top<>0$reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 74 as: m4+flow_inputs(/port, m4_quote(m4_shift(m4_shift( |ring_out, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/port, [' |fifo_in, @1'])
               // Avail/Blocked Output:
               |fifo_in
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 74 as: m4+flow_outputs(/port, m4_quote(m4_shift(m4_shift( |fifo_in, @1))))
                  
               \end_source
               
            \end_source
         \end_source
      
      
      
   
      /tb
         |count
            @1
               $CycCount[15:0] <= /top/port[0]|fifo_in>>1$reset
                                     ? 16'b0 :
                                       $CycCount + 1;
               \SV_plus
                  always_ff @(posedge clk) begin
                     \$display("Cycle: %0d", $CycCount);
                  end
         /port[3:0]
            // STIMULUS
            |send
               @1
                  // Generate a transaction to inject sometimes (if needed)
                  $reset = /port|receive2>>0$reset;
                  $valid_in = /tb|count<>0$CycCount == 3;
                  ?$valid_in
                     /gen_trans
                        $cyc_cnt[15:0] = /tb|count<>0$CycCount;
                        $response_debug = 1'b0;  // Not a response (for debug)
                        $sender[1:0] = #port;
                        //m4_rand($size, M4_PACKET_SIZE-1, 0, #m4_port) // unused
                        $dest_tmp[1:0] = *RW_rand_vect[(0 + (port)) % 257 +: 2];
                        $dest[1:0] = $dest_tmp % 4;
                        //$dest[M4_['']M4_PORT['']_INDEX_RANGE] = #m4_port;
                        //$packet_valid = #m4_port == 0 ? 1'b1 : 1'b0; // valid for only first port - unused
                  $avail = $valid_in || /port|receive2>>0$valid_request;
                  ?$avail
                     /trans_out
                        // Loopback requests as responses or use gen_trans.
                        $ANY = /port|receive2>>0$valid_request
                                    ? /port|receive2/trans>>0$ANY :
                                      |send/gen_trans$ANY;
                        
                        \SV_plus
                           always_ff @(posedge clk) begin
                              if (! |send$reset && ! *reset && /top/port|fifo_in<>0$accepted) begin
                                 \$display("\|send[%0d]", #port);
                                 \$display("Sender: %0d, Orig. Cyc: %0d, Dest: %0d, Resp: %0d", $sender, $cyc_cnt, $dest, $response_debug);
                              end
                           end
            // Hook router out to |receive1 and determine transaction response routing (within the transaction).
            |receive1
               @1
                  $avail = /top/port|ring_out<>0$avail;
                  $reset = /top/port|ring_out<>0$reset_in;
                  ?$accepted
                     /trans
                        $response_debug = 1'b1; // Turn this around as a response.
                        $request = $sender != #port;  // Arrived as request?
                        $response = $sender == #port; // Arrived as response?
                        $ANY = /top/port|ring_out/trans<>0$ANY;
                        $dest[1:0] = $request ? $sender : $dest;
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 342   // Instantiated from top.tlv, 1368 as: m4+bp_stage(/port, |receive1, @1, |receive2, @1, /trans)
               
               
               
               
               
               
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 349 as: m4+flow_interface(/port, [' |receive1, @1'], [' |receive2, @1'], )
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/port, [' |receive1, @1'], )
                     // Avail/Blocked Input:
                     |receive1
                        @1
                           $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                           $reset_in = $reset;
                           `BOGUS_USE($accepted $reset_in)
                     \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 74 as: m4+flow_inputs(/port, m4_quote(m4_shift(m4_shift( |receive1, @1))), m4_quote(m4_shift(_resets)))
                        
                     \end_source
                     
                  \end_source
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/port, [' |receive2, @1'])
                     // Avail/Blocked Output:
                     |receive2
                        @1
                           `BOGUS_USE($reset) // Output pipes must provide $reset.
                     \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 74 as: m4+flow_outputs(/port, m4_quote(m4_shift(m4_shift( |receive2, @1))))
                        
                     \end_source
                     
                  \end_source
               \end_source
               |receive2
                  @0
                     $reset = /port|receive1>>1$reset_in;
                     
                     $avail = $reset ? 1'b0 :
                                       (>>1$avail && >>1$blocked) ||  // Recirc'ed or
                                       // Above is recomputation of $recirc to avoid a flop.
                                       // For SELF, its in the same stage, and is redundant computation.
                                       /port|receive1>>1$avail; // Incoming available
                     //$first_avail = $avail && ! >>1$blocked;  // Transaction is newly available.
                  @0
                     ?$avail  // Physically, $first_avail && *reset_b for functional gating in
                              // place of recirculation.
                        /trans
                           $ANY =
                              |receive2>>1$recirc ? >>1$ANY
                                                   : /port|receive1/trans>>1$ANY;
                  @1
                     $recirc = $avail && $blocked;  // Available transaction that is blocked; must recirc.
               |receive1
                  @1
                     $blocked = /port|receive2>>0$recirc;
                     // This trans is blocked (whether valid or not) if the next stage is recirculating.
               
               
               
               
               
               
            \end_source
            // A one-cycle backpressured stage to avoid 0-cycle loopback.
            |receive2
               @1
                  $valid_request = $accepted && /trans$request;
                  $valid_response = $accepted && /trans$response;
                  // Block requests that cannot loopback a response .
                  $blocked = $valid_request && /top/port|fifo_in>>0$blocked;
                  $accepted = $avail && ! $blocked;
                  $generated_request =   /top/port|fifo_in>>0$accepted &&
                                       ! /top/port|fifo_in/trans>>0$response_debug;
                  $OutstandingPackets[16-1:0] <=
                       $reset ? '0 :
                         ($OutstandingPackets +
                          ($generated_request ? 16'b1 : '0) -
                          ($valid_response ? 16'b1 : '0)
                         );
            |passed  // Aligned to |receive2, but given a new pipeline name to provide a cleaner interface for this $passed output.
               @1
                  $passed = ! /port|receive2<>0$reset && /port|receive2<>0$OutstandingPackets == '0 && /tb|count>>0$CycCount > 12;
      // Connect with DUT.
      /port[3:0]
         |fifo_in
            @1
               $avail = ! $reset && /top/tb/port|send<>0$avail;
               ?$avail
                  /trans
                     $ANY = /top/tb/port|send/trans_out<>0$ANY;
               $reset = /top/tb/port|receive2>>0$reset;
         |ring_out
            @1
               $blocked = /top/tb/port|receive1<>0$blocked;
            /trans
      
      
   \end_source
   
   
   *passed = | /top/tb/port[*]|passed>>1$passed;
   *failed = *cyc_cnt > 20;
   
\SV
endmodule 
