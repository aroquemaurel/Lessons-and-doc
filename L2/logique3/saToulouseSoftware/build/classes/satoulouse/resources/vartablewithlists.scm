(define nombre 0)


;vérifie si la table contient la variable v
(define (table-contains? t v)
  (if (null? t)
      #f
      (if (equal? (car (car t)) v)
          #t
          (table-contains? (cdr t) v))))


(define (table-add t v n)
  (if (table-contains? t v)
      t
      (cons `(,v ,n) t)))


;(define (table-add t v n) (hashtable-set! 

;ajoute la variable v dans la table t (l'entier correspondant est généré)
(define (table-add-generated-int t v)
  (begin (set! nombre (+ nombre 1))
         (table-add t v nombre)))


;(table-getint? (getvartable '(p and (q or p))) 'p)
(define (table-getint? t v)
  (if (null? t)
      (raise "no found in table")
      (if (equal? (car (car t)) v)
          (cadr (car t))
          (table-getint? (cdr t) v))))



;(table-getvar? (getvartable '(p and (q or p))) 2)
(define (table-getvar? t i)
  (if (null? t)
      (raise "no found in table")
      (if (equal? (cadr (car t)) i)
          (car (car t))
          (table-getvar? (cdr t) i))))


(define (table-create) (begin (set! nombre 0) ()))