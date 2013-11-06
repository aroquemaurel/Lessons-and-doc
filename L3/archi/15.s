	ADR	r1, =t
	MOV	r0, #N-1
	ADR	r2, =za @fin
	
tq:	CMP	r0, #0
	BHS	ftq
	LDR	r4, [r1,r0,lsl#4]
	STR r4,[r2,r0,lsl#4]
	SUB r0,r0,#1
	B	tq
ftq:
