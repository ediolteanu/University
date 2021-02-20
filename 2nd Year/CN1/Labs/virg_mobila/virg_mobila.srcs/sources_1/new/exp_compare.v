`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/01/2020 08:12:29 PM
// Design Name: 
// Module Name: exp_compare
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


module exp_compare(
    input [15:0] exponents,
    output reg [8:0] valoarea1,
    output reg [7:0] exp_out
    );
    reg [7:0]exp_a , exp_b;
    
    always@(*)
    begin
        exp_a <= exponents[15:8] - 127;
        exp_b <= exponents[7:0] - 127;
        if($signed(exp_a) > $signed(exp_b))
        begin
            valoarea1[8] = 1;
            valoarea1[7:0] <= exp_a[7:0] - exp_b[7:0];
            exp_out <= exp_a;
        end
        else 
        begin
            valoarea1[8] = 0;
            valoarea1[7:0] = exp_b[7:0] - exp_a[7:0];
            exp_out <= exp_b;
        end
    end
endmodule
