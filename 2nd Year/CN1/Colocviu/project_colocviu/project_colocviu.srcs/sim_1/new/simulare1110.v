`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/13/2020 10:30:06 AM
// Design Name: 
// Module Name: simulare1110
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


module simulare1110();
    wire detectat;
    reg clk;
    reg bit;
    
    stare1110 intance(bit, detectat, clk);
    
    always #25 clk = ~clk;
    initial
    begin
        clk = 0;
        #50 bit = 0;
        #50 bit = 1;
        #50 bit = 0;
        #50 bit = 1;
        #50 bit = 1;
        #50 bit = 1;
        #50 bit = 0;
        #50 bit = 1;
        #50 bit = 0;
        #50 bit = 0;
        #50 bit = 1;
        #50 bit = 1;
        #50 bit = 0;
    end
endmodule
