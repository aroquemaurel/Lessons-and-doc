let elem2Sur3= function
    un::deux::trois::[]->deux;;

let elem2sur3Bis = fun l ->
    match l with
        _::deux::_::[]->deux;;

let elem2sur3Ter = function
    _::deux::_::[]->deux
    |_ -> failwith "erreur";;

let elem2 = function
    _::deux::_::_->deux;;

let access = function
    (_::deux::_,_::_) -> deux;;

let accessBis = function
    (_,deux)::_::[] -> deux;;

