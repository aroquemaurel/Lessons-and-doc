maximum([M], M) :- !. % Cut defficacité : non conseillé
maximum([X|L], M) :- maximum(L, P), sup(X,P,M). %2
sup(X, P, X) :- X >= P, !. % Si X >= P alors clause 3 mais pas 4
sup(X, P, P).
