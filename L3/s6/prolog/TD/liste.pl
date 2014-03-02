member(X, cons(X,_)).
member(X, cons(_,Q)) :- member(X,Q).

longueur(vide, 0).
longueur(cons(_,Q), X) : longueur(Q, R), X is R + 1
