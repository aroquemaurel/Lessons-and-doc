		MOV		r0, #0
		MOV		r1, #0
		MOV		r2, #0
		MOV		r3, #42 @;N
		MOV		r4, #1

tq:		CMP		r4, r3
		BEQ		ftq	
		MOV		r5, r4

		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		@ multiple 2
tqMul2:	CMP		r5, #2
		BHI		finMul2	
		SUB		r5, r5, #2
		CMP		r5, #0
		BEQ		ftqMul2	
ftqMul2:
		ADD		r0,r0, r4
finMul2:
		MOV		r5, r4

		@ multiple 4
tqMul4:	CMP		r5, #4
		BHI		finMul4	
		SUB		r5, r5, #4
		CMP		r5, #0
		BEQ		ftqMul4	
ftqMul4:
		ADD		r1,r1, r4
finMul4:
		MOV		r5, r4

		@ multiple 8
tqMul8:	CMP		r5, #8
		BHI		finMul8	
		SUB		r5, r5, #8
		CMP		r5, #0
		BEQ		ftqMul8
ftqMul4:
		ADD		r2,r2, r4
finMul4:
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		ANDS	r5, r4, #0b1
		BNE		noMul2
		ADD		r0, r0, r4
noMul2:
		ANDS	r5, r4, #0b11
		BNE		noMul4
		ADD		r1, r1, r4
noMul4:
		ANDS	r5, r4, #0b111
		BNE		noMul8
		ADD		r2, r2, r4
noMul8:

		ADD		r4, r4, #1
		B tq
ftq:		



