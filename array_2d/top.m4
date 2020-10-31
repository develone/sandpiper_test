\TLV_version [\source top.tlv] 1d: tl-x.org
\SV

// An example of a two-dimensional array (a banked register file) implemented various ways.
// The RF is written with a transaction (/top|wr/trans$ANY @0) and read into (/top|rd/trans$ANY @1).
// |rd and |wr pipelines are naturally-aligned in the sense that data written to the array from |wr is first
// visible to the stage-aligned |rd transaction.

module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
// Included URL: "https://raw.githubusercontent.com/stevehoover/tlv_flow_lib/aa1f91c9e09326e8506bd81d8a077455ddfb0606/arrays.tlv"

\TLV
   //$reset = *reset;

   //--------------------------------------------------
   // Stimulus
   //
   
   // Explicit random inputs (same inputs for all approaches).
   
   
   
   |wr
      @0
         // The array hierarchy (to declare ranges)
         /bank[1:0]
            /entry[3:0]
               // These must be declared before referenced (currently).
               /trans2
               /trans3
               /trans4
         $wr_en[0:0] = *RW_rand_vect[(0 + (0)) % 257 +: 1];
         ?$wr_en
            $bank[0:0] = *RW_rand_vect[(124 + (0)) % 257 +: 1];
            $entry[1:0] = *RW_rand_vect[(248 + (0)) % 257 +: 2];
            /trans
               $data1[7:0] = *RW_rand_vect[(115 + (0)) % 257 +: 8];
               $data2[3:0] = *RW_rand_vect[(239 + (0)) % 257 +: 4];
   |rd
      @1
         $rd_en[0:0] = *RW_rand_vect[(106 + (0)) % 257 +: 1];
         ?$rd_en
            $bank[0:0] = *RW_rand_vect[(230 + (0)) % 257 +: 1];
            $entry[1:0] = *RW_rand_vect[(97 + (0)) % 257 +: 2];
         
   
   //----------------------------------------------------
   // Approach 1:
   // Utilizing SV module instantiation.
   
   // ... (not implemented)
   
   
   //----------------------------------------------------
   // Approach 2:
   // Utilizing array write.
   
   // Write Pipeline
   |wr
      @0
         // Write the transaction
         // (TLV assignment syntax prohibits assignment outside of it's own scope, but \SV_plus does not.)
         \SV_plus
            always_comb
               if ($wr_en)
                  /bank[$bank]/entry[$entry]/trans2$$ANY = /trans$ANY;
   
   // Read Pipeline
   |rd
      @1
         // Read transaction from array
         ?$rd_en
            /trans2
               $ANY = /top|wr/bank[|rd$bank]/entry[|rd$entry]/trans2<>0$ANY;
               `BOGUS_USE($data1 $data2)  // Pull transaction through.

   
   //----------------------------------------------------
   // Approach 3:
   // Write each entry every cycle (preserving value w/ recirculation).
   // Most-native TLV, but poor simulation performance today.
   
   // Write Pipeline
   |wr
      @0
         // The array hierarchy
         /bank[*]
            /entry[*]
               /trans3
                  $ANY = (|wr$wr_en && (|wr$bank == #bank) && (|wr$entry == #entry))
                              ? |wr/trans$ANY :
                                >>1$ANY;
   
   // Read Pipeline
   |rd
      @1
         // Read
         ?$rd_en
            /trans3
               $ANY = /top|wr/bank[|rd$bank]/entry[|rd$entry]/trans3<>0$ANY;
               `BOGUS_USE($data1 $data2)  // Pull transaction through.

   //----------------------------------------------------
   // Approach 4:
   // Utilizing macro, per bank.

   /bank[1:0]
      // Copy of /top|wr and /top|rd per bank.
      |wr
         @0
            $wr_en = /top|wr$wr_en && /top|wr$bank == #bank;
            ?$wr_en
               $entry[3:0] = /top|wr$entry;
               /trans4
                  $ANY = /top|wr/trans$ANY;
      |rd
         @1
            $rd_en = /top|rd$rd_en && /top|rd$bank == #bank;
            ?$rd_en
               $entry[3:0] = /top|rd$entry;
      \source /raw.githubusercontent.com/stevehoover/tlvflowlib/aa1f91c9e09326e8506bd81d8a077455ddfb0606/arrays.tlv 33   // Instantiated from top.tlv, 121 as: m4+array1r1w(/bank, /entry, |wr, @0, $wr_en, $entry, |rd, @1, $rd_en, $entry, $ANY, /trans4)
         // Write Pipeline
         // The array entries hierarchy (needs a definition to define range, and currently, /trans4 declaration required before reference).
         /entry[3:0]
            /trans4
               
         // Write transaction to cache
         // (TLV assignment syntax prohibits assignment outside of it's own scope, but \SV_plus does not.)
         \SV_plus
            always_comb
               if (|wr>>0$wr_en)
                  /entry[|wr>>0$entry]/trans4$$ANY = |wr/trans4>>0$ANY;
         
         // Read Pipeline
         |rd
            @1
               // Read transaction from cache.
               ?$rd_en
                  /trans4
                     $ANY = /bank/entry[|rd$entry]/trans4>>-1$ANY;
      \end_source
   // Pull read out of the bank.
   |rd
      @1
         ?$rd_en
            /trans4
               $ANY = /top/bank[|rd$bank]|rd/trans4$ANY;


   //-----------------------------------------------------
   // Checking
   
   |rd
      @1
         ?$rd_en
            /mismatch
               // A vector pulled through $ANY, with bits asserted for any mismatches between read data for
               // different implementations.
               $ANY = (|rd/trans2$ANY ^ |rd/trans3$ANY) |
                      (|rd/trans2$ANY ^ |rd/trans4$ANY);
         // $error if any mismatching data was read.
         $error = $rd_en &&
                  (| /mismatch$data1 ||
                   | /mismatch$data2);
      
      
   // Assert these to end simulation (before Makerchip cycle limit).
   *passed = *cyc_cnt > 50;
   *failed = *cyc_cnt > 4 && |rd>>2$error;

\SV
   endmodule
