CREATE OR REPLACE TRIGGER T_A_DIU_PROPP
after DELETE OR INSERT OR UPDATE of idP on propP
for each row 
begin
	if deleting then
		UPDATE plat SET nbResto = nbResto-1 WHERE idP = :old.idP;
		UPDATE resto SET nbplat = nbPlat-1 WHERE idR = :old.idR;	
	else if inserting then
		UPDATE plat SET nbResto = nbResto+1 WHERE idP = :old.idP;
		UPDATE resto SET nbplat = nbPlat+1 WHERE idR = :old.idR;	
	else
		UPDATE plat SET nbResto = nbResto-1 WHERE idP = :old.idP;
		UPDATE plat SET nbResto = nbResto+1 WHERE idP = :new.idP;
	end if;
end

