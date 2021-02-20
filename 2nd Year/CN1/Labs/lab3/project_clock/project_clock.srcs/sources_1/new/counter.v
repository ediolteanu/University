`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/11/2020 10:37:09 AM
// Design Name: 
// Module Name: counter
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


module counter(clk_out_led, pauza, reset, valoare_bin, carry_out);
    input clk_out_led, pauza, reset;
    output [5:0] valoare_bin;
    output carry_out;
    reg [5:0] valoare_bin;
    reg carry_out;
    
    always @(posedge clk_out_led)
    begin
        if(reset) begin
            valoare_bin = 0;
            carry_out = 0;
        end
        else begin
            if(!pauza)
            begin
            valoare_bin = valoare_bin + 1;
            if (valoare_bin > 59)
            begin
                valoare_bin = 0;
                carry_out = 1;
            end
            #100 carry_out = 0;
            end
        end
    end
endmodule
