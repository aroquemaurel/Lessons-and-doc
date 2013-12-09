(* == Fonctions auxiliaires == *)

(* Prend en paramètre une liste de couple et retourne une liste
 * contenant le premier élément de chaque couples *)
let rec listFirstElems = function 
[] -> []
|(a,_)::q -> a::(listFirstElems q);;

let rec listSecondElems = function
[] -> []
|(_,a)::q -> a::(listSecondElems q);;

(* Retourne vrai si elem appartient à la liste liste*)
let rec appartient = fun elem liste ->
    match liste with
     [] -> false
    |t::q -> t = elem || (appartient elem q);;

(* Retourne le premier élement d'un couple *)
let firstElem = function (a,b) -> a;;

(* Retourne le second élement d'un couple *)
let secondElem = function (a,b) -> b;;

(* Fonction auxiliaire de produit faisant le produit entre un couple et une
 * fonction. La fonction produit quant-à elle utilise cette fonction afin de
 * faire le produit entre deux fonctions *)
let rec produitAux = fun couple fct ->
    match fct with
         [] -> []
        |t::q -> (((firstElem couple), (firstElem t)), ((secondElem couple), (secondElem t)))::(produitAux couple q);;

(* Compte le nombre d'élément d'une liste *)
let rec nbElems = function
         [] -> 0
        |t::q -> (nbElems q)+1;;


(* === Fonctions demandées == *)

(* -- estFonction --
 * Vérifie que la liste des premiers éléments ne contient pas de duplication. *)
let estFonction = fun listCouple ->
    let rec noDoublon = function
         [] -> true
        |t::q -> not (appartient t q ) && (noDoublon q)
    in noDoublon (listFirstElems listCouple);;

(* -- image --
 * Étant donnés un élément et une liste de couples retourne la
 * valeur associée à l'élément si elle existe. *)
let image = fun elem ->
    let rec imageRec = function
         [] -> failwith "La valeur n'est pas dans l'intervalle"
        |t::q -> if (firstElem t) = elem then (secondElem t) else imageRec q
    in imageRec;;


(* -- imageEns --
 * étant données une liste d’éléments L et une liste de couples (représentant une fonction f) retourne la liste des valeurs associées 
 * à chaque élément de L.
 *)
let rec imageEns = fun listeCouple liste ->
    match liste with
     [] -> []
    |t::q -> (image t listeCouple)::(imageEns listeCouple q);;

(* --estInjective --
 * appliquée à une fonction f représentée par une liste de couples, vérifie que 2 éléments n’ont pas la même image.*)
let estInjective = fun listCouple ->
    let rec noDoublon = function
         [] -> true
        |t::q -> not (appartient t q ) && (noDoublon q)
    in noDoublon (listSecondElems listCouple);;

(* -- surcharge --
 * Fonction prenant 2 listes représentant les fonctions f1 et f2, et retournant une liste 
 * représentant la fonction f définie sur l’union des domaines de définition de f1 et f2, 
 * et dont l’image d’un élément est donné soit par f1, soit par f2, en donnant priorité à f2.
 *)
let rec surcharge = fun f1 f2 ->
    match (f1,f2) with
         ([],[]) -> []
        |([],t::q) -> t::q
        |(t::q, []) -> t::q
        |(t1::q1, t2::q2) -> 
                if not (appartient (firstElem t1) (listFirstElems (t2::q2)))
                then t1::(surcharge q1 (t2::q2))
                else (surcharge q1 (t2::q2)) ;;


(* --composition--
 * Fonction composition, prenant 2 listes représentant les fonctions f1 et
 * f2, et retournant une liste représentant la fonction f dont l’image d’un
 * élément est donné par f1 appliquée à l’image par f2 de cet élément.
 *)
let composition = fun f1 f2 ->
    let rec aux = function 
        [] -> []
        |t::q -> if (appartient (firstElem t) (listFirstElems f2)) &&
                    (appartient (image (firstElem t) f2) (listFirstElems f1))
                then ((firstElem t),(image (image (firstElem t) (f2)) f1))::aux q
                else aux q
    in aux f1
;;

(* -- produit --
 * Prend en argument 2 listes représentant 2 fonctions f1 et f2, et retourne la liste 
 * représentant la fonction qui à un couple (x,y) associe le couple (f1 x, f2 y).
*) 
let produit = fun f1 f2 ->
        let rec fctAux = function
             [] -> []
            |t::q -> (produitAux t f2)@(fctAux q)
        in fctAux f1 ;;


