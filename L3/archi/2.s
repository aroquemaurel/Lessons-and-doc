	MOV		r1, #0
tq: CMP	r0, #0
	BEQ	ftq
	MUL	r1, r1, r0 
	SUB	r0, r0, #1
	B	tq
ftq:	
	

