-- a)
SELECT idV, COUNT(*), MIN(prixV), AVG(prixP) 
FROM propV GROUP BY idV;

-- b)
(SELECT idV, COUNT(*), MIN(prixV), AVG(prixP) FROM propV GROUP BY idV)
UNION
(SELECT idV, 'O', null, null FROM vin WHERE idV not in(
		SELECT DISTINCT idV FROM propV)
);

