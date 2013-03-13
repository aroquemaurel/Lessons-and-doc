alter table EQUIPE ADD (
	np decimal(3),
	bt decimal(3),
	constraint ck_equipe_bt check(bt >= 0),
	constraint ck_equipe_np check(np >= 0)
);

update equipe e1 set np = (select count(*) from projets WHERE projets.ne=e1.ne),
		      bt = (select sum(pbudget) from projets where projets.ne=e1.ne);
