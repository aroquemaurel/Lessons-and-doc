append([],L2,L2).
append([X|L],L2,[X|R]) :- append(L, L2, R).

replace(_, _, [], []).
replace(E1, E2, [X|L], [Y|R]) :- replace(E1, E2, L, R).
replace(E1, E2, [W|L], [X|R]) :- W /== X, replace(E1, E2, L, R).

prefixe([], _).
prefixe([X|L1], [Y|L2]) :- prefixe(L1, L2).

segment(S,L) :- prefixe(S,L).
segment(S,[_|L]) :- segment(S,L).

prefixe2(P, L) :- append(P,_,L).
segment2(S, L) :- append(_,K,L), append(S,_,K), S \== [].
