// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"


genvar bank, entry;


//
// Signals declared top-level.
//

// For /bank|rd/trans4$data1.
logic [7:0] Bank_RD_Trans4_data1_a1 [1:0];

// For /bank|rd/trans4$data2.
logic [3:0] Bank_RD_Trans4_data2_a1 [1:0];

// For |rd$bank.
logic [0:0] RD_bank_a1;

// For |rd$entry.
logic [1:0] RD_entry_a1;

// For |rd$error.
logic RD_error_a1,
      RD_error_a2;

// For |rd$rd_en.
logic [0:0] RD_rd_en_a1;

// For |rd/mismatch$data1.
logic [7:0] RD_Mismatch_data1_a1;

// For |rd/mismatch$data2.
logic [3:0] RD_Mismatch_data2_a1;

// For |rd/trans2$data1.
logic [7:0] RD_Trans2_data1_a1;

// For |rd/trans2$data2.
logic [3:0] RD_Trans2_data2_a1;

// For |rd/trans3$data1.
logic [7:0] RD_Trans3_data1_a1;

// For |rd/trans3$data2.
logic [3:0] RD_Trans3_data2_a1;

// For |rd/trans4$data1.
logic [7:0] RD_Trans4_data1_a1;

// For |rd/trans4$data2.
logic [3:0] RD_Trans4_data2_a1;

// For |wr$bank.
logic [0:0] WR_bank_a0;

// For |wr$entry.
logic [1:0] WR_entry_a0;

// For |wr$wr_en.
logic [0:0] WR_wr_en_a0;

// For |wr/bank/entry/trans2$data1.
logic [7:0] WR_Bank_Entry_Trans2_data1_a0 [1:0][3:0],
            WR_Bank_Entry_Trans2_data1_a1 [1:0][3:0];

// For |wr/bank/entry/trans2$data2.
logic [3:0] WR_Bank_Entry_Trans2_data2_a0 [1:0][3:0],
            WR_Bank_Entry_Trans2_data2_a1 [1:0][3:0];

// For |wr/bank/entry/trans3$data1.
logic [7:0] WR_Bank_Entry_Trans3_data1_a0 [1:0][3:0],
            WR_Bank_Entry_Trans3_data1_a1 [1:0][3:0];

// For |wr/bank/entry/trans3$data2.
logic [3:0] WR_Bank_Entry_Trans3_data2_a0 [1:0][3:0],
            WR_Bank_Entry_Trans3_data2_a1 [1:0][3:0];

// For |wr/trans$data1.
logic [7:0] WR_Trans_data1_a0;

// For |wr/trans$data2.
logic [3:0] WR_Trans_data2_a0;



generate


   //
   // Scope: |rd
   //

      // For $error.
      always_ff @(posedge clk) RD_error_a2 <= RD_error_a1;



   //
   // Scope: |wr
   //


      //
      // Scope: /bank[1:0]
      //
      for (bank = 0; bank <= 1; bank++) begin : L1gen_WR_Bank

         //
         // Scope: /entry[3:0]
         //
         for (entry = 0; entry <= 3; entry++) begin : L2gen_Entry

            //
            // Scope: /trans2
            //

               // For $data1.
               always_ff @(posedge clk) WR_Bank_Entry_Trans2_data1_a1[bank][entry][7:0] <= WR_Bank_Entry_Trans2_data1_a0[bank][entry][7:0];

               // For $data2.
               always_ff @(posedge clk) WR_Bank_Entry_Trans2_data2_a1[bank][entry][3:0] <= WR_Bank_Entry_Trans2_data2_a0[bank][entry][3:0];



            //
            // Scope: /trans3
            //

               // For $data1.
               always_ff @(posedge clk) WR_Bank_Entry_Trans3_data1_a1[bank][entry][7:0] <= WR_Bank_Entry_Trans3_data1_a0[bank][entry][7:0];

               // For $data2.
               always_ff @(posedge clk) WR_Bank_Entry_Trans3_data2_a1[bank][entry][3:0] <= WR_Bank_Entry_Trans3_data2_a0[bank][entry][3:0];


         end
      end



endgenerate




//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS


      //
      // Scope: /bank[1:0]
      //
      for (bank = 0; bank <= 1; bank++) begin : \/bank 

         //
         // Scope: /entry[3:0]
         //
         for (entry = 0; entry <= 3; entry++) begin : \/entry 

            //
            // Scope: /trans4
            //
            if (1) begin : \/trans4 
               logic [7:0] \@0$data1 ;
               assign \@0$data1 = L1_Bank[bank].L1_Entry_Trans4_data1_a0[entry];
               logic [3:0] \@0$data2 ;
               assign \@0$data2 = L1_Bank[bank].L1_Entry_Trans4_data2_a0[entry];
            end
         end

         //
         // Scope: |rd
         //
         if (1) begin : \|rd 
            logic [3:0] \@1$entry ;
            assign \@1$entry = L1_Bank[bank].L1_RD_entry_a1;
            logic  \@1$rd_en ;
            assign \@1$rd_en = L1_Bank[bank].L1_RD_rd_en_a1;

            //
            // Scope: /trans4
            //
            if (1) begin : \/trans4 
               logic [7:0] \@1$data1 ;
               assign \@1$data1 = Bank_RD_Trans4_data1_a1[bank];
               logic [3:0] \@1$data2 ;
               assign \@1$data2 = Bank_RD_Trans4_data2_a1[bank];
            end
         end

         //
         // Scope: |wr
         //
         if (1) begin : \|wr 
            logic [3:0] \@0$entry ;
            assign \@0$entry = L1_Bank[bank].L1_WR_entry_a0;
            logic  \@0$wr_en ;
            assign \@0$wr_en = L1_Bank[bank].L1_WR_wr_en_a0;

            //
            // Scope: /trans4
            //
            if (1) begin : \/trans4 
               logic [7:0] \@0$data1 ;
               assign \@0$data1 = L1_Bank[bank].L1_WR_Trans4_data1_a0;
               logic [3:0] \@0$data2 ;
               assign \@0$data2 = L1_Bank[bank].L1_WR_Trans4_data2_a0;
            end
         end
      end

      //
      // Scope: |rd
      //
      if (1) begin : \|rd 
         logic [0:0] \@1$bank ;
         assign \@1$bank = RD_bank_a1;
         logic [1:0] \@1$entry ;
         assign \@1$entry = RD_entry_a1;
         logic  \@1$error ;
         assign \@1$error = RD_error_a1;
         logic [0:0] \@1$rd_en ;
         assign \@1$rd_en = RD_rd_en_a1;

         //
         // Scope: /mismatch
         //
         if (1) begin : \/mismatch 
            logic [7:0] \@1$data1 ;
            assign \@1$data1 = RD_Mismatch_data1_a1;
            logic [3:0] \@1$data2 ;
            assign \@1$data2 = RD_Mismatch_data2_a1;
         end

         //
         // Scope: /trans2
         //
         if (1) begin : \/trans2 
            logic [7:0] \@1$data1 ;
            assign \@1$data1 = RD_Trans2_data1_a1;
            logic [3:0] \@1$data2 ;
            assign \@1$data2 = RD_Trans2_data2_a1;
         end

         //
         // Scope: /trans3
         //
         if (1) begin : \/trans3 
            logic [7:0] \@1$data1 ;
            assign \@1$data1 = RD_Trans3_data1_a1;
            logic [3:0] \@1$data2 ;
            assign \@1$data2 = RD_Trans3_data2_a1;
         end

         //
         // Scope: /trans4
         //
         if (1) begin : \/trans4 
            logic [7:0] \@1$data1 ;
            assign \@1$data1 = RD_Trans4_data1_a1;
            logic [3:0] \@1$data2 ;
            assign \@1$data2 = RD_Trans4_data2_a1;
         end
      end

      //
      // Scope: |wr
      //
      if (1) begin : \|wr 
         logic [0:0] \@0$bank ;
         assign \@0$bank = WR_bank_a0;
         logic [1:0] \@0$entry ;
         assign \@0$entry = WR_entry_a0;
         logic [0:0] \@0$wr_en ;
         assign \@0$wr_en = WR_wr_en_a0;

         //
         // Scope: /bank[1:0]
         //
         for (bank = 0; bank <= 1; bank++) begin : \/bank 

            //
            // Scope: /entry[3:0]
            //
            for (entry = 0; entry <= 3; entry++) begin : \/entry 

               //
               // Scope: /trans2
               //
               if (1) begin : \/trans2 
                  logic [7:0] \@0$data1 ;
                  assign \@0$data1 = WR_Bank_Entry_Trans2_data1_a0[bank][entry];
                  logic [3:0] \@0$data2 ;
                  assign \@0$data2 = WR_Bank_Entry_Trans2_data2_a0[bank][entry];
               end

               //
               // Scope: /trans3
               //
               if (1) begin : \/trans3 
                  logic [7:0] \@0$data1 ;
                  assign \@0$data1 = WR_Bank_Entry_Trans3_data1_a0[bank][entry];
                  logic [3:0] \@0$data2 ;
                  assign \@0$data2 = WR_Bank_Entry_Trans3_data2_a0[bank][entry];
               end
            end
         end

         //
         // Scope: /trans
         //
         if (1) begin : \/trans 
            logic [7:0] \@0$data1 ;
            assign \@0$data1 = WR_Trans_data1_a0;
            logic [3:0] \@0$data2 ;
            assign \@0$data2 = WR_Trans_data2_a0;
         end
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
