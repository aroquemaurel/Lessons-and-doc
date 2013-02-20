-- Moniteur(noM, nomM, prenomM, adresse, dateNaissance)
insert into moniteur(noM, nomM, prenomM, adresse, dateNaissance) 
	VALUES (1, 'Dupond', 'Jean', '12 route de la montagne, Super Besse', '01-01-1980');
insert into moniteur(noM, nomM, prenomM, adresse, dateNaissance) 
	VALUES (2, 'Ano', 'Nyme', '56 rue des pistes, Saint Pierre Colamines', '23-06-1968');
insert into moniteur(noM, nomM, prenomM, adresse, dateNaissance) 
	VALUES (3, 'Martin', 'Sophie', 'Route du lac Pavin, Compains', '13-05-1988');
insert into moniteur(noM, nomM, prenomM) VALUES (4, 'Picoud', 'Sebastien');

-- Specialite(idSpecialite, nomS)
insert into Specialite(idSpecialite, nomS) VALUES(1, 'ski alpin');
insert into Specialite(idSpecialite, nomS) VALUES(2, 'ski de fond');
insert into Specialite(idSpecialite, nomS) VALUES(3, 'raquette');
insert into Specialite(idSpecialite, nomS) VALUES(4, 'kitesurf');
insert into Specialite(idSpecialite, nomS) VALUES(5, 'monoski');
insert into Specialite(idSpecialite, nomS) VALUES(6, 'surf');

-- adherent(noA, nomA, prenomA, adresseA, telephoneA, ageA)
insert into adherent(noA, nomA, prenomA, adresseA, telephoneA, ageA) 
	values(1, 'Lars', 'Julien', '12 rue P. Picasso, Clermont-Ferrand', '0666666666', 13);
insert into adherent(noA, nomA, prenomA, adresseA, telephoneA, ageA) 
	values(2, 'Salma', 'Louise', '23 rue Jean Moulin Clermont-Ferrand', '0777777777', 26);
insert into adherent(noA, nomA, prenomA, adresseA, ageA) 
	values(3, 'Jardin', 'Lucien', 'Avenue de l''arête, Super-Besse', 13);
-- materiel(codeM, type, marque, prix, quantiteDispo)
insert into materiel(codeM, type, marque, prix, quantiteDispo) VALUES (1, 'Skis', 'GlisseVite', 10, 10);
insert into materiel(codeM, type, marque, prix, quantiteDispo) VALUES (2, 'Surfs', 'GlisseVite', 11, 6);
insert into materiel(codeM, type, marque, prix, quantiteDispo) VALUES (3, 'Patinettes', 'GlisseVite', 10, 4);
insert into materiel(codeM, type, marque, prix, quantiteDispo) VALUES (4, 'Raquettes', 'AccrocheBien', 8, 10);
insert into materiel(codeM, type, marque, prix, quantiteDispo) VALUES (5, 'Chaussures', 'AccrocheBien', 6, 20);
-- cours(codeC, niveau, nbPlaces, dateCours, #idSpecialite, #noM)
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM) 
	values (1, 'débutant', 5, '01-02-2013', 1, 2);
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM) 
	values (2, 'moyen', 5, '02-02-2013', 1, 2);
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM) 
	values (3, 'débutant', 8, '01-02-2013', 1, 2);
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM)	
	values (4, 'moyen', 8, '02-02-2013', 1, 2);
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM) 
	values (5, 'confirmé', 8, '02-02-2013', 1, 2);
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM) 
	values (6, 'débutant', 10, '01-02-2013', 1, 2);
insert into cours(codeC, niveau, nbPlaces, dateCours, idSpecialite, noM) 
	values (7, 'compétition', 2, '01-02-2013', 1, 2);
-- suivre(#codeC, #noA)
insert into suivre(codeC, noA) values (1,1);
insert into suivre(codeC, noA) values (1,2);
insert into suivre(codeC, noA) values (3,1);
insert into suivre(codeC, noA) values (5,3);
-- louer(#noA, #codeM, quantite)
insert into louer(noA, codeM, quantite) values(3,1,1);
insert into louer(noA, codeM, quantite) values(2,1,2);

-- Select
select * from moniteur;
select * from specialite;
select * from cours; 
select * from adherent;
select * from materiel;
select * from suivre;
select * from louer;

-- delete
delete from materiel where type='Raquettes'; 
delete from suivre where codeC = 5 AND noA = 3;
-- Ajout d'un delete on cascade afin de pouvoir supprimer les fils.
-- alter table suivre add constraint fk_suivre_noA FOREIGN KEY (noA) REFERENCES materiel(codeM) on delete cascade;
delete from cours where codeC=5;

--update
update adherent set adresseA = '23 route de Lyon, Clermont-Ferrand' WHERE noA=1;
update materiel set prix = prix+(prix*0.10);
update materiel set quantiteDispo=quantiteDispo+2 WHERE codeM=1;


-- Partie 2
select * from user_tables; --Liste des tables
select * from all_cons_columns  WHERE owner = 'SAUVAGNA'; -- contraintes
