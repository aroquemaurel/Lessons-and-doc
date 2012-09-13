CREATE TABLE propVBis AS SELECT idV, idR, moyP, prixP, prixV
FROM propV ;
DROP TABLE propV;
RENAME propVBis TO propV;
ALTER TABLE propV 
ADD ( CONSTRAINT pk_propV PRIMARY KEY(idR, idV),
	  CONSTRAINT fk_propV_idR FOREIGN KEY(idR) REFERENCES resto,
	  CONSTRAINT fk_propV_idV FOREIGN KEY(idV) REFERENCES vin
	);

