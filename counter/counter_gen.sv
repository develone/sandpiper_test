// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"





//
// Signals declared top-level.
//

// For $num.
logic [15:0] L0_num_a0,
             L0_num_a1;



generate

   // For $num.
   always_ff @(posedge clk) L0_num_a1[15:0] <= L0_num_a0[15:0];



endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
