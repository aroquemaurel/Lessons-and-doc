/* appartient à un arbre */					
estDansAbe(N, abe(_,N,_)).
estDansAbe(N, abe(G,_,_)) :- estDansAbe(N, G). 
estDansAbe(N, abe(_,_,D)) :- estDansAbe(N, D). 

/* appartient à un arbre ordonné */					
estDansAbeo(N, abe(_,N,_)).
estDansAbeo(N, abe(G,_,_)) :- X < R, estDansAbeo(N, G). 
estDansAbeo(N, abe(_,_,D)) :- X > R, estDansAbeo(N, D). 

/* Insérer dans un arbre ordonné */
inserer(X, vide, abe(vide,X,vide)).
inserer(X, abe(G,R,D), abe(RG,R,D) ) :-  X < Y, inserer(X, G, RG).
inserer(X, abe(G,R,D), abe(G,R,RD) ) :-  X > Y, inserer(X, G, RD).
