SET LONG 9000 --largeur colonne, afficher
SELECT constraint_name, constraint_type, search_condition 
FROM user_constraint 
WHERE table_name = '&nom_table'; --& = paramètre
