let rec elim = fun e -> fun l ->
    match l with
     [] -> []
    | t::q -> if t = e then elim e q else (t::elim e q)
