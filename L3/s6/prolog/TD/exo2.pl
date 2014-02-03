/* 
 * Fonction basique : retourner une pièce 
 * {pile,face} x {pile,face} -> {Vrai,Faux}
*/
opp(pile,face).
oppp(face,pile).

retourne(table(A,B,C),table(AA,BB,C)) :- opp(A,AA) ,opp(B,BB).
retourne(table(A,B,C),table(AA,B,C)) :- opp(A,AA) ,opp(C,CC).
retourne(table(A,B,C),table(A,BB,CC)) :- opp(B,BB) ,opp(C,CC).

jeu(T0) :- retourne(T0,T1), retourne(T1,T2), retourne(T2,table(X,X,X)),
			writeln(T0),writeln(T1),writeln(T2,writeln(table(X,X,X)).
