(load "unification.scm")


;(rule-positiveconditionspatterns-get ruleDiamond)
;is
;((formula W (diamond PHI)))
(define 
  (rule-positiveconditionspatterns-get rule)
  (let ( (ssCONDITIONS (unifyPattern1WithElementsOfSet2 '(condition |C|) rule)) )
 ;   (if (null? ssCONDITIONS)
 ;       '()
        (substitution-variable-valeur-get (car ssCONDITIONS) '|C|)))

(define (rule-suchthat-get rule)
  (let ( (ssCONDITIONS (unifyPattern1WithElementsOfSet2 '(suchthat |C|) rule)) )
    (if (null? ssCONDITIONS)
        '#t
        (substitution-variable-valeur-get (car ssCONDITIONS) '|C|))))

(define (rule-performs-get rule)
  (let ( (ssCONDITIONS (unifyPattern1WithElementsOfSet2 '(perform |C|) rule)) )
    (if (null? ssCONDITIONS)
        'machinestate
        (substitution-variable-valeur-get (car ssCONDITIONS) '|C|))))


(define (rule-doesnotcontain-get rule)
  (let ( (ssCONDITIONS (unifyPattern1WithElementsOfSet2 '(doesnotcontain |C|) rule)) )
    (if (null? ssCONDITIONS)
        #f
        (substitution-variable-valeur-get (car ssCONDITIONS) '|C|))))




(define (rule-merge-get rule)
  (let ( (ssCONDITIONS (unifyPattern1WithElementsOfSet2 '(merge |C|) rule)) )
    (if (null? ssCONDITIONS)
        #f
        (substitution-variable-valeur-get (car ssCONDITIONS) '|C|))))


;(rule-addspatterns-get ruleDiamond)
;is
;((W link V) (world V) (formula V PHI))
(define 
  (rule-addspatterns-get rule)
  (let ( (ssADDS (unifyPattern1WithElementsOfSet2 '(add |A|) rule))
         (ssADDSNONDETERMINIST (unifyPattern1WithElementsOfSet2 '(add-nondeterminist |A1| |A2|) rule)))
    (if (null? ssADDSNONDETERMINIST)
        (if (null? ssADDS)
            '(())
            (set-singleton (substitution-variable-valeur-get (car ssADDS) '|A|)))
        (set-add
         (set-singleton (substitution-variable-valeur-get (car ssADDSNONDETERMINIST) '|A1|))
         (substitution-variable-valeur-get (car ssADDSNONDETERMINIST) '|A2|)))))



(define (rule-who-puts-phi-in-every-world phi)
  `(primitiverule (condition ((world |W|)))
                  ('add ( (formula |W| ,phi)))
                        )
  )


;(rule-allsubsmatchingwithnewterm-get rule newterm)
;is
;
(define (rule-allsubsmatchingwithnewterm-get rule newterm)
  (unifyOnePatternOfSet1WithElement2 
   (rule-positiveconditionspatterns-get rule)
   newterm))




