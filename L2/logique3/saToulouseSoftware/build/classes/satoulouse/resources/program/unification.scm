(load "sets.scm") 

  ;(myandmap f L) is true iff (f i) is true for all i in L
  (define (myandmap f L)
    (if (set-isempty? L)
        #t
        (if (f (car L))
            (myandmap f (cdr L))
            #f)) )
  
  ;(char-upper-case-or-numeric c) is true iff c in {A, ...Z} U {0, 1, ...9}
  (define (char-upper-case-or-numeric c) 
    (or (char-upper-case? c) 
        (char-numeric? c)))
  
  
  ;(isVariable? v) is true iff v is a variable for unification
  (define (isVariable? v) 
    (if (symbol? v)
        (myandmap
         char-upper-case-or-numeric 
         (string->list (symbol->string v)))
        #f))
  ;Dans cette fonction, on voit toute la puissance de Scheme !!
  ; 1) Primo, Scheme a un contrôle sur le nom des variables. On lui donne un identifiant et on peut avoir la chaîne de caractères qui la représente (on est pas bridé)
  ; 2) les noms des fonctions sont claires avec une "flèche" "->"... string->list existe ! waouh ! Et ça fait ce qu'on attend : transformer la chaîne de caractères en liste de caractères (car une liste c'est quand même plus pratique)
  ; 3) andmap !! waouh ! Pas de boucle où je ne sais pas quoi ! andmap renvoie vrai si, quand j'appelle char-upper-case-or-numeric sur chaque élément de ma liste de caractères, j'ai toujours vrai. La sémantique est claire non ? Pourquoi j'irai faire une boucle !?! On s'en fout ! On est au XXIe siècle !
  ; (on est XXIe siècle mais j'ai préféré redéfinir ma myandmap car il y a des interpréteurs qui ne possède pas andmap :( )
  ; 4) OUI ! Je passe en paramètre une fonction ! Et ce n'est pas GeEk ! Pas de pointeurs ou je ne sais pas quoi... je suis bien en train de faire des mathématiques et pas du GeEkAgE bas niveau...
  
  
  
  
  
  
  ;Remplace dans Expr les occurences des variables v de S par S(v) et renvoie cette nouvelle expression
  (define (substituteBySub1InTerm2 sigma term)
    (if (null? term)
        '()
        (if (list? term)
            (cons (substituteBySub1InTerm2 sigma (car term))
                  (substituteBySub1InTerm2 sigma (cdr term))
                  )
            (let (( value (substitution-variable-valeur-get sigma term)))
              (if value
                  value
                  term)))))
  
  
  ;renvoie la concaténation de deux listes. #t = () et #f est absorbant
  (define (appendwithtf L1 L2) (if (equal? L1 #t)
                                   (if (equal? L2 #t)
                                       '()
                                       (if (equal? L2 #f)
                                           #f
                                           L2))
                                   (if (equal? L1 #f)
                                       #f
                                       (if (equal? L2 #t)
                                           L1
                                           (if (equal? L2 #f)
                                               #f
                                               (append L1 L2)
                                               )))))
  
  ;tente d'unifier ExprWithVariable et Expr. Expr ne contient pas de variables. ExprWithVariable oui.
  ;En cas d'échec, renvoie #f.
  ;En cas de succès renvoie la substitution qui unifie ExprWithVariable et Expr.
  ;Exemple 1 : sur pattern = (g A B) et term = (g s t), ça renvoie
  ;            ((A s) (B t))
  ;Exemple 2 : sur pattern = (g A) et term = (g s t), ça renvoie
  ;            #f
  ;Exemple 3 : sur pattern = (g g) et term = (g g), ça renvoie
  ;            ()
  (define (unifyPattern1WithTerm2 pattern term)
    (if (null? pattern)
        (if (null? term)
            '()
            #f
            )
        (if (list? pattern) ;pattern is a non empty list
            (if (null? term)
                #f
                (if (list? term)
                    (let ((sigma (unifyPattern1WithTerm2 (car pattern) (car term))))
                      (if sigma
                          (let (( nextsigma 
                                  (unifyPattern1WithTerm2 
                                   (substituteBySub1InTerm2 sigma (cdr pattern)) 
                                   (cdr term))))
                            (if nextsigma
                                (append sigma nextsigma)
                                #f))
                          #f)
                      )         
                    #f
                    )
                )
            (if (isVariable? pattern)
                `((,pattern ,term))
                (if (equal? pattern term)
                    '()
                    #f
                    )
                )
            )
        )
    )       
  
  
  
  ; extract from the set S all the elements which can be unified with pattern
  (define (set-extract-with-unification S pattern)
    (if (null? S)
        '()
        (if (unifyPattern1WithTerm2 pattern (car S))
            (cons (car S) (set-extract-with-unification (cdr S) pattern))
            (set-extract-with-unification (cdr S) pattern)
            )
        )
    )
  
  ; renvoie S(v)
  ; (define (substitution-variable-valeur-get-weknowvariable-nameisok sigma variable-name)
  ; (if (null? sigma)
  ; #f
  ; (if (equal? sigma #f)
  ; #f
  ; (let ( (variable-value-couple (car sigma)) )
  ; (if (equal? (car variable-value-couple) variable-name)
  ; (cadr variable-value-couple)
  ; (substitution-variable-valeur-get (cdr sigma) variable-name)
  ; )
  ; )
  ; )
  ; )
  ; )
  
  ; (define (substitution-variable-valeur-get sigma variable-name)
  ; (if (isVariable? variable-name)
  ; (substitution-variable-valeur-get-weknowvariable-nameisok sigma variable-name)
  ; #f
  ; )
  ; )
  (define (substitution-variable-valeur-get sigma variable-name)
    (let ((couple (assv variable-name sigma)))
      (if couple
          (cadr couple)
          #f)))
  
  
  
  ;renvoie l'ensemble des substitutions où pattern s'unifie avec un élément de S
  ; par exemple ça peut renvoyer quelque chose qui ressemble à ( ((A t)) ((A s) (B t)) )
  ;si renvoie () c'est que element ne peut s'unifier avec aucun élément de Ensemble
  ; (ensemble vide = il n'y a pas de substitution qui marche)
  ; example 1 : (unifierElementAvecElementEnsemble '(gaga L) '((gaga prout))) returns (((L prout)))
  ; example 2 : (unifierElementAvecElementEnsemble '(gaga L) '((gaga prout) (gaga (q q)))) returns (((L prout)) ((L (q q))))
  ; example 3 (unifyPattern1WithElementsOfSet2 'a '(a) ) returns (())
  ; (define (unifyPattern1WithElementsOfSet2 pattern S)
    ; (if (null? S)
        ; ()
        ; (let ((substitution (unifyPattern1WithTerm2 pattern (car S))))
          ; (if substitution
              ; (cons substitution
                    ; (unifyPattern1WithElementsOfSet2 pattern (cdr S))
                    ; )
              ; (unifyPattern1WithElementsOfSet2 pattern (cdr S))
              ; )
          ; )
        ; )
    ; )
  
  
  
  (define (unifyPattern1WithElementsOfSet2-iter pattern S sigmaSetAccu)
    (if (null? S)
        sigmaSetAccu
        (let ((substitution (unifyPattern1WithTerm2 pattern (car S))))
          (if substitution
            (unifyPattern1WithElementsOfSet2-iter pattern (cdr S) (cons substitution sigmaSetAccu))
            (unifyPattern1WithElementsOfSet2-iter pattern (cdr S) sigmaSetAccu)))))
  
  (define (unify-pattern-elementsofset pattern S)
    (unifyPattern1WithElementsOfSet2-iter pattern S '()))

  (define unifyPattern1WithElementsOfSet2 unify-pattern-elementsofset)
  
  ;exemple si e = ((A s) (B t)) et S = (((C u)) ((D v) (E, h)))
  ;revoie ((((A s) (B t) (C u)) ((A s) (B t) (D v) (E, h))))
  (define (composeSub1WithEachSubOfSet2 e S)
    (if (null? S)
        '()
        (cons (append e (car S))
              (composeSub1WithEachSubOfSet2 e (cdr S)
                                            )
              )
        )
    )
  
  
  ;renvoie l'ensemble des substitutions où un des éléments de SousEnsembleAvecVariable s'unifie avec un élément de elementsSet
  (define (unifyOnePatternOfSet1WithOneElementOfSet2 patternsSet elementsSet)
    (if (null? patternsSet)
        '()
        (set-union (unifyPattern1WithElementsOfSet2 (car patternsSet) elementsSet)
                   (unifyOnePatternOfSet1WithOneElementOfSet2 (cdr patternsSet) elementsSet)
                   )
        )
    )
  
  
  (define (unifyOnePatternOfSet1WithElement2 patternsSet element)
    (unifyOnePatternOfSet1WithOneElementOfSet2 patternsSet (set-singleton element)))
  
  
  
  ;renvoie l'ensemble des substitutions où les éléments de patternsSet s'unifient tous avec des éléments de elementsSet
  ;(unifyPatternsSet1WithElementsOfSet2 '(a) '(a)) returns (())
  ;((unifyPatternsSet1WithElementsOfSet2 '( () ) '( () )) returns (())
  ;(unifyPatternsSet1WithElementsOfSet2 '() '(a)) returns (())
  (define (unifyPatternsSet1WithElementsOfSet2 patternsSet elementsSet)
    (if (null? patternsSet)
        ;si SousEnsembleAvecVariable est vide, l'unification est possible... (()) code toutes les unifications possibles
        '(())
        (let ((pattern1 (car patternsSet) ))
        (let ((substitutionsSetForPattern1Set 
              (unifyPattern1WithElementsOfSet2 pattern1 elementsSet) ))
        (letrec
             (( 
              unifierEnsembleAvecSousEnsembleAvecSubstitutionsSet
              (lambda 
                  (SubstitutionsSet tailPatternsSet elementsSet)
                (if (null? SubstitutionsSet)
                    '()
                    (appendwithtf
                     (let ((sigma (car SubstitutionsSet)))
                       (composeSub1WithEachSubOfSet2 
                        sigma
                        (unifyPatternsSet1WithElementsOfSet2
                         (substituteBySub1InTerm2 sigma tailPatternsSet) 
                         elementsSet
                         ))
                        )
                     (unifierEnsembleAvecSousEnsembleAvecSubstitutionsSet
                      (cdr SubstitutionsSet)
                      tailPatternsSet
                      elementsSet
                      ))  
                    ))
              )
             )
          
          ;code de la fonction
          (if substitutionsSetForPattern1Set 
              (unifierEnsembleAvecSousEnsembleAvecSubstitutionsSet
               substitutionsSetForPattern1Set (cdr patternsSet) elementsSet)
              '())
          )))))

  
  
  
  
  (define (unifiablePatternsSet1WithElementsSet2? patternsSet elementsSet)
    (not (null? (unifyPatternsSet1WithElementsOfSet2 patternsSet elementsSet) ))
    )
  
  
  (define (unifiableOnePatternsSetsOfSet1WithElementsSet2? patternsSetsSet elementsSet)
    (if (null? patternsSetsSet)
        #f
        (or  (unifiablePatternsSet1WithElementsSet2? (car patternsSetsSet) elementsSet)
             (unifiableOnePatternsSetsOfSet1WithElementsSet2? (cdr patternsSetsSet) elementsSet))))
  
  
  
  
  
  (define (unifyPatternsSet1WithElementsOfSet2AccordingToSubsSet3 patternsSet elementsSet subsSet)
    (if (null? subsSet)
        '()
        (let ((sigma (car subsSet)))
          (set-union
           (composeSub1WithEachSubOfSet2 sigma (unifyPatternsSet1WithElementsOfSet2 (substituteBySub1InTerm2 sigma patternsSet)
                                                                                    elementsSet))
           (unifyPatternsSet1WithElementsOfSet2AccordingToSubsSet3 patternsSet elementsSet (cdr subsSet))
           ))))
  
  
  
  
  ;renvoie l'ensemble des variables "libres" (qui restent) dans E
  ;exemple : (free-variables-get '(g A B s)) renvoie (A B)
  (define (free-variables-get expression)
    (if (null? expression)
        '()
        (if (list? expression)
            (set-union (free-variables-get (car expression))
                       (free-variables-get (cdr expression))
                       )
            (if (isVariable? expression)
                (list expression)
                '()
                )
            )
        )
    )
  
  ;invente des éléments aux variables dans variablesSet
  ;exemple si V = (A B)
  ;ça renvoie ((A 190) (B 191)) où 190 et 191 sont des nouveaux éléments qui n'ont pas encore été utilisé
  (define (substitution-free-variables-create variablesSet)
    (if (null? variablesSet)
        '()
        (begin
          (element-generate)
          (append
           `( ( ,(car variablesSet) ,element-generated-get  ))
           (substitution-free-variables-create (cdr variablesSet) )
           ))))
  
  
  
  ;remplace les variables "libres" de expression par des nouveaux éléments
  ;(f A s A B) devient (f 190 s 190 191)
  (define (free-variables-instanciate expression)
    (substituteBySub1InTerm2 
     (substitution-free-variables-create (free-variables-get expression))
     expression
     )
    )
  
  
  
  ;(substitution-values-quote '((A (+ 1 2)) (B b)))
  ;returns ((A '(+ 1 2)) (B 'b))
  (define (substitution-values-quote sigma)
    (if (null? sigma)
        '()
        (cons (couple-create (car (car sigma)) (list 'quote (cadr (car sigma)))) (substitution-values-quote (cdr sigma)))))
  
  
  
  ;(replaceUnquoteByNewVariables '(1 2 ,(+ 1 2)))
  (define (replaceUnquoteByNewVariables L)
    (if (list? L)
        (if (null? L)
            '()
            (if (equal? (car L) 'unquote)
                'AZZERTYQWERTY
                (cons (replaceUnquoteByNewVariables (car L)) (replaceUnquoteByNewVariables (cdr L)))))
        L))
            