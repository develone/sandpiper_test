\TLV_version [\source top.tlv] 1d: tl-x.org
\SV

module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/221c93b3603bb4c72d3b024b3ec410e48f60e199/arrays.tlv"

\TLV
   //$reset = *reset;

   //--------------------------------------------------
   // Stimulus
   //
   
   // Explicit random inputs.
   
   
   |wr
      @0
         // The array hierarchy (to declare ranges)
         /entry[3:0]
         
         $wr_en[0:0] = *RW_rand_vect[(0 + (0)) % 257 +: 1];
         ?$wr_en
            $entry[1:0] = *RW_rand_vect[(124 + (0)) % 257 +: 2];  // entry to write into
            $data[7:0] = *RW_rand_vect[(248 + (0)) % 257 +: 8];  // data to write
   |rd
      @1
         $rd_en[0:0] = *RW_rand_vect[(115 + (0)) % 257 +: 1];
         ?$rd_en
            $entry[1:0] = *RW_rand_vect[(239 + (0)) % 257 +: 2];  // entry to read from
         
   
   //----------------------------------------------------
   // The array

   \source /raw.githubusercontent.com/stevehoover/tlvflowlib/221c93b3603bb4c72d3b024b3ec410e48f60e199/arrays.tlv 36   // Instantiated from top.tlv, 36 as: m4+array1r1w(/top, /entry, |wr, @0, $wr_en, $entry, |rd, @1, $rd_en, $entry, $data[7:0], )
      // Write Pipeline
      // The array entries hierarchy (needs a definition to define range, and currently,  declaration required before reference).
      /entry[3:0]
         
            
      // Write transaction to cache
      // (TLV assignment syntax prohibits assignment outside of it's own scope, but \SV_plus does not.)
      \SV_plus
         always_comb
            if (|wr>>0$wr_en)
               /entry[|wr>>0$entry]$$data[7:0] = |wr>>0$data[7:0];
      
      // Read Pipeline
      |rd
         @1
            // Read transaction from cache.
            ?$rd_en
               
               $data[7:0] = /top/entry[|rd$entry]>>0$data[7:0];
   \end_source


   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 50;
   *failed = 1'b0;

\SV
   endmodule
