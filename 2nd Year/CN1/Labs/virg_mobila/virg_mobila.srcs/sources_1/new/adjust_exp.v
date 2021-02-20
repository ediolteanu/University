`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/02/2020 12:56:56 AM
// Design Name: 
// Module Name: adjust_exp
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


module adjust_exp(
    input [7:0] exp,
    input [8:0] val2,
    output reg [7:0] exp_out
    );
    always@(*)
    begin
        if (val2[8] == 1)
        begin
            exp_out <= exp + 1;
        end
        else 
        begin
            exp_out <= exp - val2[7:0];
        end
    end
endmodule
