`line 2 "top.tlv" 0 //_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV
   // -------------------------------------------------------------------------------
   // This code implements a bank account balance.
   // Transactions consist of deposits and withdrawals.
   // -------------------------------------------------------------------------------

   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // A generic module declaration macro instantiation
      // Note: We do not ignore width mismatch in this example.
`include "top_gen.sv" //_\TLV

   //_|bank
      //_@0
         assign BANK_reset_a0 = reset;
      

      // ----------------------------------------------------------------------------
      // Explicitly assign inputs.
      // Assign/randomize initial balance, account action, and amount to deposit or withdraw
      // ----------------------------------------------------------------------------
      //_@1
         assign BANK_init_balance_a1[15:0] = 16'b1; // initial balance
         assign BANK_action_a1[0:0] = RW_rand_vect[(0 + (0)) % 257 +: 1];       // deposit = 0; withdrawal = 1
         assign BANK_transaction_a1[1:0] = RW_rand_vect[(124 + (0)) % 257 +: 2];  // 75% chance of valid (01, 10, 11); 25% chance of invalid (00)
         assign BANK_rand_amount_a1[10:0] = RW_rand_vect[(248 + (0)) % 257 +: 11]; // amount to deposit or withdraw
         assign BANK_amount_a1[15:0] = {5'b0, BANK_rand_amount_a1};


      // ---
      // DUT
      // ---
      //_@2
         assign BANK_valid_transaction_a2 = BANK_transaction_a2 != 2'b0;
         assign BANK_withdraw_error_a2 = BANK_action_a2 == 1'b1 && BANK_amount_a2 > BANK_Balance_a2 ? 1'b1 : // true if withdrawal amount is greater than current balance
                                                                   1'b0;  // false otherwise
         assign BANK_valid_transaction_or_reset_a2 = (BANK_valid_transaction_a2 && !BANK_withdraw_error_a2) || BANK_reset_a2;
         
         //_?$valid_transaction_or_reset
            assign BANK_Balance_a1[15:0] = BANK_reset_a2          ? BANK_init_balance_a2 :      // set to init_balance at the beginning
                              BANK_action_a2 == 1'b0 ? BANK_Balance_a2 + BANK_amount_a2 : // deposit amount
                                                BANK_Balance_a2 - BANK_amount_a2;  // withdraw amount
            
            //$NumTransactions[15:0] = 16'b0; to count how many successful transactions occur.
            assign BANK_NumTransactions_a1[15:0] = BANK_reset_a2 ? 16'b0 :BANK_NumTransactions_a2 + 16'b1;

      // -----------------
      // Print transaction
      // -----------------
      //_@3
         /*SV_plus*/
            always_ff @(posedge clk) begin
               if (BANK_valid_transaction_a3 && ! BANK_reset_a3) begin
                  if (!BANK_withdraw_error_a3) begin
                     $display(" NumTransaction #: %0d", BANK_NumTransactions_a3);
                     $display("     $%5d %0s $%4d = $%5d", BANK_Balance_a3, BANK_action_a3 == 1'b0 ? "+" : "-", BANK_amount_a3, BANK_Balance_a2);
                  end else begin
                     $display(" Insufficient funds. Balance: $%5d Withdrawal: $%4d", BANK_Balance_a2, BANK_amount_a3);
                  end
               end
            end
      

      // ---------------------------------------------------
      // Test for Positive Remaining Balance after 20 Cycles
      // ---------------------------------------------------
      //_@4
         assign BANK_CycCount_a3[15:0] = BANK_reset_a4 ? 16'b0 : BANK_CycCount_a4 + 16'b1;
           
         assign passed = BANK_Balance_a4[15] == 1'b0 && BANK_CycCount_a4 > 16'd20; endgenerate

//_\SV
endmodule
