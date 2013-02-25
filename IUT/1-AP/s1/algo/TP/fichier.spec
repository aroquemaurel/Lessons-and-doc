-- fichier.spec

-- Permet de choisir le fichier dans lequel on souhaite écrire des informations.
-- Si le fichier  existe son contenu sera effacé
-- Si le fichier n'existe pas, il sera créé
-- Seul un fichier peut être ouvert en même temps dans le même programme
procédure ouvrirFichier ;
 
 
-- Ferme le fichier
-- Note : Tout fichier doit être dermé s'il a été ouvert
procédure fermerFichier ;

-- Ecrit dans le fichier ouvert la chaîne c
procédure écrireFichier (entrée c <Chaîne>)  ;

-- Ecrit dans le fichier ouvert la chaîne c puis passe à la ligne suivante dans le fichier
procédure écrireFichierNL (entrée c <Chaîne>)  ;

-- Ecrit dans le fichier ouvert l'entier i
procédure écrireFichier (entrée i <Entier>)  ;

-- Ecrit dans le fichier ouvert l'entier i  puis passe à la ligne suivante dans le fichier
procédure écrireFichierNL (entrée i <Entier>)  ;
