# ________________________________________________
#|
#|     Programme: TP5 nombres romains 
#|     Langage: C++
#|     Auteur: Antoine de Roquemaurel & Fabrice Valleix
#|
#|     Fichier: makefile 
#|     Date de modification: 04/05/11
#|
#|________________________________________________
CFLAGS = 
LDFLAGS =

#Nom de l'executable
EXEC = nbRomains

#Programme Principal
PP = main
#Liste des fichiers (chaque fichier correspond a un .{EXT} et un .h)
F2 = convEntierRomain
F3 = convRomainEntier

#Extensions des fichiers, elle permet également de choisir le compilateur
EXT=cpp

CP=g++

all: ${EXEC}

${EXEC}:${PP}.o ${F2}.o ${F3}.o 
	@${CP} -o ${EXEC} ${PP}.o ${F2}.o ${F3}.o 

${PP}.o: ${PP}.${EXT} 
	@${CP} -c ${PP}.${EXT} ${CFLAG}
	 
${F2}.o: ${F2}.${EXT} ${F2}.h
	@${CP} -c ${F2}.${EXT} ${CFLAG}

${F3}.o: ${F3}.${EXT} ${F3}.h ${F2}.h
	@${CP} -c ${F3}.${EXT} ${CFLAG}

#Supprim les .o
clean:
	@rm *.o

#Supprime les .o et l'executable
remove: clean
	@rm ${EXEC} 

#Recompile tout le projet
recomp: clean 
	@make
