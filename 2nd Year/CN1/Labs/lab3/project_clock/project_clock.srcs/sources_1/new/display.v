`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2020 04:51:07 PM
// Design Name: 
// Module Name: display
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


module display(
    input clk_out_seg, reset,
    input [3:0] BCD0, BCD1, BCD2, BCD3,
    output reg [7:0]An,
    output reg [6:0]Seg,
    output reg DP
    );
    
    reg [3:0]BCD;
    reg [1:0]S; //stari de afisare
    
always @(posedge clk_out_seg)
begin
    if(!reset)
        S=2'b00;
        
    An[7:4]=4'b1111;
    
    case (S)
        2'b00: {BCD, An[3:0]} = {BCD0, 4'b0111};
        2'b00: {BCD, An[3:0]} = {BCD1, 4'b1011};
        2'b00: {BCD, An[3:0]} = {BCD2, 4'b1101};
        2'b00: {BCD, An[3:0]} = {BCD3, 4'b1110};
    endcase
    case (BCD)
        4'b0000 : Seg = 7'b0000001; // - a, b, c, d, e, f, g
        4'b0001 : Seg = 7'b1001111; //1
        4'b0010 : Seg = 7'b0010010; //2
        4'b0011 : Seg = 7'b0000110; //3
        4'b0100 : Seg = 7'b1101100; //4
        4'b0101 : Seg = 7'b0100100; //5
        4'b0110 : Seg = 7'b0100000; //6
        4'b0111 : Seg = 7'b0001111; //7
        4'b1000 : Seg = 7'b0000000; //8
        4'b1001 : Seg = 7'b0001100; //9
        4'b1010 : Seg = 7'b0001001; //A
        4'b1011 : Seg = 7'b1100000; //B
        4'b1100 : Seg = 7'b0110001; //C
        4'b1101 : Seg = 7'b1000010; //D
        4'b1110 : Seg = 7'b0110000; //E
        4'b1111 : Seg = 7'b0111000; //F
        default: Seg = 7'b1111111; //dispozitiv stins
    endcase
    
    if (S==2'b10)
        DP=0;
    else
        DP=1;
end
endmodule
