N $\geq $1
bool trouve(X,T,N)
(o  $\leq$ pos $\leq$ N) \wedge ($\forall$ I : 0 $\leq $I < pos $\rightarrow $T[I] $\neq$ X) $\wedge$ (pos < N $\rightarrow$ T[pos] = X)  

Méthode: Recherche séquentielle ou parcours le tableau jusqu'à ce qu'on rencontre X ou bien  qu'on sorte du tableau T[pos] = X || pos=N

stratégie Elimination d'un conjoint
((pos $  \neq$ ) -> T[pos] = X) \equals (pos-N) v (T[pos] = X)

	/*  PE */
