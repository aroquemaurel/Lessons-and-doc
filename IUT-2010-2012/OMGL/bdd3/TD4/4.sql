UPDATE propV SET prixMoy=(
	SELECT AVG(prixP) FROM propP, plat 
	WHERE propP.idP = plat.idP 
		AND plat.idV = propV.idV 
		AND propP.idR = propV.idR);
				
