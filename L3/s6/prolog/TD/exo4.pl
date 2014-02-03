/* somme des feuilles d'un arbre */
somme(feuille(X), X).
somme(noeud(G,D), S) :- somme(G, SG), 
						somme(D, SD),
						S is SG + SD.
