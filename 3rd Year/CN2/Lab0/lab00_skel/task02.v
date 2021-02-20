module task02(
	output reg serial_out,
	input serial_in,
	input clk,
	input reset
);
    reg [7:0] biti;
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            biti = 8'b00000000;
        end
        serial_out = biti[7];
        biti <= biti << 1;
        biti[0] <= serial_in;
    end
    
endmodule
