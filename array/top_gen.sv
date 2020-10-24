// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"


genvar entry;


//
// Signals declared top-level.
//

// For /entry$data.
logic [7:0] Entry_data_a0 [3:0],
            Entry_data_a1 [3:0];

// For |rd$data.
logic [7:0] RD_data_a1;

// For |rd$entry.
logic [1:0] RD_entry_a1;

// For |rd$rd_en.
logic [0:0] RD_rd_en_a1;

// For |wr$data.
logic [7:0] WR_data_a0;

// For |wr$entry.
logic [1:0] WR_entry_a0;

// For |wr$wr_en.
logic [0:0] WR_wr_en_a0;



generate


   //
   // Scope: /entry[3:0]
   //
   for (entry = 0; entry <= 3; entry++) begin : L1gen_Entry
      // For $data.
      always_ff @(posedge clk) Entry_data_a1[entry][7:0] <= Entry_data_a0[entry][7:0];

   end


endgenerate




//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS


      //
      // Scope: /entry[3:0]
      //
      for (entry = 0; entry <= 3; entry++) begin : \/entry 
         logic [7:0] \@0$data ;
         assign \@0$data = Entry_data_a0[entry];
      end

      //
      // Scope: |rd
      //
      if (1) begin : \|rd 
         logic [7:0] \@1$data ;
         assign \@1$data = RD_data_a1;
         logic [1:0] \@1$entry ;
         assign \@1$entry = RD_entry_a1;
         logic [0:0] \@1$rd_en ;
         assign \@1$rd_en = RD_rd_en_a1;
      end

      //
      // Scope: |wr
      //
      if (1) begin : \|wr 
         logic [7:0] \@0$data ;
         assign \@0$data = WR_data_a0;
         logic [1:0] \@0$entry ;
         assign \@0$entry = WR_entry_a0;
         logic [0:0] \@0$wr_en ;
         assign \@0$wr_en = WR_wr_en_a0;
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
