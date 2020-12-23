`timescale 1ns/1ps
module test();
    reg[3:0] ta;
    reg[3:0] tb;
    wire [3:0] ts;
    wire tc;
    adder4 test(.A(ta),.B(tb),.S(ts),.C(tc));
    initial begin
        ta <= 0;
        tb <= 0;
    end
    always #5 begin
        tb <= tb+2;
        ta <= ta+1;
    end
endmodule