`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/01/2020 10:06:41 PM
// Design Name: 
// Module Name: op_m
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


module op_m(
    input [47:0] mantise,
    input op,
    output reg [25:0] RSEA,
    output reg inferior
    );
    reg [23:0] rez;
    wire [23:0] res;
    reg [23:0] m1, m2;
    wire GG, GP, cout;
    integer i;
    sum24biti sum(m1, m2, op, res, GP, GG, cout);
    always@(*)
    begin
        m1[23] = 0;
        m2[23] = 0;
        if (mantise[47] == 1)
        begin
            for(i = 0; i < 22; i = i + 1)
            begin
                m1[i] = !m1[i];
            end
        end
        if (mantise[23] == 1)
        begin
            for(i = 0; i < 22; i = i + 1)
            begin
                m1[i] = !m1[i];
            end
        end
        m1 <= mantise[46:24];
        m2 <= mantise[22:0];
        inferior = 0;
        if (op == 0)
        begin
            if (mantise[47] == 0 && mantise[23] == 0)
            begin
                RSEA[24] = 0;
            end
            if (mantise[47] == 1 && mantise[23] == 1)
            begin
                RSEA[24] = 1;
            end
            if (mantise[47] == 1 || mantise[23] == 1)
            begin
                if (m1 < m2)
                begin
                    RSEA[24] = mantise[23]; 
                end
                else
                begin
                    RSEA[24] = mantise[47];
               end
            end
        end
        else
        begin
            if (mantise[47] == 0 && mantise[23] == 0)
            begin
                if (m1 < m2)
                begin
                    RSEA[24] = 1; 
                end
                else
                begin
                    RSEA[24] = 0;
               end
            end
            if (mantise[47] == 1 && mantise[23] == 1)
            begin
                if (m1 < m2)
                begin
                    RSEA[24] = 0; 
                end
                else
                begin
                    RSEA[24] = 1;
               end
            end
            if (mantise[47] == 1 && mantise[23] == 0)
            begin
                RSEA[24] = 1;
            end
            if (mantise[47] == 0 && mantise[23] == 1)
            begin
                RSEA[24] = 0;
            end
        end
    end
    always@(*)
    begin
    rez = res;
    if (rez == 0)
        begin
            RSEA[25] = 1;
            RSEA[24] = 0;
        end
        else if (rez[23] == 1)
            begin
                RSEA[25] = 0;
                RSEA[24] = RSEA[24] ^ rez[23];
                for (i = 0; i < 24; i = i + 1)
                begin
                    rez[i] = !rez[i];
                end
                rez = rez + 1;
                inferior = 1;
            end
            else
            begin
                RSEA[25] = 0;
                RSEA[24] = RSEA[24] ^ rez[23];
            end
        RSEA[23] = cout;
        RSEA[22:0] = rez[22:0];
    end
endmodule
