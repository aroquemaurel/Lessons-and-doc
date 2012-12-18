glossaire
	R0: .pA puis a
	R1: .pR puis b
	R2: .pMin
debut
	si (R0 <- .pA, R0 <- R0$\uparrow$, R1 <- .pB, R1 <- R1$\uparrow$, R0 < R1)
		alors
		R2 <- .pMin;
		R2$\uparrow$ <- R0;
	sinon
		R2 <- .pMin;
		R2$\uparrow$
fin si;
