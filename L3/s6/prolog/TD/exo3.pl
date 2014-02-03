/* 1- somme(L,S) est vrai si S est la somme des entiers d'une ligne L */
somme(lig(A,B,C),S) :- S is A+B+C.

/* 2- */
colo1(mat(lig(A,_,_),lig(B,_,_),lig(C,_,_))) :- lig(A,B,C).
colo2(mat(lig(_,A,_),lig(_,B,_),lig(_,C,_))) :- lig(A,B,C).
colo3(mat(lig(_,_,A),lig(_,_,_),lig(_,_,C))) :- lig(A,B,C).

diag1(mat(lig(A,_,_),lig(_,B,_),lig(_,_,C))) :- lig(A,B,C).
diag2(mat(lig(_,_,C),lig(_,B,_),lig(A,_,_))) :- lig(A,B,C).

/* l'unification ne permet pas de tester que deux paramètres sont différents : 
 *	ils faut tous les testers 2 à 2 
 */
tousdiff(mat(lig(A,B,C)), mat(lig(D,E,F)), mat(lig(G,H,I))) :- A \==B, A\==C, A\==D.  /* .... */

magique(mat(lig(A,B,C), lig(D,E,F), lig(G,H,I)) :-
												somme(L1,S),
												somme(L2,S),
												somme(L3,S),
												colo1(mat(L1,L2,L3), C1), somme(C1,S),
												colo2(mat(L1,L2,L3), C2), somme(C2,S),
												colo3(mat(L1,L2,L3), C3), somme(C3,S),
												diag1(mat(L1,L2,L3), D1), somme(D1,S),
												diag2(mat(L1,L2,L3), D2), somme(D2,S),
												tousdiff(mat(L1,L2,L3)).


					
