-------------------------------------
-- Fichier libgraphique.spec
-- Auteur    : SAFORCADA Valentin
-- Date      : 10 octobre 2010
-------------------------------------

-- Constante MAXPOINT qui correspond au nombre de point maximum dans un polygone
constante MAXPOINT <Entier> = 120 ;

-- Définition de la structure Point .
type Point : enregistrement 
    iX <Entier>,
    iY <Entier> ;

-- Définition de la structure Rect .
type Rect : enregistrement
    pos <Point>,
    iLongueur <Entier>,
    iHauteur  <Entier> ;

type Polygone : tableau [1 à MAXPOINT] de <Point> ;

procédure initPoint(entrée iX <Entier>, entrée iY <Entier>, màj pos <Point>) ;
procédure initPolygone(màj polygone <Polygone>) ;

fonction getPoint(entrée iX <Entier>, entrée iY <Entier>) retourne <Point> ;
fonction pointIdentique(entrée pos1 <Point>, entrée pos2 <Point>) retourne <Booléen> ;

procédure déplacerStyletDe(entrée iNbr <Entier>) ;
procédure déplacerStyletAuPoint(entrée pos <Point>, entrée offSetX <Entier>, entrée offSetY <Entier>, entrée trace <Booléen>)  ;

procédure tracerSegment(entrée pos1 <Point>, entrée pos2 <Point>) ;
procédure tracerPolygone (entrée polygone <Polygone>)  ;
procédure tracerCercle(entrée posDepart <Point>, entrée iRayon <Entier>)  ;
