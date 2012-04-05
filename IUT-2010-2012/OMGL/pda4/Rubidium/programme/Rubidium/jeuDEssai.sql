insert into POLE (Nom_Pole, UE) values ('AP', 1) ;
insert into POLE (Nom_Pole, UE) values ('ASR', 1) ;
insert into POLE (Nom_Pole, UE) values ('EGO', 2) ;
insert into POLE (Nom_Pole, UE) values ('MATHS', 2);


insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('C++',1, 2);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Java', 1, 3);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Assembleur', 2, 2);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Réseau', 2, 2);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Droit', 3, 1);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Economie', 3, 1);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Droit', 3, 2);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Economie', 3, 2);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Droit', 3, 3);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Economie', 3, 3);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Algèbre linéaire', 4, 4);
insert into MATIERE(Nom_M, Id_Pole, Semestre_M) values ('Maths discrètes', 4, 4);


insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Chevalier', 'Max', 'Caillou1', 20, 'False', 'False', 8);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Julien', 'Christine', 'Caillou2', 15, 'False', 'False', 0);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Facca', 'Roland', 'Caillou3', 10, 'False' , 'False' , 2);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Broisin', 'Julien', 'Caillou4', 16, 'False', 'False', 15);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Kross', 'Catherine', 'Caillou5', 6, 'False', 'False', 6);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Paul', 'Emmanuel', 'Caillou6', 12, 'False', 'False', 7);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Benbou', 'Mario', 'Caillou7', 25, 'False', 'False', 0);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Administrateur', 'Banane', 'Caillou8', 0, 'False', 'True',0);
insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Responsable', 'Planning', 'Caillou9', 0, 'True', 'False', 0);


insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (1,1,'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (2,1,'False');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (2,2,'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (3,3, 'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (4,3, 'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (4,4, 'False');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (5,5, 'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (6,5, 'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (7,6, 'True');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (7,7, 'False');
insert into ENSEIGNER (Id_M, Id_P, Responsable_Matiere) values (8,6, 'True');


insert into TYPE_CONTROLE (Nom_TC) values('Examen écrit');
insert into TYPE_CONTROLE (Nom_TC) values('QCM');
insert into TYPE_CONTROLE (Nom_TC) values('Soutenance');


insert into CONTROLE (Date_C, Heure_C, Duree_C, Coefficient_C, Calculatrice_OK, Documents_OK, Id_M, Id_TC)
values ('2012-02-01', '14:00', 240, 2.6, 'False', 'True', 1, 1);
insert into CONTROLE (Date_C, Heure_C, Duree_C, Coefficient_C, Calculatrice_OK, Documents_OK, Id_M, Id_TC)
values ('2011-09-04', '08:30', 30, 1.75 , 'False', 'False', 2, 2);
insert into CONTROLE (Date_C, Heure_C, Duree_C, Coefficient_C, Calculatrice_OK, Documents_OK, Id_M, Id_TC)
values ('2011-11-27', '16:15', 120, 0.975 , 'True', 'True', 3, 3);


insert into SURVEILLER (Id_P, Id_C) values (1,1);
insert into SURVEILLER (Id_P, Id_C) values (2,1);
insert into SURVEILLER (Id_P, Id_C) values (3,1);
insert into SURVEILLER (Id_P, Id_C) values (4,2);
insert into SURVEILLER (Id_P, Id_C) values (2,2);
insert into SURVEILLER (Id_P, Id_C) values (3,3);
insert into SURVEILLER (Id_P, Id_C) values (4,3);
insert into SURVEILLER (Id_P, Id_C) values (5,3);


insert into SE_DEROULER (Id_C, Id_Salle) values (1,1);
insert into SE_DEROULER (Id_C, Id_Salle) values (2,2);
insert into SE_DEROULER (Id_C, Id_Salle) values (3,3);


insert into SALLE (Nom_S, Nombre_Surveillants_S, Capacite_S) values ('Salle d examen', 8, 175);
insert into SALLE (Nom_S, Nombre_Surveillants_S, Capacite_S) values ('Salle 022', 2, 30);
insert into SALLE (Nom_S, Nombre_Surveillants_S, Capacite_S) values ('Exp-com 210', 1, 30);
insert into SALLE (Nom_S, Nombre_Surveillants_S, Capacite_S) values ('Egoûts', 28, 4);
