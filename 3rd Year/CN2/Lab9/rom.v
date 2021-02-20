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
            		/*	 rjmp 	main 		*/
		0:		value = 16'b1100000000010010;
		/*	 reti 	 		*/
		1:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		2:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		3:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		4:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		5:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		6:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		7:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		8:		value = 16'b1001010100011000;
		/*	 rjmp 	tim0_compa_isr 		*/
		9:		value = 16'b1100000000000111;
		/*	 reti 	 		*/
		10:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		11:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		12:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		13:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		14:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		15:		value = 16'b1001010100011000;
		/*	 reti 	 		*/
		16:		value = 16'b1001010100011000;
		/*	 sbi 	0x02, 0 		*/
		17:		value = 16'b1001101000010000;
		/*	 sbi 	0x02, 1 		*/
		18:		value = 16'b1001101000010001;
		/*	 sbi 	0x01, 255 		*/
		19:		value = 16'b1001101000001111;
		/*	 ldi 	r16, 0b00000000 		*/
		20:		value = 16'b1110000000000000;
		/*	 out 	tccr0a, r16 		*/
		21:		value = 16'b1011101100001001;
		/*	 ldi 	r16, 0b00000001 		*/
		22:		value = 16'b1110000000000001;
		/*	 out 	tccr0b, r16 		*/
		23:		value = 16'b1011101100001000;
		/*	 ldi 	r16, 0b00000010 		*/
		24:		value = 16'b1110000000000010;
		/*	 out 	timsk, r16 		*/
		25:		value = 16'b1011110100000110;
		/*	 ldi 	r16, 0b00000010 		*/
		26:		value = 16'b1110000000000010;
		/*	 out 	0x25, r16 		*/
		27:		value = 16'b1011110100000101;
		/*	 sei 	 		*/
		28:		value = 16'b1001010001111000;
		/*	 rjmp 	loop 		*/
		29:		value = 16'b1100111111111111;
		default:		value = 16'b0000000000000000;

        endcase
    end

    always @(negedge clk) begin
        data <= value;
    end

endmodule
