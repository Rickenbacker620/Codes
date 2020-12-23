`timescale 1ns/1ps
module test();
    reg clk;
    reg [15:0] in_num;
    wire [7:0] out_led;
    wire [3:0] arrange;
    num_top unt(clk,in_num,out_led,arrange);
    initial begin
        in_num <= 0;
        clk <= 0;
    end
    always #10 begin
        clk <= ~clk;
        in_num <= in_num+1;
    end
endmodule