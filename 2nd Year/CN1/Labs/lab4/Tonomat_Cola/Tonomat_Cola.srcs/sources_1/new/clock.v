`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2020 06:39:15 PM
// Design Name: 
// Module Name: clock
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


module clock(
    input clk_in, reset,
    output clk_out_led, clk_out_seg
    );
    reg [32:0] counter;

always@(posedge clk_in, posedge reset)
    if(reset)
        counter = 0;
    else
        counter <= counter + 1;
        
    assign clk_out_led = counter[27];
    assign clk_out_seg = counter[16];
endmodule
