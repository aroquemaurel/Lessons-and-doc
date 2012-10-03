;;syntax

(define logicCPL-prefixed-unary-operators-set (list  'not 'diamond 'box))
(define logicCPL-postfixed-unary-operators-set (list ))
(define logicCPL-prefixed-binary-operators-set (list ))
(define logicCPL-infixed-binary-operators-set (list 'and 'or 'imply 'equiv))


(define (logicCPL-parse phi)
  (parse
   logicCPL-prefixed-unary-operators-set
   logicCPL-postfixed-unary-operators-set
   logicCPL-prefixed-binary-operators-set
   logicCPL-infixed-binary-operators-set
   phi))


	(define (proposition? |P|)
	  (not (list? |P|)))


	;;; My tableau rule

	(define ruleAnd '(primitiverule 
	                  ;when I see |A| (|PHI1| and |PHI2|) formula in word |A|
	                  (condition (
	                              (formula |A| (|PHI1| and |PHI2|))
	                              ) )
	                  
	                  ;and the world |A| in my tableau must contain |PHI1| and |PHI2|.
	                  (add (
	                        (formula |A| |PHI1|)
	                        (formula |A| |PHI2|)
	                        ))))
							
							
	


	(define ruleOr '(primitiverule 
	                 ;when I see |A| (|PHI1| or |PHI2|) formula in word |A|
	                 (condition (
	                             (formula |A| (|PHI1| or |PHI2|))
	                             )
	                            )
	                
	                 ;there is |A| nondeterminist choice:
	                 ;either my world |A| must contain |PHI1|
	                 ;or it must contain |PHI2|
	                 (add-nondeterminist (
	                                      (formula |A| |PHI1|)
	                                      )
	                                     (
	                                      (formula |A| |PHI2|)
	                                      ))))

	(define ruleImply '(primitiverule 
	                  (condition (
	                              (formula |A| (|PHI1| imply |PHI2|))
	                              ))

	                  (add (
	                        (formula |A| ((not |PHI1|) or |PHI2|))
	                        ))))

	(define rulenotImply '(primitiverule 
	                  (condition (
	                              (formula |A| (not (|PHI1| imply |PHI2|)))
	                              ))

	                  (add (
	                        (formula |A| (|PHI1| and (not |PHI2|)))
	                        ))))

	(define ruleEquiv '(primitiverule 
	                  (condition (
	                              (formula |A| (|PHI1| equiv |PHI2|))
	                              ))

	                  (add (
	                        (formula |A| ((|PHI1| imply |PHI2|) and (|PHI2| imply |PHI1|)))
	                        ))))



	(define ruleNotAnd '(primitiverule 
	                  (condition ((formula |A| (not (|PHI1| and |PHI2|)))))
	                  (add ((formula |A| ((not |PHI1|) or (not |PHI2|)))))))

	(define ruleNotEquiv '(primitiverule 
	                  (condition ((formula |A| (not (|PHI1| equiv |PHI2|)))))
	                  (add ((formula |A| (((not |PHI1|) and |PHI2|) or (|PHI1| and (not |PHI2|))))))))


	(define ruleNotOr '(primitiverule 
	                  (condition ((formula |A| (not (|PHI1| or |PHI2|)))))
	                  (add ((formula |A| ((not |PHI1|) and (not |PHI2|)))))))

	(define ruleNotNot '(primitiverule 
	                  (condition ((formula |A| (not (not |PHI1|)))))
	                  (add ((formula |A| |PHI1|)))))
					  
					  
	(define ruleCutOrLeft '(primitiverule 
	                  (condition ((formula |A| (|PHI1| or |PHI2|)) (formula |A| (not |PHI1|))))
	                  (add ( (formula |A| |PHI2|) ))))

	(define ruleCutOrRight '(primitiverule 
	                  (condition ((formula |A| (|PHI1| or |PHI2|)) (formula |A| (not |PHI2|))))
	                  (add ( (formula |A| |PHI1|) ))))
					  
	(define ruleCutOrNotLeft '(primitiverule 
	                  (condition ((formula |A| ((not |PHI1|) or |PHI2|)) (formula |A| (|PHI1|))))
	                  (add ( (formula |A| |PHI2|) ))))

	(define ruleCutOrNotRight '(primitiverule 
	                  (condition ((formula |A| (|PHI1| or (not |PHI2|))) (formula |A| |PHI2|)))
	                  (add ( (formula |A| |PHI1|) ))))


					  
	(define ruleContradiction '(primitiverule 
	                            ;If |A| world contains (not PHI) and PHI	
	                            (condition (
	                                        (formula |A| (not |PHI|))
	                                        (formula |A| |PHI|)
	                                        )
	                                       )
	                            ;The derivation is not correct and we stop the process (closed tableau)
	                            (add (
	                                  (formula |A| bottom)
	                                  ))))


	                         

	(define ruleContradictionBottom '(primitiverule 
	                                  ;If |A| world contains bottom (false)...
	                                  (condition (
	                                              (formula |A| bottom)
	                                              )
	                                             )
	                                  ;The derivation is not correct and we stop the process closed tableau
	                                  (add (
	                                        (halt)
	                                        ))))

											
											
	(define ruleContradictionNotTop '(primitiverule 
	                                  ;If |A| world contains bottom (false)...
	                                  (condition (
	                                              (formula |A| (not top))
	                                              )
	                                             )
	                                  ;The derivation is not correct and we stop the process closed tableau
	                                  (add (
	                                        (halt)
	                                        ))))
											
											
	(define ruleProposition '(primitiverule
	                          (suchthat (proposition? (quote |P|)))
	                          (condition ((formula |A| |P|)))
	                          (add ((proposition |A| |P|)))))

	(define ruleNotProposition '(primitiverule
	                          (suchthat (proposition? (quote |P|)))
	                          (condition ((formula |A| (not |P|))))
	                          (add ((proposition |A| (not |P|))))))
													

		(define rulesCPL (list ruleNotEquiv ruleEquiv rulenotImply ruleImply ruleNotAnd ruleNotOr ruleNotNot ruleAnd  ruleContradiction ruleContradictionBottom ruleContradictionNotTop
ruleCutOrLeft 
ruleCutOrRight
ruleCutOrNotLeft
ruleCutOrNotRight 
ruleOr)) 



	(define (logicCPLsat? kb)
	  (rules-apply 
	   rulesCPL
	   kb))



	(define (isCPLsat? phi)  
	  (begin
	    (nondeterminism-initialize)
	    (car (logicCPLsat?  (machinestate-create (premodel-oneworld-containing-one-formula phi) rulesCPL)))
	  ))


