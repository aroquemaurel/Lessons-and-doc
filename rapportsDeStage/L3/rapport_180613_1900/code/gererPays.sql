drop table inforsid_base_pays;

create table inforsid_base_pays (
	idV			number(5)	constraint	pk_basePays	primary key,
	ville		varchar(100)	constraint	nn_ville_basePays	not null,
	pays		varchar(100)	constraint	nn_pays_basePays	not null
);


create or replace view inforsid_villesSansPays as (
	select nomVille, nomPays
	from inforsid_ville v
	where not exists (
		select ville
		from inforsid_base_pays
		where lower(ville) = lower(v.nomVille)
	)
);


-- Spécifier «update du pays» ?
-- "A column list was specified for a non-update trigger type."
create or replace trigger ajoutVilleBase
		instead of update on inforsid_villesSansPays
		for each row
declare
	v_idNewV	inforsid_base_pays.idV%type;
begin
	select max(idV)+1 into v_idNewV
	from inforsid_base_pays;
	insert into inforsid_base_pays(idV, ville, pays)
		values (v_idNewV, :new.nomVille, :new.nomPays);
end ajoutVilleBase;
/


create or replace procedure gererPays is
	v_pays inforsid_base_pays.pays%type;
begin
	for v in (select idV, nomVille, nomPays from inforsid_ville) loop
		select pays into v_pays
			from inforsid_base_pays
			where lower(ville) = lower(v.nomVille);
		if v.nomPays <> v_pays then
			update inforsid_ville
				set nomPays = v_pays
				where idV = v.idV;
		end if;
	end loop;
	commit;
exception
	when no_data_found then
		dbms_output.put_line('/!\ Une ville n''est pas dans base_pays.');
	when others then
		dbms_output.put_line(sqlcode||' : '||sqlerrm);
end;
/

