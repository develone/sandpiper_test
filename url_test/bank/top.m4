\TLV_version [\source top.tlv] 1d: tl-x.org
\SV

   // =========================================
   // Welcome!  Try the tutorials via the menu.
   // =========================================

   // Default Makerchip TL-Verilog Code Template
   
   // Macro providing required top-level module definition, random
   // stimulus support, and Verilator config.
   //m4_include_url(['https:/']['/raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/fundamentals_lib.tlv'])
   //m4_include_url(['https:/']['/raw.githubusercontent.com/stevehoover/tlv_flow_lib/5a8c0387be80b2deccfcd1506299b36049e0663e/pipeflow_lib.tlv'])
   //testing using links that I created. 
   // FAILED to access: "https:///github.com/develone/sandpiper_test/blob/master/url_test/fundamentals_lib/fundamentals_lib.tvl"
   // FAILED to access: "https:///github.com/develone/sandpiper_test/blob/master/url_test/pipeflow_lib/pipeflow_lib.tlv"
   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */   // (Expanded in Nav-TLV pane.)

\TLV

   |bank
      @0
         $reset = *reset;
      

      // ----------------------------------------------------------------------------
      // Explicitly assign inputs.
      // Assign/randomize initial balance, account action, and amount to deposit or withdraw
      // ----------------------------------------------------------------------------
      @1
         $init_balance[15:0] = 16'b1; // initial balance
         $action[0:0] = *RW_rand_vect[(0 + (0)) % 257 +: 1];       // deposit = 0; withdrawal = 1
         $transaction[1:0] = *RW_rand_vect[(124 + (0)) % 257 +: 2];  // 75% chance of valid (01, 10, 11); 25% chance of invalid (00)
         $rand_amount[10:0] = *RW_rand_vect[(248 + (0)) % 257 +: 11]; // amount to deposit or withdraw
         $amount[15:0] = {5'b0, $rand_amount};


      // ---
      // DUT
      // ---
      @2
         $valid_transaction = $transaction != 2'b0;
         $withdraw_error = $action == 1'b1 && $amount > $Balance ? 1'b1 : // true if withdrawal amount is greater than current balance
                                                                   1'b0;  // false otherwise
         $valid_transaction_or_reset = ($valid_transaction && !$withdraw_error) || $reset;
         
         ?$valid_transaction_or_reset
            $Balance[15:0] <= $reset          ? $init_balance :      // set to init_balance at the beginning
                              $action == 1'b0 ? $Balance + $amount : // deposit amount
                                                $Balance - $amount;  // withdraw amount
            
            //[(1)] Create $NumTransactions to count how many successful transactions occur.


      // -----------------
      // Print transaction
      // -----------------
      @3
         \SV_plus
            always_ff @(posedge clk) begin
               if ($valid_transaction && ! $reset) begin
                  if (!$withdraw_error) begin
                     //[(1)] \$display(" Transaction #: \%0d", $NumTransactions);
                     \$display("     \$\%5d \%0s\ $\%4d = \$\%5d", $Balance, $action == 1'b0 ? "+" : "-", $amount, <<1$Balance);
                  end else begin
                     \$display(" Insufficient funds. Balance: \$\%5d Withdrawal: \$\%4d", <<1$Balance, $amount);
                  end
               end
            end
      

      // ---------------------------------------------------
      // Test for Positive Remaining Balance after 20 Cycles
      // ---------------------------------------------------
      @4
         $CycCount[15:0] <= $reset ? 16'b0 : $CycCount + 16'b1;
         *passed = $Balance[15] == 1'b0 && $CycCount > 16'd20;
 
\SV
   endmodule
