module alu4(A,B,C1,O,S,C2);
    input[3:0] A,B;
    input C1;
    input [1:0] O;
    output [3:0] S;
    output C2;
    alu ul(.ia(A),.ib(B),.ic(C1),.io(O),.os(S),.oc(C2));
endmodule

module alu(ia,ib,ic,io,os,oc);
    input [3:0] ia,ib;
    input [1:0] io;
    input ic;
    output reg oc;
    always@(io)
    case (io)
    2'b00: {oc,os} = ia+ib;
    2'b01: {oc,os} = ia-ib;
    2'b10: {oc,os} = ia&ib;
    2'b11: {oc,os} = ia|ib;
    endcase
endmodule
