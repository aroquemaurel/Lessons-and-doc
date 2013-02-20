@R0 <- R2 + R2*4
@ Attention, MUL R3,R2,#4 n'est pas possible
MOV R0,#4
MUL R0,R2,R0
ADD R0,R2,R0
