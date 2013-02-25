ALTER TABLE resto ADD nbPlat number(3,0);
UPDATE resto SET nbPlat=(SELECT COUNT(idP) FROM propP.idR = resto.idR);
