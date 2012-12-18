-- a)
SELECT idP, idV FROM plat WHERE idV in ('V05', 'V08', 'V10');

-- b)
SELECT nomR, villeR, to_char(dateFerm, 'DAY-DD-MONTH-YYYY')
FROM resto 
ORDER BY villeR;

