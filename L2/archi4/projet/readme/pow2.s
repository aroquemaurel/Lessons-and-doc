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
			MOV		r10, r6
			ADD		r10, r10, #24
fpowsi1:
powsi2:		CMP		r7, #32
			BEQ		fpowsi2
			CMP		r10, #1
			BEQ		fsitab
			MOV		r10, r7
			ADD		r10, r10, #16
fpowsi2:			
powsi3:		CMP		r8, #32
			BEQ		fpowsi3
			CMP		r10, #1
			BEQ		fsitab
			MOV		r10, r8
			ADD		r10, r10, #8
fpowsi3:			
powsi4:		CMP		r9, #32
			BEQ		fpowsi4
			CMP		r10, #1
			BEQ		fsitab
			MOV		r10, r9
fpowsi4:			

tabsi4:		CMP		r10, #0
			BEQ		fsitab
			MOV		r0, r0, LSR r10
			MOV		r1, #0
			B		finFct
fsitab:
