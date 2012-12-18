(define ruleClean '(primitiverule (condition (
                                                      (formulatreated A PHI)
                                                      )
                                                     )
                                          (delete (
                                                   (formulatreated A PHI)
                                                   ) 
                                                  )
                                          (add (
                                                ))))


(define (cleanmodel BC)
  (rules-loopfirstrule (list ruleClean) BC)
  )