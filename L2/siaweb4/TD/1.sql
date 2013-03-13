create table PROJET(
	NP varchar(4),
	nomP varchar(32),
	ne varchar(4),
	pbudget decimal(16),
	constraint pk_projet PRIMARY KEY(np),
	constraint fk_projet_ne FOREIGN KEY(ne) REFERENCES equipe(ne),
	constraint ck_projet_pbudget CHECK(ne >= 0)
);
