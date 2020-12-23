module adder4(A,B,S,C);
    input [3:0] A,B;
    output [3:0] S;
    output C;
    adder ul(.ia(A),.ib(B),.os(S),.oc(C));
endmodule

module adder(ia,ib,os,oc);
    input [3:0] ia,ib;
    output [3:0] os;
    output oc;
    assign {oc,os} = ia+ib;
endmodule