	.eq N,10
t: .fill N,1,0
	LDR r0,=t
	LDR r2,=tfin
	MOV r0,#1
tq: CMP r1,r2
	BEQ ftq
	STRB r3,[r1],#1
	ADD r0,r0,#1
	B tq
ftq:
