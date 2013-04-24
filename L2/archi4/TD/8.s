@ transformation d'un entier en 
@ chaine de caratères
@ r0 (entree) entier
@ r1 (entree) chaine 
	
itoa:		STMFD	sp!{r1-r5,LR}
			MOV		r4,r1
			MOV		r5,r1
			MOV		r1, #10

@ Cas particulier du 0
			CMP		r0, #0
			BNE		tq1
			MOV		r1, #'0'
			STRB	r1, [r5],#1
			B		ftq1

@ boucle de décomposition
tq1:		CMP		r0, #0
			BEQ		ftq1
			BL		division
			MOV		r0, r2
			ADD		r3, r3, #'0'
			STRB	r3, r5, #1
			B		tq1
ftq1:		
			MOV		r3,#'\0'
			STRB	r3, [r5]

			SUB		r5, r5, #1			
@ Boucle inversion
tq2:		CMP		r4,r5
			BHS		fq2
			LDRB	r2, [r4]
			LDRB	r3, [r5, #-1]!
			STRB	r2,[r5]
			STRB	r3, [r4], #1
			B		ftq2
ftq2:
@ dépile pc, le met dans lr et donc revient au programme appelant
			STMFD	sp!{r1-r5, pc}
