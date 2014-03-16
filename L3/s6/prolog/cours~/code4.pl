eliminer(X,[], []). %1
eliminer(X, [X|L], R) :- !, eliminer(X, L, R). %2
eliminer(X, [Y|L], [Y|R]) :- eliminer(X, L, R). %3
