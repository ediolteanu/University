`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/11/2020 11:30:43 AM
// Design Name: 
// Module Name: bcd_sim
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


module bcd_sim();
    reg [5:0] valoare_bin;
    wire [3:0] BCD0, BCD1;
    
    bin_to_bcd convertor(valoare_bin, BCD0, BCD1);
    initial begin
        valoare_bin = 23;
    #100
        valoare_bin = 59;
    end
    
endmodule
