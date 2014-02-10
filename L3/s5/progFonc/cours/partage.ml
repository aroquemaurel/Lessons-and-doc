let rec partage = function l ->
    [] -> ([],[]) (* liste vide *)
    |t::[] -> (t::[], []) (* liste à un élément *)
    |p::d::q ->let(l1,l2)=partage q in (p::l1,d::l2)
