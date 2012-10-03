(define nombre 0)

      
(define (calculervartable t phi)
 (match phi 
    ((psi1 'and psi2) 
     (calculervartable (calculervartable t psi1) psi2))
   ((psi1 'or psi2) 
     (calculervartable (calculervartable t psi1) psi2))
   (('not psi) 
      (calculervartable t psi))
   (a (begin 
        (set! nombre (+ nombre 1))
        (table-add t a nombre)))))
             


;(getvartable '(p and (q or p)))
(define (getvartable phi)
  (calculervartable (table-create)  phi))
 


;(tocnfforsat4j '(p and (q or p)))
(define (tocnfforsat4j phi)
  (cnftocnfforsat4j (getvartable phi) phi))


(define (cnftocnfforsat4j t phi)
  (match phi 
    ((psi1 'and psi2) 
     (append (cnftocnfforsat4j t psi1) (cnftocnfforsat4j t psi2)))
     (a `(,(rectoclauseforsat4j t a)))))


(define (formulatocnf phi) phi)

(define (rectoclauseforsat4j t phi)
  (match phi 
  ((psi1 'and psi2) 
   (raise "error: I have a 'and' and I need a clause"))
   ((psi1 'or psi2) 
     (append (rectoclauseforsat4j t psi1) (rectoclauseforsat4j t psi2)))
   (('not psi) 
      `(,(- (table-getint? t psi))))
   (psi `(,(table-getint? t psi)))))
  
