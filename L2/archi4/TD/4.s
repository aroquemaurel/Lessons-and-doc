		.equ N, 10
t1:		.fill N,  
t2:		.fill N, 

		ADR r0, t1
		ADR r1, t2
si:		CMP r0,r1
		BHS else
		MOV r2, #N
tq1:	CMP r0,#0
		BEQ ftq1
		SUB r2,r2,#1
		LDR r3, [r0,r2,LSL#2]
		STR r3, [r1,r2,LSL#2]
		B tq1
		B fsi
else:	MOV R2, #0
tq2:	CMP r2,#N
		BEQ ftq2
		ADD r2,r2,#1
		LDR r3[r0,r2,LSL#2]
		STR r3[r1,r2,LSL#2]
		B tq2
fsi:

@@ Autre solution
		MOV r3,#4
		ADR r0,r1
		ADR r1,r2
		ADR r2,r2+N*4
		CMP r1,r0
		BHS NO_CHANCE
		MOV r3,#-4
		ADD r1,r1,#(N-1)*4
		ADD r0,r0,#(N-1)*4
		ADR r2,r2
NO_CHANCE:
WHILE:	CMP r1,r2
		BEQ f_while
		LDR r3,[r1],r3
		STR r4,[r0],r3
		B WHILE
f_while:
