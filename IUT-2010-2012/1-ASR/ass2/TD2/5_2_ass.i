R0: .Pa
R1: .pb
R2: (a+0) ou a+4
R2: (b+0) ou b+4

			LDR R0, .Pa
			LDR R1, .Pb
Tantque:	LDR R2, [R0, #4]
			LDR R3, [R1, #4]
			CMP R2, R3
			BHI faire
			BNE fintantque
			LDR R2, [R0, #0]
			LDR R3, [R1, #0]
			CMP R2, R3
			BLS fintantque
faire:		...
			B tantque
fintantque:		
