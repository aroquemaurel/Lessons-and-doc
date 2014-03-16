maximum([M], M). %1
maximum([X|L], X) :- maximum(L, P), X > P. %2 maximum calculé deux
maximum([X|L], P) :- maximum(L, P), X < P. %3 fois

%%%
maximum([M], M). %1
maximum([X|L], M) :- maximum(L, P), sup(X,P,M). %2
sup(X, P, X) :- X >= P. %3
sup(X, P, P) :- X < P. %4
% 3 et 4 exclusives grace aux conditions
