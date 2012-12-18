.include defTypes
.global libererChaine
.text 
.align 2

libererChaine: 
				stmfd SP, {R4,LR}
				mov R4, R0
				ldr R0, [R4, #ptrCar]
				bl Free
				MOV R0, #R0
				STR R0, [R4], #PtrCar]
				MOV R0, [#NULL]
				STR R0, [R4, #ptrCar]
				ldrmfd SP, {R4, PC}
