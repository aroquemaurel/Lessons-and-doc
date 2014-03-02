decomposer([], _, [], []).
decomposer([X|L], P, [X|I], S) :- X =< P, decomposer(L, P, I, S).
decomposer([X|L], P, I, [X|S]) :- X > P, decomposer(L, P, I, S).

triPivot([], []).
triPivot([P|L], T) :- decomposer(L, P, I, S),
					  triPivot(I, TI), 
					  triPivot(S, TS),
					  append(TI, [P|TS],T).
					

