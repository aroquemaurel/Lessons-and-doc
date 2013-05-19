			.global _start
			.global	fastdiv

_start:		
			ADR		r0, tabPow2 
			BL		fillTab		@ on remplit la table

			MOV		r0, #13
			MOV		r1, #3
			BL		fastdiv

			MOV		r0, #250
			MOV		r1, #50
			BL		fastdiv 
			MOV		r0, #5
			MOV		r1, #24
			BL		fastdiv

			MOV		r0, #1000
			MOV		r1, #1
			BL		fastdiv

			MOV		r0, #2048
			MOV		r1, #8
			BL		fastdiv

			MOV		r0, #65536
			MOV		r1, #512
			BL		fastdiv

			MOV		r0, #1000
			MOV		r1, #0
			BL		fastdiv	
	
exit:		B		exit


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


@@@ Gestion du cas ou le diviseur est une puissance de 2			
			ADR		r4, tabPow2 
			MOV		r5, r1, LSR #24 @r5 contient l'octet de poids fort
			LDRB	r6, [r4, r5]
			MOV		r5, r1, LSL #8 
			MOV		r5, r5, LSR #24 @r5 contient le 2nd octet de poids fort
			LDRB	r7, [r4, r5]
			MOV		r5, r1, LSL #16 
			MOV		r5, r5, LSR #24 @r5 contient le 3e octet de poids fort
			LDRB	r8, [r4, r5]
			MOV		r5, r1, LSL #24 
			MOV		r5, r5, LSR #24 @r5 contient l'octet de poids faible 
			LDRB	r9, [r4, r5]
			MOV		r10, #0	
powsi1:		CMP		r6, #32
			BEQ		fpowsi1
			ADD		r10, r6, #24
fpowsi1:
powsi2:		CMP		r7, #32
			BEQ		fpowsi2
			CMP		r10, #0
			BEQ		fsitab
			ADD		r10, r7, #16
fpowsi2:			
powsi3:		CMP		r8, #32
			BEQ		fpowsi3
			CMP		r10, #0
			BEQ		fsitab
			ADD		r10, r8, #8
fpowsi3:			
powsi4:		CMP		r9, #32
			BEQ		fpowsi4
			CMP		r10, #0
			BEQ		fsitab
			MOV		r10, r9
fpowsi4:			

tabsi4:		CMP		r10, #0
			BEQ		fsitab
			MOV		r0, r0, LSR r10
			MOV		r1, #0
			B		finFct
fsitab:
@@ Fin gestion du cas de la puissance de 2

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

@ Sous programme de branchement en cas d'erreur à cause d'une division par 0		
div_by_0:		
			B		exit


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


finoctetPow2:
@ Déclaration du tableau des puissance de 2
tabPow2:	.fill	256,1,32	
