module bcdchange(hex,bcd);
    input [15:0] hex;
    output [15:0] bcd;
    reg [15:0] t1;
    reg [15:0] t2;
    reg [15:0] t3;
    reg [15:0] t4;
    always
    begin
     t1=hex/128;
     t2<=t/10;
     t3[15:12]=t2[3:0];
     t2=t%10;
     t3[11:8]=t2[3:0];

     t4[7:0]<=hex[7:0]/10;
     t3[7:4]=t4[3:0];
     t4=hex[7:0]%10;
     t3[3:0]=t4[3:0];
    end
    assign bcd=t3;

endmodule
