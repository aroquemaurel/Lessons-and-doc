type m3 = Zero|Un|Deux;;

let m3s = function
    Zero -> Un
    |Un -> Deux
    |Deux -> Zero;;

let m3plus = function a b ->
    match a with
    Zero -> b
    |Un -> m3s b
    |Deux -> m3s (m3s b);;

let m3mult = function a b ->
    match a with
    Zero -> Zero 
    |Un -> b
    |Deux -> m3plus y y;;

type exp = Const of m3|Produit expression*expression|Somme expression*expression;;

let e1 = Const Un;;
let e2 = Somme (Const Deux, Produit(Const(Un) Const(Deux)));;
