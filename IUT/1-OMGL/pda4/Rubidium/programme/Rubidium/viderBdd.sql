delete from POLE ;

delete from MATIERE ;

delete from PERSONNE ;

delete from ENSEIGNER ;

delete from TYPE_CONTROLE ;

delete from CONTROLE ;

delete from SURVEILLER ;

delete from SE_DEROULER ;

delete from SALLE ;

insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Root', 'Debug', 'Toor', 0, 'True', 'True', 0);
