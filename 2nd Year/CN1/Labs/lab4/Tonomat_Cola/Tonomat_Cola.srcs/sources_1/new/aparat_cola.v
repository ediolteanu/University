`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/27/2020 06:42:20 PM
// Design Name: 
// Module Name: aparat_cola
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

// Aparatul accepta doar bancnote de 1, 5 si 10 lei. Astfel, codificarile sunt 001, 010 si 100. De fiecare data cand se
// poate da o cola, aparatul o da si da si restul aferent. Rest2 este folosit cand sunt introdusi 5 lei si se da o cola
// si rest2. Iar atunci cand sunt introdusi 10 lei se da o cola si rest2 si rest5.
module aparat_cola(
    input clk, reset,
    input [2:0] ron,
    output reg cola, rest2, rest5
    );
    reg [3:0] state;
    
    always@(posedge clk, posedge reset)
    begin
    if(reset)
    begin
        state = 4'b0000;
        cola = 0;
        rest2 = 0;
        rest5 = 0;
    end
    else
        begin
        case (state)
            4'b0000:
            begin
                cola = 0;
                rest2 = 0;
                rest5 = 0;
                case (ron)
                     3'b001: state <= 4'b0001;
                     3'b010: state <= 4'b0101;
                     3'b100: state <= 4'b1010;
                endcase
            end
            4'b0001: 
                if (ron == 3'b001)
                    state <= 4'b0010;
                    
            4'b0010:
                if (ron == 3'b001)
                    state <= 4'b0011;
                    
            4'b0011: 
                begin 
                    cola = 1;
                    state <= 4'b0000;
                end
               
            4'b0101: 
                begin
                    cola = 1;
                    rest2 = 1;
                    state <= 4'b0000;
                end
                
            4'b1010:
                begin
                    cola = 1;
                    rest2 = 1;
                    rest5 = 1;
                    state <= 4'b0000;
                end
       endcase   
       end
    end

endmodule
