.equ N,10
	MOV R0,#0 @s <- 0
	MOV R1,#0 @i <- 0
tq:	CMP R1,#N @tantque(i <= N)
	BHI ftq 
	ADD R1,R0,R1 @s += i
	ADD R1,R1,#1 @ i++
	B tq
ftq:
