// Generated by SandPiper(TM) 1.9-2018/02/11-beta from Redwood EDA.
// (Installed here: /home/devel/SandPiper_1.9-2018_02_11-beta_distro.)
// Redwood EDA does not claim intellectual property rights to this file and provides no warranty regarding its correctness or quality.


`include "sandpiper_gen.vh"





//
// Signals declared top-level.
//

// For |axil$M_AXIS_TDATA.
logic [C_AXI_DATA_WIDTH-1:0] AXIL_M_AXIS_TDATA_a0,
                             AXIL_M_AXIS_TDATA_a1,
                             AXIL_M_AXIS_TDATA_a2,
                             AXIL_M_AXIS_TDATA_a3,
                             AXIL_M_AXIS_TDATA_a4,
                             AXIL_M_AXIS_TDATA_a5;

// For |axil$M_AXIS_TREADY.
logic AXIL_M_AXIS_TREADY_a0,
      AXIL_M_AXIS_TREADY_a1,
      AXIL_M_AXIS_TREADY_a2,
      AXIL_M_AXIS_TREADY_a3,
      AXIL_M_AXIS_TREADY_a4,
      AXIL_M_AXIS_TREADY_a5;

// For |axil$M_AXIS_TVALID.
logic AXIL_M_AXIS_TVALID_a0,
      AXIL_M_AXIS_TVALID_a1,
      AXIL_M_AXIS_TVALID_a2,
      AXIL_M_AXIS_TVALID_a3,
      AXIL_M_AXIS_TVALID_a4,
      AXIL_M_AXIS_TVALID_a5;

// For |axil$S_AXI_AWADDR.
logic [C_AXI_ADDR_WIDTH-1:0] AXIL_S_AXI_AWADDR_a0,
                             AXIL_S_AXI_AWADDR_a1,
                             AXIL_S_AXI_AWADDR_a2,
                             AXIL_S_AXI_AWADDR_a3,
                             AXIL_S_AXI_AWADDR_a4,
                             AXIL_S_AXI_AWADDR_a5;

// For |axil$S_AXI_AWPROT.
logic [2:0] AXIL_S_AXI_AWPROT_a0,
            AXIL_S_AXI_AWPROT_a1,
            AXIL_S_AXI_AWPROT_a2,
            AXIL_S_AXI_AWPROT_a3,
            AXIL_S_AXI_AWPROT_a4,
            AXIL_S_AXI_AWPROT_a5;

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

// For |axil$S_AXI_RDATA.
logic [C_AXI_DATA_WIDTH-1:0] AXIL_S_AXI_RDATA_a0,
                             AXIL_S_AXI_RDATA_a1,
                             AXIL_S_AXI_RDATA_a2,
                             AXIL_S_AXI_RDATA_a3,
                             AXIL_S_AXI_RDATA_a4,
                             AXIL_S_AXI_RDATA_a5;

// For |axil$S_AXI_RREADY.
logic AXIL_S_AXI_RREADY_a0,
      AXIL_S_AXI_RREADY_a1,
      AXIL_S_AXI_RREADY_a2,
      AXIL_S_AXI_RREADY_a3,
      AXIL_S_AXI_RREADY_a4,
      AXIL_S_AXI_RREADY_a5;

// For |axil$S_AXI_RVALID.
logic AXIL_S_AXI_RVALID_a0,
      AXIL_S_AXI_RVALID_a1,
      AXIL_S_AXI_RVALID_a2,
      AXIL_S_AXI_RVALID_a3,
      AXIL_S_AXI_RVALID_a4,
      AXIL_S_AXI_RVALID_a5;

// For |axil$S_AXI_WDATA.
logic [C_AXI_DATA_WIDTH-1:0] AXIL_S_AXI_WDATA_a0,
                             AXIL_S_AXI_WDATA_a1,
                             AXIL_S_AXI_WDATA_a2,
                             AXIL_S_AXI_WDATA_a3,
                             AXIL_S_AXI_WDATA_a4,
                             AXIL_S_AXI_WDATA_a5;

// For |axil$S_AXI_WREADY.
logic AXIL_S_AXI_WREADY_a0,
      AXIL_S_AXI_WREADY_a1,
      AXIL_S_AXI_WREADY_a2,
      AXIL_S_AXI_WREADY_a3,
      AXIL_S_AXI_WREADY_a4,
      AXIL_S_AXI_WREADY_a5;

// For |axil$S_AXI_WSTRB.
logic [C_AXI_DATA_WIDTH/8-1:0] AXIL_S_AXI_WSTRB_a0,
                               AXIL_S_AXI_WSTRB_a1,
                               AXIL_S_AXI_WSTRB_a2,
                               AXIL_S_AXI_WSTRB_a3,
                               AXIL_S_AXI_WSTRB_a4,
                               AXIL_S_AXI_WSTRB_a5;

// For |axil$S_AXI_WVALID.
logic AXIL_S_AXI_WVALID_a0,
      AXIL_S_AXI_WVALID_a1,
      AXIL_S_AXI_WVALID_a2,
      AXIL_S_AXI_WVALID_a3,
      AXIL_S_AXI_WVALID_a4,
      AXIL_S_AXI_WVALID_a5;

// For |axil$i_data.
logic [DW-1:0] AXIL_i_data_a0,
               AXIL_i_data_a1,
               AXIL_i_data_a2,
               AXIL_i_data_a3,
               AXIL_i_data_a4,
               AXIL_i_data_a5;

// For |axil$i_ready.
logic AXIL_i_ready_a0,
      AXIL_i_ready_a1,
      AXIL_i_ready_a2,
      AXIL_i_ready_a3,
      AXIL_i_ready_a4,
      AXIL_i_ready_a5;

// For |axil$i_valid.
logic AXIL_i_valid_a0,
      AXIL_i_valid_a1,
      AXIL_i_valid_a2,
      AXIL_i_valid_a3,
      AXIL_i_valid_a4,
      AXIL_i_valid_a5;

// For |axil$o_data.
logic [DW-1:0] AXIL_o_data_a0,
               AXIL_o_data_a1,
               AXIL_o_data_a2,
               AXIL_o_data_a3,
               AXIL_o_data_a4,
               AXIL_o_data_a5;

// For |axil$o_ready.
logic AXIL_o_ready_a0,
      AXIL_o_ready_a1,
      AXIL_o_ready_a2,
      AXIL_o_ready_a3,
      AXIL_o_ready_a4,
      AXIL_o_ready_a5;

// For |axil$o_valid.
logic AXIL_o_valid_a0,
      AXIL_o_valid_a1,
      AXIL_o_valid_a2,
      AXIL_o_valid_a3,
      AXIL_o_valid_a4,
      AXIL_o_valid_a5;

// For |axil$reset.
logic AXIL_reset_a0;



generate


   //
   // Scope: |axil
   //

      // For $M_AXIS_TDATA.
      always_ff @(posedge clk) AXIL_M_AXIS_TDATA_a1[C_AXI_DATA_WIDTH-1:0] <= AXIL_M_AXIS_TDATA_a0[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_M_AXIS_TDATA_a2[C_AXI_DATA_WIDTH-1:0] <= AXIL_M_AXIS_TDATA_a1[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_M_AXIS_TDATA_a3[C_AXI_DATA_WIDTH-1:0] <= AXIL_M_AXIS_TDATA_a2[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_M_AXIS_TDATA_a4[C_AXI_DATA_WIDTH-1:0] <= AXIL_M_AXIS_TDATA_a3[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_M_AXIS_TDATA_a5[C_AXI_DATA_WIDTH-1:0] <= AXIL_M_AXIS_TDATA_a4[C_AXI_DATA_WIDTH-1:0];

      // For $M_AXIS_TREADY.
      always_ff @(posedge clk) AXIL_M_AXIS_TREADY_a1 <= AXIL_M_AXIS_TREADY_a0;
      always_ff @(posedge clk) AXIL_M_AXIS_TREADY_a2 <= AXIL_M_AXIS_TREADY_a1;
      always_ff @(posedge clk) AXIL_M_AXIS_TREADY_a3 <= AXIL_M_AXIS_TREADY_a2;
      always_ff @(posedge clk) AXIL_M_AXIS_TREADY_a4 <= AXIL_M_AXIS_TREADY_a3;
      always_ff @(posedge clk) AXIL_M_AXIS_TREADY_a5 <= AXIL_M_AXIS_TREADY_a4;

      // For $M_AXIS_TVALID.
      always_ff @(posedge clk) AXIL_M_AXIS_TVALID_a1 <= AXIL_M_AXIS_TVALID_a0;
      always_ff @(posedge clk) AXIL_M_AXIS_TVALID_a2 <= AXIL_M_AXIS_TVALID_a1;
      always_ff @(posedge clk) AXIL_M_AXIS_TVALID_a3 <= AXIL_M_AXIS_TVALID_a2;
      always_ff @(posedge clk) AXIL_M_AXIS_TVALID_a4 <= AXIL_M_AXIS_TVALID_a3;
      always_ff @(posedge clk) AXIL_M_AXIS_TVALID_a5 <= AXIL_M_AXIS_TVALID_a4;

      // For $S_AXI_AWADDR.
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a1[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a0[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a2[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a1[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a3[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a2[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a4[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a3[C_AXI_ADDR_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWADDR_a5[C_AXI_ADDR_WIDTH-1:0] <= AXIL_S_AXI_AWADDR_a4[C_AXI_ADDR_WIDTH-1:0];

      // For $S_AXI_AWPROT.
      always_ff @(posedge clk) AXIL_S_AXI_AWPROT_a1[2:0] <= AXIL_S_AXI_AWPROT_a0[2:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWPROT_a2[2:0] <= AXIL_S_AXI_AWPROT_a1[2:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWPROT_a3[2:0] <= AXIL_S_AXI_AWPROT_a2[2:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWPROT_a4[2:0] <= AXIL_S_AXI_AWPROT_a3[2:0];
      always_ff @(posedge clk) AXIL_S_AXI_AWPROT_a5[2:0] <= AXIL_S_AXI_AWPROT_a4[2:0];

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

      // For $S_AXI_RDATA.
      always_ff @(posedge clk) AXIL_S_AXI_RDATA_a1[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_RDATA_a0[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_RDATA_a2[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_RDATA_a1[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_RDATA_a3[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_RDATA_a2[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_RDATA_a4[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_RDATA_a3[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_RDATA_a5[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_RDATA_a4[C_AXI_DATA_WIDTH-1:0];

      // For $S_AXI_RREADY.
      always_ff @(posedge clk) AXIL_S_AXI_RREADY_a1 <= AXIL_S_AXI_RREADY_a0;
      always_ff @(posedge clk) AXIL_S_AXI_RREADY_a2 <= AXIL_S_AXI_RREADY_a1;
      always_ff @(posedge clk) AXIL_S_AXI_RREADY_a3 <= AXIL_S_AXI_RREADY_a2;
      always_ff @(posedge clk) AXIL_S_AXI_RREADY_a4 <= AXIL_S_AXI_RREADY_a3;
      always_ff @(posedge clk) AXIL_S_AXI_RREADY_a5 <= AXIL_S_AXI_RREADY_a4;

      // For $S_AXI_RVALID.
      always_ff @(posedge clk) AXIL_S_AXI_RVALID_a1 <= AXIL_S_AXI_RVALID_a0;
      always_ff @(posedge clk) AXIL_S_AXI_RVALID_a2 <= AXIL_S_AXI_RVALID_a1;
      always_ff @(posedge clk) AXIL_S_AXI_RVALID_a3 <= AXIL_S_AXI_RVALID_a2;
      always_ff @(posedge clk) AXIL_S_AXI_RVALID_a4 <= AXIL_S_AXI_RVALID_a3;
      always_ff @(posedge clk) AXIL_S_AXI_RVALID_a5 <= AXIL_S_AXI_RVALID_a4;

      // For $S_AXI_WDATA.
      always_ff @(posedge clk) AXIL_S_AXI_WDATA_a1[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_WDATA_a0[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WDATA_a2[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_WDATA_a1[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WDATA_a3[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_WDATA_a2[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WDATA_a4[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_WDATA_a3[C_AXI_DATA_WIDTH-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WDATA_a5[C_AXI_DATA_WIDTH-1:0] <= AXIL_S_AXI_WDATA_a4[C_AXI_DATA_WIDTH-1:0];

      // For $S_AXI_WREADY.
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a1 <= AXIL_S_AXI_WREADY_a0;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a2 <= AXIL_S_AXI_WREADY_a1;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a3 <= AXIL_S_AXI_WREADY_a2;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a4 <= AXIL_S_AXI_WREADY_a3;
      always_ff @(posedge clk) AXIL_S_AXI_WREADY_a5 <= AXIL_S_AXI_WREADY_a4;

      // For $S_AXI_WSTRB.
      always_ff @(posedge clk) AXIL_S_AXI_WSTRB_a1[C_AXI_DATA_WIDTH/8-1:0] <= AXIL_S_AXI_WSTRB_a0[C_AXI_DATA_WIDTH/8-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WSTRB_a2[C_AXI_DATA_WIDTH/8-1:0] <= AXIL_S_AXI_WSTRB_a1[C_AXI_DATA_WIDTH/8-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WSTRB_a3[C_AXI_DATA_WIDTH/8-1:0] <= AXIL_S_AXI_WSTRB_a2[C_AXI_DATA_WIDTH/8-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WSTRB_a4[C_AXI_DATA_WIDTH/8-1:0] <= AXIL_S_AXI_WSTRB_a3[C_AXI_DATA_WIDTH/8-1:0];
      always_ff @(posedge clk) AXIL_S_AXI_WSTRB_a5[C_AXI_DATA_WIDTH/8-1:0] <= AXIL_S_AXI_WSTRB_a4[C_AXI_DATA_WIDTH/8-1:0];

      // For $S_AXI_WVALID.
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a1 <= AXIL_S_AXI_WVALID_a0;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a2 <= AXIL_S_AXI_WVALID_a1;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a3 <= AXIL_S_AXI_WVALID_a2;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a4 <= AXIL_S_AXI_WVALID_a3;
      always_ff @(posedge clk) AXIL_S_AXI_WVALID_a5 <= AXIL_S_AXI_WVALID_a4;

      // For $i_data.
      always_ff @(posedge clk) AXIL_i_data_a1[DW-1:0] <= AXIL_i_data_a0[DW-1:0];
      always_ff @(posedge clk) AXIL_i_data_a2[DW-1:0] <= AXIL_i_data_a1[DW-1:0];
      always_ff @(posedge clk) AXIL_i_data_a3[DW-1:0] <= AXIL_i_data_a2[DW-1:0];
      always_ff @(posedge clk) AXIL_i_data_a4[DW-1:0] <= AXIL_i_data_a3[DW-1:0];
      always_ff @(posedge clk) AXIL_i_data_a5[DW-1:0] <= AXIL_i_data_a4[DW-1:0];

      // For $i_ready.
      always_ff @(posedge clk) AXIL_i_ready_a1 <= AXIL_i_ready_a0;
      always_ff @(posedge clk) AXIL_i_ready_a2 <= AXIL_i_ready_a1;
      always_ff @(posedge clk) AXIL_i_ready_a3 <= AXIL_i_ready_a2;
      always_ff @(posedge clk) AXIL_i_ready_a4 <= AXIL_i_ready_a3;
      always_ff @(posedge clk) AXIL_i_ready_a5 <= AXIL_i_ready_a4;

      // For $i_valid.
      always_ff @(posedge clk) AXIL_i_valid_a1 <= AXIL_i_valid_a0;
      always_ff @(posedge clk) AXIL_i_valid_a2 <= AXIL_i_valid_a1;
      always_ff @(posedge clk) AXIL_i_valid_a3 <= AXIL_i_valid_a2;
      always_ff @(posedge clk) AXIL_i_valid_a4 <= AXIL_i_valid_a3;
      always_ff @(posedge clk) AXIL_i_valid_a5 <= AXIL_i_valid_a4;

      // For $o_data.
      always_ff @(posedge clk) AXIL_o_data_a1[DW-1:0] <= AXIL_o_data_a0[DW-1:0];
      always_ff @(posedge clk) AXIL_o_data_a2[DW-1:0] <= AXIL_o_data_a1[DW-1:0];
      always_ff @(posedge clk) AXIL_o_data_a3[DW-1:0] <= AXIL_o_data_a2[DW-1:0];
      always_ff @(posedge clk) AXIL_o_data_a4[DW-1:0] <= AXIL_o_data_a3[DW-1:0];
      always_ff @(posedge clk) AXIL_o_data_a5[DW-1:0] <= AXIL_o_data_a4[DW-1:0];

      // For $o_ready.
      always_ff @(posedge clk) AXIL_o_ready_a1 <= AXIL_o_ready_a0;
      always_ff @(posedge clk) AXIL_o_ready_a2 <= AXIL_o_ready_a1;
      always_ff @(posedge clk) AXIL_o_ready_a3 <= AXIL_o_ready_a2;
      always_ff @(posedge clk) AXIL_o_ready_a4 <= AXIL_o_ready_a3;
      always_ff @(posedge clk) AXIL_o_ready_a5 <= AXIL_o_ready_a4;

      // For $o_valid.
      always_ff @(posedge clk) AXIL_o_valid_a1 <= AXIL_o_valid_a0;
      always_ff @(posedge clk) AXIL_o_valid_a2 <= AXIL_o_valid_a1;
      always_ff @(posedge clk) AXIL_o_valid_a3 <= AXIL_o_valid_a2;
      always_ff @(posedge clk) AXIL_o_valid_a4 <= AXIL_o_valid_a3;
      always_ff @(posedge clk) AXIL_o_valid_a5 <= AXIL_o_valid_a4;




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
         logic [C_AXI_DATA_WIDTH-1:0] \@0$M_AXIS_TDATA ;
         assign \@0$M_AXIS_TDATA = AXIL_M_AXIS_TDATA_a0;
         logic  \@0$M_AXIS_TREADY ;
         assign \@0$M_AXIS_TREADY = AXIL_M_AXIS_TREADY_a0;
         logic  \@0$M_AXIS_TVALID ;
         assign \@0$M_AXIS_TVALID = AXIL_M_AXIS_TVALID_a0;
         logic [C_AXI_ADDR_WIDTH-1:0] \@0$S_AXI_AWADDR ;
         assign \@0$S_AXI_AWADDR = AXIL_S_AXI_AWADDR_a0;
         logic [2:0] \@0$S_AXI_AWPROT ;
         assign \@0$S_AXI_AWPROT = AXIL_S_AXI_AWPROT_a0;
         logic  \@0$S_AXI_AWREADY ;
         assign \@0$S_AXI_AWREADY = AXIL_S_AXI_AWREADY_a0;
         logic  \@0$S_AXI_AWVALID ;
         assign \@0$S_AXI_AWVALID = AXIL_S_AXI_AWVALID_a0;
         logic [C_AXI_DATA_WIDTH-1:0] \@0$S_AXI_RDATA ;
         assign \@0$S_AXI_RDATA = AXIL_S_AXI_RDATA_a0;
         logic  \@0$S_AXI_RREADY ;
         assign \@0$S_AXI_RREADY = AXIL_S_AXI_RREADY_a0;
         logic  \@0$S_AXI_RVALID ;
         assign \@0$S_AXI_RVALID = AXIL_S_AXI_RVALID_a0;
         logic [C_AXI_DATA_WIDTH-1:0] \@0$S_AXI_WDATA ;
         assign \@0$S_AXI_WDATA = AXIL_S_AXI_WDATA_a0;
         logic  \@0$S_AXI_WREADY ;
         assign \@0$S_AXI_WREADY = AXIL_S_AXI_WREADY_a0;
         logic [C_AXI_DATA_WIDTH/8-1:0] \@0$S_AXI_WSTRB ;
         assign \@0$S_AXI_WSTRB = AXIL_S_AXI_WSTRB_a0;
         logic  \@0$S_AXI_WVALID ;
         assign \@0$S_AXI_WVALID = AXIL_S_AXI_WVALID_a0;
         logic [DW-1:0] \@0$i_data ;
         assign \@0$i_data = AXIL_i_data_a0;
         logic  \@0$i_ready ;
         assign \@0$i_ready = AXIL_i_ready_a0;
         logic  \@0$i_valid ;
         assign \@0$i_valid = AXIL_i_valid_a0;
         logic [DW-1:0] \@0$o_data ;
         assign \@0$o_data = AXIL_o_data_a0;
         logic  \@0$o_ready ;
         assign \@0$o_ready = AXIL_o_ready_a0;
         logic  \@0$o_valid ;
         assign \@0$o_valid = AXIL_o_valid_a0;
         logic  \@0$reset ;
         assign \@0$reset = AXIL_reset_a0;
      end


   end

endgenerate




generate   // This is awkward, but we need to go into 'generate' context in the line that `includes the declarations file.
