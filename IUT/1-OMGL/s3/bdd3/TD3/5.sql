-- Ville commence par "T"
SELECT DISTINCT * WHERE villeR LIKE 'T%'; 
-- Ville finitp par E 
SELECT DISTINCT * WHERE villeR LIKE '%E'; 
-- Ville contient "T"
SELECT DISTINCT * WHERE villeR LIKE '%T%'; 
-- Ville commence par une consonne en majuscule 
SELECT DISTINCT * 
WHERE substr(villeR, 1, 1) NOT IN('A', 'E', 'I', 'O', 'U', 'Y')
	AND substri(villeR, 1, 1) between 'B' AND 'T';
