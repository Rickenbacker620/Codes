`timescale 1 ns/10 ps
module dflip_tb();
  reg clk=0;
  wire qa, qb;
  reg data=0;
  dflip i1(clk, data, qa, qb);
  always #10  clk=~clk;
  always #15 data=~data;
endmodule