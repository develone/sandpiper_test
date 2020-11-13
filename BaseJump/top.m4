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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//m4_include_url(['http://localhost:8080/wip/viz.tlv'])
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/fundamentals_lib.tlv"
// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflow_lib.tlv"

// Include BaseJump STL FIFO files.
/* verilator lint_off CMPCONST */
/* verilator lint_off WIDTH */
`include "./sv_url_inc/bsg_defines.v"  // From: "https://bitbucket.org/taylor-bsg/bsg_ip_cores/raw/0c76d71f1e06cf844f767448e4df376b112b831f/bsg_misc/bsg_defines.v"
`include "./sv_url_inc/bsg_fifo_tracker.v"  // From: "https://bitbucket.org/taylor-bsg/bsg_ip_cores/raw/0c76d71f1e06cf844f767448e4df376b112b831f/bsg_dataflow/bsg_fifo_tracker.v"
`include "./sv_url_inc/bsg_circular_ptr.v"  // From: "https://bitbucket.org/taylor-bsg/bsg_ip_cores/raw/0c76d71f1e06cf844f767448e4df376b112b831f/bsg_misc/bsg_circular_ptr.v"
`include "./sv_url_inc/bsg_fifo_1r1w_small.v"  // From: "https://bitbucket.org/taylor-bsg/bsg_ip_cores/raw/0c76d71f1e06cf844f767448e4df376b112b831f/bsg_dataflow/bsg_fifo_1r1w_small.v"
`include "./sv_url_inc/bsg_mem_1r1w.v"  // From: "https://bitbucket.org/taylor-bsg/bsg_ip_cores/raw/0c76d71f1e06cf844f767448e4df376b112b831f/bsg_mem/bsg_mem_1r1w.v"
`include "./sv_url_inc/bsg_mem_1r1w_synth.v"  // From: "https://bitbucket.org/taylor-bsg/bsg_ip_cores/raw/0c76d71f1e06cf844f767448e4df376b112b831f/bsg_mem/bsg_mem_1r1w_synth.v"
/* verilator lint_on WIDTH */
/* verilator lint_on CMPCONST */


module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */



\TLV
   $reset = *reset;
   
   
   // DUT
   
   /ring_stop[3:0]
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 511   // Instantiated from top.tlv, 64 as: m4+stall_pipeline(/ring_stop, |stall, 0, 3, /trans)
         
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 464   // Instantiated from top.tlv, 64 as: m4+stall_stage(/ring_stop, |stall['']m4_stage, @1, |stall['']m4_eval(m4_stage + 1), @1, /trans, )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 465 as: m4+flow_interface(/ring_stop, [' |stall0, @1'], [' |stall1, @1'], )
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |stall0, @1'], )
                  // Avail/Blocked Input:
                  |stall0
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 64 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall0, @1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |stall1, @1'])
                  // Avail/Blocked Output:
                  |stall1
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 64 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall1, @1))))
                     
                  \end_source
                  
               \end_source
            \end_source
            
            |stall0
               @1
                  $blocked = /ring_stop|stall1>>0$blocked;
            |stall1
               @1
                  // Propagate $reset to next stage with no delay (may create timing pressure,
                  //   but similar to reverse path for $blocked).
                  $reset = /ring_stop|stall0>>0$reset_in;
                  
                  $avail = $reset      ? 1'b0 :
                           >>1$blocked ? >>1$avail :
                                         /ring_stop|stall0>>1$avail;
                  ?$avail
                     /trans
                        $ANY = |stall1>>1$blocked ? >>1$ANY : /ring_stop|stall0/trans>>1$ANY;
            
         \end_source
         
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 464   // Instantiated from top.tlv, 64 as: m4+stall_stage(/ring_stop, |stall['']m4_stage, @1, |stall['']m4_eval(m4_stage + 1), @1, /trans, )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 465 as: m4+flow_interface(/ring_stop, [' |stall1, @1'], [' |stall2, @1'], )
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |stall1, @1'], )
                  // Avail/Blocked Input:
                  |stall1
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 64 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall1, @1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |stall2, @1'])
                  // Avail/Blocked Output:
                  |stall2
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 64 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall2, @1))))
                     
                  \end_source
                  
               \end_source
            \end_source
            
            |stall1
               @1
                  $blocked = /ring_stop|stall2>>0$blocked;
            |stall2
               @1
                  // Propagate $reset to next stage with no delay (may create timing pressure,
                  //   but similar to reverse path for $blocked).
                  $reset = /ring_stop|stall1>>0$reset_in;
                  
                  $avail = $reset      ? 1'b0 :
                           >>1$blocked ? >>1$avail :
                                         /ring_stop|stall1>>1$avail;
                  ?$avail
                     /trans
                        $ANY = |stall2>>1$blocked ? >>1$ANY : /ring_stop|stall1/trans>>1$ANY;
            
         \end_source
         
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 464   // Instantiated from top.tlv, 64 as: m4+stall_stage(/ring_stop, |stall['']m4_stage, @1, |stall['']m4_eval(m4_stage + 1), @1, /trans, )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 465 as: m4+flow_interface(/ring_stop, [' |stall2, @1'], [' |stall3, @1'], )
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |stall2, @1'], )
                  // Avail/Blocked Input:
                  |stall2
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 64 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall2, @1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |stall3, @1'])
                  // Avail/Blocked Output:
                  |stall3
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 64 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall3, @1))))
                     
                  \end_source
                  
               \end_source
            \end_source
            
            |stall2
               @1
                  $blocked = /ring_stop|stall3>>0$blocked;
            |stall3
               @1
                  // Propagate $reset to next stage with no delay (may create timing pressure,
                  //   but similar to reverse path for $blocked).
                  $reset = /ring_stop|stall2>>0$reset_in;
                  
                  $avail = $reset      ? 1'b0 :
                           >>1$blocked ? >>1$avail :
                                         /ring_stop|stall2>>1$avail;
                  ?$avail
                     /trans
                        $ANY = |stall3>>1$blocked ? >>1$ANY : /ring_stop|stall2/trans>>1$ANY;
            
         \end_source
         
         //
      \end_source
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 575   // Instantiated from top.tlv, 65 as: m4+flop_fifo_v2(/ring_stop, |stall3, @1, |bp0, @1, 4, /trans)
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 576 as: m4+flow_interface(/ring_stop, [' |stall3, @1'], [' |bp0, @1'], )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |stall3, @1'], )
               // Avail/Blocked Input:
               |stall3
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in = $reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 65 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall3, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |bp0, @1'])
               // Avail/Blocked Output:
               |bp0
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 65 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp0, @1))))
                  
               \end_source
               
            \end_source
         \end_source
         
         
         
         
         
         //   @0
         \SV_plus
            localparam bit [\$clog2((4)+1)-1:0] full_mark_25 = 4 - 0;
         // FIFO Instantiation
         // Hierarchy declarations
         |stall3
            /entry[(4)-1:0]
         |bp0
            /entry[(4)-1:0]
         |stall3
            @1
               $out_blocked = /ring_stop|bp0>>0$blocked;
               $blocked = >>1$full && $out_blocked;
               `BOGUS_USE($blocked)   // Not required to be consumed elsewhere.
               $would_bypass = >>1$empty;
               $bypass = $would_bypass && ! $out_blocked;
               $push = $accepted && ! $bypass;
               $grow   =   $accepted &&   $out_blocked;
               $shrink = ! $avail && ! $out_blocked && ! >>1$empty;
               $valid_count[\$clog2((4)+1)-1:0] = $reset ? '0
                                                           : >>1$valid_count + (
                                                                $grow   ? { {(\$clog2((4)+1)-1){1'b0}}, 1'b1} :
                                                                $shrink ? '1
                                                                        : '0
                                                             );
               // At least 2 valid entries.
               //$two_valid = | $ValidCount[m4_counter_width-1:1];
               // but logic depth minimized by taking advantage of prev count >= 4.
               $two_valid = | >>1$valid_count[\$clog2((4)+1)-1:2] || | $valid_count[2:1];
               // These are an optimization of the commented block below to operate on vectors, rather than bits.
               // TODO: Keep optimizing...
               {/entry[*]$$prev_entry_was_tail} = {/entry[*]>>1$reconstructed_is_tail\[2:0], /entry[3]>>1$reconstructed_is_tail} /* circular << */;
               {/entry[*]$$push} = {4{$push}} & /entry[*]$prev_entry_was_tail;
               /entry[*]
                  // Replaced with optimized versions above:
                  // $prev_entry_was_tail = /entry[(entry+(m4_depth)-1)%(m4_depth)]>>1$reconstructed_is_tail;
                  // $push = |stall3$push && $prev_entry_was_tail;
                  $valid = (>>1$reconstructed_valid && ! /ring_stop|bp0/entry>>0$pop) || $push;
                  $is_tail = |stall3$accepted ? $prev_entry_was_tail  // shift tail
                                                  : >>1$reconstructed_is_tail;  // retain tail
                  $state = |stall3$reset ? 1'b0
                                             : $valid && ! (|stall3$two_valid && $is_tail);
            @2
               $empty = ! $two_valid && ! $valid_count[0];
               $full = ($valid_count == full_mark_25);  // Could optimize for power-of-two depth.
            /entry[*]
               @2
                  $prev_entry_state = /entry[(entry+(4)-1)%(4)]$state;
                  $next_entry_state = /entry[(entry+1)%(4)]$state;
                  $reconstructed_is_tail = (  /ring_stop|stall3$two_valid && (!$state && $prev_entry_state)) ||
                                           (! /ring_stop|stall3$two_valid && (!$next_entry_state && $state)) ||
                                           (|stall3$empty && (entry == 0));  // need a tail when empty for push
                  $is_head = $state && ! $prev_entry_state;
                  $reconstructed_valid = $state || (/ring_stop|stall3$two_valid && $prev_entry_state);
            // Write data
         |stall3
            @1
               /entry[*]
                     //?$push
                     //   $aNY = |m4_in_pipe['']m4_trans$ANY;
                  /trans
                     $ANY = /entry$push ? /ring_stop|stall3/trans$ANY : >>1$ANY /* RETAIN */;
            // Read data
         |bp0
            @1
                  //$pop  = ! /m4_top|m4_in_pipe>>m4_align(m4_in_at + 1, m4_out_at)$empty && ! $blocked;
               /entry[*]
                  $is_head = /ring_stop|stall3/entry>>1$is_head;
                  $pop  = $is_head && ! |bp0$blocked;
                  /read_masked
                     /trans
                        $ANY = /entry$is_head ? /ring_stop|stall3/entry/trans>>1$ANY /* $aNY */ : '0;
                  /accum
                     /trans
                        $ANY = ((entry == 0) ? '0 : /entry[(entry+(4)-1)%(4)]/accum/trans$ANY) |
                                   /entry/read_masked/trans$ANY;
               /head
                  $avail = |bp0$avail;
                  ?$avail
                     /trans
                        $ANY = /ring_stop|bp0/entry[(4)-1]/accum/trans$ANY;
         // Bypass
         |bp0
            @1
               // Available output.  Sometimes it's necessary to know what would be coming to determined
               // if it's blocked.  This can be used externally in that case.
               /fifo_head
                  $avail = |bp0$avail;
                  ?$avail
                     /trans
                        $ANY = /ring_stop|stall3>>0$would_bypass
                                     ? /ring_stop|stall3/trans>>0$ANY
                                     : |bp0/head/trans$ANY;
               $avail = ! /ring_stop|stall3>>0$would_bypass || /ring_stop|stall3>>0$avail;
               $trans_valid = $avail && ! $blocked;
               ?$trans_valid
                  /trans
                     $ANY = |bp0/fifo_head/trans$ANY;
               
               // Deliver reset.
               $reset = /ring_stop|stall3>>0$reset_in;
      
         
         
         
         
         
         /* Alternate code for pointer indexing.  Replaces $ANY expression above.
      
         // Hierarchy
         |m4_in_pipe
            /entry2[(m4_depth)-1:0]
      
         // Head/Tail ptrs.
         |m4_in_pipe
            @m4_in_at
               >>1$WrPtr[m4_ptr_width-1:0] =
                   $reset       ? '0 :
                   $trans_valid ? ($WrPtr == (m4_depth - 1))
                                    ? '0
                                    : $WrPtr + {{(m4_ptr_width-1){1'b0}}, 1'b1} :
                                  $RETAIN;
         |m4_out_pipe
            @m4_out_at
               >>1$RdPtr[m4_ptr_width-1:0] =
                   /m4_top|m4_in_pipe>>m4_reverse_bypass_align$reset
                                ? '0 :
                   $trans_valid ? ($RdPtr == (m4_depth - 1))
                                    ? '0
                                    : $RdPtr + {{(m4_ptr_width-1){1'b0}}, 1'b1} :
                                  $RETAIN;
         // Write FIFO
         |m4_in_pipe
            @m4_in_at
               $dummy = '0;
               ?$trans_valid
                  // This doesn't work because SV complains for FIFOs in replicated context that
                  // there are multiple procedures that assign the signals.
                  // Array writes can be done in an SV module.
                  // The only long-term resolutions are support for module generation and use
                  // signals declared within for loops with cross-hierarchy references in SV.
                  // TODO: To make a simulation-efficient FIFO, use DesignWare.
                  {/entry2[$WrPtr]$$ANY} = $ANY;
         // Read FIFO
         |m4_out_pipe
            @m4_out_at
               /read2
                  $trans_valid = |m4_out_pipe$trans_valid;
                  ?$trans_valid
                     $ANY = /m4_top|m4_in_pipe/entry2[|m4_out_pipe$RdPtr]>>m4_reverse_bypass_align$ANY;
                  `BOGUS_USE($dummy)
               ?$trans_valid
                  $ANY = /read2$ANY;
         */
      
  
    
    
    
  

      \end_source
      //m4+simple_bypass_fifo_v2(/ring_stop, |stall3, @1, |bp0, @1, 4, 100, /trans)
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 416   // Instantiated from top.tlv, 67 as: m4+bp_pipeline(/ring_stop, |bp, 0, 3, /trans)
         
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 342   // Instantiated from top.tlv, 67 as: m4+bp_stage(/ring_stop, |bp['']m4_stage, @1, |bp['']m4_eval(m4_stage + 1), @1, /trans, 0, 0, , )
            
            
            
            
            
            
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 349 as: m4+flow_interface(/ring_stop, [' |bp0, @1'], [' |bp1, @1'], )
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |bp0, @1'], )
                  // Avail/Blocked Input:
                  |bp0
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 67 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp0, @1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |bp1, @1'])
                  // Avail/Blocked Output:
                  |bp1
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 67 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp1, @1))))
                     
                  \end_source
                  
               \end_source
            \end_source
            |bp1
               @0
                  $reset = /ring_stop|bp0>>1$reset_in;
                  
                  $avail = $reset ? 1'b0 :
                                    (>>1$avail && >>1$blocked) ||  // Recirc'ed or
                                    // Above is recomputation of $recirc to avoid a flop.
                                    // For SELF, its in the same stage, and is redundant computation.
                                    /ring_stop|bp0>>1$avail; // Incoming available
                  //$first_avail = $avail && ! >>1$blocked;  // Transaction is newly available.
               @0
                  ?$avail  // Physically, $first_avail && *reset_b for functional gating in
                           // place of recirculation.
                     /trans
                        $ANY =
                           |bp1>>1$recirc ? >>1$ANY
                                                : /ring_stop|bp0/trans>>1$ANY;
               @1
                  $recirc = $avail && $blocked;  // Available transaction that is blocked; must recirc.
            |bp0
               @1
                  $blocked = /ring_stop|bp1>>0$recirc;
                  // This trans is blocked (whether valid or not) if the next stage is recirculating.
            
            
            
            
            
            
         \end_source
         
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 342   // Instantiated from top.tlv, 67 as: m4+bp_stage(/ring_stop, |bp['']m4_stage, @1, |bp['']m4_eval(m4_stage + 1), @1, /trans, 0, 0, , )
            
            
            
            
            
            
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 349 as: m4+flow_interface(/ring_stop, [' |bp1, @1'], [' |bp2, @1'], )
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |bp1, @1'], )
                  // Avail/Blocked Input:
                  |bp1
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 67 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp1, @1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |bp2, @1'])
                  // Avail/Blocked Output:
                  |bp2
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 67 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp2, @1))))
                     
                  \end_source
                  
               \end_source
            \end_source
            |bp2
               @0
                  $reset = /ring_stop|bp1>>1$reset_in;
                  
                  $avail = $reset ? 1'b0 :
                                    (>>1$avail && >>1$blocked) ||  // Recirc'ed or
                                    // Above is recomputation of $recirc to avoid a flop.
                                    // For SELF, its in the same stage, and is redundant computation.
                                    /ring_stop|bp1>>1$avail; // Incoming available
                  //$first_avail = $avail && ! >>1$blocked;  // Transaction is newly available.
               @0
                  ?$avail  // Physically, $first_avail && *reset_b for functional gating in
                           // place of recirculation.
                     /trans
                        $ANY =
                           |bp2>>1$recirc ? >>1$ANY
                                                : /ring_stop|bp1/trans>>1$ANY;
               @1
                  $recirc = $avail && $blocked;  // Available transaction that is blocked; must recirc.
            |bp1
               @1
                  $blocked = /ring_stop|bp2>>0$recirc;
                  // This trans is blocked (whether valid or not) if the next stage is recirculating.
            
            
            
            
            
            
         \end_source
         
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 342   // Instantiated from top.tlv, 67 as: m4+bp_stage(/ring_stop, |bp['']m4_stage, @1, |bp['']m4_eval(m4_stage + 1), @1, /trans, 0, 0, , )
            
            
            
            
            
            
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 349 as: m4+flow_interface(/ring_stop, [' |bp2, @1'], [' |bp3, @1'], )
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |bp2, @1'], )
                  // Avail/Blocked Input:
                  |bp2
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 67 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp2, @1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |bp3, @1'])
                  // Avail/Blocked Output:
                  |bp3
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 67 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp3, @1))))
                     
                  \end_source
                  
               \end_source
            \end_source
            |bp3
               @0
                  $reset = /ring_stop|bp2>>1$reset_in;
                  
                  $avail = $reset ? 1'b0 :
                                    (>>1$avail && >>1$blocked) ||  // Recirc'ed or
                                    // Above is recomputation of $recirc to avoid a flop.
                                    // For SELF, its in the same stage, and is redundant computation.
                                    /ring_stop|bp2>>1$avail; // Incoming available
                  //$first_avail = $avail && ! >>1$blocked;  // Transaction is newly available.
               @0
                  ?$avail  // Physically, $first_avail && *reset_b for functional gating in
                           // place of recirculation.
                     /trans
                        $ANY =
                           |bp3>>1$recirc ? >>1$ANY
                                                : /ring_stop|bp2/trans>>1$ANY;
               @1
                  $recirc = $avail && $blocked;  // Available transaction that is blocked; must recirc.
            |bp2
               @1
                  $blocked = /ring_stop|bp3>>0$recirc;
                  // This trans is blocked (whether valid or not) if the next stage is recirculating.
            
            
            
            
            
            
         \end_source
         
      \end_source
      |bp3
         @1
            $local = /trans$dest == #ring_stop;
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 179   // Instantiated from top.tlv, 71 as: m4+opportunistic_flow(/ring_stop, |bp3, @1, |bypass, @1, $local, |ring_in, @1, /trans)
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 180 as: m4+flow_interface(/ring_stop, [' |bp3, @1'], [' |bypass, @1, |ring_in, @1'], )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |bp3, @1'], )
               // Avail/Blocked Input:
               |bp3
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in = $reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 71 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bp3, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |bypass, @1, |ring_in, @1'])
               // Avail/Blocked Output:
               |bypass
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 71 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |bypass, @1, |ring_in, @1))))
                  // Avail/Blocked Output:
                  |ring_in
                     @1
                        `BOGUS_USE($reset) // Output pipes must provide $reset.
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 71 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift(|ring_in,@1))))
                     
                  \end_source
                  
               \end_source
               
            \end_source
         \end_source
         
         |bypass
            @1
               $avail = /ring_stop|bp3>>0$avail &&
                        /ring_stop|bp3>>0$local;
               $reset = /ring_stop|bp3>>0$reset_in;
               ?$avail
                  /trans
                     $ANY = /ring_stop|bp3/trans>>0$ANY;
         |ring_in
            @1
               $avail = /ring_stop|bp3>>0$avail &&
                        (! /ring_stop|bp3>>0$local ||
                         /ring_stop|bypass>>0$blocked);
               $reset = /ring_stop|bp3>>0$reset_in;
               ?$avail
                  /trans
                     $ANY = /ring_stop|bp3/trans>>0$ANY;
         |bp3
            @1
               $blocked = (/ring_stop|ring_in>>0$blocked ||
                           ! $local) &&
                          /ring_stop|bypass>>0$blocked;
         
      \end_source
   \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 1017   // Instantiated from top.tlv, 72 as: m4+simple_ring(/ring_stop, |ring_in, @1, |ring_out, @1, /top<>0$reset, |rg, /trans)
      
      
      
      
      
      
      // Logic
      /ring_stop[*]
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 1026 as: m4+flow_interface(/ring_stop, [' |ring_in, @1'], [' |ring_out, @1'], /top<>0$reset)
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |ring_in, @1'], /top<>0$reset)
               // Avail/Blocked Input:
               |ring_in
                  @1
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in =  /top<>0$reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 72 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |ring_in, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |ring_out, @1'])
               // Avail/Blocked Output:
               |ring_out
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 72 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |ring_out, @1))))
                  
               \end_source
               
            \end_source
         \end_source
         |default
            @0
               \SV_plus
                  int prev_hop = (ring_stop + 4 - 1) % 4;
         |ring_in
            @1
               $blocked = /ring_stop|rg<>0$passed_on;
         |rg
            @1
               $passed_on = /ring_stop[prev_hop]|rg>>1$pass_on;
               $valid = ! /ring_stop|ring_in<>0$reset_in &&
                        ($passed_on || /ring_stop|ring_in<>0$avail);
               $pass_on = $valid && ! /ring_stop|ring_out>>0$trans_valid;
               $dest[1:0] =
                  $passed_on
                     ? /ring_stop[prev_hop]|rg>>1$dest
                     : /ring_stop|ring_in/trans<>0$dest;
            @1
               ?$valid
                  /trans
                     $ANY =
                       |rg$passed_on
                           ? /ring_stop[prev_hop]|rg/trans>>1$ANY
                           : /ring_stop|ring_in/trans<>0$ANY;
         |ring_out
            // Ring out
            @1
               $avail = /ring_stop|rg>>0$valid && (/ring_stop|rg>>0$dest == #ring_stop);
               //$blocked = 1'b0;
               $trans_valid = $avail; // && ! $blocked;
               $reset = /ring_stop|ring_in>>0$reset_in;
            ?$trans_valid
               @1
                  /trans
                     $ANY = /ring_stop|rg/trans>>0$ANY;
      
      
      
      
      
   \end_source
   
   /ring_stop[*]
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 150   // Instantiated from top.tlv, 75 as: m4+arb2(/ring_stop, |ring_out, @4, |bypass, @1, |arb_out, @1, /trans)
         \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 114   // Instantiated from top.tlv, 151 as: m4+flow_interface(/ring_stop, [' |ring_out, @4, |bypass, @1'], [' |arb_out, @1'], )
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 115 as: m4+flow_inputs(/ring_stop, [' |ring_out, @4, |bypass, @1'], )
               // Avail/Blocked Input:
               |ring_out
                  @4
                     $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                     $reset_in = $reset;
                     `BOGUS_USE($accepted $reset_in)
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 75 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |ring_out, @4, |bypass, @1))), m4_quote(m4_shift(_resets)))
                  // Avail/Blocked Input:
                  |bypass
                     @1
                        $accepted = $avail && ! $blocked;  // provided for optional upstream use.
                        $reset_in = $reset;
                        `BOGUS_USE($accepted $reset_in)
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 75 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift(|bypass,@1))), m4_quote(m4_shift(_resets)))
                     
                  \end_source
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |arb_out, @1'])
               // Avail/Blocked Output:
               |arb_out
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 75 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |arb_out, @1))))
                  
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
   
   
   //m4+trans()
   
   
   // Testbench
   \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 1305   // Instantiated from top.tlv, 97 as: m4+router_testbench(/top, /ring_stop, |stall0, @1, |fifo2_out, @1, /trans, /top<>0$reset)
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
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 97 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |fifo2_out, @1))), m4_quote(m4_shift(_resets)))
                  
               \end_source
               
            \end_source
            \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |stall0, @1'])
               // Avail/Blocked Output:
               |stall0
                  @1
                     `BOGUS_USE($reset) // Output pipes must provide $reset.
               \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 97 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |stall0, @1))))
                  
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
                     \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 119   // Instantiated from top.tlv, 97 as: m4+flow_inputs(/ring_stop, m4_quote(m4_shift(m4_shift( |receive1, @1))), m4_quote(m4_shift(_resets)))
                        
                     \end_source
                     
                  \end_source
                  \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 116 as: m4+flow_outputs(/ring_stop, [' |receive2, @1'])
                     // Avail/Blocked Output:
                     |receive2
                        @1
                           `BOGUS_USE($reset) // Output pipes must provide $reset.
                     \source /raw.githubusercontent.com/stevehoover/tlvflowlib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflowlib.tlv 129   // Instantiated from top.tlv, 97 as: m4+flow_outputs(/ring_stop, m4_quote(m4_shift(m4_shift( |receive2, @1))))
                        
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
   
   
   // Simulation control.
   *passed = & /top/tb/ring_stop[*]|passed>>1$passed;
   *failed = *cyc_cnt > 80;
\SV
endmodule 
