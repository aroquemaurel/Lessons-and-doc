siPlus:		CMP r0, #'+'
			BNE	siMoin
			ADD	r3, r1, r2
			B	fsi
siMoin:		CMP r0, #'-'
			BNE	siMul
			SUB	r3, r1, r2
			B	fsi
siMul:		
			MUL r3, r1, r2
fsi:
