module task03(
	output reg out,
	input [7:0] in,
	input clk,
	input reset
);

	localparam STATE_NONE	= 3'd0;
	// TODO: Adaugati starile necesare.

	reg [2:0] state;
    initial begin
        out = 0;
        state <= STATE_NONE;
    end
    
	always @(posedge clk) begin
		if (reset) begin
			state <= STATE_NONE;
		end else begin

			// TODO: Implementati logica tranzitiilor intre stari.
			case(state)
			     STATE_NONE:
			     begin
			         out = 0;
			         if(in == "B")
			         begin
			             state <= 3'b001;
			         end
			         else
			         begin
			             state <= STATE_NONE;
			         end
			     end
			     3'b001 :
			     begin
			         if(in == "A")
			         begin
			             state <= 3'b010;
			         end
			         else
			         begin
			             state <= STATE_NONE;
			         end
			     end
			     3'b010 :
			     begin
			         if(in == "D")
			         begin
			             state <= 3'b010;
			         end
			         else
			         begin
			             state <= STATE_NONE;
			         end
			     end
			     3'b100 :
			     begin
			         if(in == "C")
			         begin
			             out = 1;   
			         end
			         state <= STATE_NONE;
			     end 
			 endcase
			// TODO: Implementati logica iesirii.
	   end
	end

endmodule
