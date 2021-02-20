`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/02/2020 01:57:52 AM
// Design Name: 
// Module Name: simulation
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


module simulation();
    reg clk, load, clear;
    reg [31:0] nr1, nr2;
    reg op;
    wire [7:0] exp_out;
    wire [23:0] mantisa_out;
    
    always #50 clk = ~clk;
    tot tot(nr1, nr2, clk, load, clear, op, exp_out, mantisa_out);
    initial 
    begin
        clk = 0;
        clear = 0;
        load = 1;
        op = 1;
        nr1 = 0; 
        nr2 = 0; 
        
        #100
        load = 1;
        nr1 = 32'b01000010000011110000000000000000; 
        nr2 = 32'b01000001101001000000000000000000;
        
        #100
        load = 1;
        nr1 = 1; 
        nr2 = 1; 
        op = 0;
        
        #100
        load = 1;
        nr1 = 0; 
        nr2 = 0; 
        op = 1;
    end
endmodule
