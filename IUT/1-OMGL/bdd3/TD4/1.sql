SELECT idR FROM propP, propV
GROUP BY idR
HAVING COUNT(idP) > 20 AND COUNT(idV) > 10

-- ou
SELECT propP idR FROM propP; propV 
WHERE propP.idR = propV.idR 
GROUP BY propP.idR
HAVING COUNT(DISTINCT propP.idP) > 20
	AND COUNT (DISTINCT vin.idV) > 10;

