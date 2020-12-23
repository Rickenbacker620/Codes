`timescale 1 ns/10 ps
module ledsim_tb;
  reg [3:0]data_in_tb;
  wire [6:0]data_out_tb;
  reg enable_tb;
  ledsim t1(data_in_tb,data_out_tb,enable_tb);
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
    #50 data_in_tb=8;
    #50 data_in_tb=9;
    #50 data_in_tb=10;
    #50 data_in_tb=11;
    #50 data_in_tb=12;
    #50 data_in_tb=13;
    #50 data_in_tb=14;
    #50 data_in_tb=15;
    #50 $finish();
  end
endmodule