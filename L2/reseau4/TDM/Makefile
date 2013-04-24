CC=gcc
SYS= -Wall -DUNIX -I.
BIN=bin
SL0=sl0
SL1=sl1
SL2=sl2
SL3=sl3
OBJ_COMMON=$(BIN)/physique.o $(BIN)/couche_liaison.o

OBJ_LSAP0=$(SL0)/$(BIN)/service_liaison0.o
OBJ_LSAP1=$(SL1)/$(BIN)/service_liaison1.o
OBJ_LSAP2=$(SL2)/$(BIN)/service_liaison2.o
OBJ_LSAP3=$(SL3)/$(BIN)/service_liaison3.o

OBJ_ENVOIE=$(BIN)/emetteur.o
OBJ_RECOIT=$(BIN)/recepteur.o
OBJ_ENVOIE_CONNECT=$(BIN)/sl3/emetteur.o
OBJ_RECOIT_CONNECT=$(BIN)/sl3/recepteur.o

PRG=emetteur recepteur

all: sl0 sl1 sl2 sl3

# Pas de controle de flux, ni reprise sur erreurs
sl0: $(OBJ_COMMON) $(OBJ_LSAP0) $(OBJ_ENVOIE) $(OBJ_RECOIT)
	$(CC) -o emetteurSl0 $(OBJ_COMMON) $(OBJ_LSAP0) $(OBJ_ENVOIE)
	$(CC) -o recepteurSl0 $(OBJ_COMMON) $(OBJ_LSAP0) $(OBJ_RECOIT)

# Controle de flux S&W
sl1: $(OBJ_COMMON) $(OBJ_LSAP1) $(OBJ_ENVOIE) $(OBJ_RECOIT)
	$(CC) -o emetteurSl1 $(OBJ_COMMON) $(OBJ_LSAP1) $(OBJ_ENVOIE)
	$(CC) -o recepteurSl1 $(OBJ_COMMON) $(OBJ_LSAP1) $(OBJ_RECOIT)	

# Controle de flux et reprise sur erreur S&W PAR (non connecté)
sl2: $(OBJ_COMMON) $(OBJ_LSAP2) $(OBJ_ENVOIE) $(OBJ_RECOIT)
	$(CC) -o emetteurSl2 $(OBJ_COMMON) $(OBJ_LSAP2) $(OBJ_ENVOIE)
	$(CC) -o recepteurSl2 $(OBJ_COMMON) $(OBJ_LSAP2) $(OBJ_RECOIT)	

sl3: $(OBJ_COMMON) $(OBJ_LSAP3) $(SL3)/$(OBJ_ENVOIE) $(SL3)/$(OBJ_RECOIT)
	$(CC) -o emetteurSl3 $(OBJ_COMMON) $(OBJ_LSAP3) $(SL3)/$(OBJ_ENVOIE)
	$(CC) -o recepteurSl3 $(OBJ_COMMON) $(OBJ_LSAP3) $(SL3)/$(OBJ_RECOIT)

# Fenetre d'anticipation
# ...
$(BIN)/%.o: %.c
	$(CC) -o $@ -c $< $(SYS)
	
sl0/$(BIN)/%.o: sl0/%.c
	$(CC) -o $@ -c $< $(SYS)
sl1/$(BIN)/%.o: sl1/%.c
	$(CC) -o $@ -c $< $(SYS)
sl2/$(BIN)/%.o: sl2/%.c
	$(CC) -o $@ -c $< $(SYS)
sl3/$(BIN)/%.o: sl3/%.c
	$(CC) -o $@ -c $< $(SYS)


clean:
	rm bin/*.o
	for i in 0 1 2 3;\
	do\
		rm sl$$i/bin/*.o;\
	done

realclean: clean
	rm -f $(PRG) *~ out.*

