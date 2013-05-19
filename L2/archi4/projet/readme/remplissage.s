@ Remplis la table à 256 entréees
@ Donnant pour chaque valeur entre 0 et 255, 
@ n si la valeur est une puissance de 2, 32 sinon
@ r0 (entree) : Adresse de début du tableau
fillTab:
			STMFD	sp!,{r0-r3}
			ADD		r0, r0, #1
			MOV		r1, #0
			MOV		r2, #1						  
tq3:		CMP		r2, #512 
			BHS		ftq3						 
			STRB	r1, [r0]	
			ADD		r1,r1,#1										
			ADD		r0, r0, r2						
			MOV		r2, r2, LSL #1										
			B		tq3							
ftq3:
			LDMFD	sp!,{r0-r3}
			MOV		pc, r14
endFillTab:
