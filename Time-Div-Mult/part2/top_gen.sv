// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"





//
// Signals declared top-level.
//

// For |in$cnt.
logic [1:0] IN_cnt_a0,
            IN_cnt_a1;

// For |in$error.
logic IN_error_a4,
      IN_error_a5;

// For |in$flit.
logic [3:0] IN_flit_a0,
            IN_flit_a1,
            IN_flit_a2,
            IN_flit_a3,
            IN_flit_a4;

// For |in$packet_in.
logic [15:0] IN_packet_in_a0,
             IN_packet_in_a1,
             IN_packet_in_a2,
             IN_packet_in_a3,
             IN_packet_in_a4;

// For |in$packet_out.
logic [15:0] IN_packet_out_a4;

// For |in$reset.
logic IN_reset_a0,
      IN_reset_a1,
      IN_reset_a2,
      IN_reset_a3,
      IN_reset_a4;

// For |in$valid.
logic IN_valid_a0,
      IN_valid_a1,
      IN_valid_a2,
      IN_valid_a3,
      IN_valid_a4;


//
// Scope: |in
//

// Clock signals.
logic clkP_IN_valid_a1 ;
logic clkP_IN_valid_a2 ;
logic clkP_IN_valid_a3 ;
logic clkP_IN_valid_a4 ;


generate


   //
   // Scope: |in
   //

      // For $cnt.
      always_ff @(posedge clk) IN_cnt_a1[1:0] <= IN_cnt_a0[1:0];

      // For $error.
      always_ff @(posedge clk) IN_error_a5 <= IN_error_a4;

      // For $flit.
      always_ff @(posedge clk) IN_flit_a1[3:0] <= IN_flit_a0[3:0];
      always_ff @(posedge clk) IN_flit_a2[3:0] <= IN_flit_a1[3:0];
      always_ff @(posedge clk) IN_flit_a3[3:0] <= IN_flit_a2[3:0];
      always_ff @(posedge clk) IN_flit_a4[3:0] <= IN_flit_a3[3:0];

      // For $packet_in.
      always_ff @(posedge clkP_IN_valid_a1) IN_packet_in_a1[15:0] <= IN_packet_in_a0[15:0];
      always_ff @(posedge clkP_IN_valid_a2) IN_packet_in_a2[15:0] <= IN_packet_in_a1[15:0];
      always_ff @(posedge clkP_IN_valid_a3) IN_packet_in_a3[15:0] <= IN_packet_in_a2[15:0];
      always_ff @(posedge clkP_IN_valid_a4) IN_packet_in_a4[15:0] <= IN_packet_in_a3[15:0];

      // For $reset.
      always_ff @(posedge clk) IN_reset_a1 <= IN_reset_a0;
      always_ff @(posedge clk) IN_reset_a2 <= IN_reset_a1;
      always_ff @(posedge clk) IN_reset_a3 <= IN_reset_a2;
      always_ff @(posedge clk) IN_reset_a4 <= IN_reset_a3;

      // For $valid.
      always_ff @(posedge clk) IN_valid_a1 <= IN_valid_a0;
      always_ff @(posedge clk) IN_valid_a2 <= IN_valid_a1;
      always_ff @(posedge clk) IN_valid_a3 <= IN_valid_a2;
      always_ff @(posedge clk) IN_valid_a4 <= IN_valid_a3;




endgenerate



//
// Gated clocks.
//

generate



   //
   // Scope: |in
   //

      clk_gate gen_clkP_IN_valid_a1(clkP_IN_valid_a1, clk, 1'b1, IN_valid_a0, 1'b0);
      clk_gate gen_clkP_IN_valid_a2(clkP_IN_valid_a2, clk, 1'b1, IN_valid_a1, 1'b0);
      clk_gate gen_clkP_IN_valid_a3(clkP_IN_valid_a3, clk, 1'b1, IN_valid_a2, 1'b0);
      clk_gate gen_clkP_IN_valid_a4(clkP_IN_valid_a4, clk, 1'b1, IN_valid_a3, 1'b0);



endgenerate



//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS


      //
      // Scope: |in
      //
      if (1) begin : \|in 
         logic [1:0] \@0$cnt ;
         assign \@0$cnt = IN_cnt_a0;
         logic  \@4$error ;
         assign \@4$error = IN_error_a4;
         logic [3:0] \@0$flit ;
         assign \@0$flit = IN_flit_a0;
         logic [15:0] \@0$packet_in ;
         assign \@0$packet_in = IN_packet_in_a0;
         logic [15:0] \@4$packet_out ;
         assign \@4$packet_out = IN_packet_out_a4;
         logic  \@0$reset ;
         assign \@0$reset = IN_reset_a0;
         logic  \@0$valid ;
         assign \@0$valid = IN_valid_a0;
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
