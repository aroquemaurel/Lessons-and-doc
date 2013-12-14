type figure =  Sphere of int
             | Cube of int
             | Pyramide of int;;

type mobile = Figure of figure
             |Tige of (int*mobile)*(int*mobile);;

let s = Figure(Sphere 1);;
let p = Figure(Pyramide 1);;
let c = Figure(Cube 1);;
let m1 = Figure((2,p), 
                (4, Tige ((3, S), 
                          (4, c))));;

(* Compte le nombre de sphère dans le mobile passé en argument *)
let rec nbSphere = function
      Figure(Sphere _) -> 1
    | Figure(_) -> 0
    | Tige((_, m1)(_,m2)) -> (nbSphere m1) + (nbSphere m2);;

let max = fun x y -> if x > y then x else y ;;

(* Calcul la hauteur d'un mobile *)
let rec hauteur = function
     Figure(_) -> 0
    | Tige((_, m1)(_,m2)) -> 1 + max (hauteur mobile1) (hauteur mobile2);; 
             
(* Fonction echanger qui étant donnés un mobile et deux figures f1 et f2
 * construit un mobile en remplacant partout dans le mobile la figrue f1 par f2
 *)
let rec echanger = fun m f1 f2 ->
    match m with
     Figure (f) -> if f = f1 then Figure (f2) else Figure (f1)
    |Tige((l1,m1)(l2,m2)) -> Tige ((l1, echanger (m1 f1 f2)), (l2, echanger (m2 f1 f2)));;
    

(* fonction listeFigures qui étant donné un mobile construit la lite de toutes
 * les figures du mobile *)
let rec listeFigures = function
      Figure(f) -> [f]
    | Tige((_,m1),(_,m2)) -> (listeFigures m1)@(listeFigures m2);;

(* Ecrire les fonctions masseFigure et la fonction masseMobile qu calculent
 * respectivement la masse d'une figure et d'un mobile. On ignore la masse des
 * fils et des tiges*)
let masseFigure -> fun fig
    let volumeFigure = function
        Shpere r -> 4./.3. *. 3.1416 *.(float_of_int r)** 3.0
        |Cube c -> (float_of_int c) ** 3.0
        |Pyramide h -> 1./.2 *. (float_of_int) ** 3.0
    in 7.8 *. volumeFigure fig;; (* Densité de l'objet => permet de retourner la masse *)

let rec masseMobile = function
        Figure(f) -> masseFigure f
        |Tige((_,m1),(_,m2)) -> (masseMobile m1) +. (masseMobile m2);;

(* Fonction equilibreLocal qui détermine si un mobile est localement équilibré *)
let equilibreLocal = function
         Figure(_) -> true
        |Tige((l1,m1),(l2,m2)) -> ((masseMobile m1) *. float_of_int(l1)) = ((masseMobile m2) *. (float_of_int(l2)));; 

(* Un mobile est dit globalement équilibré si tous les mobiles qu'il contient
 * sont localement équilibrés. *)
let rec equilibreGlobal = fun m ->
    match m with
         Figure(f) -> true
        |Tige((l1,m1),(l2,m2)) -> (equilibreGlobal m1) && (equilibreGlobal m2) && (equilibreLocal m);;

(* Deux mobiles sont équivalents s'ils sont égaux ou si on peut les rendre égaux
 * à la suite d'une série de rotation de 180° d'une ou plusieurs tiges
 * horizontales *)
let rec equivalent = fun m1 m2 ->
        Fig(fig1,Fig(fig2)) -> fig1 = fig2
        | Tige((lg1,mg1),(ld1,md1)),Tige((lg2,mg2),(ld2,md2)) -> l1 = l2 && l1 = l2 &&
            equivalent mg1 mg2 && equilibreLocal md1 md2 or (lg1 = ld2 && ld1 = lg2
            && equivalent mg1 md2 && equivalent md1 mg2)
        |_ -> false
;;
