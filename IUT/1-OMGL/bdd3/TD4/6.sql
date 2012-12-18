SELECT resto.idR FROM propP AS P1, propP AS P2
WHERE P1.idR = P2.idR 
	AND P1.idR = 'P01'
	AND P2.idR = 'P02';

(SELECT idR FROM propP WHERE idV='P01')
INTERSECT 
(SELECT idR FROM proP WHERE idP = 'P02');

SELECT idR FROM propP
WHERE idP='P01' AND idR in(SELECT idR FROM propP WHERE idP='P02');

SELECT idR FROM propP as P1
WHERE idP='P01'
	AND EXISTS(SELECT idR FROM propP as P2
				WHERE idP = 'P02' AND P1.idR = P2.idR);

