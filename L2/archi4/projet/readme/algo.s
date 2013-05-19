@ Implémentation performante de la division X = Q * Y + R
@ Si Y = 0, branchement sur le sous-programme div_by_0
@ à fournir par l'utilisateur de cette fonction
@	r0 (entree) = X (Dividende)
@	r1 (entree) = Y (Diviseur)
@	r0 (sortie) = R (Reste)
@	r1 (sortie) = Q (Quotient)
fastdiv:
			STMFD	sp!,{r2-r10}
			CMP		r1, #0
			BEQ		div_by_0



@ Gestion du cas ou le diviseur est une puissance de 2			
@ Cf algo 2.2

@ Si on arrive ici, ce n'est pas une puissance de 2

			MOV		r2, #0
si1:		CMP		r0, #0
			BEQ		fsi1
			MOV		r1, r1, LSL #16

			MOV		r3, #1
pour:		CMP		r3, #16
			BHI		fpour
			MOV		r0, r0, LSL #1
			SUB		r0, r0, r1

			MOV		r2, r2, LSL #1
si2:		CMP		r0, #0
			BLT		sinon2
			ADD		r2, r2, #1
			B		fsi2
sinon2:
			ADD		r0, r0, r1
fsi2:

			ADD		r3, r3, #1
			B		pour
fpour:		
fsi1:		
			MOV		r1, r0, LSR	#16
			MOV		r0, r2
finFct:	
			LDMFD	sp!,{r2-r10}
			MOV		pc,r14
