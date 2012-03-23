a .long	

si:
	LDR R0, .pA
	LDR R0[R0]
	LDR R1, .pB
	LDR R1, [R1]
	CMP R0, R1
	LDR R2, .pMin
	STRLO R0, [R2]
	STRHS R1, [R2]

