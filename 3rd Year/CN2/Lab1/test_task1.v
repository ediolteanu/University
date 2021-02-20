`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:01:56 10/20/2020
// Design Name:   task01
// Module Name:   C:/Users/student/Documents/lab01_skel/test_task1.v
// Project Name:  lab01_skel
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: task01
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_task1;

	// Inputs
	reg [3:0] address;

	// Outputs
	wire [7:0] data;

	// Instantiate the Unit Under Test (UUT)
	task01 uut (
		.address(address), 
		.data(data)
	);

	initial begin
		// Initialize Inputs
		address = 0;

		// Wait 100 ns for global reset to finish
		#100;
		address = 8'd10;
		#100 address = 8'd6;
		#100 address = 8'd15;
		#100;
        
		// Add stimulus here

	end
      
endmodule

