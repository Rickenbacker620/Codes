module led_sim( );
    reg clock =0;
    reg reset =0;
    wire y0;
    wire y1;
    wire y2;
    wire y3;
    wire y4;
    wire y5;
    wire y6;
    wire y7;
    led_light yyt(.clock(clock),.reset(reset),.y0(y0),.y1(y1),.y2(y2),.y3(y3),.y4(y4),.y5(y5),.y6(y6),.y7(y7) );
    initial begin
        #500000005 reset =1;
    end
    always #5 clock =~clock;
endmodule
