// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"


genvar floor;


//
// Signals declared top-level.
//

// For $reset.
logic L0_reset_a0;

// For /version2|ctrl$called_bottom.
logic Version2_CTRL_called_bottom_a0;

// For /version2|ctrl$called_top.
logic Version2_CTRL_called_top_a0;

// For /version2|ctrl$down_light.
logic [2:1] Version2_CTRL_down_light_a0;

// For /version2|ctrl$down_pressed.
logic [2:0] Version2_CTRL_down_pressed_a0;

// For /version2|ctrl$elevator_button_pressed.
logic [2:0] Version2_CTRL_elevator_button_pressed_a0;

// For /version2|ctrl$elevator_light.
logic [2:0] Version2_CTRL_elevator_light_a0;

// For /version2|ctrl$floor_mask.
logic [2:0] Version2_CTRL_floor_mask_a0;

// For /version2|ctrl$next_down_light.
logic [2:1] Version2_CTRL_next_down_light_a0,
            Version2_CTRL_next_down_light_a1;

// For /version2|ctrl$next_elevator_light.
logic [2:0] Version2_CTRL_next_elevator_light_a0,
            Version2_CTRL_next_elevator_light_a1;

// For /version2|ctrl$next_floor_mask.
logic [2:0] Version2_CTRL_next_floor_mask_a0,
            Version2_CTRL_next_floor_mask_a1;

// For /version2|ctrl$next_up_light.
logic [1:0] Version2_CTRL_next_up_light_a0,
            Version2_CTRL_next_up_light_a1;

// For /version2|ctrl$next_went_down.
logic Version2_CTRL_next_went_down_a0,
      Version2_CTRL_next_went_down_a1;

// For /version2|ctrl$reset.
logic Version2_CTRL_reset_a0;

// For /version2|ctrl$up_light.
logic [1:0] Version2_CTRL_up_light_a0;

// For /version2|ctrl$up_pressed.
logic [2:0] Version2_CTRL_up_pressed_a0;

// For /version2|ctrl$went_down.
logic Version2_CTRL_went_down_a0;

// For |ctrl$Error.
logic CTRL_Error_n1,
      CTRL_Error_a0;

// For |ctrl$Floor.
logic [1:0] CTRL_Floor_n1,
            CTRL_Floor_a0;

// For |ctrl$go_down.
logic CTRL_go_down_a0,
      CTRL_go_down_a1;

// For |ctrl$go_up.
logic CTRL_go_up_a0;

// For |ctrl$next_floor.
logic [1:0] CTRL_next_floor_a0,
            CTRL_next_floor_a1;

// For |ctrl$reset.
logic CTRL_reset_a0;

// For |ctrl/floor$called.
logic CTRL_Floor_called_a0 [2:0];

// For |ctrl/floor$called_above.
logic CTRL_Floor_called_above_a0 [2:0];

// For |ctrl/floor$called_below.
logic CTRL_Floor_called_below_a0 [2:0];

// For |ctrl/floor$down_pressed.
logic [2:0] CTRL_Floor_down_pressed_a0;

// For |ctrl/floor$elevator_button_pressed.
logic [2:0] CTRL_Floor_elevator_button_pressed_a0;

// For |ctrl/floor$up_pressed.
logic [2:0] CTRL_Floor_up_pressed_a0;



generate


   //
   // Scope: /version2
   //


      //
      // Scope: |ctrl
      //

         // For $next_down_light.
         always_ff @(posedge clk) Version2_CTRL_next_down_light_a1[2:1] <= Version2_CTRL_next_down_light_a0[2:1];

         // For $next_elevator_light.
         always_ff @(posedge clk) Version2_CTRL_next_elevator_light_a1[2:0] <= Version2_CTRL_next_elevator_light_a0[2:0];

         // For $next_floor_mask.
         always_ff @(posedge clk) Version2_CTRL_next_floor_mask_a1[2:0] <= Version2_CTRL_next_floor_mask_a0[2:0];

         // For $next_up_light.
         always_ff @(posedge clk) Version2_CTRL_next_up_light_a1[1:0] <= Version2_CTRL_next_up_light_a0[1:0];

         // For $next_went_down.
         always_ff @(posedge clk) Version2_CTRL_next_went_down_a1 <= Version2_CTRL_next_went_down_a0;




   //
   // Scope: |ctrl
   //

      // For $Error.
      always_ff @(posedge clk) CTRL_Error_a0 <= CTRL_Error_n1;

      // For $Floor.
      always_ff @(posedge clk) CTRL_Floor_a0[1:0] <= CTRL_Floor_n1[1:0];

      // For $go_down.
      always_ff @(posedge clk) CTRL_go_down_a1 <= CTRL_go_down_a0;

      // For $next_floor.
      always_ff @(posedge clk) CTRL_next_floor_a1[1:0] <= CTRL_next_floor_a0[1:0];


      //
      // Scope: /floor[2:0]
      //
      for (floor = 0; floor <= 2; floor++) begin : L1gen_CTRL_Floor
         // For $DownLight.
         always_ff @(posedge clk) L1b_CTRL_Floor[floor].L1_DownLight_a0 <= L1b_CTRL_Floor[floor].L1_DownLight_n1;

         // For $ElevatorLight.
         always_ff @(posedge clk) L1b_CTRL_Floor[floor].L1_ElevatorLight_a0 <= L1b_CTRL_Floor[floor].L1_ElevatorLight_n1;

         // For $UpLight.
         always_ff @(posedge clk) L1b_CTRL_Floor[floor].L1_UpLight_a0 <= L1b_CTRL_Floor[floor].L1_UpLight_n1;

      end



endgenerate




//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS

      logic  \@0$reset ;
      assign \@0$reset = L0_reset_a0;

      //
      // Scope: /version2
      //
      if (1) begin : \/version2 

         //
         // Scope: |ctrl
         //
         if (1) begin : \|ctrl 
            logic  \@0$called_bottom ;
            assign \@0$called_bottom = Version2_CTRL_called_bottom_a0;
            logic  \@0$called_top ;
            assign \@0$called_top = Version2_CTRL_called_top_a0;
            logic [2:1] \@0$down_light ;
            assign \@0$down_light = Version2_CTRL_down_light_a0;
            logic [2:0] \@0$down_pressed ;
            assign \@0$down_pressed = Version2_CTRL_down_pressed_a0;
            logic [2:0] \@0$elevator_button_pressed ;
            assign \@0$elevator_button_pressed = Version2_CTRL_elevator_button_pressed_a0;
            logic [2:0] \@0$elevator_light ;
            assign \@0$elevator_light = Version2_CTRL_elevator_light_a0;
            logic [2:0] \@0$floor_mask ;
            assign \@0$floor_mask = Version2_CTRL_floor_mask_a0;
            logic [2:1] \@0$next_down_light ;
            assign \@0$next_down_light = Version2_CTRL_next_down_light_a0;
            logic [2:0] \@0$next_elevator_light ;
            assign \@0$next_elevator_light = Version2_CTRL_next_elevator_light_a0;
            logic [2:0] \@0$next_floor_mask ;
            assign \@0$next_floor_mask = Version2_CTRL_next_floor_mask_a0;
            logic [1:0] \@0$next_up_light ;
            assign \@0$next_up_light = Version2_CTRL_next_up_light_a0;
            logic  \@0$next_went_down ;
            assign \@0$next_went_down = Version2_CTRL_next_went_down_a0;
            logic  \@0$reset ;
            assign \@0$reset = Version2_CTRL_reset_a0;
            logic [1:0] \@0$up_light ;
            assign \@0$up_light = Version2_CTRL_up_light_a0;
            logic [2:0] \@0$up_pressed ;
            assign \@0$up_pressed = Version2_CTRL_up_pressed_a0;
            logic  \@0$went_down ;
            assign \@0$went_down = Version2_CTRL_went_down_a0;
         end
      end

      //
      // Scope: |ctrl
      //
      if (1) begin : \|ctrl 
         logic  \@-1$Error ;
         assign \@-1$Error = CTRL_Error_n1;
         logic [1:0] \@-1$Floor ;
         assign \@-1$Floor = CTRL_Floor_n1;
         logic  \@0$go_down ;
         assign \@0$go_down = CTRL_go_down_a0;
         logic  \@0$go_up ;
         assign \@0$go_up = CTRL_go_up_a0;
         logic [1:0] \@0$next_floor ;
         assign \@0$next_floor = CTRL_next_floor_a0;
         logic  \@0$reset ;
         assign \@0$reset = CTRL_reset_a0;

         //
         // Scope: /floor[2:0]
         //
         for (floor = 0; floor <= 2; floor++) begin : \/floor 
            logic  \@-1$DownLight ;
            assign \@-1$DownLight = L1b_CTRL_Floor[floor].L1_DownLight_n1;
            logic  \@-1$ElevatorLight ;
            assign \@-1$ElevatorLight = L1b_CTRL_Floor[floor].L1_ElevatorLight_n1;
            logic  \@-1$UpLight ;
            assign \@-1$UpLight = L1b_CTRL_Floor[floor].L1_UpLight_n1;
            logic  \@0$called ;
            assign \@0$called = CTRL_Floor_called_a0[floor];
            logic  \@0$called_above ;
            assign \@0$called_above = CTRL_Floor_called_above_a0[floor];
            logic  \@0$called_below ;
            assign \@0$called_below = CTRL_Floor_called_below_a0[floor];
            logic  \@0$down_pressed ;
            assign \@0$down_pressed = CTRL_Floor_down_pressed_a0[floor];
            logic  \@0$elevator_button_pressed ;
            assign \@0$elevator_button_pressed = CTRL_Floor_elevator_button_pressed_a0[floor];
            logic  \@0$up_pressed ;
            assign \@0$up_pressed = CTRL_Floor_up_pressed_a0[floor];
         end
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
