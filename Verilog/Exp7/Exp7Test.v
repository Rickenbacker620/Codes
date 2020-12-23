`timescale 1ns/1ps
module test();
    reg[3:0] ta;
    reg[3:0] tb;
    reg tic;
    reg [1:0] to;
    wire[3:0] ts;
    wire rc;
    alu4 test(.A(ta),.B(tb),.C1(tic),.O(to),.S(ts),.C2(tc));

    initial begin
        ta <= 0;
        tb <= 0;
        tic <= 0;
        to <= 0;
    end
    always #5 begin
        tb <= tb+2;
        ta <= ta+1;
        tic <=tic+1;
        to <=tp+1;
    end
endmodule