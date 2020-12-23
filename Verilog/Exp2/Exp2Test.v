`timescale 1 ns/10 ps
module counter_tb();
  reg clk=0;
  wire [7:0] cnt;
  always #100  clk=~clk;
  counter i1(.clk(clk),.cnt(cnt));
endmodule