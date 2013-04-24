_atoi:		STMFD	sp!{r0,r2,r3,r4}
			MOV		r1, #0
			MOV		r4, #10

tq:			LDRB	r3,[r0]
			CMP		r3, #'\0'
			BEQ		ftq
			MOV		r2,r3
			MUL		r1,r4,r1
			ADD		r0,r0,#1
			SUB		r2,r2,#0
			B		tq
ftq:		LDMFD	sp!{r0,r2,r3,r4}


@ Optimisation
_atoi:		STMFD	sp!{r0,r2}
			MOV		r1, #0

tq:			LDRB	r2,[r0]
			CMP		r2, #'\0'
			BEQ		ftq
			ADD		r1,r1,r1
			ADD		r1,r2,r2,LSL#2
			SUB		r2,r2,#0
			B		tq
ftq:		LDMFD	sp!{r0,r2}


