`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/02/2020 12:14:54 AM
// Design Name: 
// Module Name: tot
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


module tot(
    input [31:0] a, b,
    input clk, load, clear,
    input op,
    output [7:0] expout,
    output [23:0] mantisa
    );
    wire inferior;
    wire [15:0] r1;
    wire [7:0] r2, r7;
    wire [47:0] r3, r5;
    wire [56:0] r4;
    wire [25:0] r6;
    wire [8:0] val1, val2;
    wire [23:0] r8;
    wire [23:0] mantisa_out;
    wire [7:0] exp_out;
    wire [56:0] concatenate;
    wire [25:0] RSEA;
    wire [47:0] mantise_out;
    reg [15:0] exponents;
    reg [47:0] mantise;
    always@(*)
    begin
        exponents[15:8] <= a[30:23];
        exponents[7:0] <= b[30:23];
        mantise[47] = a[31];
        mantise[23] = b[31];
        mantise[46:24] = a[22:0];
        mantise[22:0] = a[22:0];
    end
     
    registru16 registru1(exponents, clk, load, clear, r1);
    exp_compare exp_compare(r1, val1, exp_out);
    registru8 registru2(exp_out, clk, load, clear, r2);
    
    registru48 registru3(mantise, clk, load, clear, r3);
    concat concat(r3, val1, concatenate);

    registru56 registru4(concatenate, clk, load, clear, r4); 
    allign_mantise allign_mantise(r4, mantise_out);
    
    registru48 registru5(mantise_out, clk, load, clear, r5);
    op_m op_m(r5, op, RSEA, inferior);
    
    registru26 registru6(RSEA, clk, load, clear, r6);
    norm norm(r6, inferior, mantisa_out, val2);

    adjust_exp adjust_exp(r2, val2, exp_out);
    registru8 registru7(exp_out, clk, load, clear, r7);
    registru24 registru8(mantisa_out, clk, load, clear, r8);
    
    assign expout = r7;
    assign mantisa_out = r8;
endmodule
