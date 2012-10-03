;ce code est fait pour être utilisé avec Kawa (lancé à partir de java)
(import (srfi :69 basic-hash-tables))
;bug = j'arrive pas à faire une table de hashage qui tient compte que "p" et "p" c'est le même objet !!!

(define nombre 0)

(define (table-add table var number)
  (begin
    (if (not (hash-table-exists? (car table) var))
		(begin
			(hash-table-set! (car table) var number)
			(hash-table-set! (cadr table) number var)))
			table))


;ajoute la variable v dans la table t (l'entier correspondant est généré)
(define (table-add-generated-int table var)
  (begin (set! nombre (+ nombre 1))
		(display `("on ajoute " ,var ,nombre))
          (table-add table var nombre)
		    (table-getvar? table nombre) ;teste si ok
			(table-getint? table var)    ;teste si ok
			 table))


;(table-getint? (getvartable '(p and (q or p))) 'p)
(define (table-getint? table var)
(let ((r (hash-table-ref (car table) var #f)))
	(if r
		r
		(display `("problème dans table-getint?" ,var )))))



;(table-getvar? (getvartable '(p and (q or p))) 2)
(define (table-getvar? table number)
(let ((r (hash-table-ref (cadr table) number #f)))
	(if r
		r
		(display `("problème dans table-getvar?" ,number)))))


(define (table-create) `(,(make-hash-table) ,(make-hash-table)))



(define (tabletosexpr table)
	`("table = " ,(hash-table->alist (car table) ) " -- " ,(hash-table->alist (cadr table) )))
	
	
	
	
      