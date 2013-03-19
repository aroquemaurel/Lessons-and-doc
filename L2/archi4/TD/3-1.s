.eq N,10
t: .fill N,4,0
LDR r1,=t
MOV R2,#0
MOV R0,#0

tq: CMP r1,N
	BHS ftq
	LDR r3,[r1,r2,LSL#2]	
	ADD r0,r0,r3
	ADD r2,r2,#1
	B tq 
ftq:
