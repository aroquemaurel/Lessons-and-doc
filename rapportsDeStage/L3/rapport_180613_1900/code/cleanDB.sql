drop table inforsid_syVilles;
drop table inforsid_syPersonnes;

-- villes
create table inforsid_syVilles as
	select v1.idV as id1, v1.nomville as nom1, v2.idV as id2, v2.nomville as nom2
	from inforsid_ville v1, inforsid_ville v2
	where soundex(v1.nomville) = soundex(v2.nomville)
	and v1.nomville > v2.nomville
	order by 2, 4 ;

-- personnes
create table inforsid_syPersonnes as
	select p1.idP as id1, p1.nom as nom1, p1.prenom as prenom1, p2.idP as id2, p2.nom as nom2, p2.prenom as prenom2
	from inforsid_personne p1, inforsid_personne p2
	where (((	regexp_substr(p2.nom, '\w+', 1, 2) is not null
				and (p2.nom like p1.nom||'-%' or p2.nom like '%-'||p1.nom))
			or (regexp_substr(p1.nom, '\w+', 1, 2) is not null
				and (p1.nom like '%-'||p2.nom or p1.nom like p2.nom||'-%')))
		and p1.prenom = p2.prenom
		and p1.nom > p2.nom)
	or (soundex(p1.nom) = soundex(p2.nom)
		and (soundex(p1.prenom) = soundex(p2.prenom)
			or (length(p1.prenom) <= 4 and substr(p1.prenom, length(p1.prenom), 1) = '.')
			or (length(p2.prenom) <= 4 and substr(p2.prenom, length(p2.prenom), 1) = '.'))
		and (p1.nom > p2.nom
			or (p1.nom = p2.nom
				and p1.prenom > p2.prenom)))
	order by 2, 3, 5, 6 ;

create or replace procedure gererSy is
begin
	--traitement des villes
	for coupleV in (select id1, nom1, id2 from inforsid_syVilles) loop
		update inforsid_congres
			set idV = coupleV.id1
			where idV = coupleV.id2;
		update inforsid_ecrire
			set idV = coupleV.id1
			where idV = coupleV.id2;
		update inforsid_membre
			set idV = coupleV.id1
			where idV = coupleV.id2;
		delete from inforsid_ville
			where idV = coupleV.id2;
		update inforsid_ville
			set nomVille = coupleV.nom1
			where idV = coupleV.id1;
	end loop;
	--traitement des personnes
	for coupleP in (select id1, nom1, prenom1, id2 from inforsid_syPersonnes) loop
		update inforsid_ecrire
			set idP = coupleP.id1
			where idP = coupleP.id2;
		update inforsid_membre
			set idP = coupleP.id1
			where idP = coupleP.id2;
		delete from inforsid_personne
			where idP = coupleP.id2;
		update inforsid_personne
			set nom = coupleP.nom1, prenom = coupleP.prenom1
			where idP = coupleP.id1;
	end loop;
	commit;
end gererSy;
/
