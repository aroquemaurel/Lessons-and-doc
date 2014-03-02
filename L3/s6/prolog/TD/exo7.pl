inserer(X, [], [X]).
inserer(X, [Y|L], [X|[Y|L]]) :- X =< Y.
inserer(X, [Y|L], [Y|R]) :- X > Y, inserer(X, L, R).

triInsertion([], []).
triInsertion([X|L], T) :- triInsertion(L, TL), 
						  inserer(X, Tl, T).
