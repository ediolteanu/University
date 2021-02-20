`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/01/2020 11:05:27 PM
// Design Name: 
// Module Name: sum1bit
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


module sum1bit(
    input a, b, cin,
    output reg p, g, sum
    );
    
    always @(a or b or cin)
    begin
        p = a | b;
        g = a & b;
        sum = (a^b)^cin;
        
    end
endmodule
