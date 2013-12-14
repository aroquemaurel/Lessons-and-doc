let rec somme = function
     Feuille n -> n
    |Noeud(g,d) -> somme g + somme d;;

let rec consListe = function
    Feuille n -> [n] 
    |Noeud(g,d) -> (consListe g)@(consListe d);;

let rec equal = fun a1 a2 ->
    match(a1,a2) with
     (Feuille a, Feuille b) -> a = b
    |(Noeud(g1,d1), Noeud(g2,d2)) -> (equal g1 g2) && (equal d1 d2) 
    |_ -> false;;

let rec equal = fun a1 a2 ->
    match(a1,a2) with
     (Feuille a, Feuille b) -> a = b
    |(Noeud(g1,d1), Noeud(g2,d2)) -> ((equal g1 g2) && (equal d1 d2)) 
                                || ((equal g1 d2) && (equal d1 g2)) 

    |_ -> false;;


type 'a arbreNaire = Node of 'a * 'a arbreNaireList;

let rec cons = function
    Node(v,l) -> v::consInfoListe l

and consInfoListe = function
    [] -> []
    |  a::q -> (cons a)@(consInfoListe q);;

let rec position = fun etatInit action -> 
    match action
    Poser -> true
    |Lever -> false
    |seq(a1,a2) -> position (position etatInit a1) a2
    |rep(a,0) -> etatInit
    | Rep(a,nà -> position (position etatInit a)(Rep(a,n-1))
