module num_top(clk,in_num,out_led,arrange);
    input clk;
    input [15:0] in_num;
    wire [1:0] count;
    output [7:0] out_led;
    output [7:0] arrange;
    clock_div ucd(clk, sclk);
    counter uc(sclk,count);
    num un(count, in_num, out_led, arrange);
endmodule