let rec triInsertion = function ->
     [] -> []
    |t::q -> inserer t (triInsertion q)
