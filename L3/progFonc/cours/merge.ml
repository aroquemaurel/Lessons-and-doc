let rec merge = fun l1 l2 ->
    match (l1,l2) with
    ([], l) -> l
    [(l,[]) -> l
    |(t1:q1,t2:q2) -> if t1 < t2 then t1::merge q1(t2::q2) else t2::merge q2(t1::q1)
