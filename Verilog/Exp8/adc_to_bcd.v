`timescale 1ns / 1ps
module bcdchange(
     ssw,ssw2
    );
    input [15:0] ssw;
    output [15:0] ssw2;
     reg [15:0] t;
     reg [15:0]t2;
     reg[15:0] t4;
     reg [15:0] t3;
    always
    begin 
     t=ssw/128;
     t2<=t/10;
     t3[15:12]=t2[3:0];
     t2=t%10;
     t3[11:8]=t2[3:0];
     
     t4[7:0]<=ssw[7:0]/10;
     t3[7:4]=t4[3:0];
     t4=ssw[7:0]%10;
     t3[3:0]=t4[3:0];
    end    
    assign ssw2=t3;
    
endmodule
