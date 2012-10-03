(define amb-fail (lambda ()
        (error "this formula is not satisfiable.")))
; amb-fail contains what to do after an execution is broken



(define nondeterminism-initialize
  (lambda ()
    (set! amb-fail
      (lambda ()
        (error "this formula is not satisfiable.")))))
;at the beginning of a computing using "nondeterminism", we should call "nondeterminism-initialize"
;this function says : "ok, amb-fail is the function causing an error



(nondeterminism-initialize)
; we execute (nondeterminism-initialize)



;the code Scheme below is difficult...

(define-macro nondeterminism
  (lambda alts...
    `(let ((prev-amb-fail amb-fail))
       (call/cc
        (lambda (sk)

          ,@(map (lambda (alt)
                   `(call/cc
                     (lambda (fk)
                       (set! amb-fail
                         (lambda ()
                           (set! amb-fail prev-amb-fail)
                           (fk 'fail)))
                       (sk ,alt))))
                 alts...)

          (prev-amb-fail))))))





; Let us consider an example : (display (nondeterminism A B)).
; The expression (nondeterminism A B) is replaced by :
; 
;(let ((+prev-amb-fail amb-fail))
;       (call/cc
;        (lambda (+sk)
;
;          ,@(map (lambda (alt)
;                   `(call/cc
;                     (lambda (+fk)
;                       (set! amb-fail
;                         (lambda ()
;                           (set! amb-fail +prev-amb-fail)
;                           (+fk 'fail)))
;                       (+sk ,alt))))
;                 A B)
;
;          (+prev-amb-fail))))



;The instruction call/cc permet d'appeler une fonction à laquelle on passer le futur. Ici, on appelle :

;        (lambda (+sk)
;
;          ,@(map (lambda (alt)
;                   `(call/cc
;                     (lambda (+fk)
;                       (set! amb-fail
;                         (lambda ()
;                           (set! amb-fail +prev-amb-fail)
;                           (+fk 'fail)))
;                       (+sk ,alt))))
;                 A B)
;
;          (+prev-amb-fail))


;où l'argument +sk désigne le futur... c'est à dire "(display ...)". Autrement dit, on est sur le point d'exécuter :

;,@(map (lambda (alt)
;                   `(call/cc
;                     (lambda (+fk)
;                       (set! amb-fail
;                         (lambda ()
;                           (set! amb-fail +prev-amb-fail)
;                           (+fk 'fail)))
;                       (display ,alt))))
;                 A B)



;Quand tu es dans un environnement quasiquote, ",@A" signifie "j'évalue A, j'obtiens donc une liste L puis je renvoie L mais sans les parenthèses.

; exemple : `(,@'(a b)) ---> (a b)
; exemple : `(,@3) ---> non car quand on évalue 3, on n'obtient pas de liste
; exemple : `,@'(a b) ----> non, il faudrait renvoyer "a b" qui n'existe pas en Scheme...

; là, la fonction map applique la fonction
;(lambda (alt)
;  `(call/cc
;    (lambda (+fk)
;      (set! amb-fail
;            (lambda ()
;              (set! amb-fail +prev-amb-fail)
;              (+fk 'fail)))
;      (display ,alt))))

;à A puis B.


;Donc on commence par exemple à exécuter (pour A) le code :

;`(call/cc
;    (lambda (+fk)
;      (set! amb-fail
;            (lambda ()
;              (set! amb-fail +prev-amb-fail)
;              (+fk 'fail)))
;      (display ,A)))

;Cette portion de code exécute :
; (set! amb-fail
;            (lambda ()
;              (set! amb-fail +prev-amb-fail)
;              (+fk 'fail)))
;      (display ,A)))

;(nondeterminism (nondeterminism) 2)
;(nondeterminism (nondeterminism) (nondeterminism) (nondeterminism) (+ 1212 (nondeterminism (nondeterminism) 2)) 2)
;(nondeterminism-choose (list (nondeterminism-choose ()) 2))
;(define (nondeterminism-choose l)
;  (if (null? l)
;      (nondeterminism)
;      (nondeterminism (car l) (nondeterminism-choose (cdr l)))))

;(define (ndprogram l)
;	(append '(nondeterminism) l))
	
;(define (nondeterminism-choose l)
;	(eval (ndprogram l)))




(define (nondeterminism-choose l)
	(if (null? l)
		(nondeterminism)
		(if (null? (cdr l))
			(car l)
			(nondeterminism (car l) (cadr l)))))





(define (nondeterminism-fail) (nondeterminism))