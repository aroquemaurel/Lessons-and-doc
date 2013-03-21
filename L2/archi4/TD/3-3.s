.eq N, 100
s:	.byte	1,23,255 @,...
t: .fill N, 1, 0
	LDR r0,=t
	LDRB r1,=s
	MOV r2, #N
tq:	CMP r2, #N
	BHS ftq:
	RSB r4, R0, #N-1			
	LDRB r3, [r1,r2]
	STRB r3,[r0,r4]
	ADD r2, r2, #1
	B tq:
ftq:

@ Avec pointeurs
ADR r1, s
ADR r2, t
ADD r3, r1, #N-1
tq: CMP r3, r1
	BHS ftq
	LDR r4, [r2], #1
	STR r4, [r3], #-1

	B tq
ftq:
