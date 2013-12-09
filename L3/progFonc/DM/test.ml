open ListFonction

let setEq s1 s2 = 
    List.for_all (fun e -> List.mem e s2) s1 &&
    List.for_all (fun e -> List.mem e s1) s2;;

let unordListEq s1 s2 =
    List.sort compare s1 = List.sort compare s2;;

(* Fonction auxiliaires *)
let exemple = [(1,3);(2,5);(3,7);(4,9);(5,11)];;
let exempleSucc = [	(1,2);(2,3);(3,4);(4,5);(5,6);(6,7);(7,8);(8,9);(9,10);
				(10,11);(11,12);(12,13)];;
let exempleDouble = [(1,2);(2,4);(3,6);(4,8);(5,10);(6,12)];;

let id x = x
let succ x = x+1
let succ2 x = x+2
let min x = x-1
let dbl x = 2*x
let tpl x = 3*x
let dbl_succ x = 2*x+1
let trpl_succ x = 3*x+1

(* création de liste représetnant une fonction *)
let toFunction f n =
    let rec aux acc i =
        if i <= 0 then
            acc
        else
            aux ((i,f i)::acc) (i-1)
    in aux [] n
;;


let okko i res =
    if res then
        Printf.printf "mTest #%d: OKm\n" i
    else
        Printf.printf "mTest #%d: KOm\n" i
;;

let iteri f l =
   let rec aux i = function
   | [] -> ()
   | a::l -> f i a; aux (i+1) l
   in aux 0 l
;;

let testAFunction nom_function function_true list_true function_false list_false =
    Printf.printf "\nmTest de %sm\n" nom_function;
    if list_true <> [] then
        (Printf.printf "Correctness tests\n";
        iteri function_true list_true);
    if list_false <> [] then
        (Printf.printf "Wrongness tests\n";
        iteri function_false list_false)
;;
    
(* Test estFunction *)
let testtrue = [ exemple;
                 [1,2;3,4;5,7];
                 [1,2;3,4;5,7;4,7]
               ]
and testfalse = [ [1,2;3,4;5,7;3,7];
                ] in
testAFunction "estFunction"
    (fun i t -> okko i (estFonction t)) testtrue
    (fun i t -> okko i (not (estFonction t))) testfalse;
;;

(* Test image *)
let testtrue = [ (2, 5, exemple);
                 (3, 4, exempleSucc);
                 (1, 3, toFunction succ2 3);
                 (3, 5, toFunction succ2 3);
               ]
and testfalse = [ (0, 5, exemple);
                  (-1, 7, toFunction (fun x -> x) 3);
                  (6, 8, exemple);
                  (15, 0, exempleSucc);
                  (3, 5, exempleSucc);
                  (1, 33, toFunction succ2 3);
                ] in
testAFunction "Image" 
              (fun i (v,r,l) -> okko i (try r = image v l with _ -> false)) testtrue
              (fun i (v,r,l) -> okko i (try r <> image v l with _ -> true)) testfalse
;;

(* Test imageEns *)
let testtrue = [ [1;2;3;4], [2;3;4;5], toFunction succ 6;
                 [2;5;8], [7;16;25], toFunction trpl_succ 9;
               ]
and testfalse = [
                 [2;5;8], [7;16;25], toFunction trpl_succ 6;
                 [2;5], [3;4], toFunction id 6 ;
                ] in
testAFunction "imageEns"
    (fun i (v,r,l) -> okko i (try setEq r (imageEns l v) with _ -> false)) testtrue
    (fun i (v,r,l) -> okko i (try not (setEq r (imageEns l v)) with _ -> true)) testfalse
;;

(* Test estInjective*)

let testtrue = [ toFunction succ 6;
                 toFunction tpl 10;
                 toFunction min 4;
               ]
and testfalse = [ toFunction (fun x -> x mod 3) 7;
                  toFunction (fun x -> if x = 3 || x = 4 then 7 else id x) 4;
                ] in
testAFunction "estInjective"
    (fun i l -> okko i (estInjective l)) testtrue
    (fun i l -> okko i (not(estInjective l))) testfalse;
;;

(* Test surcharge *)
let testtrue = [ toFunction id 3, toFunction succ 6, [1,2;2,3;3,4;4,5;5,6;6,7];
                 toFunction succ 4, List.tl (List.tl (toFunction dbl 4)), [1,2; 2,3; 3,6; 4,8];
               ]
and testfalse = [
                ] in
testAFunction "surcharge"
    (fun i (l,m,r) -> okko i (unordListEq r (surcharge l m))) testtrue
    (fun i (l,m,r) -> okko i (not (unordListEq r (surcharge l m)))) testfalse;
;;

(* test composition *)
let testtrue = [ toFunction id 8, toFunction succ 3, toFunction succ 3;
                 toFunction succ 8, toFunction dbl 4, toFunction dbl_succ 4;
                 toFunction id 4, [],[];
                  [],[],[];
               ]
and testfalse = [ toFunction id 3, toFunction id 4, [];
                  [], toFunction id 3, toFunction id 3;
                ] in
testAFunction "composition"
    (fun i (f,g,r) -> okko i (try unordListEq r (composition f g) with _ -> false)) testtrue
    (fun i (f,g,r) -> okko i (try not (unordListEq r (composition f g)) with _-> true)) testfalse;
;;

(* Test produit *)
let testtrue = [ toFunction id 3, toFunction succ 3,
                    [((1, 1), (1, 2)); ((1, 2), (1, 3)); ((1, 3), (1, 4)); ((2, 1), (2, 2));
                     ((2, 2), (2, 3)); ((2, 3), (2, 4)); ((3, 1), (3, 2)); ((3, 2), (3, 3));
                     ((3, 3), (3, 4))];
                 toFunction id 3, [], [];
                 [], toFunction id 3, [];
                 toFunction dbl 3, toFunction succ 5, 
                    [((1, 1), (2, 2)); ((1, 2), (2, 3)); ((1, 3), (2, 4)); ((1, 4), (2, 5));
                     ((1, 5), (2, 6)); ((2, 1), (4, 2)); ((2, 2), (4, 3)); ((2, 3), (4, 4));
                     ((2, 4), (4, 5)); ((2, 5), (4, 6)); ((3, 1), (6, 2)); ((3, 2), (6, 3));
                     ((3, 3), (6, 4)); ((3, 4), (6, 5)); ((3, 5), (6, 6))];
                 toFunction dbl 6, toFunction succ 3, 
                    [((1, 1), (2, 2)); ((1, 2), (2, 3)); ((1, 3), (2, 4)); ((2, 1), (4, 2));
                     ((2, 2), (4, 3)); ((2, 3), (4, 4)); ((3, 1), (6, 2)); ((3, 2), (6, 3));
                     ((3, 3), (6, 4)); ((4, 1), (8, 2)); ((4, 2), (8, 3)); ((4, 3), (8, 4));
                     ((5, 1), (10, 2)); ((5, 2), (10, 3)); ((5, 3), (10, 4)); ((6, 1), (12, 2));
                     ((6, 2), (12, 3)); ((6, 3), (12, 4))];
               ] in
testAFunction "produit"
    (fun i (f,g,r) -> okko i (try unordListEq r (produit f g) with _ -> false)) testtrue
    (fun _ _  -> () ) [] (* pas (encore?) de wrongness test *)
;;

