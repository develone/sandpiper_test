`line 2 "top.tlv" 0 //_\TLV_version 1d: tl-x.org, generated by SandPiper(TM) 1.9-2018/02/11-beta
`include "sp_default.vh" //_\SV
   // A state machine for a 3-floor elevator controller.
   // Elevator can travel one story each cycle, stopping at each floor (whether necessary or not).

   // This controller is written three ways:
   //   1) in SystemVerilog, in a big always_ff block
   //   2) directly translated to TL-Verilog
   //   3) cleanly rewritten in TL-Verilog with a single assignment for each signal
   //   4) (and the SandPiper(TM)-generated Verilog could be considered a fourth style)
   //
   //   Sequential style: 1) SV -> 2) TLV
   //                        |         |
   //   Parallel style:   4) SV <- 3) TLV

   // Observations:
   //  o Using a nested if-else structure (sequential style) is not better or worse than
   //    individual assignments (parallel style) in terms of code size. With sequential style,
   //    signals are repeated multiple times. With parallel style, cases are repeated
   //    multiple times.
   //  o TL-Verilog lends itself to parallel style. This:
   //     - allows signal declarations to be incorporated into assignments
   //     - provides individual atomic re-timable statements.
   //  o The logic representation chosen for TL-Verilog is less specific to 3 floors, with more
   //    logic replicated per floor, where Verilog logic is coded uniquely per-floor.
   //  o Coding time was roughly the same for Verilog and TL-Verilog (but, for what it's
   //    worth, I had two bugs of any significance in my Verilog and none in TL-Verilog).
   //  o Even though no simplicity benefit is claimed for TL-Verilog for state machines, the code
   //    is about half the size.

   module top(input logic clk, input logic reset, input logic [31:0] cyc_cnt, output logic passed, output logic failed);    /* verilator lint_save */ /* verilator lint_off UNOPTFLAT */  bit [256:0] RW_rand_raw; bit [256+63:0] RW_rand_vect; pseudo_rand #(.WIDTH(257)) pseudo_rand (clk, reset, RW_rand_raw[256:0]); assign RW_rand_vect[256+63:0] = {RW_rand_raw[62:0], RW_rand_raw};  /* verilator lint_restore */  /* verilator lint_off WIDTH */ /* verilator lint_off UNOPTFLAT */
   /* verilator lint_on WIDTH */

   // ==========
   // Version 1) SystemVerilog by hand.
   // ==========

   // Inputs:
   logic [2:0] up_pressed, down_pressed;  // Elevator up/down button input on each floor. 1 == pressed.
   logic [2:0] elevator_button_pressed;   // The floor buttons/lights in the elevator. 1 == pressed.

   logic [2:0] floor_mask;  // Floor the elevator is on (1-hot decoded).
   logic [1:0] up_light; logic [2:1] down_light;   // Elevator up/down button lights on each floor. 1 == lit. Cleared after departure.
   logic [2:0] elevator_light;  // The floor lights in the elevator. 1 == lit. Cleared on arrival.
   logic went_up, went_down; // 1 if the elevator just went this direction to reach its current floor.

   logic called_top, called_bottom;  // 1 if there's a reason to go up/down.
   always_comb begin
      // For decisions from floor 1:
      called_top = elevator_light[2] || down_light[2] || up_light[1];
      called_bottom = elevator_light[0] || up_light[0] || down_light[1];
   end
   always_ff @(posedge clk) begin
      // Random input:
      // Note that we do not keep track of who is in the elevator, and elevator buttons
      // can be pressed at any time, whether there is a passenger or not.
      // All button presses are given 1/8 probability, here.
      {up_pressed, down_pressed, elevator_button_pressed} <=
           9'b011110111 &  // Mask non-existant buttons.
           RW_rand_raw[26:18] & RW_rand_raw[17:9] & RW_rand_raw[8:0];  // random w/ 1/8 probability.
      
      // State machine, to update:
      //   o floor
      //   o up/down_light
      //   o went_up/down
      
      // Stay, until we decide otherwise.
      //went_up <= 1'b0;
      went_down <= 1'b0;
      
      // Update state for elevator button presses.
      for (int fl = 0; fl < 3; fl++) begin
         if (elevator_button_pressed[fl]) elevator_light[fl] <= '1;
            // Note that if button is pressed for our new floor, the light is not lit.
      end
      // Note that we cannot have been called to the floor we are on.
      if (reset) begin
         floor_mask <= 3'b001;
         up_light <= 2'b00;
         down_light <= 2'b00;
         elevator_light <= 3'b000;
      end else if (floor_mask[0]) begin
         // From floor 0
         if (| {up_light[1:0], down_light[2:1], elevator_light[2:1]}) begin
            // Go up.
            //went_up <= '1;
            floor_mask <= 3'b010;
            up_light[0] <= '0;
            elevator_light[1] <= '0;
         end else begin
            // Stay.
            elevator_light[0] <= '0;
         end
      end else if (floor_mask[2]) begin
         // From floor 2
         if (| {down_light[2:1], up_light[1:0], elevator_light[1:0]}) begin
            // Go down.
            went_down <= '1;
            floor_mask <= 3'b010;
            down_light[2] <= '0;
            elevator_light[1] <= '0;
         end else begin
            // Stay.
            elevator_light[2] <= '0;
         end
      end else begin
         // From floor 1
         if (called_top && (!went_down || !called_bottom)) begin
            // Go up (gets priority over down when no momentum).
            //went_up <= '1;
            floor_mask <= 3'b100;
            up_light[1] <= '0;
            elevator_light[2] <= '0;
         end else if (called_bottom && (went_down || !called_top)) begin
            // Go down.
            went_down <= '1;
            floor_mask <= 3'b001;
            down_light[1] <= '0;
            elevator_light[0] <= '0;
         end else begin
            // Stay.
            elevator_light[1] <= '0;
         end
      end
         
      // Update state for floor button presses.
      for (int fl = 0; fl < 3; fl++) begin
         if (up_pressed[fl]) up_light[fl] <= '1;
         if (down_pressed[fl]) down_light[fl] <= '1;
      end
   end

`include "top_gen.sv" //_\TLV
   assign L0_reset_a0 = reset;
   
   // -------------------------
   // Random stimulus.
   // Use values from Verilog model.
   //_|ctrl
      //_@0
         for (floor = 0; floor <= 2; floor++) begin : L1_CTRL_Floor //_/floor
            // Elevator up/down button input on each floor. 1 == pressed.
            assign CTRL_Floor_up_pressed_a0[floor] = up_pressed[floor];   // BUG: [#floor] doesn't work.
            assign CTRL_Floor_down_pressed_a0[floor] = down_pressed[floor];
            // The floor buttons/lights in the elevator. 1 == pressed.
            assign CTRL_Floor_elevator_button_pressed_a0[floor] = elevator_button_pressed[floor]; end
   // -------------------------
   
   // ==========
   // Version 2) Direct translation to TL-Verilog.
   // ==========
   
   //_/version2
      //_|ctrl
         //_@0
            // Random input:
            // Note that we do not keep track of who is in the elevator, and elevator buttons
            // can be pressed at any time, whether there is a passenger or not.
            // All button presses are given 1/8 probability, here.
            assign {Version2_CTRL_up_pressed_a0[2:0], Version2_CTRL_down_pressed_a0[2:0], Version2_CTRL_elevator_button_pressed_a0[2:0]} =
                 {CTRL_Floor_up_pressed_a0, CTRL_Floor_down_pressed_a0, CTRL_Floor_elevator_button_pressed_a0};
            
            assign Version2_CTRL_reset_a0 = CTRL_reset_a0;
            
            // For decisions from floor 1:
            assign Version2_CTRL_called_top_a0 = Version2_CTRL_elevator_light_a0[2] || Version2_CTRL_down_light_a0[2] || Version2_CTRL_up_light_a0[1];
            assign Version2_CTRL_called_bottom_a0 = Version2_CTRL_elevator_light_a0[0] || Version2_CTRL_up_light_a0[0] || Version2_CTRL_down_light_a0[1];

            always_comb begin
               // State machine, to update:
               //   o floor
               //   o up/down_light
               //   o went_up/down
               
               // Stay, until we decide otherwise.
               // 1 if the elevator will have just gone this direction to reach its current floor.
               //$$next_went_up = 1'b0;
               Version2_CTRL_next_went_down_a0 = 1'b0;
               
               // Update state for elevator button presses.
               for (int fl = 0; fl < 3; fl++) begin
                  if (Version2_CTRL_elevator_button_pressed_a0[fl]) Version2_CTRL_next_elevator_light_a0[fl] = '1;
                     // Note that if button is pressed for our new floor, the light is not lit.
               end
               // Note that we cannot have been called to the floor we are on.
               if (Version2_CTRL_reset_a0) begin
                  Version2_CTRL_next_floor_mask_a0[2:0] = 3'b001;     // Next value of: The floor the elevator is on (1-hot decoded).
                  Version2_CTRL_next_up_light_a0[1:0] = 2'b00;        // Next value of: Elevator up/down button lights on each floor. 1 == lit. Cleared after departure.
                  Version2_CTRL_next_down_light_a0[2:1] = 2'b00;      // Next value of: The floor lights in the elevator. 1 == lit. Cleared on arrival.
                  Version2_CTRL_next_elevator_light_a0[2:0] = 3'b000; // Next value of: The floor lights in the elevator. 1 == lit. Cleared on arrival.
               end else if (Version2_CTRL_floor_mask_a0[0]) begin
                  // From floor 0
                  if (| {Version2_CTRL_up_light_a0[1:0], Version2_CTRL_down_light_a0[2:1], Version2_CTRL_elevator_light_a0[2:1]}) begin
                     // Go up.
                     //$next_went_up = '1;
                     Version2_CTRL_next_floor_mask_a0 = 3'b010;
                     Version2_CTRL_next_up_light_a0[0] = '0;
                     Version2_CTRL_next_elevator_light_a0[1] = '0;
                  end else begin
                     // Stay.
                     Version2_CTRL_next_elevator_light_a0[0] = '0;
                  end
               end else if (Version2_CTRL_floor_mask_a0[2]) begin
                  // From floor 2
                  if (| {Version2_CTRL_down_light_a0[2:1], Version2_CTRL_up_light_a0[1:0], Version2_CTRL_elevator_light_a0[1:0]}) begin
                     // Go down.
                     Version2_CTRL_next_went_down_a0 = '1;
                     Version2_CTRL_next_floor_mask_a0 = 3'b010;
                     Version2_CTRL_next_down_light_a0[2] = '0;
                     Version2_CTRL_next_elevator_light_a0[1] = '0;
                  end else begin
                     // Stay.
                     Version2_CTRL_next_elevator_light_a0[2] = '0;
                  end
               end else begin
                  // From floor 1
                  if (Version2_CTRL_called_top_a0 && (!Version2_CTRL_went_down_a0 || !Version2_CTRL_called_bottom_a0)) begin
                     // Go up (gets priority over down when no momentum).
                     //$next_went_up = '1;
                     Version2_CTRL_next_floor_mask_a0 = 3'b100;
                     Version2_CTRL_next_up_light_a0[1] = '0;
                     Version2_CTRL_next_elevator_light_a0[2] = '0;
                  end else if (Version2_CTRL_called_bottom_a0 && (Version2_CTRL_went_down_a0 || !Version2_CTRL_called_top_a0)) begin
                     // Go down.
                     Version2_CTRL_next_went_down_a0 = '1;
                     Version2_CTRL_next_floor_mask_a0 = 3'b001;
                     Version2_CTRL_next_down_light_a0[1] = '0;
                     Version2_CTRL_next_elevator_light_a0[0] = '0;
                  end else begin
                     // Stay.
                     Version2_CTRL_next_elevator_light_a0[1] = '0;
                  end 
               end
               
               // Update state for floor button presses.
               for (int fl = 0; fl < 3; fl++) begin
                  if (Version2_CTRL_up_pressed_a0[fl]) Version2_CTRL_next_up_light_a0[fl] = '1;
                  if (Version2_CTRL_down_pressed_a0[fl]) Version2_CTRL_next_down_light_a0[fl] = '1;
               end end
            
            // Stage next state values from combinational state update logic.
            assign Version2_CTRL_went_down_a0 = Version2_CTRL_next_went_down_a1;
            //$went_up = >>1$next_went_up;
            assign Version2_CTRL_floor_mask_a0[2:0] = Version2_CTRL_next_floor_mask_a1;
            assign Version2_CTRL_up_light_a0[1:0] = Version2_CTRL_next_up_light_a1;
            assign Version2_CTRL_down_light_a0[2:1] = Version2_CTRL_next_down_light_a1;
            assign Version2_CTRL_elevator_light_a0[2:0] = Version2_CTRL_next_elevator_light_a1;

   
   // ==========
   // Version 3) Hand-coded TL-Verilog.
   // ==========
   
   // DUT
   // Macros to compute floor above/below with wrap (because some Verilog compilers complain about out-of-bounds accesses).
   // Note that for m4_above ($1 + 2) % 3 is ($1 - 1) % 3, but with positive modulo math.
   
   
   //_|ctrl
      //_@0
         assign CTRL_reset_a0 = L0_reset_a0;
         assign CTRL_next_floor_a0[1:0] = CTRL_reset_a0   ? 2'b0 :
                            CTRL_go_up_a0   ? CTRL_Floor_a0 + 2'b1 :
                            CTRL_go_down_a0 ? CTRL_Floor_a0 - 2'b1 :
                                       CTRL_next_floor_a1[1:0];
         assign CTRL_Floor_n1[1:0] = CTRL_next_floor_a0;  // WORKAROUND: <<1$Floor can't be used, currently, so $next_floor created as temporary.
         for (floor = 0; floor <= 2; floor++) begin : L1b_CTRL_Floor logic L1_DownLight_n1, L1_DownLight_a0; logic L1_ElevatorLight_n1, L1_ElevatorLight_a0; logic L1_UpLight_n1, L1_UpLight_a0; //_/floor
            // Clear elevator light on arrival at next floor, or set it after pressed.
            assign L1_ElevatorLight_n1 = CTRL_reset_a0 ? 1'b0 :
                              CTRL_next_floor_a0 == floor ? 1'b0 :
                              L1_ElevatorLight_a0 || CTRL_Floor_elevator_button_pressed_a0[floor];
            // Set up   light on this floor when pressed, and clear when leaving this floor upward.
            assign L1_UpLight_n1   = CTRL_Floor_up_pressed_a0[floor]                                ? 1'b1 :
                          ((CTRL_Floor_a0 == floor) && CTRL_go_up_a0)   ? 1'b0 :
                                                                       L1_UpLight_a0;
            // Set down light on this floor when pressed, and clear when leaving this floor downward.
            assign L1_DownLight_n1 = CTRL_Floor_down_pressed_a0[floor]                              ? 1'b1 :
                          ((CTRL_Floor_a0 == floor) && CTRL_go_down_a0) ? 1'b0 :
                                                                       L1_DownLight_a0;
            // Call elevator to this floor when requested within elevator or at floor.
            assign CTRL_Floor_called_a0[floor] = L1_ElevatorLight_a0 || L1_DownLight_a0 || L1_UpLight_a0;
            // $called_above/below if $called above/below or up/down button is lit on this floor.
            assign CTRL_Floor_called_above_a0[floor] = L1_UpLight_a0   || ((floor == 2) ? 1'b0 : CTRL_Floor_called_a0[((floor + 1) % 3)] || CTRL_Floor_called_above_a0[((floor + 1) % 3)]);
            assign CTRL_Floor_called_below_a0[floor] = L1_DownLight_a0 || ((floor == 0) ? 1'b0 : CTRL_Floor_called_a0[((floor + 2) % 3)] || CTRL_Floor_called_below_a0[((floor + 2) % 3)]); end
         // Go up or down if called that way, breaking tie based on momentum and then prioritizing up.
         assign CTRL_go_up_a0   = ((! CTRL_go_down_a1 || ! CTRL_Floor_called_below_a0[CTRL_Floor_a0]) && CTRL_Floor_called_above_a0[CTRL_Floor_a0]);
         assign CTRL_go_down_a0 = ((  CTRL_go_down_a1 || ! CTRL_Floor_called_above_a0[CTRL_Floor_a0]) && CTRL_Floor_called_below_a0[CTRL_Floor_a0]);

         
         // Compare all three models.
         assign CTRL_Error_n1 = CTRL_reset_a0 ? 1'b0 : !((floor_mask == Version2_CTRL_floor_mask_a0) && ((3'b1 << CTRL_Floor_a0) == Version2_CTRL_floor_mask_a0)) || CTRL_Error_a0;
         assign failed = (cyc_cnt > 400) &&   CTRL_Error_a0;
         assign passed = (cyc_cnt > 400) && ! CTRL_Error_a0; endgenerate
//_\SV
   endmodule
