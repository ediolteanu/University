`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/01/2020 10:28:50 PM
// Design Name: 
// Module Name: norm
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


module norm(
    input [25:0] RSEA,
    input inferior,
    output reg [23:0] mantisa,
    output reg [8:0] val2
    );
    reg [22:0] m;
    integer i, ok;
    always@(*)
    begin
        i = 22;
        ok = 0;
        val2 <= 0;
        m <= RSEA[22:0];
        if (RSEA[23] == 1)
        begin
            val2[8] = 1;
            m <= m >> 1;
            m[22] = RSEA[23];
        end
        if (inferior == 1)
        begin
            while(i > 0 && ok == 0)
            begin
                if(m[i] == 0)
                begin
                   m <= m << 1; 
                   val2 <= val2 + 1;
                end
            end
        end
        mantisa[23] = RSEA[24];
        mantisa <= m;
    end
    
endmodule
