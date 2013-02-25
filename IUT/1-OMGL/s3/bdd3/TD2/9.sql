ALTER TABLE Plat ADD(
	prixMax number(4,2),
	prixMin number (4,2),
	prepaMax number (4,2),
	prepaMin number (4,2);
				
UPDATE plat SET prixMax=(SELECT max(prixP) from propP WHERE idP='P10')
	WHERE idP='P10';
	
UPDATE plat SET prixMin=(SELECT min(prixP) from propP WHERE idP='P10')
	WHERE idP='P10';

-- etc.... 
-- ou sinon, en une seule requete:

UPDATE plat SET (prixMax, prixMin, prepaMax, prepaMin)=
	(
		SELECT max(prixP), min(prixMin), max(prepaP), min(prepaMin) 
		FROM propP
		WHERE idP='P10'
	)


