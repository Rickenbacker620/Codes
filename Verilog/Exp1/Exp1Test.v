`timescale 1 ns/10 ps
module decode38_tb;
  reg [2:0] data_in_tb;
  wire [7:0] data_out_tb;
  reg enable_tb;
  decode38 t1(data_in_tb,data_out_tb,enable_tb);
  initial begin
    enable_tb=0;
    data_in_tb=0;
    #20 enable_tb=1;
    #50 data_in_tb=0;
    #50 data_in_tb=1;
    #50 data_in_tb=2;
    #50 data_in_tb=3;
    #50 data_in_tb=4;
    #50 data_in_tb=5;
    #50 data_in_tb=6;
    #50 data_in_tb=7;
    #50 $finish();
  end
endmodule
