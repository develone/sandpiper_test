// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"





//
// Signals declared top-level.
//

// For $reset.
logic L0_reset_a0;





//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS

      logic  \@0$reset ;
      assign \@0$reset = L0_reset_a0;


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
