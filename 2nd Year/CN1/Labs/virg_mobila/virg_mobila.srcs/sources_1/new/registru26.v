`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2020 11:31:42 AM
// Design Name: 
// Module Name: registru26
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


module registru26(
    input [25:0] a,
    input clk, load, clear,
    output reg [25:0] b
    );
    
    always@(posedge clk)
    begin
        if (clear)
            b = 0;
        else if (load)
                b = a;
    end
endmodule
