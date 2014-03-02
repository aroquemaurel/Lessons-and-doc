nuplet(0, []).
nuplet(N, [0|L]) :- M is N-1, nuplet(M, L).
nuplet(N, [1|L]) :- M is N-1, nuplet(M, L).

/* insérer dans toutes les positions*/
insertion(X, L, [X|L]).
insertion(X, [Y|L], [Y|R]) :- insertion(X,L,R).

permutation([], []).
permutation([X|L], P) :- permutation(L, PL), insertion(X, PL, P).

