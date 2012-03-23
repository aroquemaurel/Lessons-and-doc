-------------------------------------
-- Fichier libgraphique.spec
-- Auteur    : SAFORCADA Valentin
-- Date      : 10 octobre 2010
-------------------------------------

-- Constante MAXPOINT qui correspond au nombre de point maximum dans un polygone
constante MAXPOINT <Entier> = 120 ;

-- D�finition de la structure Point .
type Point : enregistrement 
    iX <Entier>,
    iY <Entier> ;

-- D�finition de la structure Rect .
type Rect : enregistrement
    pos <Point>,
    iLongueur <Entier>,
    iHauteur  <Entier> ;

type Polygone : tableau [1 � MAXPOINT] de <Point> ;

proc�dure initPoint(entr�e iX <Entier>, entr�e iY <Entier>, m�j pos <Point>) ;
proc�dure initPolygone(m�j polygone <Polygone>) ;

fonction getPoint(entr�e iX <Entier>, entr�e iY <Entier>) retourne <Point> ;
fonction pointIdentique(entr�e pos1 <Point>, entr�e pos2 <Point>) retourne <Bool�en> ;

proc�dure d�placerStyletDe(entr�e iNbr <Entier>) ;
proc�dure d�placerStyletAuPoint(entr�e pos <Point>, entr�e offSetX <Entier>, entr�e offSetY <Entier>, entr�e trace <Bool�en>)  ;

proc�dure tracerSegment(entr�e pos1 <Point>, entr�e pos2 <Point>) ;
proc�dure tracerPolygone (entr�e polygone <Polygone>)  ;
proc�dure tracerCercle(entr�e posDepart <Point>, entr�e iRayon <Entier>)  ;
