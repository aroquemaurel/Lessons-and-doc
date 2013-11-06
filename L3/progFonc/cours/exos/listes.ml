- : int list = [1; 2; 3]
# 1::[2;3];r
- : int list = [1; 2; 3]
# 1::(1*2)::[2+1];;
- : int list = [1; 2; 3]
# 1::2::3::[];;
- : int list = [1; 2; 3]
# (2=3-1)::(1<2)::false::[];;
- : bool list = [true; true; false]
# 1.5::(2.5::(3::[]));;
Error: This expression has type int but an expression was expected of type float
# [1,2,3];;
- : (int * int * int) list = [(1, 2, 3)]
# [[1];[2];[3;4];[]];;
- : int list list = [[1]; [2]; [3; 4]; []]
# [[1];[2.5];[3;4];[]];;
 Error: This expression has type float but an expression was expected of type int
# [1;true];;
 Error: This expression has type bool but an expression was expected of type int
# [1,true];;
- : (int * bool) list = [(1, true)]
# [[1;2];[];3;4];;   
 Error: This expression has type int but an expression was expected of type int list
# [1]::[];;
 - : int list list = [[1]]
# []::[];;
 - : 'a list list = [[]]
# [1]::[[2;3];[4]];; 
 - : int list list = [[1]; [2; 3]; [4]]
