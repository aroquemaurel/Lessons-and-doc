;(condition-tester '(diff 1 2))
(define (condition-tester c)
  (match c
    ((a 'diff b)
         (diff a b))
    (a 12)))


(define (singleton? e)
  (if (null? e)
      #f
      (null? (cdr e))))



(define (suiterec a b l)
  (if (> a b)
      l
      (suiterec a (- b 1) (cons b l))))

;(suite 0 9)
(define (suite a b)
  (suiterec a b ()))
  

;(calculer '(bigand i (1 .. 9) (p i)))
;(calculer '(bigand i (1 .. 9) (p (1 + 2))))
(define (calculer phi)
  (match phi 
    ((a '.. b) (suite a b))
	((i '+ j)
		(if (and (number? i) (number? j))
			(+ i j)
			(map calculer phi)))
	((i '- j)
		(if (and (number? i) (number? j))
			(- i j)
			(map calculer phi)))
	((i '* j)
		(if (and (number? i) (number? j))
			(* i j)
			(map calculer phi)))
	((i '/ j)
		(if (and (number? i) (number? j))
			(/ i j)
			(map calculer phi)))
    (a
     (if (list? a) (map calculer phi)
         a))))
  




(define (formula-or-multi? l)
  (match l
    ((a 'or . L) #t)
    (b #f)
    ))

(define (formula-and-multi? l)
  (match l
    ((a 'and . L) #t)
    (b #f)
    ))
          
;(andByTwo '(a and b and c))
;(andByTwo '((r i) and (not (a i)) and (not (b i)) ))
(define (andByTwo l)
  (if (null? (cdr l))
      (car l)
      (if (not (equal? (cadr l) 'and))
          (error `("il faut un and dans " ,l))
          `(,(car l) and ,(andByTwo (cddr l))))))


;(orByTwo '(a and b and c))
(define (orByTwo L)
  (if (null? (cdr L))
      (car L)
      (if (not (equal? (cadr L) 'or))
          (error "il faut un or")
          `(,(car L) or ,(orByTwo (cddr L))))))


		  
(define (make-bigxor-rec i s bigset psi)
	(if (singleton? s)
		`( ,(remplacer i (car s) psi) and (bigand ,i ,bigset (,i diff ,(car s)) (not ,psi)))
		`(( ,(remplacer i (car s) psi) and (bigand ,i ,bigset (,i diff ,(car s)) (not ,psi))) or ,(make-bigxor-rec i (cdr s) bigset psi))))



;(make-bigxor 'i '(1 2 3) '(p i))
(define (make-bigxor i s psi)
	(if (null? s)
		'bottom
		(if (singleton? s)
			(remplacer i (car s) psi)
			(make-bigxor-rec i s s psi))))

;(formula-expand phi ... à optimiser
;(formula-expand '(bigxor i (1 2 3) (p i)))
;(formula-expand '(p xor q))
(define (formula-expand phi)
  (match (calculer phi)
    (('bigand i s condition psi)
     (if (null? s)
         'top
         (if (condition-tester (remplacer i (car s) condition))
             (if (singleton? s)
                 (formula-expand (remplacer i (car s) psi))
                 `(,(formula-expand (remplacer i (car s) psi)) and ,(formula-expand `(bigand ,i ,(cdr s) ,condition ,psi))))
             (formula-expand `(bigand ,i ,(cdr s)  ,condition ,psi)))))
    (('bigor i s condition psi)
     (if (null? s)
         'bottom
         (if (condition-tester (remplacer i (car s) condition))
            (if (singleton? s)
             (formula-expand (remplacer i (car s) psi))
             `(,(formula-expand (remplacer i (car s) psi)) or ,(formula-expand `(bigor ,i ,(cdr s) ,condition ,psi))))
             (formula-expand `(bigor ,i ,(cdr s)  ,condition ,psi)))))
    (('bigand i s psi)
     (if (null? s)
         'top
         (if (singleton? s)
           (formula-expand (remplacer i (car s) psi))  
         `(,(formula-expand (remplacer i (car s) psi)) and ,(formula-expand `(bigand ,i ,(cdr s) ,psi))))))
    (('bigor i s psi)
     (if (null? s)
         'bottom
         (if (singleton? s)
             (formula-expand (remplacer i (car s) psi))
         `(,(formula-expand (remplacer i (car s) psi)) or ,(formula-expand `(bigor ,i ,(cdr s) ,psi))))))
    (('bigxor i s psi)
	  (formula-expand (make-bigxor i s psi)))
    ((phi 'and psi)
     `(,(formula-expand phi) and ,(formula-expand psi)))
    
    ((phi 'or psi)
     `(,(formula-expand phi) or ,(formula-expand psi)))
    
    ((phi 'xor psi)
     (let ((sphi (formula-expand phi))
           (spsi (formula-expand psi)))
       `((,sphi and (not ,spsi)) or ((not ,sphi) and ,spsi))))
    
    ((phi 'imply psi)
     `((not ,(formula-expand phi)) or ,(formula-expand psi)))
    
    ((phi 'equiv psi)
     `(((not ,(formula-expand psi)) or ,(formula-expand phi)) and ((not ,(formula-expand phi)) or ,(formula-expand psi))) )
    
    
    (('not phi)
     `(not ,(formula-expand phi)))
  (a 
   (if (formula-and-multi? a)
       (formula-expand (andByTwo a))
       (if (formula-or-multi? a)
           (formula-expand (orByTwo a))
           a)))
  ))
  




(define (remplacer a b L)
  (if (list? L)
     (let ((f (lambda (e) (remplacer a b e))))
	      (map f L))
      (if (equal? L a)
          b
          L)))
  
  







(define (diff a b)
  (not (equal? a b)))
