-- a)
SELECT idR, idP, prixP FROM propP WHERE prixP < 20 AND spec = 'O';

-- b)
SELECT 'le restaurant' || idR || 'propose sa spécialité' || idP || 
	i'au prix de' || prixP || 'euros' FROM propP 
WHERE prixP < 20 AND spec = 'O';

