	CMP r0, #0
	BLT sinon1
	MOV r4,#0
	RSB r0,#0
	B fsi1
sinon1: MOV r4,#1
fsi1:
	CMP r1, #0
	BLT sinon2
	MOV r5,#0
	RSB r2,#0
sinon2:
@(boucle)
	CMP r4,#1
	BNE fsi
	RSB r3,#0
fsi3:
	CMP r4,r5
	BEQ fsi4
	RSB r2,#0
fsi4:
