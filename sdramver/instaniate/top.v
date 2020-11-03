module top;
reg data, clock;
wire q_out, net_1;
  dff inst_1 (clock, data, net_1);
  dff inst_2 (clock, net_1, q_out);
endmodule
