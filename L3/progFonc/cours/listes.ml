let rec dernier = function 
     e::[] -> e
    |e::l -> dernier l
    |_ -> failwith "erreur liste vide";;

let rec longueur = function
     [] -> 0
    |e::l -> (longueur l)+1 ;;

(* somme des élémets d'un liste 
 * int list -> int 
 *)
let rec somme = function
     [] -> 0
    |t::q -> t + somme q ;;

