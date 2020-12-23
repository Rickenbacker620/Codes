`timescale 1ns/1ps
module num(c_digit, in_num, out_led, arrange);
    input [1:0] c_digit;
    input [15:0] in_num;
    output reg [7:0] out_led;
    output reg [7:0] arrange;
    reg [3:0] temp;

    always@(c_digit)
        case(c_digit)
            2'b00:
            begin
                temp <= in_num[3:0];
                arrange <= 8'b1111_1110;
                out_led[0] <= 1;
            end
            2'b01:
            begin
                temp <= in_num[7:4];
                arrange <= 8'b1111_1101;
                out_led[0] <= 1;
            end
            2'b10:
            begin
                temp <= in_num[11:8];
                arrange <= 8'b1111_1011;
                out_led[0] <= 0;
            end
            2'b11:
            begin
                temp <= in_num[15:12];
                arrange <= 8'b1111_0111;
                out_led[0] <= 1;
            end
            default:
            begin
                temp <= 4'bxxxx;
                arrange <= 4'b1111;
                out_led[0] <= 1;
            end
        endcase

    always @(temp)
        case(temp)
            4'b0000: out_led[7:1] <= 7'b0000_001;
            4'b0001: out_led[7:1] <= 7'b1001_111;
            4'b0010: out_led[7:1] <= 7'b0010_010;
            4'b0011: out_led[7:1] <= 7'b0000_110;
            4'b0100: out_led[7:1] <= 7'b1001_100;
            4'b0101: out_led[7:1] <= 7'b0100_100;
            4'b0110: out_led[7:1] <= 7'b0100_000;
            4'b0111: out_led[7:1] <= 7'b0001_111;
            4'b1000: out_led[7:1] <= 7'b0000_000;
            4'b1001: out_led[7:1] <= 7'b0001_100;
            default: out_led[7:1] <= 7'bxxxx_xxx;
        endcase
endmodule