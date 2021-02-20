`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/06/2020 12:12:38 PM
// Design Name: 
// Module Name: memorie2
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


module memorie2 #(parameter biti = 32) (
    input clk, we_a, we_b,
    input [2:0] addr_a, addr_b,
    input [biti-1:0] da_in, db_in,
    output [biti-1:0] da_out, db_out
    );
    reg [biti-1:0] ram_vec[7:0];
    reg [2:0] read_addr_a;
    reg [biti-1:0] ram_vec[7:0];
    reg [2:0] read_addr_b;
    reg [biti-1:0] a_temp, b_temp;
    
    always @(posedge clk)
    begin 
        a_temp = ram_vec[addr_a];
        if (we_a)
        begin
            ram_vec[addr_a] <= da_in;
        end
        else
        begin
            read_addr_a <= addr_a;
        end
    end
    
    always @(posedge clk)
    begin
        b_temp = ram_vec[addr_b];
        if (we_b)
        begin
            ram_vec[addr_b] <= db_in;
        end
        else
        begin
            read_addr_b <= addr_b;
        end
    end
    
    assign da_out = a_temp;
    assign db_out = b_temp;
endmodule
