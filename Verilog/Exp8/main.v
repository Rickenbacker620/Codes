module temp(clk, sda,scl,out_led,arrange);
    input clk;
    inout sda;
    output scl;
    output [7:0] out_led;
    output [7:0] arrange;
    wire [15:0] adc;
    wire [15:0] in_num;
    temp_sensor ts(clk, 1, scl, sda, adc[15:8], adc[7:0]);
    convert bc(adc, in_num);
    num_top nt(clk,in_num,out_led,arrange);
endmodule