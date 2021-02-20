`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2020 06:45:06 PM
// Design Name: 
// Module Name: simulare
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


module simulare();
    wire  cola, rest2, rest5;
    reg clk, reset;
    reg [2:0] ron;

    aparat_cola inst1(clk, reset, ron, cola, rest2, rest5);
    always #25 clk = ~clk;

    initial
    begin
        clk = 0; reset = 1; 
        #100 reset = 0; ron = 3'b001; //1 leu
        #100 reset = 0; ron = 3'b001; //1 leu
        #100 reset = 0; ron = 3'b001; //1 leu
        #100 reset = 1;
        #150 reset = 0; ron = 3'b010; //5 lei
        #100 reset = 1;
        #150 reset = 0; ron = 3'b100; //10 lei
        #100 reset = 1;
    end
endmodule
