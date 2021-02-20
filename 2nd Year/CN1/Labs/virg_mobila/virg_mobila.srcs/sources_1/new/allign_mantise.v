`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/01/2020 09:50:39 PM
// Design Name: 
// Module Name: allign_mantise
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


module allign_mantise(
    input [56:0] concatenate,
    output reg [47:0] mantise
    );
    reg [8:0] val1;
    reg [22:0] m1, m2;
    integer i;
    always@(*)
    begin
        val1 <= concatenate[56:48];
        m1 <= concatenate[46:24];
        m2 <= concatenate[22:0];
        if (val1[8] == 1)
        begin
            m2 <= m2 >> val1[7:0];
        end
        else
        begin
            m1 <= m1 >> val1[7:0];
        end
        mantise[47] = concatenate[47];
        mantise[23] = concatenate[23];
        mantise[46:24] <= m1;
        mantise[22:0] <= m2;
    end
endmodule
