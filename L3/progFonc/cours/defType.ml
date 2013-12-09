typeDcl ::=
        type typeParam idType = 
            type | typeUnion
        typeUnion ::= IdConst [of type] | ...
        type ::= int | bool | ... | 'ident |
        (type * ... * type) | type -> type |
        (type, ..., type=idType |
        type idType | idType
        typePara ::= ('ident, ..., 'ident) | | 'ident
