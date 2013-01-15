/* PE : (N > 0) $\wedge$ T(0..N, $\leq$) */
int i  = 1;
int nb = 1;
int p  = 1;

/*  INV= 1 $\leq$ p$\leq$ i $\wedge$ nb $\geq$ 1 $\wedge$ nb = $\nu$I : 0 $\leq$ I $\leq$ i - p 
 * $\wedge$ T[I] = T[I+p-1] $\wedge$ 
 * $\forall$ J : O $\leq$ J $\leq$ i-p-1 $\rightarrow$ T[J] $\neq$ T[J+p] 
 */
while(i != N) {
	/*  INV $\wedge$ C*/
	if (T[i] == T[i-p]) {
		np = 1;
		++p;
	} else if(T[i] == T[i-p+1]) {
		++np;
	}
	++i;
	/*  INV  */
}

/* On remplace une constante par une variable ainsi on a $\neg$C $\wedge$ INV
 * PS : (i = N) $\wedge$ nb $\geq$ 1 $\wedge$ nb = $\nu$I : 0 $\leq$ I $\leq$ i - p 
 * $\wedge$ T[I] = T[I+p-1] $\wedge$ 
 * $\forall$ J : O $\leq$ J $\leq$ i-p-1 $\rightarrow$ T[J] $\neq$ T[J+p] 
 */

/* PS : 1 $\leq$ p$\leq$ i $\wedge$ nb $\geq$ 1 $\wedge$ nb = $\nu$I : 0 $\leq$ I $\leq$ N - p $\wedge$ T[I] = T[I+p-1] $\wedge$ 
 * $\forall$ J : O $\leq$ J $\leq$ N-p-1 $\rightarrow$ T[J] $\neq$ T[J+p] 
 */

