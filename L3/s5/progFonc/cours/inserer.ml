let rec inserer -> fun e l ->
    match l with
    [] -> e::[] 
    |t::q -> if e < t then e::t::q else t::inserer e q;;
