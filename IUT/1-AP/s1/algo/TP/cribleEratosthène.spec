importer entr�eSortie;

type Ruban : tableau [1 � 250] de <Entier>;

-- Pose un jeton sur la case de rang i du ruban rub ; si celle-ci est occup�e l'op�ration est sans effet.
proc�dure poser (m�j rub <Ruban>, entr�e i <Entier>)
;
-- Enleve un jeton sur la case de rang i du ruban rub ; si celle-ci est vide l'op�ration est sans effet.
proc�dure enlever (m�j rub <Ruban>, entr�e i <Entier>)
;

-- retourne VRAI si la case ne contient pas de jeton et FAUX sinon.
fonction estLibre (entr�e rub <Ruban>, entr�e i <Entier>) retourne <Bool�en>
;

fonction nouveauRuban retourne <Ruban>;

-- Affiche un ruban à l'�cran. Affiche un . si la case est vide et * si la case contient un jeton.
proc�dure afficherRuban (entr�e rub <Ruban>) 
;
