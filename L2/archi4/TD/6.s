_start:
		ADR r0, t
		ADR r1, ft
		SUB r1,r1,#4
tq1:		CMP r0, r1
		BHS ftq
		BL	rechMax
		LDR	r3,[r1]
		STR	r3,[r3]
		STR r2,[r1]
		SUB	r1,r1,#4
		B	tq1
ftq1:


rechMax:
		STMFD	sp!, {r0,r4}
		LDR		r2, [r0] 
		MOV		r3, r0

tq:		CMP		r0, r1
		BHS		ftq
		LDR		r4, [r0]

si1:	CMP		r2, r4
		BHS		fsi
		MOV		r2, r4
		MOV		r3, r0
fsi:
		ADD		r0, r0, #4
		B		tq
ftq:
		LDMFD	sp!, {r0,r4}
		MOV		pc, r14

t:	.int 3,4,9,...
ft:	
