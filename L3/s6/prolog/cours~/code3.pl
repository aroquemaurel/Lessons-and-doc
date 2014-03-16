intersection([], E2, []). %1
intersection([X|E1], E2, [X|I]) :- member(X, E2), intersection(E1, E2, I). %2
intersection([X|E1], E2, I) :- not(member(X,E2)), intersection(E1, E2, I). %3

% 1 exclusives avec 2 et 3
% 2 et 3 non exclusives, si X appartient E2
% rajouter not(member) dans clause 3...
