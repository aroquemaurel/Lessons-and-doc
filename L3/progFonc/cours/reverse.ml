(* Renvoie la liste constuite à l'envers *)
let rec reverse = function
     [] -> [] 
    |t::q ->  (reverse q)@t::[] ;;
