let rec trierFusion = fun l ->
    let (l1,l2) = partage l
    in matchh (l1,l2) with
        ([],l) ->l
        | (l,[]) -> l
        |_ -> merge (trierFusion l1) (trierFusion l2);;
