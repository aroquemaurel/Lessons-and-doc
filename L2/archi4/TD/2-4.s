	MOV r3, #1
	CMP r1, #0
	BGT boucle
	RSB r1, r1, #0
	MOV r3, #0
boucle: MOV R2, #0
tque: CMP R1, #0 
	BEQ sortie1
	ADD r2, r0, r0
	SUB r1, r1, #1
	B tque
sortie1: CMP R3, #0
	BNE sortie2
	RSB r1, r1, #0
sortie2:
