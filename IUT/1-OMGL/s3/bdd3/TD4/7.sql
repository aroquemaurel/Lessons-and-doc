SELECT 'le resto de code ' || idP || 'propose le plat' || plat.idP||'
sans disposer du vin' || 'recommandé avec le plat' 
FROM propP, plat
WHERE propP.idP = plat.idP
	AND plat.idV not in (SELECT idV FROM propV WHERE idR = prop.idR)
