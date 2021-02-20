`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2020 11:29:49 AM
// Design Name: 
// Module Name: registru48
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


module registru48(
    input [47:0] a,
    input clk, load, clear,
    output reg [47:0] b
    );
    
    always@(posedge clk)
    begin
        if (clear)
            b = 0;
        else if (load)
                b = a;
    end
endmodule
