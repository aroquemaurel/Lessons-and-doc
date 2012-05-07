-- not in
SELECT idV WHERE idV NOT IN (SELECT DISTINCT idv FROM propV);
-- minus
SELECT idV FROM vin MINUS SELECT DISTINCT idV FROM propV;
-- demi-jointures
SELECT vin.idV FROM vin, propV 
WHERE vin.idV = propV.idV(+)
	AND idR IS NULL ; 
-- not exist (requete synchronisé)
SELECT vin.idV FROM vin 
WHERE not exist (SELECT * FROM propV WHERE vin.idV = propV.idV);
