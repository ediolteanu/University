`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2020 06:37:44 PM
// Design Name: 
// Module Name: Aparat
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


module Aparat(
input reset, clk_in,
    input [2:0] ron,
    output cola, rest1, rest5,
    output clk_out
    );
    
    wire clk_out_seg;
    clock c1(clk_in, reset, clk_out, clk_out_seg);
    aparat_cola t1(clk_out, reset, ron, cola, rest1, rest5);
endmodule
