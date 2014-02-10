(* compte le nombe d'occurences de l'élément dans la liste *)
let rec nbOcc e l ->
    match l with 
     [] -> 0
    |t::q -> if t = e then (nbOcc e q)+1 else nbOccc e q;;

(* Le e ne bouge pas durant l'appel récursif. Il peut être intéressant donc de
 * ne pas le passe systématiquement *)
let nbOccBis = fun e ->
    let rec compte = fun l ->
        match with
             [] -> 0
            |t::q -> if t = e then 1 + compte q else compte q
    in compte;;
        
