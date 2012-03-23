R0: .Pa
R1: .pb
R2: (a+0) ou a+4
R2: (b+0) ou b+4

/!\ on suppose R0 et R1 non modifiés dans la boucle

R0 <- .pa
R1 <- .pb

tantque ((R2 <- (R0+#4)$\uparrow$, R3 <- (R1+#4)$\uparrow$, R2 > 3) ou (R2=R3 et
			(R2 <- R0$\uparrow$, R3 <- R1$\uparrow$, R2 > R3)) faire
		...
fin tantque
