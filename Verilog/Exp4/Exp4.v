module dflip(clk, data, qa, qb);
  input clk;
  input data;
  output reg qa;
  output reg qb;
  initial begin
    qa=0;
    qb=0;
  end
  always @(posedge clk) begin
    qa <= data;
    qb <= !data;
  end
endmodule