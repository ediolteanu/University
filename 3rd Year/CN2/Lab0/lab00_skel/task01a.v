//descriere structurala
module task01a(
	output out,
	input in0,
	input in1,
	input in2,
	input in3
);
    wire out1, out2, out3, out4, out5;
    or or1(out3, in1, in2);
    nand nand1(out1, in3, out3);
    not not1(out4, in0);
    or or2(out5, in1, in3);
    and and2(out2, out4, out5); 
	and and1(out, out1, out2);
	
endmodule


