CFLAGS = 
LDFLAGS =

#Nom de l'executable
EXEC = agendaCli

#Programme Principal
PP = clientAgenda
#Liste des fichiers (chaque fichier correspond a un .{EXT} et un .h)
F2 = evenement
F3 = agenda

#Extensions des fichiers, elle permet également de choisir le compilateur
EXT=cpp

#Si on utilise du C++, alors le compilo est g++
ifeq (${EXT}, cpp) 
	CP=g++
endif

#Si on utilise du C alors le compilo est gcc
ifeq (${EXT}, c)
	CP=gcc
endif 

all: ${EXEC}

${EXEC}:${PP}.o ${F2}.o ${F3}.o
	 @${CP} -o ${EXEC} ${PP}.o ${F2}.o 

${PP}.o: ${PP}.${EXT} ${F2}.h ${F3}.h
	@${CP} -o ${PP}.o -c ${PP}.${EXT} ${CFLAG}
	 
${F2}.o: ${F2}.${EXT} ${F2}.h
	@${CP} -o ${F2}.o -c ${F2}.${EXT} ${CFLAG}

${F3}.o: ${F3}.${EXT} ${F3}.h
	@${CP} -o ${F3}.o -c ${F3}.${EXT} ${CFLAG}

#Supprim les .o
clean:
	rm *.o

remove: clean
	rm ${EXEC} 
