-- destruction des tables
drop table suivre;
drop table louer;
drop table cours;
drop table moniteur;
drop table specialite;
drop table adherent;
drop table materiel;

-- Moniteur(noM, nomM, prenomM, adresse, dateNaissance)
create table moniteur (
	noM number,
	nomM varchar2(64),
	prenomM varchar2(32),
	adresse varchar2(128),
	dateNaissance date
);

alter table moniteur add constraint pk_moniteur PRIMARY KEY (noM);

-- Specialite(idSpecialite, nomS)
create table specialite(
	idSpecialite number,
	nomS varchar2(64)
);
alter table specialite add constraint pk_specialite PRIMARY KEY (idSpecialite);
alter table specialite add constraint ck_specialite_nomS CHECK (nomS 
					IN('ski de fond', 'ski alpin', 'raquette', 'kitesurf', 'monoski', 'surf')
);


-- adherent(noA, nomA, prenomA, adresseA, telephoneA, ageA)
create table adherent(
	noA number,
	nomA varchar2(64),
	prenomA varchar2(32),
	adresseA varchar2(128),
	telephoneA char(10),
	ageA number(2)
);
alter table adherent add constraint pk_adherent PRIMARY KEY (noA);
alter table adherent add constraint ck_adherent_age CHECK(ageA > 12 OR ageA < 100);

-- materiel(codeM, type, marque, prix, quantiteDispo)
create table materiel(
	codeM number,
	type varchar2(32),
	marque varchar2(32),
	prix number(8),
	quantiteDispo number(8)
);
alter table materiel add constraint pk_materiel PRIMARY KEY (codeM);
alter table materiel add constraint ck_materiel_quantiteDispo CHECK(quantiteDispo > 0);
alter table materiel add constraint ck_materiel_prix CHECK(prix > 0);

-- cours(codeC, niveau, nbPlaces, dateCours, #idSpecialite, #noM)
create table cours(
	codeC number,
	niveau varchar2(16),
	nbPlaces number(4),
	dateCours date,
	idSpecialite number,
	noM number
);
alter table cours add constraint pk_cours PRIMARY KEY (codeC);
alter table cours add constraint fk_cours_idSpecialite FOREIGN KEY (codeC) REFERENCES cours(codeC);
alter table cours add constraint fk_cours_noM FOREIGN KEY (idSpecialite) REFERENCES specialite(idSpecialite);
alter table cours add constraint ck_cours_idSpecialite CHECK(idSpecialite IS NOT NULL);
alter table cours add constraint ck_cours_niveau CHECK(niveau IN('débutant', 'moyen', 'confirmé', 'compétition'));
alter table cours add constraint cb_cours_nbPlaces CHECK(nbPlaces > 0);

-- suivre(#codeC, #noA)
create table suivre(
	codeC number,
	noA number 
);

alter table suivre add constraint pk_suivre PRIMARY KEY (codeC, noA);
alter table suivre add constraint fk_suivre_codeC FOREIGN KEY (codeC) REFERENCES cours(codeC);
alter table suivre add constraint fk_suivre_noA FOREIGN KEY (noA) REFERENCES materiel(codeM) on delete cascade;

-- louer(#noA, #codeM, quantite)
create table louer(
	noA number,
	codeM number,
	quantite number(8)
);
alter table louer add constraint pk_louer PRIMARY KEY (noA, codeM);
alter table louer add constraint fk_louer_noA FOREIGN KEY (noA) REFERENCES adherent(noA);
alter table louer add constraint fk_louer_codeM FOREIGN KEY (noA) REFERENCES materiel(codeM);
alter table louer add constraint ck_louer_quantite CHECK(quantite > 0);

