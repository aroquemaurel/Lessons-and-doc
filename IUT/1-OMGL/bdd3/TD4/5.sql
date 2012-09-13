SELECT vin.nomV FROM vin, plat, resto, propP
WHERE plat.idV = vin.idV
	AND propP.idR = resto.idR
	AND propP.idP = plat.idP
	AND resto.nomR = "La bonne fourchette" 
	AND propP.prixP < 12
ORDER BY vin.nomV;
