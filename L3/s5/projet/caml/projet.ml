(************************************************
 * Projet de Caml
 * Antoine de Roquemaurel
 * Groupe 1.1
 * L3 Informatique
 ***********************************************)
 

(* 
 * ===================
 * Utiles 
 * ===================
 *)
let string_of_char = String.make 1;;

(* 
 * ===================
 * Définition des types 
 * ===================
 *)

(** Type expr, permet de représenter une expression arithmétique *)
type expr =  Const of int
            |Var of char
            |Add of expr*expr
            |Sub of expr*expr
            |Mul of expr*expr
            |Div of expr*expr
            |Opp of expr;;

(**Type environnement, permet de représenter un environnement *)
type environnement = Environnement of (char*int) list;;

(** Retourne la variable d'un couple (variable,constante) *)
let liaisonGetVar = function (v,c) -> v;;

(** Retourne la constante d'un couple (variable,constante) *)
let liaisonGetConst = function (v,c) -> c;;

(*
 * ===================
 * Fonctions sur les types
 * ===================
 *)

    (* — 2.2 Fonctions permettant l'affichage *)

(** Retourne une expression sous forme de chaîne de caractère *)
let rec getStringExpr = function 
      Const(c) -> string_of_int c
    | Var(v) -> string_of_char v
    | Add(e1,e2) -> "("^(getStringExpr e1)^" + "^(getStringExpr e2)^")"
    | Sub(e1,e2) -> "("^(getStringExpr e1)^" - "^(getStringExpr e2)^")"
    | Mul(e1,e2) -> "("^(getStringExpr e1)^" * "^(getStringExpr e2)^")"
    | Div(e1,e2) -> "("^(getStringExpr e1)^" / "^(getStringExpr e2)^")"
    | Opp(e) -> "(-"^(getStringExpr e)^")"
;;

(** Affiche une expression à l'écran *)
let displayExpr = fun expr -> print_string ((getStringExpr expr)^"\n");;


    (* — 2.3 Fonctions permettant l'évaluation *)
(**
 * Retourne une nouvelle expression dans laquelle toutes les variables ont été
 * remplacés par leur valeurs en fonction d'une seule et unique liaison
 *)
let evalReplaceLiaison = fun expr liaison ->
    let rec interne = function
      Const(c) -> Const(c)
    | Var(v) -> if(v = (liaisonGetVar liaison)) then Const(liaisonGetConst liaison) else Var(v)
    | Add(e1,e2) -> Add((interne e1), (interne e2))
    | Mul(e1,e2) -> Mul((interne e1), (interne e2))
    | Sub(e1,e2) -> Sub((interne e1), (interne e2))
    | Div(e1,e2) -> Div((interne e1), (interne e2))
    | Opp(e) -> Opp((interne e))
    in (interne expr);;

(**
 * Retourne une nouvelle expression dans laquelle toutes les variables ont été
 * rempalcées par leurs valeurs en fonction de l'environnement.
 *)
let rec evalWithEnvironment = fun expr environnement ->
    match environnement with
      Environnement([]) -> expr
    | Environnement(t::q) -> evalWithEnvironment (evalReplaceLiaison expr t) (Environnement(q)) ;;
    
    
(**
 * Calcul le résultat d'une expression. Celle-ci ne doit contenir aucune
 * variable.
 *)
let rec calcul = function
      Var(v) -> failwith "Impossible de calculer le résultat d'une variable"
    | Const(c) -> c
    | Add(e1,e2) -> calcul(e1) + calcul(e2)
    | Sub(e1,e2) -> calcul(e1) - calcul(e2)
    | Div(e1,e2) -> calcul(e1) / calcul(e2)
    | Opp(e) -> -(calcul(e))
    | Mul(e1,e2) -> calcul(e1) * calcul(e2);;

(**
 * Evalue une exression à l'aide de son environnement 
 *)
let eval = fun expr env -> calcul(evalWithEnvironment expr env);;

    (* — 2.4 Fonctions permettant la simplification *)
(**
 * Simplifie une expression, cependant celle-ci n'est pas simplifiée au maximum
 *)
let rec noMinimumSimplification = function
      Const(c) -> Const(c)
    | Var(v) -> Var(v)
    | Add(e1,e2) -> if e1 = Const(0) then (noMinimumSimplification e2) 
                    else
                        if e2 = Const(0) then noMinimumSimplification e1 
                        else Add((noMinimumSimplification e1), (noMinimumSimplification e2))
    | Sub(e1,e2) -> if e1 = Const(0) then (noMinimumSimplification (Opp(e2)))
                    else
                        if e2 = Const(0) then noMinimumSimplification e1 
                        else Sub((noMinimumSimplification e1), (noMinimumSimplification e2))
    | Mul(e1,e2) -> if e1 = Const(1) then (noMinimumSimplification e2) 
                    else
                        if e2 = Const(1) then noMinimumSimplification e1 
                        else if e1 = Const(0) || e2 = Const(0) then Const(0)
                            else Mul((noMinimumSimplification e1), (noMinimumSimplification e2))
    | Div(e1,e2) -> if(e2 = Const(0)) then failwith "Division par 0" else Div(e1,e2)
    | Opp(Opp(e)) -> e
    | Opp(e) -> Opp(noMinimumSimplification(e))


(** Simplifie une expression à son maximum *)
let rec simplify = fun expr ->
    let exprSimplify = (noMinimumSimplification expr) in 
        if expr <> exprSimplify then (simplify exprSimplify) 
        else exprSimplify;;

    (* — 2.5 Fonctions permettant le calcul du maximum *)

(** Retourne une liste de couple (char,int) pour lesquel toutes les char sont associées à 0 *)
let rec getListEnvWith0 = fun expr ->
    match expr with
      Var(v) -> [(v, 0)] 
    | Const(c) -> [] 
    | Add(e1,e2)|Sub(e1,e2)|Mul(e1,e2)|Div(e1,e2) -> ((getListEnvWith0 e1)@(getListEnvWith0 e2))
    | Opp(e) -> (getListEnvWith0 e);;

(** Transforme une (char*int) list en environnement *)
let getEnvironmentWith0 = fun expr ->
    Environnement(getListEnvWith0 expr);;

(** Retourne l'environnement possible suivant d'un environnement donné *)
let rec getNextEnvironment = function
      (Environnement([])) -> []
    | (Environnement((v,c)::q)) -> 
            if c = 0 then ((v, 1)::q) 
            else ((v,0)::(getNextEnvironment (Environnement(q))))
;;

(**
 * Retourne une liste d'environnement contenant tous les environnements
 * possibles 
 *)
let getAllEnvironment = fun environnementStart ->
    let rec interne = function
        [] -> []
    |   t::q -> if t = environnementStart then t::q 
                 else (interne([(Environnement(getNextEnvironment t))]))@(t::q)
    in (interne [Environnement(getNextEnvironment(environnementStart))])
;;

(** Retourne une liste contenant chacun des environnements associé à leur valeurs *)
let evalAllEnvironment = fun expr listEnvironments ->
    let rec interne = function
      [] -> []
    | t::q -> (t, (eval expr t))::(interne q)
    in (interne listEnvironments);;

(** Retourne un couple contenant l'environnement maximal et sa valeure associée *)
let maximum = fun expr ->
    let rec interne = function
        [] -> (Environnement([]),0)
      | (a,b)::q -> 
            if b > (liaisonGetConst(interne q)) then (a,b) 
            else (interne q)
    in interne (evalAllEnvironment expr (getAllEnvironment (getEnvironmentWith0 expr))) 

(** Retourne true si l'expression peut être évaluée à 0 *)
let nullite = fun expr ->
    let environnementStart = getEnvironmentWith0 expr in ( 
    let rec interne = function
        [] -> false 
    |   t::q -> if t = environnementStart then (eval expr environnementStart) = 0
                 else if (eval expr t) =  0 then true else (interne([(Environnement(getNextEnvironment t))]))
    in (interne [Environnement(getNextEnvironment(environnementStart))])
    )
;;


(** Applique récursivement à expr la fonction passée en paramètre *)
let application = fun expr fct ->
    let rec interne = function
         Var(v) -> (fct (Var(v)))
        |Const(c) -> (fct (Const(c)))
        | Add(e1,e2) -> Add((interne e1),(interne e2))
        | Sub(e1,e2) -> Sub((interne e1),(interne e2))
        | Mul(e1,e2) -> Mul((interne e1),(interne e2))
        | Div(e1,e2) -> Div((interne e1),(interne e2))
        | Opp(e) -> Opp(interne (e))
    in (interne expr)
;;

(** Remplace une variable par son code ascii *)
let var2code = fun expr ->
    match expr with
    Var(v) -> Const(Char.code(v))
    |_ -> expr;;

(** Remplace la variable var par l'exression transfo *)
let x2exp = fun var transfo expr ->
    match expr with
    Var(v) -> if var = Var(v) then transfo else Var(v)
    |_ -> expr;;

(** Permute les expressions d'opérateurs binaires *)
let miroir = fun expr ->
    match expr with
      Add(e1,e2) -> Add(e2,e1)
    | Sub(e1,e2) -> Sub(e2,e1)
    | Mul(e1,e2) -> Mul(e2,e1)
    | Div(e1,e2) -> Div(e2,e1)
    | _ -> expr;;

(*
 * ===================
 * Tests 
 * ===================
 *)
let e1 = Add(Add(Mul(Var('x'), Const(1)), Opp(Var('y'))), Sub(Const(5), Const(7)));;
let e2 = Add(Add(Var('x'), Var('y')), Const(5));;
let e3 = Add(Add(Mul(Var('x'),Const(1)),Opp(Sub(Const(0),Var('y')))),(Sub(Const(5),Mul(Const(0),Var('z')))));;
let e4 = Mul(Var('a'), Const(3));;
let env1 = Environnement([('x',1);('y',5)]);;

print_string "— Test d'affichage\n";;
displayExpr e1;;
displayExpr e2;;
print_string "\n";;

print_string "— Test d'évaluation\n";;
displayExpr (evalWithEnvironment e1 env1);; 
print_int (eval e1 env1);;

print_string "\n";;

print_string "— Test de simplification \n";;
displayExpr (e3);;
displayExpr (simplify e3);;
displayExpr (e1);;
displayExpr (simplify e1);;
print_string "\n";;

print_string "— Test de Maximum\n";;
print_string "Next Environement : ";;
print_string "\n";;
(getAllEnvironment (Environnement([('a',0); ('b', 0);('c', 0)])));;
getEnvironmentWith0 e3;;
(evalAllEnvironment e3 (getAllEnvironment (getEnvironmentWith0 e3)));;
maximum e3;;
getEnvironmentWith0 e4;;
nullite ((Mul(Var('a'), Const(3))));;

print_string "\n— Test des applications\n";;
displayExpr e3;;
displayExpr (application e3 var2code);;
displayExpr (application e3 (x2exp (Var('x')) (Add(Var('c'),Const(3)))));;
displayExpr (application e3 miroir);;
print_string "\n";;

