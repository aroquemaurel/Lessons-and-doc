



(define (set-card S)
  (if (null? S)
      0
      (+ 1 (set-card (cdr S)))
      )
  )


;(define (set-contains S e) (member S e))

(define (set-contains S e)
  (if (null? S)
      #f
      (if (equal? (car S) e)
          #t
          (set-contains (cdr S) e)
          )
      )
  )

(define (set-elementadd S e)
  (if (set-contains S e)
      S
      (cons e S)
      )
  )


(define set-add set-elementadd)


(define (set-add-even-if-contained S e)
  (cons e S))

(define (set-addelements S E)
  (if (null? E)
      S
      (set-elementadd (set-addelements S (cdr E)) (car E))
      ))

(define (set-addelements-even-if-contained S E)
		(append E S))




; (define (filter-iter test S accu)
; (if (null? S)
; accu
; (if (test (car S))



; )

; (define (filter test S) 
; (filter-iter test S '())
; )


; (define (set-remove S e) (filter (lambda (x) (not (equal? x e))) S))
; (define (set-remove S e)
; (if (null? S)
; ()
; (if (equal? (car S) e)
; (cdr S)
; (cons (car S) 
; (set-remove (cdr S) e)))))


(define (set-remove-iter S accu e)
		(if (null? S)
                    accu
                    (if (equal? (car S) e)
                        (set-remove-iter (cdr S) accu e)
                        (set-remove-iter (cdr S) (cons (car S) accu) e))))

(define (set-remove S e)
		(set-remove-iter S '() e))





(define set-delete set-remove)


(define (set-deleteelements S E)
  (if (null? E)
      S
      (set-remove (set-deleteelements S (cdr E)) (car E))
      )
  )

(define set-minus set-deleteelements)

(define set-emptyset '())

(define (set-isempty? S) (equal? S '()))

(define set-empty? set-isempty?)

(define (set-cartesian-product-oneelement-set a B)
  (if (set-isempty? B)
      set-emptyset
      (cons (couple-create a (car B)) (set-cartesian-product-oneelement-set a (cdr B)))
      )
  )

(define (set-cartesian-product A B)
  (if (set-isempty? A)
      set-emptyset
      (set-union (set-cartesian-product-oneelement-set (car A) B)
                 (set-cartesian-product (cdr A) B)
                 )
      )
  )



(define (set-union A B)
  `(,@A ,@B)
  )




(define (set-singleton e)
  (cons e '())
  )


(define (set-contains-element-verifying S V) (if (null? S) 
                                                 #f 
                                                 (or 
                                                  (V (car S)) 
                                                  (set-contains-element-verifying (cdr S) V)
                                                  )
                                                 )
  )



(define (couple-create a b) (list a b))
(define (couple-first c) (car c))
(define (couple-second c) (car (cdr c)))
;(define (couple-second c) (if c
;                              (car (cdr c))
;                              (display "error in (couple-second c): c is #f!")))

(define (couple? c) (if (list? c)
                        (if (null? c)
                            #f
                            (not (null? (cdr c))))
                        #f))

(define (set-createCouplesElementOfSet1AndElement2 S e)
		(if (null? S)
                    '()
                    (cons (couple-create (car S) e) (set-createCouplesElementOfSet1AndElement2 (cdr S) e))))



(define (triplet a b c) (list a b c))
(define (triplet-first c) (car c))
(define (triplet-second c) (car (cdr c)))
(define (triplet-third c) (car (cdr (cdr c))))




(define (relation-successors-get R w)
  (if (set-isempty? R)
      set-emptyset
      (if(equal? (couple-first
                  (car R)) 
                 w)
         
         (cons (couple-second
                (car R)
                )
               (relation-successors-get
                (cdr R)
                w
                )
               )
         (relation-successors-get 
          (cdr R)
          w)
         )
      )
  )












(define (list-head l) (car l))
(define (list-queue l) (cdr l))
(define (list-isempty? l) (equal? l '()))

(define 
  (match? structure modele)
  
  (if (list? modele)
      (if (list? structure)
          (if (list-isempty? modele)
              (list-isempty? structure)
              (if (list-isempty? structure)
                  #f
                  
                  (and (match? (list-head structure)
                               (list-head modele))
                       (match? (list-queue structure)
                               (list-queue modele))
                       )
                  )
              )
          #f
          )
      
      (if (equal? modele '_)
          #t
          (equal? structure modele)
          )
      )
  )


(define (set-element-matchwith S modele)
  (if (set-isempty? S)
      #f
      (if (match? (car S) modele)
          (car S)
          (set-element-matchwith (cdr S) modele)
          )
      )
  )


(define (element-extractV e modele)
  
  (if (list? modele)
      (if (list? e)
          (if (list-isempty? modele)
              #f
              (if (list-isempty? e)
                  #f
                  
                  (or (element-extractV (list-head e)
                                        (list-head modele))
                      (element-extractV (list-queue e)
                                        (list-queue modele))
                      )
                  
                  )
              
              )
          )
      (if (equal? modele 'V)
          e
          #f
          )
      )
  )



(define (set-include? A B)
  (if (null? A)
      #t
      (if (set-contains B (car A))
          (set-include? (cdr A) B)
          #f
          )
      )
  )



(define (set-equal? A B)
  (and (set-include? A B) (set-include? B A))
  )


;(set-nodoublons '(1 1 2 1 3 2 3 3 4 5))
; returns (1 2 3 4 5)
(define (set-nodoublons S)
  (if (null? S)
      '()
      (if (set-contains (cdr S) (car S))
                        (set-nodoublons (cdr S))
                        (cons (car S) (set-nodoublons (cdr S))))))
