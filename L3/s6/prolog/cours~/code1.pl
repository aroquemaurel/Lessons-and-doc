eliminer(X,[], []). %1
eliminer(X, [X|L], R) :- eliminer(X, L, R). %2
eliminer(X, [Y|L], [Y|R]) :- X \== Y, eliminer(X, L, R). %3
% 1 Exclusivité avec 2 et 3
% 2 et 3 pas non exclusives -> Si 2 ne pas faire 3 -> X \== Y
