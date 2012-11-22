 /* N > 0 */
s = T[0];
T[0] = 0;
i = 1;
while(i != N) {
	/*  INV $\wedge$ c */
	s += T[i];
	T[i] = s - T[i];
	++i;
	/* INV */
}
 /* i = N $\wedge$ t[0] = 0 $\wedge$ ($\forall$ I $\leq$ i < i $\rightarrow$ T[I] = T[I-1] + T[I-1]) 
  * $\wedge$ s = t[i-1]+T|i-1]
  *
 /* t[0] = 0 $\wedge$ ($\forall$ I $\leq$ I < N $\rightarrow$ T[I] = T[I-1] + T[I-1]) 
  * $\wedge$ s = t[N-1]+T|N-1]
  */
