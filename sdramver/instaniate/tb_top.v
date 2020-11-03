module tb_top;
reg data, clock;
wire q_out, net_1;
  //dff inst_1 (.clock(clk), .data(d), .net_1(q));
  dff inst_1 (.clk(clock), .d(data), .q(net_1));
  //dff inst_2 (.clock(clk), .net_1(d), .q_out(q));
  
  always #20 clock <= ~clock;
	reg	pwr_reset;
	initial	pwr_reset = 1'b1;
	always @(posedge clock)
		pwr_reset <= 1'b0;
		
  initial
  begin
  #30 data = 1'b1;
  #40 data = 1'b0;
  #6624000;
  $finish();
  end
  
  initial 
  begin 
    $dumpfile("dump.vcd");
    $dumpvars(0);
  end    
endmodule
