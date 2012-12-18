; (iscplsat? '(q and (not q)))
;(iscplsat? '(not (p and q)))
;(iscplsat? '((p 1) and ((not (p 1)) or (p 2))))
(define (iscplsat? phi)
    (let ((result (tableau () `(,(putnegationinside phi)))))
      (if result
          ;(filter isproposition? result )
          result
          #f)))


(define (isproposition? phi)
  (match phi
    (('not a) #f)
    ('top #f)
    (a #t)))
    

  
  ;(putnegationinside  '(q and ((not p) or (not q))))
(define (putnegationinside phi)
  (match phi
    (('not psi) 
     (match psi
       ((psi1 'and psi2) `(,(putnegationinside `(not ,psi1)) or ,(putnegationinside `(not ,psi2))))
       ((psi1 'or psi2) `(,(putnegationinside `(not ,psi1)) and ,(putnegationinside `(not ,psi2))))
       (('not chi) (putnegationinside chi))
       (a phi) ) )
    (a  (if (list? phi)  (map putnegationinside phi)   phi))
    ))
  
      
  


(define (replace a b l)
  (if (equal? a l)
      b
      (if (list? l)
          (if (null? l)
              ()
              (cons (replace a b (car l)) (replace a b (cdr l))))
          l)))





(define (nottreatedadd phi l)
  (match phi
    ((psi1 'or psi2) (append (simplify phi l) (cons phi ())))
    (a (cons a (simplify phi l)))))



(define (simplify phi l)
  (match phi
    (('not psi) (simplify-or (replace psi 'bottom l)))
    (chi (simplify-or (replace phi 'top (replace `(not ,phi) 'bottom l))))))




(define (simplify-or phi)
  (match phi
    ((psi1 'or psi2)
          (if (equal? psi1 'bottom) 
              (simplify-or psi2)
              (if (equal? psi2 'bottom)
                  (simplify-or psi1)
                  `(,(simplify-or psi1) or ,(simplify-or psi2)))))
    (a (if (list? a)
           (map simplify-or phi)
           a))))
  

(define (contains? e l)
  (if (null? l)
      #f
      (if (equal? e (car l))
          #t
          (contains? e (cdr l)))))


(define (addifneeded e l)
  (if (contains? e l)
      l
      (cons e l)))

(define (test-nocontradiction psi treated nottreated)
  (if (contradition? psi treated nottreated)
      (nondeterminism)))


(define (contradiction? psi treated nottreated)
  (match psi
    (('not 'top) #t)
    ('bottom #t)
    (('not chi) (or (contains? chi treated) (contains? chi nottreated)))
     (chi (or (contains? `(not ,chi) treated) (contains? `(not ,chi) nottreated)))))  
    


(define (formula-length phi)
  (if (list? phi)
      (if (null? phi)
          0
          (+ 1 (formula-length (cdr phi))))
      1))



(define (tableau treated nottreated)
  (begin
   ; (print treated)
   ;(print nottreated)
   ; (print " * ")
  (if (null?  nottreated)
      treated
      (let ((phi (car nottreated)))
        (if (contradiction? phi treated nottreated)
            #f
        (match phi
          ((psi 'and chi) 
           (if (or (contradiction? psi treated (cons chi (cdr nottreated)))
                   (contradiction? chi treated (cons psi (cdr nottreated))))
               #f
               (if (> (formula-length chi) (formula-length psi))
                   (tableau treated (nottreatedadd psi (nottreatedadd chi (cdr nottreated))))
                   (tableau treated (nottreatedadd chi (nottreatedadd psi (cdr nottreated)))))))
          
          ((psi 'or chi)     
           
           (if (> (formula-length chi) (formula-length psi))
               (if (contradiction? psi treated nottreated)
                   (if (contradiction? chi treated nottreated)
                             #f
                             (tableau treated (nottreatedadd chi (cdr nottreated))))
                   (let ((resultat (tableau treated (nottreatedadd psi (cdr nottreated)))))
                     (if resultat
                         resultat
                         (if (contradiction? chi treated nottreated)
                             #f
                             (tableau treated (nottreatedadd chi (cdr nottreated)))))))
               (if (contradiction? chi treated nottreated)
                   (if (contradiction? psi treated nottreated)
                             #f
                             (tableau treated (nottreatedadd psi (cdr nottreated))))
                   (let ((resultat (tableau treated (nottreatedadd chi (cdr nottreated)))))
                     (if resultat
                         resultat
                         (if (contradiction? psi treated nottreated)
                             #f
                             (tableau treated (nottreatedadd psi (cdr nottreated)))))))))
          
           (a (if (contradiction? a treated nottreated)
                  #f
                  (tableau (addifneeded a treated) (cdr nottreated))))
          
        ))))))



(define (filter test list)
  (if (null? list)
       ()
      (if (test (car list))
          (cons (car list) (filter test (cdr list)))
          (filter test (cdr list)))))

