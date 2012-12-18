;USAGE :
;(formulatocnf phi)
;(getvartable cnf)
;(calculervartable () cnf)
;(cnftocnfforsat4j t cnf)
;cnftemp
;tabletemp


(load "vartablewithlists.scm")

;variable qui contient la formule à tester
(define phi ())

;variable qui servira à stocker la table des variables
(define tabletemp ())

;variable qui servira à stocker la cnf
(define cnftemp ())







 
  
;calcule la table des variables (var entier) de la cnf
;(calculervartable () '((p) (p q (not r))))
(define (calculervartable table cnf)
  (if (null? cnf)
      table
      (calculervartable (calculervartableclause table (car cnf)) (cdr cnf))))


;calcule la table des variables (var entier) juste d'une clause
;(calculervartableclause () '(p q (not r)))
(define (calculervartableclause table clause)
  (if (null? clause)
      table
      (match (car clause)
        (('not p)  (calculervartableclause (table-add-generated-int table p) (cdr clause)))
        (p (calculervartableclause (table-add-generated-int table p) (cdr clause))))))







;fonction qui prend en entrée une cnf et fournit la table des variables présentes dans la cnf
(define (getvartable cnf)
  (calculervartable (table-create) cnf))
 



(define (clausetoclauseforsat4j table clause)
  (let ((f (lambda (litteral) 
            (match litteral
              (('not p) (- (table-getint? table p)))
              (p (table-getint? table p))))))
    (map f clause)))
                               
  
 ;(cnftocnfforsat4j '((p 1) (q 2)) '((p q) (p)))
(define (cnftocnfforsat4j table cnf)
  (let ((f (lambda (clause) (clausetoclauseforsat4j table clause))))
    (map f cnf)))




(define temppropnumber 0)
(define (newtempprop) (begin (set! temppropnumber (+ temppropnumber 1)) `(temp ,temppropnumber)) 	 )
	 
;renvoie un couple "(proposition pphi qui représente phi, grande cnf qui équisatisfiable à "pphi <-> phi")"
;(cnfsub 'p)
;(cnfsub '(p and q))
  (define (cnfsub phi)
    (match phi
      ((psi1 'and psi2)
       (let* ((r1 (cnfsub psi1))
             (r2 (cnfsub psi2))
             (pphi (newtempprop))
             (ppsi1 (car r1))
             (ppsi2 (car r2)))
         `(,pphi  ,(append `( ((not ,pphi) ,ppsi1)
                              ((not ,pphi) ,ppsi2)
                              ((not ,ppsi1) (not ,ppsi2) ,pphi) )
                            (append (cadr r1) (cadr r2)      )) )))
      ((psi1 'or psi2)
       (let* ((r1 (cnfsub psi1))
             (r2 (cnfsub psi2))
             (pphi (newtempprop))
             (ppsi1 (car r1))
             (ppsi2 (car r2)))
         `(,pphi  ,(append `( ((not ,ppsi1) ,pphi)
                              ((not ,ppsi2) ,pphi)
                              ((not ,pphi) ,ppsi1 ,ppsi2) )
                           (append (cadr r1) (cadr r2) )     )) ))
      
      (('not psi1)
       (let* ((r1 (cnfsub psi1))
             (pphi (newtempprop))
             (ppsi1 (car r1)))
         `(,pphi  ,(append `( (,ppsi1 ,pphi)
                              ( (not ,pphi) (not ,ppsi1)) )
                               (cadr r1)     )) ))

      (p   `(,p ()))))
  
  
  ;(formulaclause? '(a or b))
  ;(formulaclause? '(a or (not b)))
  (define (formulaclause? phi)
    (match phi
      ((psi1 'and psi2) #f)
      ((psi1 'or psi2) (and (formulaclause? psi1) (formulaclause? psi2)))
      (('not psi)
       (match psi
         ((psi1 'and psi2) #f)
         ((psi1 'or psi2) #f)
         (('not a) #f)
         (a #t)))
      (a #t)))
                        
  
  ;(formulatoclause '(a or (not b)))
  (define (formulatoclause phi)
    (match phi
      ((psi1 'or psi2) (append (formulatoclause psi1) (formulatoclause psi2)))
      (('not p) `(,phi))
      (p `(,phi))))
  
  ;(formulatocnf 'p)
  ;(formulatocnf '(p and q))
  ;(formulatocnf '(p and (not p)))
  (define (formulatocnf phi)
    (match phi
       ((psi1 'and psi2) (append (formulatocnf psi1) (formulatocnf psi2)))
      (phi
       (if (formulaclause? phi)
           `( ,(formulatoclause phi) )
           (let* ((r (cnfsub phi))
                  (prop (car r))
                  (cnfrule (cadr r)))
             (cons `(,prop) cnfrule))))))
    
		    
