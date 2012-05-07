-- fichier.spec

-- Permet de choisir le fichier dans lequel on souhaite �crire des informations.
-- Si le fichier  existe son contenu sera effac�
-- Si le fichier n'existe pas, il sera cr��
-- Seul un fichier peut �tre ouvert en m�me temps dans le m�me programme
proc�dure ouvrirFichier ;
 
 
-- Ferme le fichier
-- Note : Tout fichier doit �tre derm� s'il a �t� ouvert
proc�dure fermerFichier ;

-- Ecrit dans le fichier ouvert la cha�ne c
proc�dure �crireFichier (entr�e c <Cha�ne>)  ;

-- Ecrit dans le fichier ouvert la cha�ne c puis passe � la ligne suivante dans le fichier
proc�dure �crireFichierNL (entr�e c <Cha�ne>)  ;

-- Ecrit dans le fichier ouvert l'entier i
proc�dure �crireFichier (entr�e i <Entier>)  ;

-- Ecrit dans le fichier ouvert l'entier i  puis passe � la ligne suivante dans le fichier
proc�dure �crireFichierNL (entr�e i <Entier>)  ;
