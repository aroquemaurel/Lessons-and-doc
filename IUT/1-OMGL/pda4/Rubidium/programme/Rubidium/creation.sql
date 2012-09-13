CREATE TABLE PERSONNE
   (
   ID_P INTEGER NOT NULL ,
   NOM_P VARCHAR (128)  ,
   PRENOM_P VARCHAR (128)  ,
   MDP_P VARCHAR (128)  ,
   QUOTA_P INTEGER  ,
   RESPONSABLE_PLANNING_P SMALLINT  ,
   ADMINISTRATEUR_P SMALLINT  ,
   HEURES_EFFECTUEES_P INTEGER  ,
     PRIMARY KEY (ID_P) CONSTRAINT PK_PERSONNE
   );

CREATE TABLE CONTROLE
   (
   ID_C INTEGER NOT NULL ,
   ID_TC INTEGER NOT NULL ,
   ID_M INTEGER NOT NULL ,
   DATE_C DATE  ,
   HEURE_C TIME   ,
   DUREE_C TIME  ,
   COEFFICIENT_C DOUBLE PRECISION  ,
   CALCULATRICE_OK SMALLINT  ,
   DOCUMENTS_OK SMALLINT  ,
     PRIMARY KEY (ID_C) CONSTRAINT PK_CONTROLE,
     FOREIGN KEY (ID_TC) REFERENCES TYPE_CONTROLE (ID_TC),
     FOREIGN KEY (ID_M) REFERENCES MATIERE (ID_M)
   );

CREATE  INDEX I_FK_CONTROLE_TYPE_CONTROLE
     ON CONTROLE (ID_TC ASC);

CREATE  INDEX I_FK_CONTROLE_MATIERE
     ON CONTROLE (ID_M ASC);

CREATE TABLE TYPE_CONTROLE
   (
   ID_TC INTEGER NOT NULL ,
   NOM_TC VARCHAR (128)  ,
     PRIMARY KEY (ID_TC) CONSTRAINT PK_TYPE_CONTROLE
   );

CREATE TABLE MATIERE
   (
   ID_M INTEGER NOT NULL ,
   ID_POLE INTEGER NOT NULL ,
   SEMESTRE_M INTEGER NOT NULL ,
   NOM_M VARCHAR (128)  ,
     PRIMARY KEY (ID_M) CONSTRAINT PK_MATIERE,
     FOREIGN KEY (ID_POLE) REFERENCES POLE (ID_POLE)
   );

CREATE  INDEX I_FK_MATIERE_POLE
     ON MATIERE (ID_POLE ASC);

CREATE TABLE SALLE
   (
   ID_SALLE INTEGER NOT NULL ,
   NOM_S VARCHAR (128)  ,
   NOMBRE_SURVEILLANTS_S INTEGER  ,
   CAPACITE_S INTEGER  ,
     PRIMARY KEY (ID_SALLE) CONSTRAINT PK_SALLE
   );

CREATE TABLE POLE
   (
   ID_POLE INTEGER NOT NULL ,
   NOM_POLE VARCHAR (128)  ,
   UE VARCHAR (128)  ,
     PRIMARY KEY (ID_POLE) CONSTRAINT PK_POLE
   );

CREATE TABLE SURVEILLER
   (
   ID_C INTEGER NOT NULL ,
   ID_P INTEGER NOT NULL ,
     PRIMARY KEY (ID_C, ID_P) CONSTRAINT PK_SURVEILLER,
FOREIGN KEY (ID_C) REFERENCES CONTROLE (ID_C),
      FOREIGN KEY (ID_P) REFERENCES PERSONNE (ID_P)
   );

CREATE  INDEX I_FK_SURVEILLER_CONTROLE
     ON SURVEILLER (ID_C ASC);

CREATE  INDEX I_FK_SURVEILLER_PERSONNE
     ON SURVEILLER (ID_P ASC);

CREATE TABLE SE_DEROULER
   (
   ID_C INTEGER NOT NULL ,
   ID_SALLE INTEGER NOT NULL ,
   FOREIGN KEY (ID_C) REFERENCES CONTROLE (ID_C),
     PRIMARY KEY (ID_C, ID_SALLE) CONSTRAINT PK_SE_DEROULER,
     FOREIGN KEY (ID_SALLE) REFERENCES SALLE (ID_SALLE)
   );

CREATE  INDEX I_FK_SE_DEROULER_CONTROLE
     ON SE_DEROULER (ID_C ASC);

CREATE  INDEX I_FK_SE_DEROULER_SALLE
     ON SE_DEROULER (ID_SALLE ASC);

CREATE TABLE ENSEIGNER
   (
   ID_M INTEGER NOT NULL ,
   ID_P INTEGER NOT NULL ,
   RESPONSABLE_MATIERE SMALLINT  ,
     PRIMARY KEY (ID_M, ID_P) CONSTRAINT PK_ENSEIGNER,
     FOREIGN KEY (ID_M) REFERENCES MATIERE (ID_M),
     FOREIGN KEY (ID_P) REFERENCES PERSONNE (ID_P)
   );

CREATE  INDEX I_FK_ENSEIGNER_MATIERE
     ON ENSEIGNER (ID_M ASC);

CREATE  INDEX I_FK_ENSEIGNER_PERSONNE
     ON ENSEIGNER (ID_P ASC);

insert into PERSONNE (Nom_P, Prenom_P, MDP_P, Quota_P, Responsable_Planning_P, Administrateur_P, Heures_Effectuees_P) values ('Root', 'Debug', 'Toor', 0, 'True', 'True', 0);