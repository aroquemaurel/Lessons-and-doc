


	(define (machinestate-create S rules)
			(couple-create
				S
				(set-createCouplesElementOfSet1AndElement2 rules S)
				)
	)
	
	
	(define (machinestate-set-get ms)
		(couple-first ms))
        
        
        
	
	
	(define (machinestate-events-get ms)
          (if (couple? ms)
              (couple-second ms)
              (raise  "error: the machine is not a couple (T, E)!")))
	
	
	(define (events-add-to-each-queue E elementsSet)
		(if (null? E)
                    '()
                    (let ((current-couple-rule-events (car E)))
                      (if (couple? current-couple-rule-events)
                          (cons (couple-create (couple-first current-couple-rule-events)
                                               (set-addelements 
                                                (couple-second current-couple-rule-events) elementsSet))
                                (events-add-to-each-queue (cdr E) elementsSet))
                          (begin
                            (raise  "error in events-add-to-each-queue! the couple is: ")
                            (display current-couple-rule-events))))))
        
	
	(define (events1-delete-event3-for-rule2 E rule event)
		(if (null? E)
			'()
                        (let ((current-couple-rule-events (car E)))
                          (if (couple? current-couple-rule-events)
                              (if (equal? (couple-first current-couple-rule-events) rule)
                                  (begin
                                    ;(display "event deleted !")
                                    ;(newline)
                                    (cons (couple-create (couple-first current-couple-rule-events)
                                                         (set-delete (couple-second current-couple-rule-events) event))
                                          (cdr E)))
                                  (cons current-couple-rule-events (events1-delete-event3-for-rule2 (cdr E) rule event))
                                  )
                              (begin
                                (raise "error in events1-delete-event3-for-rule2! the couple is: ")
                                (display current-couple-rule-events)) ))))
				
				
	(define (events-allempty? E)
          (if (null? E)
              #t
              (and (set-isempty? (couple-second (car E)))
                   (events-allempty? (cdr E)))))
        
        (define (events-number E)
          (if (null? E)
              0
              (+ (set-card (couple-second (car E)))
                   (events-number (cdr E)))))
        
  
  
  (define (events-forrule-get E rule)
	(couple-second (assoc rule E)))
;assq, search using eq?
;assv search using eqv?
;assoc search using equal?
			  
			  
			  
    ; (define (events-forrule-get E rule)
      ; (if (null? E)
          ; #f
          ; (if (eq? (couple-first (car E)) rule)
              ; (couple-second (car E))
              ; (events-forrule-get (cdr E) rule))))
  
  
                   
	(define (machinestate-elementsadd ms elementsSet)
		(couple-create
			(set-addelements-even-if-contained (machinestate-set-get ms) elementsSet)
			(events-add-to-each-queue (machinestate-events-get ms) elementsSet)
		)
	)
	
	
	(define (machinestate-event-delete ms rule event)
          (begin
;          (display "arf : ")
;          (display ms)
;          (newline)
;          (display "rule : ")
;          (display rule)
;          (newline)
;          (newline)
;          (display (events1-delete-event3-for-rule2 (machinestate-events-get ms) rule event))
;          (newline)
;          (newline)
		(couple-create
			(machinestate-set-get ms)
			(events1-delete-event3-for-rule2 (machinestate-events-get ms) rule event)
                        
               )         
	))
	

  (define (machinestate-events-forrule-get ms rule)
    (events-forrule-get (machinestate-events-get ms) rule))

  (define (machinestate-nothingtodo? ms)
    (events-allempty? (machinestate-events-get ms)))
  
  (define (machinestate-events-number ms)
    (events-number (machinestate-events-get ms)))
  
  (define (machinestate-compterendu-display ms)
    (begin
      (display "size of premodel: ")
      (display (set-card (machinestate-set-get ms)))
      (display " terms. Number of events: ")
      (display (machinestate-events-number ms))
      (newline)))
  
  
  (define (machinestate-nodoublons ms)
    (couple-create (set-nodoublons (machinestate-set-get ms)) (machinestate-events-get ms)))
  
