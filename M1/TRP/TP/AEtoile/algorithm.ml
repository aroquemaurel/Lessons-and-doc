#use "graphes.ml";;
open List;;


let estBut e = estBut1 e;;
let etatsSuivants e = etatsSuivants1 e;;
let opPoss  = opPoss1;;


let rec print_list_string (l : string list) : unit = 
	match l with
	  [] -> print_endline "."
	| t::q -> begin print_string (t ^ " "); (print_list_string q) end
	;;
let rec contains (value : 'a) (l : 'a list) = 
	match l with
	 [] -> false
    |t::q -> if t = value then true else (contains value q)
    ;;
		
let rec profondeurBeta (la : string list) : string = 
begin
print_list_string la;
match la with
	[] -> failwith "Pas de solution"
	| t::q -> if estBut t then t 
			  else (profondeurBeta ((etatsSuivants t)@q))
end			  
;;

let rec merge (l1 : 'a list) (l2 : 'a list) =
	match l1 with
	 [] -> l2
	| [t] -> if not(contains t l2) then t::l2 else l2
	| t::q -> if not(contains t l2) then merge q (t::l2) 
			  else merge q l2
			  ;;
	
	
let rec profondeurBetaVus (la : string list)
						  (vus : string list) : string = 
begin
print_list_string la;
match la with
	[] -> failwith "Pas de solution"
	| t::q -> if estBut t then t
              else 
                  if (contains t vus) then (profondeurBetaVus q (vus))
                  else (profondeurBetaVus ((etatsSuivants t)@q) (t::vus))
end			  
;;

let getEtat (triplet : string * char list * int) = 	
    match triplet with
    (e,_,_) -> e;;
	
let getChemin (triplet : string * char list * int) = 	
    match triplet with
    (_,c,_) -> c;;

let getCout (triplet : string * char list * int) = 	
    match triplet with
    (_,_,c) -> c;;

let getStates (views: 'a list) (etat: string) 
                    : (char * string * int) list
                = filter(fun(_, element, _) -> not(mem element views)) (opPoss (etat));;

let rec profondeur  (queue: ('a*('b list)*'c) list) 
                    (views: 'a list) 
                    :('a*('b list)*'c)
 = match(queue) with
	 [] -> ("",[],0)
    | (e::t) -> if(estBut (getEtat e)) then e 
                else let newStates = (getStates views (getEtat e)) in 
                    profondeur ((map (fun((a,b,c))->(b,(a::(getChemin e)),(c+(getCout e)))) newStates )@t)
                               ((map (fun((a,b,c))->b) newStates)@views);; 
(* Algo du A* : *  Quadriplet, avec en plus h(x) l'estimation : (X, [b d f], 8, 11) *  Ajouter getG et getH
 *
 *  Insérer un quadriplet au bon endroit dans la liste : la liste doit toujours
 *  être parfaitement triée par f + h.
 *
 *  Insérer une liste au bon endroit dans la liste d'attente.
 *
 *  Si g+h egaux, alors le h le plus petit en premier.
 *
 *  à la place du @, utiliser la fonction d'insertino
 *)

let getG (quadriplet : string * char list * int * int) : int = 
    match quadriplet with
    (_,_,g,_) -> g;;

let getH (quadriplet : string * char list * int * int) : int = 
    match quadriplet with
    (_,_,_,h) -> h;;

let quadripletComp  (q1 :string * char list * int * int) 
                     (q2 :string * char list * int * int)
                     : int = 
    if ((getH q1) + (getG q1)) < ((getG q2) + (getH q2)) then
        -1
    else if((getH q1) + (getG q1)) > ((getG q2) + (getH q2)) then
        1
    else 0
;;
let rec insert  (value : (string * char list * int * int))
                (list: (string * char list * int * int)list) = 
    match list with
     [] -> [value]
    |t::q ->    if (quadripletComp t value) < 0 then value::t::q 
                else if (quadripletComp t value) = 0 then 
                    if (getH value) < (getH t) then
                        value::t::q
                    else
                        t::value::q
                else
                    insert value q
;;
