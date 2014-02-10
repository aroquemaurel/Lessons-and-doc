	MOV		r0, #2
	MOV		r3, #42 @;N
tq:	CMP		r1, r3
	BEQ		ftq
	MOV		r0, r0, LSL #1
	ADD		r2, r2, r0
	ADD		r1, r1, #1
	B		tq
ftq:	
