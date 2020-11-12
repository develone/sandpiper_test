// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"





//
// Signals declared top-level.
//

// For |axil$S_AXI_AWADDR.
logic [C_AXI_ADDR_WIDTH-1:0] AXIL_S_AXI_AWADDR_a0,
                             AXIL_S_AXI_AWADDR_a1,
                             AXIL_S_AXI_AWADDR_a2,
                             AXIL_S_AXI_AWADDR_a3,
                             AXIL_S_AXI_AWADDR_a4,
                             AXIL_S_AXI_AWADDR_a5;

// For |axil$S_AXI_AWREADY.
logic AXIL_S_AXI_AWREADY_a0,
      AXIL_S_AXI_AWREADY_a1,
      AXIL_S_AXI_AWREADY_a2,
      AXIL_S_AXI_AWREADY_a3,
      AXIL_S_AXI_AWREADY_a4,
      AXIL_S_AXI_AWREADY_a5;

// For |axil$S_AXI_AWVALID.
logic AXIL_S_AXI_AWVALID_a0,
      AXIL_S_AXI_AWVALID_a1,
      AXIL_S_AXI_AWVALID_a2,
      AXIL_S_AXI_AWVALID_a3,
      AXIL_S_AXI_AWVALID_a4,
      AXIL_S_AXI_AWVALID_a5;

// For |axil$S_AXI_WREADY.
logic AXIL_S_AXI_WREADY_a0,
      AXIL_S_AXI_WREADY_a1,
      AXIL_S_AXI_WREADY_a2,
      AXIL_S_AXI_WREADY_a3,
      AXIL_S_AXI_WREADY_a4,
      AXIL_S_AXI_WREADY_a5;

// For |axil$S_AXI_WVALID.
logic AXIL_S_AXI_WVALID_a0,
      AXIL_S_AXI_WVALID_a1,
      AXIL_S_AXI_WVALID_a2,
      AXIL_S_AXI_WVALID_a3,
      AXIL_S_AXI_WVALID_a4,
      AXIL_S_AXI_WVALID_a5;

// For |axil$reset.
logic AXIL_reset_a0;



generate


   //
   // Scope: |axil
   //

      // For $S_AXI_AWADDR.
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a1[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a0[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a2[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a1[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a3[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a2[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a4[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a3[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a5[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a4[C_AXI_ADDR_WIDTH-1:0];

      // For $S_AXI_AWREADY.
      always_ff @(posedge clk) AXIL_S_AXI_AWREADY_a1 <= AXIL_S_AXI_AWREADY_a0;
      always_ff @(posedge clk) AXIL_S_AXI_AWREADY_a2 <= AXIL_S_AXI_AWREADY_a1;
      always_ff @(posedge clk) AXIL_S_AXI_AWREADY_a3 <= AXIL_S_AXI_AWREADY_a2;
      always_ff @(posedge clk) AXIL_S_AXI_AWREADY_a4 <= AXIL_S_AXI_AWREADY_a3;
      always_ff @(posedge clk) AXIL_S_AXI_AWREADY_a5 <= AXIL_S_AXI_AWREADY_a4;

      // For $S_AXI_AWVALID.
      always_ff @(posedge clk) AXIL_S_AXI_AWVALID_a1 <= AXIL_S_AXI_AWVALID_a0;
      always_ff @(posedge clk) AXIL_S_AXI_AWVALID_a2 <= AXIL_S_AXI_AWVALID_a1;
      always_ff @(posedge clk) AXIL_S_AXI_AWVALID_a3 <= AXIL_S_AXI_AWVALID_a2;
      always_ff @(posedge clk) AXIL_S_AXI_AWVALID_a4 <= AXIL_S_AXI_AWVALID_a3;
      always_ff @(posedge clk) AXIL_S_AXI_AWVALID_a5 <= AXIL_S_AXI_AWVALID_a4;

      // For $S_AXI_WREADY.
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a1 <= AXIL_S_AXI_WREADY_a0;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a2 <= AXIL_S_AXI_WREADY_a1;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a3 <= AXIL_S_AXI_WREADY_a2;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a4 <= AXIL_S_AXI_WREADY_a3;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a5 <= AXIL_S_AXI_WREADY_a4;

      // For $S_AXI_WVALID.
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a1 <= AXIL_S_AXI_WVALID_a0;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a2 <= AXIL_S_AXI_WVALID_a1;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a3 <= AXIL_S_AXI_WVALID_a2;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a4 <= AXIL_S_AXI_WVALID_a3;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a5 <= AXIL_S_AXI_WVALID_a4;




endgenerate




//
// Debug Signals
//

generate

   if (1) begin : DEBUG_SIGS


      //
      // Scope: |axil
      //
      if (1) begin : \|axil 
         logic [C_AXI_ADDR_WIDTH-1:0] \@0$S_AXI_AWADDR ;
         assign \@0$S_AXI_AWADDR = AXIL_S_AXI_AWADDR_a0;
         logic  \@0$S_AXI_AWREADY ;
         assign \@0$S_AXI_AWREADY = AXIL_S_AXI_AWREADY_a0;
         logic  \@0$S_AXI_AWVALID ;
         assign \@0$S_AXI_AWVALID = AXIL_S_AXI_AWVALID_a0;
         logic  \@0$S_AXI_WREADY ;
         assign \@0$S_AXI_WREADY = AXIL_S_AXI_WREADY_a0;
         logic  \@0$S_AXI_WVALID ;
         assign \@0$S_AXI_WVALID = AXIL_S_AXI_WVALID_a0;
         logic  \@0$reset ;
         assign \@0$reset = AXIL_reset_a0;
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.