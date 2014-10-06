#use "graphes.ml";;


let estBut e = estBut2 e;;
let etatsSuivants e = etatsSuivants2 e;;
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
let getTriplet (op : (char * string * int) list) : (string * char list * int) = 
    match op with
     [] -> []
    |t::q -> ;;
let rec profondeur (la : (string  * char list * int) list) : (string * char list * int) = 
    match la with
	 [] -> failwith "Pas de solution"
	| t::q -> if estBut (getEtat t) then t 
			  else (* opPoss (getEtat t) *)
;;
