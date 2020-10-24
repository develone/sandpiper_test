`line 2 "top.tlv" 0 //_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV

module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/221c93b3603bb4c72d3b024b3ec410e48f60e199/arrays.tlv"

`include "top_gen.sv" //_\TLV
   //$reset = *reset;

   //--------------------------------------------------
   // Stimulus
   //
   
   // Explicit random inputs.
   
   
   //_|wr
      //_@0
         // The array hierarchy (to declare ranges)
         for (entry = 0; entry <= 3; entry++) begin : L1_WR_Entry //_/entry
            // Must be declared before reference (currently).
            end //_/trans
         
         assign WR_wr_en_a0[0:0] = RW_rand_vect[(0 + (0)) % 257 +: 1];
         //_?$wr_en
            assign WR_entry_a0[1:0] = RW_rand_vect[(124 + (0)) % 257 +: 2];  // entry to write into
            //_/trans  // data to write (anything in this scope is available to pass through array, if used)
               assign WR_Trans_data1_a0[7:0] = RW_rand_vect[(248 + (0)) % 257 +: 8];
               assign WR_Trans_data2_a0[3:0] = RW_rand_vect[(115 + (0)) % 257 +: 4];
   //_|rd
      //_@1
         assign RD_rd_en_a1[0:0] = RW_rand_vect[(239 + (0)) % 257 +: 1];
         //_?$rd_en
            assign RD_entry_a1[1:0] = RW_rand_vect[(106 + (0)) % 257 +: 2];  // entry to read from
            
            // Pull signals through array, simply by using them in this scope.
            //_/trans
               `BOGUS_USE(RD_Trans_data1_a1 RD_Trans_data2_a1)
         
   
   //----------------------------------------------------
   // The array

   `line 37 "/raw.githubusercontent.com/stevehoover/tlvflowlib/221c93b3603bb4c72d3b024b3ec410e48f60e199/arrays.tlv" 1   // Instantiated from top.tlv, 44 as: m4+array1r1w(/top, /entry, |wr, @0, $wr_en, $entry, |rd, @1, $rd_en, $entry, $ANY, /trans)
      // Write Pipeline
      // The array entries hierarchy (needs a definition to define range, and currently, /trans declaration required before reference).
      for (entry = 0; entry <= 3; entry++) begin : L1_Entry //_/entry
         end //_/trans
            
      // Write transaction to cache
      // (TLV assignment syntax prohibits assignment outside of it's own scope, but \SV_plus does not.)
      /*SV_plus*/
         always_comb
            if (WR_wr_en_a0)
               {Entry_Trans_data1_a0[WR_entry_a0][7:0], Entry_Trans_data2_a0[WR_entry_a0][3:0]} = {WR_Trans_data1_a0, WR_Trans_data2_a0};
      
      // Read Pipeline
      //_|rd
         //_@1
            // Read transaction from cache.
            //_?$rd_en
               //_/trans
                  assign {RD_Trans_data1_a1[7:0], RD_Trans_data2_a1[3:0]} = {Entry_Trans_data1_a1[RD_entry_a1], Entry_Trans_data2_a1[RD_entry_a1]};
   //_\end_source
   `line 45 "top.tlv" 2


   // Assert these to end simulation (before Makerchip cycle limit).
   assign passed = cyc_cnt > 50;
   assign failed = 1'b0; endgenerate

//_\SV
   endmodule
