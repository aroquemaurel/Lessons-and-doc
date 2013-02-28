	MOV r3, #0 @ i <- 0
	MOV r2, #0 @ r2 <- 0
tq: CMP r3,r1 @ tantque(i < r1)
	BHS ftq 
	ADD r2,r0,r2 @r2 <- r0 + r2
	ADD r3, r3, #1 @i++
	B tq
ftq:


