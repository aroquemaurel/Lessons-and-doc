-- a)
SELECT COUNT(*) FROM resto;

-- b)
SELECT COUNT(*) FROM propV WHERE idV='V12';

-- c)
SELECT COUNT(distinct idV) FROM propV;

-- d) 
SELECT COUNT(*) FROM resto WHERE dateFerm IS NOT NULL;

-- e)
SELECT COUNT(distinct idV) FROM plat;

-- f)
SELECT COUNT(*) - COUNT(dateFerm) FROM resto;
