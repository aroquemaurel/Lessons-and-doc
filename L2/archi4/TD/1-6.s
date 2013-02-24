@En un minimm d'instructions calculez r0 <- 10 * r1 
@(sans utiliser la multiplication)
MOV r0,r1,LSL #3 @r0 = r1 * 2^3
@r0 <- r0 + r1 * 2^1 
@r0 <- r1 * 2^3 + r1 * 2^1
@r1 * (2^3 + 2^1)
ADD r0,r0,r1,LSL #1 

