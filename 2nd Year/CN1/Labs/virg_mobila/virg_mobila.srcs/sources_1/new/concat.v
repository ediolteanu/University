`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/01/2020 09:44:04 PM
// Design Name: 
// Module Name: concat
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


module concat(
    input [47:0] mantise,
    input [8:0] valoarea1,
    output reg [56:0] concatenate
    );
    always@(*)
    begin
        concatenate [56:48] <= valoarea1;
        concatenate [47:0] <= mantise;
    end
endmodule
