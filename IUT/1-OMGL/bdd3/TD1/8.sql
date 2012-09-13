ALTER TABLE propP --precedemment number(2) xx
MODIFY prixP number(4,2)
ADD CONSTRAINT chk_proP_spec CHECK (spec != 'O' OR 
									prixP between 10 AND 20 OR
									prepa > 60) ;
