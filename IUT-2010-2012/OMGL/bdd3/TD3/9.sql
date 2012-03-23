-- a)
SELECT COUNT(*) FROM propP WHERE idP='&codeResto';

-- b)
SELECT idR, COUNT(*) FROM propP GROUP BY idR;

-- c)
SELECT idR, COUNT(*) FROM propP GROUP BY idR HAVING COUNT(*) > 15;


