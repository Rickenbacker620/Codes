module counter(clk,cnt);
  input clk;
  output reg[7:0]cnt=8'b0;
  always @(posedge clk) begin
    cnt<=cnt+1;
  end
endmodule