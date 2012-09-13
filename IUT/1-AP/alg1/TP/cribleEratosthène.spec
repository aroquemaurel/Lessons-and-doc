importer entréeSortie;

type Ruban : tableau [1 à 250] de <Entier>;

-- Pose un jeton sur la case de rang i du ruban rub ; si celle-ci est occupée l'opération est sans effet.
procédure poser (màj rub <Ruban>, entrée i <Entier>)
;
-- Enleve un jeton sur la case de rang i du ruban rub ; si celle-ci est vide l'opération est sans effet.
procédure enlever (màj rub <Ruban>, entrée i <Entier>)
;

-- retourne VRAI si la case ne contient pas de jeton et FAUX sinon.
fonction estLibre (entrée rub <Ruban>, entrée i <Entier>) retourne <Booléen>
;

fonction nouveauRuban retourne <Ruban>;

-- Affiche un ruban Ã  l'écran. Affiche un . si la case est vide et * si la case contient un jeton.
procédure afficherRuban (entrée rub <Ruban>) 
;
