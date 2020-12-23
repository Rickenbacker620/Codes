module clock_div(clk,clk_sys);
    input clk;
    output clk_sys;
    reg clk_sys =0;
    reg[25:0] div_counter = 0;
    always @(posedge clk) begin
        if (div_counter > 50000000) begin
            clk_sys <= ~clk_sys;
            div_counter <= 0;
        end
        else begin
            div_counter <= div_counter+1;
        end
    end
endmodule

module ctc(clk,reset,count );
    input clk,reset;
    output reg[2:0] count;
    always @(posedge clk or negedge reset) begin
        if (reset == 0) begin
            count =0;
        end
        else begin
            if (count == 0)
                count =7;
            else begin
                count =count-1;
            end
        end
    end
endmodule

module s_74ls138(Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7, A0, A1, A2, Enable);
    input A0,A1,A2,Enable;
    output reg Y0,Y1,Y2,Y3,Y4,Y5,Y6,Y7;
    always @(A0  or A1 or A2 or Enable) begin
        if(!Enable)
            {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0000_0000;
        else begin
            case ({A2,A1,A0})
                3'b000 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0000_0001;
                3'b001 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0000_0010;
                3'b010 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0000_0100;
                3'b011 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0000_1000;
                3'b100 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0001_0000;
                3'b101 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0010_0000;
                3'b110 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0100_0000;
                3'b111 : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b1000_0000;
                default : {Y7,Y6,Y5,Y4,Y3,Y2,Y1,Y0} <= 8'b0000_0000;
            endcase
        end
    end
endmodule

module led_light(clock,reset,y0,y1,y2,y3,y4,y5,y6,y7 );
    input clock,reset;
    output y0,y1,y2,y3,y4,y5,y6,y7;
    wire clk_sys;
    wire[2:0] count;
    clock_div u0(.clk(clock),.clk_sys(clk_sys));
    s_74ls138 u1(.A0(count[0]),.A1(count[1]),.A2(count[2]),.Enable(reset),.Y0(y0),.Y1(y1),.Y2(y2),.Y3(y3),.Y4(y4),.Y5(y5),.Y6(y6),.Y7(y7));
    ctc u2(.clk(clk_sys),.reset(reset),.count(count));
endmodule
