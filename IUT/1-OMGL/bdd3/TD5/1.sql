CREATE OR REPLACE VIEW vMoyParPlat (idP, moy, nbResto)
	AS SELECT idP,AVG(prix),COUNT(idR) FROM propP GROUP BY idP;

CREATE OR REPLACE VIEW vNbRestoSupMoy (idP, nbRestoSupMoy)
	AS SELECT idP, COUNT(*) FROM propP WHERE prixP > 
		(select moy FROM vMoyParPlat WHERE idP = propP.idP)
	GROUP BY idP;

SELECT vMoyParPlat.idP, nbRestoSupMoy, vnbrestosupmoy.nbRestoSupMoy 
FROM vMoyParPlat v1, vnbrestosupmoy v2 
WHERE v1.idP = v2.idP;
