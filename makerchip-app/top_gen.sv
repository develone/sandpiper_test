// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"


genvar port;


//
// Signals declared top-level.
//

// For $reset.
logic L0_reset_a0,
      L0_reset_a1;

// For /port|rg$dest.
logic [1:0] Port_RG_dest_a1 [3:0],
            Port_RG_dest_a2 [3:0];

// For /port|rg$pass_on.
logic Port_RG_pass_on_a1 [3:0],
      Port_RG_pass_on_a2 [3:0];

// For /port|rg/trans$cyc_cnt.
logic Port_RG_Trans_cyc_cnt_a1 [3:0] /* verilator lint_save */ /* verilator lint_off MULTIDRIVEN */,
      Port_RG_Trans_cyc_cnt_a2 [3:0] /* verilator lint_restore */;

// For /port|rg/trans$data.
logic [7:0] Port_RG_Trans_data_a1 [3:0] /* verilator lint_save */ /* verilator lint_off MULTIDRIVEN */,
            Port_RG_Trans_data_a2 [3:0] /* verilator lint_restore */;

// For /port|rg/trans$sender.
logic [1:0] Port_RG_Trans_sender_a1 [3:0] /* verilator lint_save */ /* verilator lint_off MULTIDRIVEN */,
            Port_RG_Trans_sender_a2 [3:0] /* verilator lint_restore */;

// For /tb/port|passed$passed.
logic [3:0] Tb_Port_PASSED_passed_a1;

// For /tb|count$CycCount.
logic [15:0] Tb_COUNT_CycCount_a0,
             Tb_COUNT_CycCount_a1;


//
// Scope: /port[3:0]
//

//
// Scope: /port|rg
//

// Clock signals.
logic clkP_Port_RG_valid_a2 [3:0];

//
// Scope: /port|ring_out
//

// Clock signals.
logic clkP_Port_RING_OUT_trans_valid_a2 [3:0];

//
// Scope: /tb
//

//
// Scope: /tb/port[3:0]
//

//
// Scope: /tb/port|receive2
//

// Clock signals.
logic clkP_Tb_Port_RECEIVE2_avail_a1 [3:0];


generate

   // For $reset.
   always_ff @(posedge clk) L0_reset_a1 <= L0_reset_a0;


   //
   // Scope: /port[3:0]
   //
   for (port = 0; port <= 3; port++) begin : L1gen_Port

      //
      // Scope: |fifo_in
      //

         // For $reset.
         always_ff @(posedge clk) L1e_Port[port].L1_FIFO_IN_reset_a2 <= L1e_Port[port].L1_FIFO_IN_reset_a1;



      //
      // Scope: |rg
      //

         // For $dest.
         always_ff @(posedge clk) Port_RG_dest_a2[port][1:0] <= Port_RG_dest_a1[port][1:0];

         // For $pass_on.
         always_ff @(posedge clk) Port_RG_pass_on_a2[port] <= Port_RG_pass_on_a1[port];


         //
         // Scope: /trans
         //

            // For $cyc_cnt.
            always_ff @(posedge clkP_Port_RG_valid_a2[port]) Port_RG_Trans_cyc_cnt_a2[port] <= Port_RG_Trans_cyc_cnt_a1[port];

            // For $data.
            always_ff @(posedge clkP_Port_RG_valid_a2[port]) Port_RG_Trans_data_a2[port][7:0] <= Port_RG_Trans_data_a1[port][7:0];

            // For $sender.
            always_ff @(posedge clkP_Port_RG_valid_a2[port]) Port_RG_Trans_sender_a2[port][1:0] <= Port_RG_Trans_sender_a1[port][1:0];




      //
      // Scope: |ring_out
      //

         // For $trans_valid.
         always_ff @(posedge clk) L1b_Port[port].L1_RING_OUT_trans_valid_a2 <= L1b_Port[port].L1_RING_OUT_trans_valid_a1;


         //
         // Scope: /trans
         //

            // For $data.
            always_ff @(posedge clkP_Port_RING_OUT_trans_valid_a2[port]) L1b_Port[port].L1_RING_OUT_Trans_data_a2[7:0] <= L1b_Port[port].L1_RING_OUT_Trans_data_a1[7:0];



   end

   //
   // Scope: /tb
   //


      //
      // Scope: /port[3:0]
      //
      for (port = 0; port <= 3; port++) begin : L1gen_Tb_Port

         //
         // Scope: |receive2
         //

            // For $OutstandingPackets.
            always_ff @(posedge clk) L1_Tb_Port[port].L1_RECEIVE2_OutstandingPackets_a1[16-1:0] <= L1_Tb_Port[port].L1_RECEIVE2_OutstandingPackets_a0[16-1:0];

            // For $avail.
            always_ff @(posedge clk) L1_Tb_Port[port].L1_RECEIVE2_avail_a1 <= L1_Tb_Port[port].L1_RECEIVE2_avail_a0;

            // For $reset.
            always_ff @(posedge clk) L1_Tb_Port[port].L1_RECEIVE2_reset_a1 <= L1_Tb_Port[port].L1_RECEIVE2_reset_a0;


            //
            // Scope: /trans
            //

               // For $cyc_cnt.
               always_ff @(posedge clkP_Tb_Port_RECEIVE2_avail_a1[port]) L1_Tb_Port[port].L1_RECEIVE2_Trans_cyc_cnt_a1 <= L1_Tb_Port[port].L1_RECEIVE2_Trans_cyc_cnt_a0;

               // For $dest.
               always_ff @(posedge clkP_Tb_Port_RECEIVE2_avail_a1[port]) L1_Tb_Port[port].L1_RECEIVE2_Trans_dest_a1[1:0] <= L1_Tb_Port[port].L1_RECEIVE2_Trans_dest_a0[1:0];

               // For $request.
               always_ff @(posedge clkP_Tb_Port_RECEIVE2_avail_a1[port]) L1_Tb_Port[port].L1_RECEIVE2_Trans_request_a1 <= L1_Tb_Port[port].L1_RECEIVE2_Trans_request_a0;

               // For $response.
               always_ff @(posedge clkP_Tb_Port_RECEIVE2_avail_a1[port]) L1_Tb_Port[port].L1_RECEIVE2_Trans_response_a1 <= L1_Tb_Port[port].L1_RECEIVE2_Trans_response_a0;

               // For $response_debug.
               always_ff @(posedge clkP_Tb_Port_RECEIVE2_avail_a1[port]) L1_Tb_Port[port].L1_RECEIVE2_Trans_response_debug_a1 <= L1_Tb_Port[port].L1_RECEIVE2_Trans_response_debug_a0;

               // For $sender.
               always_ff @(posedge clkP_Tb_Port_RECEIVE2_avail_a1[port]) L1_Tb_Port[port].L1_RECEIVE2_Trans_sender_a1 <= L1_Tb_Port[port].L1_RECEIVE2_Trans_sender_a0;



      end

      //
      // Scope: |count
      //

         // For $CycCount.
         always_ff @(posedge clk) Tb_COUNT_CycCount_a1[15:0] <= Tb_COUNT_CycCount_a0[15:0];





endgenerate



//
// Gated clocks.
//

generate



   //
   // Scope: /port[3:0]
   //
   for (port = 0; port <= 3; port++) begin : L1clk_Port

      //
      // Scope: |rg
      //

         clk_gate gen_clkP_Port_RG_valid_a2(clkP_Port_RG_valid_a2[port], clk, 1'b1, L1b_Port[port].L1_RG_valid_a1, 1'b0);


      //
      // Scope: |ring_out
      //

         clk_gate gen_clkP_Port_RING_OUT_trans_valid_a2(clkP_Port_RING_OUT_trans_valid_a2[port], clk, 1'b1, L1b_Port[port].L1_RING_OUT_trans_valid_a1, 1'b0);

   end

   //
   // Scope: /tb
   //


      //
      // Scope: /port[3:0]
      //
      for (port = 0; port <= 3; port++) begin : L1clk_Tb_Port

         //
         // Scope: |receive2
         //

            clk_gate gen_clkP_Tb_Port_RECEIVE2_avail_a1(clkP_Tb_Port_RECEIVE2_avail_a1[port], clk, 1'b1, L1_Tb_Port[port].L1_RECEIVE2_avail_a0, 1'b0);

      end



endgenerate



generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
