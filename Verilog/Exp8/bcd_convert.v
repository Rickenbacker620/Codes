module convert(adc,bcd);
    input [15:0] adc;
    output [15:0] bcd;
    reg [15:0] t1;
    reg [15:0] t2;
    reg [15:0] t3;
    reg [15:0] t4;
    always
    begin
     t1=adc/128;
     t2<=t1/10;
     t3[15:12]=t2[3:0];
     t2=t1%10;
     t3[11:8]=t2[3:0];

     t4[7:0]<=adc[7:0]/10;
     t3[7:4]=t4[3:0];
     t4=adc[7:0]%10;
     t3[3:0]=t4[3:0];
    end
    assign bcd=t3;

endmodule
