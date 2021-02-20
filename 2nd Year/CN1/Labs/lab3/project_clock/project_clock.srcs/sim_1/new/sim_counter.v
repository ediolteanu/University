`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/11/2020 10:54:02 AM
// Design Name: 
// Module Name: sim_counter
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


module sim_counter();
    reg clk_out_led, reset, pauza;
    wire [5:0] valoare_bin;
    wire carry_out;
    counter counter1(clk_out_led, pauza, reset, valoare_bin, carry_out);
    initial begin
    clk_out_led = 0; reset = 1; pauza = 0;
    #100 reset = 0;
    end
    always
    #50 clk_out_led = !clk_out_led;
endmodule
