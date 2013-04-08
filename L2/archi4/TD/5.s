		.equ	N,50
t:		.word	1,5,...
		MOV		r1,#0
		MOV		r2,#N
		ADR		r0,t

tq1:	CMP		r2,#N
		BLS		ftq1
		MOV		r1,#0
tq2:	SUB		r3,r2,#1
		CMP		r1,r3
		BHS		ftq2
		LDR		r3,[r4,r1,LSL #2]
		ADD		r5,r1,#1
		LDR		r4,[r0,r5,LSL #2]
si1:	CMP		r3,r4
		BHS		finsi
		STR		r4, [r0,r1,LSL #2]
		STR		r3, [r0,r5,LSL #2]
finsi:	ADD		r1, r1, #1
		B		tq2
ftq2:	SUB r2,r2,#1
ftq1:	B	tq1






@ Autre algorithme
si1:	CMP		r3,r4
		BHS		fsi
		STR		r3, [r2]
		STR		r4,[r2,#-4]
fsi1:	B		tq2
ftq2:	SUB		r1,r1,#4
		B		tq1
ftq1:
