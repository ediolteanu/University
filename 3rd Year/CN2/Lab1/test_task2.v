`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:06:00 10/20/2020
// Design Name:   task02
// Module Name:   C:/Users/student/Documents/lab01_skel/test_task2.v
// Project Name:  lab01_skel
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: task02
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_task2;

	// Inputs
	reg clk;
	reg oe;
	reg cs;
	reg we;
	reg [6:0] address;
	reg [7:0] data_in;

	// Outputs
	wire [7:0] data_out;

	// Instantiate the Unit Under Test (UUT)
	task02 uut (
		.clk(clk), 
		.oe(oe), 
		.cs(cs), 
		.we(we), 
		.address(address), 
		.data_in(data_in), 
		.data_out(data_out)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		oe = 0;
		cs = 1;
		we = 0;
		address = 0;
		data_in = 0;

		// Wait 100 ns for global reset to finish
		#100;
      
		// Add stimulus here
		#100 
		clk = 1;
		we = 1;
		data_in = 12;
		address = 8'd10;
		#100
		clk = 0;
		
		#100
		clk = 1;
		we = 0; 
		oe = 1;
		address = 8'd10;
		
		#100 clk = 0;
		
		#100
		clk = 1;
		we = 1;
		oe = 0;
		address = 8'd10;
		data_in = 20;
		
		#100
		clk = 0;
		
		#100
		clk = 1;
		we = 0;
		oe = 1;
		address = 8'd10; 
		
	end
      
endmodule

