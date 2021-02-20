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
		  	// Checker ex 1 si ex 2
			/*	 ldi 	r28, 3 		*/
			//0:		value = 16'b1110000011000011;
			/*	 out 	0x06, r28 		*/
			//1:		value = 16'b1011100111000110;
			/*	 in 	r17, 0x06 		*/
			//2:		value = 16'b1011000100010110;
			
			
			//ex3
			/*	 ldi 	r19, 42 		*/
			//0:		value = 16'b1110001000111010;
			/*	 out 	0x02, r19 		*/
			//1:		value = 16'b1011100100110010;
			/*	 in 	r20, 0x02 		*/
			//2:		value = 16'b1011000101000010;
			
			//ex4
					/*	 ldi 	r20, 255 		*/
		//0:		value = 16'b1110111101001111;
		/*	 out 	0x01, r20 		*/
		//1:		value = 16'b1011100101000001;
		/*	 ldi 	r19, 101 		*/
		//2:		value = 16'b1110011000110101;
		/*	 out 	0x02, r19 		*/
		//3:		value = 16'b1011100100110010;
		
		//ex5
		/*	 ldi 	r20, 255 		*/
		0:		value = 16'b1110111101001111;
		/*	 out 	0x01, r20 		*/
		1:		value = 16'b1011100101000001;
		/*	 ldi 	r19, 128 		*/
		2:		value = 16'b1110100000110000;
		/*	 out 	0x02, r19 		*/
		3:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 64 		*/
		4:		value = 16'b1110010000110000;
		/*	 out 	0x02, r19 		*/
		5:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 32 		*/
		6:		value = 16'b1110001000110000;
		/*	 out 	0x02, r19 		*/
		7:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 16 		*/
		8:		value = 16'b1110000100110000;
		/*	 out 	0x02, r19 		*/
		9:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 8 		*/
		10:		value = 16'b1110000000111000;
		/*	 out 	0x02, r19 		*/
		11:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 4 		*/
		12:		value = 16'b1110000000110100;
		/*	 out 	0x02, r19 		*/
		13:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 2 		*/
		14:		value = 16'b1110000000110010;
		/*	 out 	0x02, r19 		*/
		15:		value = 16'b1011100100110010;
		/*	 ldi 	r19, 1 		*/
		16:		value = 16'b1110000000110001;
		/*	 out 	0x02, r19 		*/
		17:		value = 16'b1011100100110010;
		default:		value = 16'b0000000000000000;



        endcase
    end

    always @(negedge clk) begin
        data <= value;
    end

endmodule
