VRAI	 .equ 1
FAUX	 .equ 0 
TAILLE	 .equ 1000
		 .bss 
		 .align 2
tab		 .space 4 * TAILLE
n		 .space 4
else	 .space	4
rang	 .space 4
trouve	 .space	1
		 .text

.pTab	 .word	tab
.pN		 .word	n
.pEle	 .word	ele
.pRang	 .word	rang
.pTrouve .word	trouve

