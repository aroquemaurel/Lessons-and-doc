/* $(N \geq 1) \wedge (B(N), \geq )$ */
j = 1;
p = 1;
/* $INV = (1 \leq p \leq j \leq N) \wedge (\exists k : 0 \leq k \leq j - p) \wedge (B[k] = B[k+p-1]))$
$\wedge (\forall k (0 \leq k \leq j -p - 1) \rightarrow (B[k] \neq B[k+p]))$ */
while (j != N) {
	/* $INV \wedge c$ */
	if(B(j-p] == B[j]) 
		p++;
	j++;
	/* INV */
}
/* $\neg c \wedge INV$ */
/* $R = (1 \leq p \leq N) \wedge (\exists k : 0 \leq k \leq N - p) \wedge $
$(B[k] = B[k+p-1])) \wedge (\forall k (0 \leq k \leq N -p - 1) \rightarrow (B[k] \neq B[k+p]))$ */
