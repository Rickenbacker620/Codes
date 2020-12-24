`timescale 1ns/1ps
module counter(clk, count);
    input clk;
    output reg[1:0] count = 0;
    always @(posedge clk)
        count <= count+1;
endmodule