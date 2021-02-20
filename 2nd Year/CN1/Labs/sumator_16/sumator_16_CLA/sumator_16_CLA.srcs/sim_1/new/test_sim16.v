`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2020 06:56:27 PM
// Design Name: 
// Module Name: test_sim16
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


module test_sim16();
    reg[15:0] a, b;
    reg cin;
    wire[15:0] result;
    wire cout;
    wire GG;
    wire GP;
    
    sum24bit sumator(a, b, cin, result, GP, GG, cout);
    
    initial
    begin
        #50;
        a = 20;
        b = 45;
        cin = 0;
        #50;
        b = 12452;
        #50;
        a = 231;
        b = 14252;
        cin = 1;
        #50;
        a = 3;
        b = 65535;
    end
endmodule
