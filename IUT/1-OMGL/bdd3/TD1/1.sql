CREATE TABLE resto 
(
	idR char (3),
	nomR varchar2(20),
	villeR varchar2(20),
	dateOuv date,
	dateFerm date
);

ALTER TABLE resto
ADD CONSTRAINT pk_resto PRIMARY KEY(idR);

CREATE TABLE vin
(
	idV char(3),
	nomV varchar2(20),
	couleurV varchar2(10)
);

ALTER TABLE vin 
ADD CONSTRAINT pk_vin PRIMARY KEY(idV);

CREATE TABLE plat
(
	idP char(3),
	nomP varchar2(20),
	placeP varchar2(10),
	idV char(3)
);

ALTER TABLE plat 
ADD ( CONSTRAINT pk_plat PRIMARY KEY(idP),
	  CONSTRAINT fk_plat_idV FOREIGN KEY(idV) REFERENCES vin(idV)
	);

CREATE TABLE propV(
	idR char(3),
	idV char(3),
	prixV number(4,2)
);

ALTER TABLE propV 
ADD ( CONSTRAINT pk_propV PRIMARY KEY(idR, idV),
	  CONSTRAINT fk_propV_idR FOREIGN KEY(idR) REFERENCES resto,
	  CONSTRAINT fk_propV_idV FOREIGN KEY(idV) REFERENCES vin
	);
