CREATE OR REPLACE TRIGGER T_A_DIU_PROPP
after DELETE OR INSERT OR UPDATE of idP on propP
for each row 
begin
	if deleting then
		UPDATE plat SET nbResto = nbResto-1 WHERE idP = :old.idP;
		UPDATE resto SET nbplat = nbPlat-1 WHERE idR = :old.idR;	
		UPDATE plat SET 
				prixMoy = (prixMoy*(nbResto+1)-old.prixP)/nbResto
			WHERE idP = :old.idP
	else if inserting then
		UPDATE plat SET nbResto = nbResto+1 WHERE idP = :old.idP;
		UPDATE resto SET nbplat = nbPlat+1 WHERE idR = :old.idR;	
		UPDATE plat SET 
				prixMoy = (prixMoy*nbResto-1)+:newpriP)/nbResto
	else
		if updating(idP) then
			UPDATE plat SET nbResto = nbResto-1 WHERE idP=:old.idP;
			UPDATE plat SET nbResto = nbResto+1 WHERE idP=:new.idP;
			UPDATE plat SET 
					prixMoy = (prixMoy*(nbResto+1)-:old.prixP)/nbResto
				WHERE idP=:old.idp;
			UPDATE plat SET 
					prixMoy = (prixMoy*(nbResto-1)-:old.prixP)/nbResto
				WHERE idP=:new.idp;
		else -- cas updating(prixP)
			UPDATE plat SET 
					prixMoy = prixMoy+(:new.prixPold-old.)/nbResto 
				WHERE idP=new.idP;
		end if;
	end if;
end

