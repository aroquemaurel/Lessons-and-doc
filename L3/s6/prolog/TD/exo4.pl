/* somme des feuilles d'un arbre */
somme(feuille(X), X).
somme(noeud(G,D), S) :- somme(G, SG), 
						somme(D, SD),
						S is SG + SD.

/* appartient à un arbre */					
member(feuille(X), X).
member(noeud(G,_), N) :- member(G, N). 
member(noeud(_,D), N) :- member(D, N). 

/* hauteur de l'arbre */
max(X,Y,X) :- X >= Y. 
max(X,Y,Y) :- Y > X. 

hauteur(feuille(_), 0).
hauteur(noeud(G,D), H) :- hauteur(G, HG),
						  hauteur(D, HD),
						  max(HD,HD,MX),
						  H is MX+1.

miroir(feuille(F), feuille(F)).					  
miroir(noeud(G,D), noeud(RD,RG)) :- miroir(noeud(G, RG)), 
									 miroir(noeud(D,RD)).
