(load "unification.scm")
(load "rule.scm")
(load "sets.scm")


(define nd-queue '())

(define (nd-queue-init) (set! nd-queue '()))


(define (nd-queue-push state)
	(set! nd-queue (cons state nd-queue)))

(define (nd-queue-pop)
	(if (null? nd-queue)
		#f
		(let ((currentstate (car nd-queue))
				(tail (cdr nd-queue)))
			(begin (set! nd-queue tail)
					currentstate))))
	
	
(define (nd-queue-top)
		(car nd-queue))

(define (graph-make S)
  `(graph ,S))

(define (chatterboxsays m) '())
;(define (chatterboxsays m) (begin (display m) (newline)))

 (define (progressbar) (display "-"))
(define (progressbar-ruleapplied) (display "+"))


;(listeval '(2 ,(+ 1 2))) returns '(2 3)
(define (listeval L)
  (if (list? L)
      (if (null? L)
          '()
          (if (equal? (car L) 'unquote)
              (eval (cadr L))
              (cons (listeval (car L)) (listeval (cdr L)))))
      L))
;  (match L
;    ((a . m)
;     (if (equal? a 'unquote)
;         (eval (car m))
;         (cons (listeval a) (listeval m))))
;    (a a)
;    ))
     

;try to add to the database kb the pattern addpatterns with a substitution in sigmaset
;if it is not possible it returns #f

;~O(1)
(define (kb-add state whatweadd)
  (if (set-contains whatweadd '(halt))
          (begin
            (display "!")
           ; (display "non determinism: a branch is closed")
            (newline)
            (nd-queue-pop))
          (machinestate-elementsadd
           state
           whatweadd )))


;~O(1)
(define (kb-chooseaddpatterns-add state sigma addpatterns)
    (begin
      (if (> (set-card addpatterns) 1)
          (begin
            (display "<")
            (newline)
            ))
      (if (null? (cdr addpatterns))
          (kb-add state (listeval (free-variables-instanciate 
                         (substituteBySub1InTerm2 
                          sigma
                          (car addpatterns)))))
          (begin
            (nd-queue-push 
             (kb-add state (listeval (free-variables-instanciate 
                            (substituteBySub1InTerm2 
                             sigma
                             (cadr addpatterns))))))
            (kb-add state (listeval (free-variables-instanciate 
                           (substituteBySub1InTerm2 
                            sigma
                            (car addpatterns)))))))))

;  (nondeterminism-choose addpatterns)))))))
      ;(display whatweadd)
      ;(newline)
      ;(newline)
  


(define (rule-application-substitution-where-addpatterns-not-in-get state sigmaset addpatterns)	  
  (if (null? sigmaset)
      #f
      (let* ((sigma (car sigmaset))
             (sigmaaddpatterns (substituteBySub1InTerm2 sigma addpatterns)))
        
        (if (unifiableOnePatternsSetsOfSet1WithElementsSet2?
             (replaceUnquoteByNewVariables sigmaaddpatterns)
             (machinestate-set-get state))
            ;if the pattern to add is already in kb, we continue to look in (cdr sigmaset)
            (rule-application-substitution-where-addpatterns-not-in-get state (cdr sigmaset) addpatterns)
            sigma
            ))))



;(sigmaok? '((A 1) (B 2)) '(+ A B set) 5)
; returns 8
(define (sigmaok? sigma suchthattoexecute set)
  (let ((programtotest (substituteBySub1InTerm2 `((set (quote ,set))) (substituteBySub1InTerm2 (substitution-values-quote sigma) suchthattoexecute)) ))
    (begin
      ;        (display "program to test:")
      ;        (display        programtotest)
      ;        (newline)
      ;        (display " result: ")
      ;        (display (eval programtotest))
      ;        (newline)
      ;        (newline)
      (eval programtotest))))




(define (sigmasetfilter sigmasetconditionpos suchthattoexecute set)
  (if (null? sigmasetconditionpos)
      '()
      (if (sigmaok? (car sigmasetconditionpos) suchthattoexecute set)
          (cons (car sigmasetconditionpos) (sigmasetfilter (cdr sigmasetconditionpos) suchthattoexecute set))
          (sigmasetfilter (cdr sigmasetconditionpos) suchthattoexecute set)
          )
      ))



(define (sigmasetdelete sigmaset doesnotcontain set)
  (if (null? sigmaset)
      '()
      (let ( (sigma (car sigmaset)) )
        (if (set-include? (substituteBySub1InTerm2 sigma doesnotcontain) set)
            (sigmasetdelete (cdr sigmaset) doesnotcontain set)
            (cons sigma (sigmasetdelete (cdr sigmaset) doesnotcontain set))))))


;return a substitution sigma making the rule applicable
;return false if it is not applicable
(define (rule-application-substitution-get rule state newterm)
  (let* ((conditionpos (rule-positiveconditionspatterns-get rule))
         (sigmasetfromnewterm (unifyOnePatternOfSet1WithElement2 conditionpos newterm))
         (sigmasetconditionpos 
          (unifyPatternsSet1WithElementsOfSet2AccordingToSubsSet3 
           conditionpos
           (machinestate-set-get state)
           sigmasetfromnewterm))
         (sigmasetwithsuchthat (sigmasetfilter sigmasetconditionpos (rule-suchthat-get rule) (machinestate-set-get state)))
         (sigmaset 
          (if (rule-doesnotcontain-get rule)
              (sigmasetdelete sigmasetwithsuchthat (rule-doesnotcontain-get rule) (machinestate-set-get state))
              sigmasetwithsuchthat))
         )
    (if (set-empty? sigmaset)
        (begin
          (chatterboxsays `(":( rule doesn't match :) : " ,rule))
          ;(machinestate-compterendu-display state) 
          ;(progressbar)
          #f)
        (begin
          (chatterboxsays `(":---)))) rule matches : " ,rule ))
          ;(progressbar-ruleapplied)
          ;(machinestate-compterendu-display state) 
          (rule-application-substitution-where-addpatterns-not-in-get 
           state 
           sigmaset
           (rule-addspatterns-get rule))
          )
        )))





(define (evalperforms sigma programtoexecute machinestate)
  ;  machinestate)
  ; (eval (substituteBySub1InTerm2 `((machinestate ,machinestate)) (substituteBySub1InTerm2 sigma '(quote machinestate)))) )
  ; (eval `(quote ,machinestate)))
  (eval (substituteBySub1InTerm2 `((machinestate (quote ,machinestate))) 
                                 (substituteBySub1InTerm2 (substitution-values-quote sigma) programtoexecute)))) 


(define (merge S e1 e2)
  (if (equal? S e2)
      e1
      (if (list? S)
          (if (null? S)
              '()
              (cons (merge (car S) e1 e2) (merge (cdr S) e1 e2)))
          S)))

(define (replaceinS1e23bye12 S e1 e2)
    (if (equal? S e2)
      e1
      (if (list? S)
          (if (null? S)
              '()
              (cons (replaceinS1e23bye12 (car S) e1 e2) (replaceinS1e23bye12 (cdr S) e1 e2)))
          S)))

(define (fusemerge S e1 e2)
  (machinestate-nodoublons (replaceinS1e23bye12 S e1 e2)))


; apply the rule rule with the substitution sigma on state
(define (rule-apply rule sigma state)
          (let* ((statewithadd (kb-chooseaddpatterns-add state sigma (rule-addspatterns-get rule)))
               ;(statewithaddandperform (evalperforms sigma (rule-performs-get rule) statewithadd))
               (mergevars (rule-merge-get rule) )
               (statewithmerge
                (if mergevars
                    (begin
                      (display "merge ")
                      (display (substitution-variable-valeur-get sigma (car mergevars)))
                      (display " and ")
                      (display (substitution-variable-valeur-get sigma (cadr mergevars)))
                      (display ".")
                      (newline)
;                      (display "Here is :")
;                      (display statewithadd)
;                      (newline)
;                      (newline)
;                      (display "After merging:")
;                      (display (merge statewithadd (substitution-variable-valeur-get sigma (car mergevars))
;                           (substitution-variable-valeur-get sigma (cadr mergevars))) )
;                      (newline)(newline)
;                      (newline)
                      (fusemerge statewithadd (substitution-variable-valeur-get sigma (car mergevars))
                           (substitution-variable-valeur-get sigma (cadr mergevars))))
                    statewithadd)))
          (begin
;            (display "we apply rule ")
;            (display rule)
;            (display " with substitution ")
;            (display sigma)
;            (display " launched by the event ")
;            (display newterm)
;            (display ". ")
            statewithmerge)))




(define (rule-apply-find-newterm rule state newterms)
  (if (null? newterms)
      #f
      (let ((sigma (rule-application-substitution-get rule state (car newterms))))
        (if sigma
            sigma
            (begin
              (rule-apply-find-newterm rule 
                                       state
                                       (cdr newterms)))))))



;try to get a good substitution to apply rule rule on state
(define (rule-apply-try rule state)
      (rule-apply-find-newterm rule state (machinestate-events-forrule-get state rule)))

	  
(define (rule-get-couple-cleanedstate-sigma-newterm rule state newterms)
  (if (null? newterms)
      (list state #f)
      (let ( (sigma (rule-application-substitution-get rule state (car newterms)))
	         (cleaned-state (machinestate-event-delete state rule (car newterms))))
        (if sigma
            (list cleaned-state sigma)
            (begin
              (rule-get-couple-cleanedstate-sigma-newterm rule 
                                       cleaned-state
                                       (cdr newterms)))))))

(define (rule-get-couple-cleanedstate-sigma rule state)
	(rule-get-couple-cleanedstate-sigma-newterm rule state (machinestate-events-forrule-get state rule)))

(define (state-clean-rule-newterms rule newterms state)
  (if (null? newterms)
      state
      (if (rule-application-substitution-get rule state (car newterms))
          ;(state-clean-rule-newterms rule (cdr newterms) state)
		  state
          (state-clean-rule-newterms rule (cdr newterms) (machinestate-event-delete state rule (car newterms))))))

(define (state-clean-rule rule state)
  (state-clean-rule-newterms rule (machinestate-events-forrule-get state rule) state))

;remove the useless event
; (define (state-clean rules state)
  ; (if (null? rules)
      ; state
      ; (state-clean (cdr rules) (state-clean-rule (car rules) state))))

(define (state-clean rules state)
 (if (null? rules)
     state
	  (let ((sigma (rule-apply-try (car rules) state)))
       (if sigma
           (state-clean-rule (car rules) state)
           (state-clean (cdr rules) (state-clean-rule (car rules) state))))))


;apply the first rule in rules applicable on state
; (define (rules-firstrule-apply-rec rules state)
  ; (if (null? rules)
      ; state
      ; (let ((clean-state (state-clean-rule (car rules) state)))
      ; (let ((sigma (rule-apply-try (car rules) clean-state)))
        ; (if sigma
            ; (rule-apply (car rules) sigma clean-state)
            ; (rules-firstrule-apply-rec (cdr rules) clean-state))))))

(define (rules-firstrule-apply-rec rules state)
  (if (null? rules)
      state
      (let* ((rule (car rules))
			(couple-cleaned-state-sigma (rule-get-couple-cleanedstate-sigma rule state))
			(cleaned-state (car couple-cleaned-state-sigma))
			(sigma (cadr couple-cleaned-state-sigma))
			)
        (if sigma
            (rule-apply rule sigma cleaned-state)
            (rules-firstrule-apply-rec (cdr rules) cleaned-state)))))
			
			
			
(define (rules-firstrule-apply rules state) (rules-firstrule-apply-rec rules state))
;(rules-firstrule-apply-rec rulesK (state-clean rulesK state))


;give me the next rule to apply on state
(define (rules-firstrule-get-future-couplerulesigmatoapply rules state)
  (if (null? rules)
      #f
        (let ((sigma (rule-apply-try (car rules) state)))
        (if sigma
            (list (car rules) sigma)
            (rules-firstrule-get-future-couplerulesigmatoapply (cdr rules) state)))))

(define (couplerulesigma-getrule C)	(car C))

(define (couplerulesigma-getsigma C) (cadr C))
			
(define (couplerulesigma-getinstanciedconditions C) 
	(let ((rule (couplerulesigma-getrule C))
		  (sigma (couplerulesigma-getsigma C)) )
		      (substituteBySub1InTerm2 sigma (rule-positiveconditionspatterns-get rule))
		)
)
			
(define (couplerulesigma-apply C state)
      (rule-apply (couplerulesigma-getrule C) (couplerulesigma-getsigma C) (state-clean-rule (couplerulesigma-getrule C) state)))
			
;apply rules until saturation
(define (rules-apply rules state)
  (if (machinestate-nothingtodo? state)
      state
      (rules-apply rules 
                   (rules-firstrule-apply rules state))))



;create the premodel "((world 1) (formula 1 phi))"
(define (premodel-oneworld-containing-one-formula phi)
  `((root ,element-generated-get) 
    (world ,element-generated-get)
     (formula ,element-generated-get ,phi)))


	 
	 
