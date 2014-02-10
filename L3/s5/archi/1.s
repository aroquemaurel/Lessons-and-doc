MOV		r0, #0
MOV		r1, #0
tq:		CMP		r0, #49
		BEQ		ftq
		ADD		r1, r0, r1	
		ADD		r0, r0, #1
		B tq
ftq:
