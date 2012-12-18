-- plat le moins cher
SELECT MIN(prixMin) FROM plat;

-- Codes restaurant le proposant avec codes et prix des plats concernés
SELECT idR, idP, prixP FROM propP WHERE prixP=(SELECT MIN(prixMin) FROM plat;)
