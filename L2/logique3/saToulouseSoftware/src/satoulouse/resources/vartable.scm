;ce code est fait pour être utilisé avec Kawa (lancé à partir de java)
(import (rnrs hashtables))
;bug = j'arrive pas à faire une table de hashage qui tient compte que "p" et "p" c'est le même objet !!!

(define nombre 0)

(define (table-add table var number)
  (begin
    (if (not (hashtable-contains? (car table) var))
		(begin
			(hashtable-set! (car table) var number)
			(hashtable-set! (cadr table) number var)))
			table))


;ajoute la variable v dans la table t (l'entier correspondant est généré)
(define (table-add-generated-int table var)
  (begin (set! nombre (+ nombre 1))
          (table-add table var nombre)
		    (table-getvar? table nombre) ;teste si ok
			(table-getint? table var)    ;teste si ok
			 table))


;(table-getint? (getvartable '(p and (q or p))) 'p)
(define (table-getint? table var)
(let ((r (hashtable-ref (car table) var #f)))
	(if r
		r
		(display `("problème dans table-getint?" ,var )))))



;(table-getvar? (getvartable '(p and (q or p))) 2)
(define (table-getvar? table number)
(let ((r (hashtable-ref (cadr table) number #f)))
	(if r
		r
		(display `("problème dans table-getvar?" ,number)))))


(define (table-create) `(,(make-hashtable equal? equal-hash ) ,(make-eq-hashtable )))



(define (tabletosexpr table)
	`("table = " ,(hashtable-entries (car table) ) " -- " ,(hashtable-entries (cadr table) )))
	
	
	
	
      