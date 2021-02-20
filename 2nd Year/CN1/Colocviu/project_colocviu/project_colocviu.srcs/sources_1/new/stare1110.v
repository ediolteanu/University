`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/13/2020 10:03:04 AM
// Design Name: 
// Module Name: stare1110
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module stare1110(
    input bit,
    output reg detectat,
    input clk
    );
    reg [3:0] state;
    always@(posedge clk)
    begin
        detectat = 0;
        state <= 4'b0000;
        case(state)
            4'b0000:
            begin
                detectat = 0;
                if(bit == 1)
                begin
                    state <= 4'b0001;
                end
            end
            
            4'b0001:
            begin
                if(bit == 1)
                begin
                    state <= 4'b0011;
                end
                else
                begin
                    state <= 4'b0000;
                end
            end
            
            4'b0011:
            begin
                if(bit == 1)
                begin
                    state <= 4'b0111;
                end
                else
                begin
                    state <= 4'b0000;
                end
            end
            
            4'b0111:
            begin
                if(bit == 0)
                begin
                    detectat = 1;
                    state <= 4'b0000;
                end
                
            end
        endcase
    end
    
endmodule
