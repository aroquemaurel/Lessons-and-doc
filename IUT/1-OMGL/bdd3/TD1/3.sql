ALTER TABLE propP
add (
	CONSTRAINT chk_propP_spec CHECK(spec in ('O', 'N')),
	CONSTRAINT chk_propP_prixP CHECK(prixP <= 50)
	);

ALTER TABLE propP ADD CONSTRAINT chk_propP_prepa CHECK(spec = 'O' OR prepa <= 60);

ALTER TABLE resto ADD CONSTRAINT chk_resto_ouv CHECK(MONTHS_BETWEEN(dateOuv, dateFerm >= 6));

ALTER TABLE propP MODIFY spec DEFAULT 'N'; 
