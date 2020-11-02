// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"


genvar slice;


//
// Signals declared top-level.
//

// For $value.
logic [8-1:0] L0_value_a0;

// For /slice$Value.
logic [8-1:0] Slice_Value_n1,
              Slice_Value_a0;

// For /slice$carry_out.
logic Slice_carry_out_a0 [8-1:0];

// For /tb$Value.
logic [8-1:0] Tb_Value_n1,
              Tb_Value_a0;

// For /tb$error.
logic Tb_error_a0;



generate


   //
   // Scope: /slice[8-1:0]
   //
   for (slice = 0; slice <= 8-1; slice++) begin : L1gen_Slice
      // For $Value.
      always_ff @(posedge clk) Slice_Value_a0[slice] <= Slice_Value_n1[slice];

   end

   //
   // Scope: /tb
   //

      // For $Value.
      always_ff @(posedge clk) Tb_Value_a0[8-1:0] <= Tb_Value_n1[8-1:0];




endgenerate




//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS

      logic [8-1:0] \@0$value ;
      assign \@0$value = L0_value_a0;

      //
      // Scope: /slice[8-1:0]
      //
      for (slice = 0; slice <= 8-1; slice++) begin : \/slice 
         logic  \@-1$Value ;
         assign \@-1$Value = Slice_Value_n1[slice];
         logic  \@0$carry_in ;
         assign \@0$carry_in = L1_Slice[slice].L1_carry_in_a0;
         logic  \@0$carry_out ;
         assign \@0$carry_out = Slice_carry_out_a0[slice];
      end

      //
      // Scope: /tb
      //
      if (1) begin : \/tb 
         logic [8-1:0] \@-1$Value ;
         assign \@-1$Value = Tb_Value_n1;
         logic  \@0$error ;
         assign \@0$error = Tb_error_a0;
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.