	CMP r1, #0
	RSBLT r1, r1, #0
	MOV r2, #0
	MOV r3, #0
tq: CMP r3, r1
	BGE ftq
	ADD r2, r2, r0
	ADD r3, r3, #1
	B tq
ftq:
