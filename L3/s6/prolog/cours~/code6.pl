intersection([], E2, []). %1
intersection([X|E1], E2, [X|I]) :- member(X, E2), !, intersection(E1, E2, I). %2
intersection([X|E1], E2, I) :- intersection(E1, E2, I). %3
