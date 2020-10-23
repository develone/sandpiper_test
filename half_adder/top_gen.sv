// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"





//
// Signals declared top-level.
//

// For |pipe$a.
logic [1:0] PIPE_a_a0,
            PIPE_a_a1,
            PIPE_a_a2,
            PIPE_a_a3,
            PIPE_a_a4,
            PIPE_a_a5;

// For |pipe$b.
logic [1:0] PIPE_b_a0,
            PIPE_b_a1,
            PIPE_b_a2,
            PIPE_b_a3,
            PIPE_b_a4,
            PIPE_b_a5;

// For |pipe$c.
logic [4:0] PIPE_c_a0,
            PIPE_c_a1,
            PIPE_c_a2,
            PIPE_c_a3,
            PIPE_c_a4,
            PIPE_c_a5;



generate


   //
   // Scope: |pipe
   //

      // For $a.
      always_ff @(posedge clk) PIPE_a_a1[1:0] <= PIPE_a_a0[1:0];
      always_ff @(posedge clk) PIPE_a_a2[1:0] <= PIPE_a_a1[1:0];
      always_ff @(posedge clk) PIPE_a_a3[1:0] <= PIPE_a_a2[1:0];
      always_ff @(posedge clk) PIPE_a_a4[1:0] <= PIPE_a_a3[1:0];
      always_ff @(posedge clk) PIPE_a_a5[1:0] <= PIPE_a_a4[1:0];

      // For $b.
      always_ff @(posedge clk) PIPE_b_a1[1:0] <= PIPE_b_a0[1:0];
      always_ff @(posedge clk) PIPE_b_a2[1:0] <= PIPE_b_a1[1:0];
      always_ff @(posedge clk) PIPE_b_a3[1:0] <= PIPE_b_a2[1:0];
      always_ff @(posedge clk) PIPE_b_a4[1:0] <= PIPE_b_a3[1:0];
      always_ff @(posedge clk) PIPE_b_a5[1:0] <= PIPE_b_a4[1:0];

      // For $c.
      always_ff @(posedge clk) PIPE_c_a1[4:0] <= PIPE_c_a0[4:0];
      always_ff @(posedge clk) PIPE_c_a2[4:0] <= PIPE_c_a1[4:0];
      always_ff @(posedge clk) PIPE_c_a3[4:0] <= PIPE_c_a2[4:0];
      always_ff @(posedge clk) PIPE_c_a4[4:0] <= PIPE_c_a3[4:0];
      always_ff @(posedge clk) PIPE_c_a5[4:0] <= PIPE_c_a4[4:0];




endgenerate




//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS


      //
      // Scope: |pipe
      //
      if (1) begin : \|pipe 
         logic [1:0] \@0$a ;
         assign \@0$a = PIPE_a_a0;
         logic [1:0] \@0$b ;
         assign \@0$b = PIPE_b_a0;
         logic [4:0] \@0$c ;
         assign \@0$c = PIPE_c_a0;
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.