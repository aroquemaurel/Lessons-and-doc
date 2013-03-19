	LDR r1,=t
	LDR r2,=tfin @ <=> ADD r2,r1,#N*4
	MOV r0,#0
tq: CMP r1,r2
	BEQ ftq
	LDR r3,[r1] @on pourrait faire 
	ADD r1,r1,#4 @LDR r3,[r1],#4 
	ADD r0,r0,r3
	B tq
ftq:
