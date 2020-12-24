module temp(clk, sda,scl,out_led,arrange);
    input clk;
    inout sda;
    output scl;
    output [7:0] out_led;
    output [7:0] arrange;
    wire [15:0] parse;
    wire [15:0] in_num;
    temp_sensor ts(clk, 1, scl, sda, parse[15:8], parse[7:0]);
    convert bc(parse, in_num);
    num_top nt(clk,in_num,out_led,arrange);
endmodule