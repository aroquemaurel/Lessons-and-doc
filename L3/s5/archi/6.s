		MOV		r2, #0
		MOV		r3, r0
tq:		CMP		r3, r1 
		BHI		ftq
		SUB		r3, r3, r1 
		ADD		r2,r2, #1 
		B		tq
ftq:
