genere(0,0).
genere(K,K) :- K > 0.
genere(K,W) :- K > 0, R is K-1,
				genere(R,W).

