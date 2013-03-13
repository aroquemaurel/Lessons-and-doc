drop table tableau;
drop table posseder;
drop table classement;
drop table categorie;
drop table joueur;
drop table tournoi;
drop table club;


create table joueur(idJ, nomJ, prenomj, mailJ, telJ, DNJ, categorieAge, noLicence, sexe, idC) as select * from TA;
create table club(idC, nomC, adresseC, sigleC) as select * from TB;
create table tournoi(idT, nomT, dateDT, dateFT, dateLimiteIniscrptionW, dateLimiteInscription, categorieT, lieuT, prix1Tableau, prix2Tableau, prix3Tableau, idC) as select * from TC;
create table classement(classement) as select * from TD;
create table categorie(categorie) as select * from TE;
create table tableau(idTableau, dateDTableau, dateFTableau, idT, classement, categorie) as select * from TF;
create table posseder(idJ, classement, categorie) as select * from TG;

--select b.constraint_name,b.table_name,b.column_name,constraint_type,search_condition,r_constraint_name
--from user_constraints a,user_cons_columns b
--where a.constraint_name=b.constraint_name;

--drop table TA;
--drop table TB;
--drop table TC;
--drop table TD;
--drop table TE;
--drop table TF;
--drop table TG;

alter table joueur add constraint pk_joueur_idJ PRIMARY KEY(idJ);
alter table club add constraint pk_club_idC PRIMARY KEY(idC);
alter table tournoi add constraint pk_tournoi_idT PRIMARY KEY(idT);
alter table classement add constraint pk_classement_classement PRIMARY KEY(classement);
alter table categorie add constraint pk_categorie_categorie PRIMARY KEY(categorie);
alter table tableau add constraint pk_tableau_idTableau PRIMARY KEY(idTableau);
alter table posseder add constraint pk_posseder_idJCltCategorie PRIMARY KEY(idJ,classement,categorie);

alter table joueur add constraint fk_joueur_idC FOREIGN KEY(idC) REFERENCES club;
alter table tournoi add constraint fk_tournoi_idC FOREIGN KEY(idC) REFERENCES club;
alter table tableau add constraint fk_tableau_idT FOREIGN KEY(idT) REFERENCES tournoi;
alter table tableau add constraint fk_tableau_classement FOREIGN KEY(classement) REFERENCES classement;
alter table tableau add constraint fk_tableau_categorie FOREIGN KEY(categorie) REFERENCES categorie;
alter table posseder add constraint fk_posseder_idJ FOREIGN KEY(idJ) REFERENCES joueur;
alter table posseder add constraint fk_posseder_classement FOREIGN KEY(classement) REFERENCES classement;
alter table posseder add constraint fk_posseder_categorie FOREIGN KEY(categorie) REFERENCES categorie;

