REM -----------------------------------------------------------------------------
REM                Génération d'une base de données
REM                         SQL Générique (SQL 2)
REM                           (10/2/2012 14:48:46)
REM -----------------------------------------------------------------------------
REM      Nom de la base : Copie de Copie de MLR Scrum
REM      Projet : 
REM      Auteur : banane2
REM      Date de dernière modification : 10/2/2012 14:47:57
REM -----------------------------------------------------------------------------

DROP TABLE PERSONNE;

DROP TABLE CONTROLE;

DROP TABLE TYPE_CONTROLE;

DROP TABLE MATIERE;

DROP TABLE SALLE;

DROP TABLE POLE;

DROP TABLE SURVEILLER;

DROP TABLE SE_DEROULER;

DROP TABLE ENSEIGNER;

REM -----------------------------------------------------------------------------
REM       TABLE : PERSONNE
REM -----------------------------------------------------------------------------

CREATE TABLE PERSONNE
   (
   ID_P INTEGER NOT NULL ,
   NOM_P VARCHAR (128)  ,
   PRENOM_P VARCHAR (128)  ,
   MDP_P VARCHAR (128)  ,
   QUOTA_P INTEGER  ,
   RESPONSABLE_PLANNING_P SMALLINT  ,
   ADMINISTRATEUR_P SMALLINT  ,
   HEURES_EFFECTUEES_P INTEGER  
,
     PRIMARY KEY (ID_P) CONSTRAINT PK_PERSONNE
   );

REM -----------------------------------------------------------------------------
REM       TABLE : CONTROLE
REM -----------------------------------------------------------------------------

CREATE TABLE CONTROLE
   (
   ID_C INTEGER NOT NULL ,
   ID_TC INTEGER NOT NULL ,
   ID_M INTEGER NOT NULL ,
   DATE_C TIMESTAMP  ,
   DUREE_C TIME  ,
   COEFFICIENT_C DOUBLE PRECISION  ,
   CALCULATRICE_OK SMALLINT  ,
   DOCUMENTS_OK SMALLINT  
,
     PRIMARY KEY (ID_C) CONSTRAINT PK_CONTROLE
   );

REM -----------------------------------------------------------------------------
REM       INDEX DE LA TABLE CONTROLE
REM -----------------------------------------------------------------------------

CREATE  INDEX I_FK_CONTROLE_TYPE_CONTROLE
     ON CONTROLE (ID_TC ASC);

CREATE  INDEX I_FK_CONTROLE_MATIERE
     ON CONTROLE (ID_M ASC);

REM -----------------------------------------------------------------------------
REM       TABLE : TYPE_CONTROLE
REM -----------------------------------------------------------------------------

CREATE TABLE TYPE_CONTROLE
   (
   ID_TC INTEGER NOT NULL ,
   NOM_TC VARCHAR (128)  
,
     PRIMARY KEY (ID_TC) CONSTRAINT PK_TYPE_CONTROLE
   );

REM -----------------------------------------------------------------------------
REM       TABLE : MATIERE
REM -----------------------------------------------------------------------------

CREATE TABLE MATIERE
   (
   ID_M INTEGER NOT NULL ,
   ID_POLE INTEGER NOT NULL ,
   NOM_M VARCHAR (128)  
,
     PRIMARY KEY (ID_M) CONSTRAINT PK_MATIERE
   );

REM -----------------------------------------------------------------------------
REM       INDEX DE LA TABLE MATIERE
REM -----------------------------------------------------------------------------

CREATE  INDEX I_FK_MATIERE_POLE
     ON MATIERE (ID_POLE ASC);

REM -----------------------------------------------------------------------------
REM       TABLE : SALLE
REM -----------------------------------------------------------------------------

CREATE TABLE SALLE
   (
   ID_SALLE INTEGER NOT NULL ,
   NOM_S VARCHAR (128)  ,
   NOMBRE_SURVEILLANTS_S INTEGER  ,
   CAPACITE_S INTEGER  
,
     PRIMARY KEY (ID_SALLE) CONSTRAINT PK_SALLE
   );

REM -----------------------------------------------------------------------------
REM       TABLE : POLE
REM -----------------------------------------------------------------------------

CREATE TABLE POLE
   (
   ID_POLE INTEGER NOT NULL ,
   NOM_POLE VARCHAR (128)  ,
   UE VARCHAR (128)  
,
     PRIMARY KEY (ID_POLE) CONSTRAINT PK_POLE
   );

REM -----------------------------------------------------------------------------
REM       TABLE : SURVEILLER
REM -----------------------------------------------------------------------------

CREATE TABLE SURVEILLER
   (
   ID_C INTEGER NOT NULL ,
   ID_P INTEGER NOT NULL 
,
     PRIMARY KEY (ID_C, ID_P) CONSTRAINT PK_SURVEILLER
   );

REM -----------------------------------------------------------------------------
REM       INDEX DE LA TABLE SURVEILLER
REM -----------------------------------------------------------------------------

CREATE  INDEX I_FK_SURVEILLER_CONTROLE
     ON SURVEILLER (ID_C ASC);

CREATE  INDEX I_FK_SURVEILLER_PERSONNE
     ON SURVEILLER (ID_P ASC);

REM -----------------------------------------------------------------------------
REM       TABLE : SE_DEROULER
REM -----------------------------------------------------------------------------

CREATE TABLE SE_DEROULER
   (
   ID_C INTEGER NOT NULL ,
   ID_SALLE INTEGER NOT NULL 
,
     PRIMARY KEY (ID_C, ID_SALLE) CONSTRAINT PK_SE_DEROULER
   );

REM -----------------------------------------------------------------------------
REM       INDEX DE LA TABLE SE_DEROULER
REM -----------------------------------------------------------------------------

CREATE  INDEX I_FK_SE_DEROULER_CONTROLE
     ON SE_DEROULER (ID_C ASC);

CREATE  INDEX I_FK_SE_DEROULER_SALLE
     ON SE_DEROULER (ID_SALLE ASC);

REM -----------------------------------------------------------------------------
REM       TABLE : ENSEIGNER
REM -----------------------------------------------------------------------------

CREATE TABLE ENSEIGNER
   (
   ID_M INTEGER NOT NULL ,
   ID_P INTEGER NOT NULL ,
   RESPONSABLE_MATIERE SMALLINT  
,
     PRIMARY KEY (ID_M, ID_P) CONSTRAINT PK_ENSEIGNER
   );

REM -----------------------------------------------------------------------------
REM       INDEX DE LA TABLE ENSEIGNER
REM -----------------------------------------------------------------------------

CREATE  INDEX I_FK_ENSEIGNER_MATIERE
     ON ENSEIGNER (ID_M ASC);

CREATE  INDEX I_FK_ENSEIGNER_PERSONNE
     ON ENSEIGNER (ID_P ASC);


REM -----------------------------------------------------------------------------
REM       CREATION DES REFERENCES DE TABLE
REM -----------------------------------------------------------------------------

ALTER TABLE CONTROLE ADD (FOREIGN KEY (ID_TC)
      REFERENCES TYPE_CONTROLE (ID_TC)
      CONSTRAINT FK_CONTROLE_TYPE_CONTROLE );

ALTER TABLE CONTROLE ADD (FOREIGN KEY (ID_M)
      REFERENCES MATIERE (ID_M)
      CONSTRAINT FK_CONTROLE_MATIERE );

ALTER TABLE MATIERE ADD (FOREIGN KEY (ID_POLE)
      REFERENCES POLE (ID_POLE)
      CONSTRAINT FK_MATIERE_POLE );

ALTER TABLE SURVEILLER ADD (FOREIGN KEY (ID_C)
      REFERENCES CONTROLE (ID_C)
      CONSTRAINT FK_SURVEILLER_CONTROLE );

ALTER TABLE SURVEILLER ADD (FOREIGN KEY (ID_P)
      REFERENCES PERSONNE (ID_P)
      CONSTRAINT FK_SURVEILLER_PERSONNE );

ALTER TABLE SE_DEROULER ADD (FOREIGN KEY (ID_C)
      REFERENCES CONTROLE (ID_C)
      CONSTRAINT FK_SE_DEROULER_CONTROLE );

ALTER TABLE SE_DEROULER ADD (FOREIGN KEY (ID_SALLE)
      REFERENCES SALLE (ID_SALLE)
      CONSTRAINT FK_SE_DEROULER_SALLE );

ALTER TABLE ENSEIGNER ADD (FOREIGN KEY (ID_M)
      REFERENCES MATIERE (ID_M)
      CONSTRAINT FK_ENSEIGNER_MATIERE );

ALTER TABLE ENSEIGNER ADD (FOREIGN KEY (ID_P)
      REFERENCES PERSONNE (ID_P)
      CONSTRAINT FK_ENSEIGNER_PERSONNE );


REM -----------------------------------------------------------------------------
REM                FIN DE GENERATION
REM -----------------------------------------------------------------------------