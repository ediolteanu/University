`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2020 06:49:44 PM
// Design Name: 
// Module Name: sum16bit
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


module sum24bit(
    input[23:0] a, b,
    input cin,
    output [23:0] result,
    output reg GP, GG, cout
    );
    
    wire P0, P1, P2, P3, P4, P5;
    wire G0, G1, G2, G3, G4, G5;
    reg C1, C2, C3, C4, C5;
    
    sum4bit bits03(a[3:0],     b[3:0],   cin, result[3:0],   P0, G0);
    sum4bit bits47(a[7:4],     b[7:4],   C1,  result[7:4],   P1, G1);
    sum4bit bits811(a[11:8],   b[11:8],  C2,  result[11:8],  P2, G2);
    sum4bit bits1215(a[15:12], b[15:12], C3,  result[15:12], P3, G3);
    sum4bit bits1619(a[19:16], b[19:16], C4,  result[19:16], P4, G4);
    sum4bit bits2023(a[23:20], b[23:20], C5,  result[23:20], P5, G5);
    
    
    always @(a or b or cin or P0 or P1 or P2 or P3 or P4 or P5 or G0 or G1 or G2 or G3 or G4 or G5)
    begin
        C1 = G0 | (P0 & cin);
        C2 = G1 | (P1 & G0) | (P1 & P0 & cin);
        C3 = G2 | (P2 & G1) | (P2 & P1 & G0) | (P2 & P1 & P0 & cin);
        C4 = G3 | (P3 & G2) | (P3 & P2 & G1) | (P3 & P2 & P1 & G0) | (P3 & P2 & P1 & P0 & cin);
        C5 = G4 | (P4 & G3) | (P4 & P3 & G2) | (P4 & P3 & P2 & G1) | (P4 & P3 & P2 & P1 & G0) | (P4 & P3 & P2 & P1 & P0 & cin);
        
        cout = G5 | (P5 & G4) | (P5 & P4 & G3) | (P5 & P4 & P3 & G2) | (P5 & P4 & P3 & P2 & G1) | (P5 & P4 & P3 & P2 & P1 & G0) | (P5 & P4 & P3 & P2 & P1 & P0 & cin); 
        
        GP = P5 & P4 & P3 & P2 & P1 & P0;
        GG = G5 | (P5 & G4) | (P5 & P4 & G3) | (P5 & P4 & P3 & G2) | (P5 & P4 & P3 & P2 & G1) | (P5 & P4 & P3 & P2 & P1 & G0);
    end
endmodule
