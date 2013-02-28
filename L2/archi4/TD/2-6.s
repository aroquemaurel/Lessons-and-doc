	MOV r2,#0
	MOV r3,r0
tq: CMP r3,r1
	BLT ftq
	ADD r2,r2,#1
	SUB r3,r3,r1
	B ftq
ftq:
