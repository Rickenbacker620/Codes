module ledsim(data_in,data_out,enable);
  input [3:0] data_in;
  output [6:0] data_out;
  input enable;
  reg [6:0] data_out;
  always @(data_in or enable) begin
    if (enable==1)
      case (data_in)
        4'b0000: data_out=7'b0000001;
        4'b0001: data_out=7'b1001111;
        4'b0010: data_out=7'b0010010;
        4'b0011: data_out=7'b0000110;
        4'b0100: data_out=7'b1001100;
        4'b0101: data_out=7'b0100100;
        4'b0110: data_out=7'b0100000;
        4'b0111: data_out=7'b0001111;
        4'b1000: data_out=7'b0000000;
        4'b1001: data_out=7'b0001100;
        4'b1010: data_out=7'b0010000;
        4'b1011: data_out=7'b1000010;
        4'b1100: data_out=7'b1100001;
        4'b1101: data_out=7'b0000110;
        4'b1110: data_out=7'b1100000;
        4'b1111: data_out=7'b1110000;
        default: data_out=7'bxxxxxxx;
      endcase
    else
      data_out=7'b0000000;
  end
endmodule

