module rom #(
        parameter   DATA_WIDTH = 16,
        parameter   ADDR_WIDTH = 8          // 2 * 1024 bytes of ROM
    )(
        input  wire                  clk,
        input  wire [ADDR_WIDTH-1:0] addr,  // here comes the program counter
        output  reg [DATA_WIDTH-1:0] data   // here goes the instruction
    );

    reg [DATA_WIDTH-1:0] value;

    
    always @* begin
        case (addr)
			/*	 ldi 	r16, 5 		*/
			//0:		value = 16'b1110000000000101;
			/*	 rjmp 	main_function 		*/
			//1:		value = 16'b1100000000000010;
			/*	 ldi 	r17, 15 		*/
			//2:		value = 16'b1110000000011111;
			/*	 ret 	 		*/
			//3:		value = 16'b1001010100001000;
			/*	 ldi 	r17, 10 		*/
			//4:		value = 16'b1110000000011010;
			/*	 rcall 	first_function 		*/
			//5:		value = 16'b1101111111111100;
			/*	 ldi 	r18, 20 		*/
			//6:		value = 16'b1110000100100100;
					
			//ex3		
			/*	 rcall 	cmain 		*/
			//0:		value = 16'b1101000000000010;
			/*	 ldi 	r20, 66 		*/
			//1:		value = 16'b1110010001000010;
			/*	 ret 	 		*/
			//2:		value = 16'b1001010100001000;
			/*	 rcall 	function 		*/
			//3:		value = 16'b1101111111111101;
			
		//ex4
					/*	 rcall 	cmain 		*/
		//0:		value = 16'b1101000000001000;
		/*	 pop 	r19 		*/
		//1:		value = 16'b1001000100111111;
		/*	 pop 	r18 		*/
		//2:		value = 16'b1001000100101111;
		/*	 pop 	r17 		*/
		//3:		value = 16'b1001000100011111;
		/*	 pop 	r16 		*/
		//4:		value = 16'b1001000100001111;
		/*	 push 	r28 		*/
		//5:		value = 16'b1001001111001111;
		/*	 push 	r19 		*/
		//6:		value = 16'b1001001100111111;
		/*	 sub 	r16, r17 		*/
		//7:		value = 16'b0001101100000001;
		/*	 ret 	 		*/
		//8:		value = 16'b1001010100001000;
		/*	 ldi 	r20, 10 		*/
		//9:		value = 16'b1110000001001010;
		/*	 ldi 	r21, 2 		*/
		//10:		value = 16'b1110000001010010;
		/*	 push 	r20 		*/
		//11:		value = 16'b1001001101001111;
		/*	 push 	r21 		*/
		//12:		value = 16'b1001001101011111;
		/*	 rcall 	diff 		*/
		//13:		value = 16'b1101111111110011;
		
		//ex5
				/*	 rcall 	cmain 		*/
		//0:		value = 16'b1101000000001100;
		/*	 pop 	r22 		*/
		//1:		value = 16'b1001000101101111;
		/*	 pop 	r23 		*/
		//2:		value = 16'b1001000101111111;
		/*	 pop 	r21 		*/
		//3:		value = 16'b1001000101011111;
		/*	 push 	r23 		*/
		//4:		value = 16'b1001001101111111;
		/*	 push 	r22 		*/
		//5:		value = 16'b1001001101101111;
		/*	 ldi 	r19, 1 		*/
		//6:		value = 16'b1110000000110001;
		/*	 ldi 	r20, 0 		*/
		//7:		value = 16'b1110000001000000;
		/*	 add 	r20, r21 		*/
		//8:		value = 16'b0000111101000101;
		/*	 sub 	r21, r19 		*/
		//9:		value = 16'b0001101101010011;
		/*	 breq 	outside_loop 		*/
		//10:		value = 16'b1111000000001001;
		/*	 rjmp 	while 		*/
		//11:		value = 16'b1100111111111100;
		/*	 ret 	 		*/
		//12:		value = 16'b1001010100001000;
		/*	 ldi 	r16, 10 		*/
		//13:		value = 16'b1110000000001010;
		/*	 push 	r16 		*/
		//14:		value = 16'b1001001100001111;
		/*	 rcall 	sum 		*/
		//15:		value = 16'b1101111111110001;
		
		//ex6
				/*	 rcall 	cmain 		*/
		0:		value = 16'b1101000000001110;
		/*	 pop 	r22 		*/
		1:		value = 16'b1001000101101111;
		/*	 pop 	r23 		*/
		2:		value = 16'b1001000101111111;
		/*	 pop 	r21 		*/
		3:		value = 16'b1001000101011111;
		/*	 pop 	r20 		*/
		4:		value = 16'b1001000101001111;
		/*	 push 	r23 		*/
		5:		value = 16'b1001001101111111;
		/*	 push 	r22 		*/
		6:		value = 16'b1001001101101111;
		/*	 ldi 	r19, 1 		*/
		7:		value = 16'b1110000000110001;
		/*	 add 	r20, r21 		*/
		8:		value = 16'b0000111101000101;
		/*	 sub 	r21, r19 		*/
		9:		value = 16'b0001101101010011;
		/*	 breq 	exit_sum 		*/
		10:		value = 16'b1111000000011001;
		/*	 push 	r20 		*/
		11:		value = 16'b1001001101001111;
		/*	 push 	r21 		*/
		12:		value = 16'b1001001101011111;
		/*	 rcall 	sum 		*/
		13:		value = 16'b1101111111110011;
		/*	 ret 	 		*/
		14:		value = 16'b1001010100001000;
		/*	 ldi 	r16, 10 		*/
		15:		value = 16'b1110000000001010;
		/*	 ldi 	r17, 0 		*/
		16:		value = 16'b1110000000010000;
		/*	 push 	r17 		*/
		17:		value = 16'b1001001100011111;
		/*	 push 	r16 		*/
		18:		value = 16'b1001001100001111;
		/*	 rcall 	sum 		*/
		19:		value = 16'b1101111111101101;



			default:		value = 16'b0000000000000000;
        endcase
    end

    always @(negedge clk) begin
        data <= value;
    end

endmodule
