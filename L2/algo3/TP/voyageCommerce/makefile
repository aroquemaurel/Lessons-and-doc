SRC=src
LIB=lib
BIN=bin
TEST=tests
CFLAGS= -Wall -g -I lib 
EXE=travellingSalesman

# Programme principal
$(EXE): $(BIN)/main.o $(BIN)/util.o $(BIN)/parsing.o $(BIN)/errors.o $(BIN)/instance.o $(BIN)/tour.o $(BIN)/town.o unitTests
	gcc -o $(EXE) $(BIN)/main.o $(BIN)/util.o $(BIN)/parsing.o $(BIN)/errors.o $(BIN)/tour.o $(BIN)/instance.o $(BIN)/town.o
$(BIN)/main.o: $(SRC)/main.c $(BIN)/parsing.o 
	gcc -o $(BIN)/main.o -c $(SRC)/main.c $(CFLAGS)
$(BIN)/util.o: $(SRC)/util.c  $(LIB)/util.h
	gcc -o $(BIN)/util.o -c $(SRC)/util.c $(CFLAGS)
$(BIN)/parsing.o: $(SRC)/parsing.c  $(LIB)/parsing.h
	gcc -o $(BIN)/parsing.o -c $(SRC)/parsing.c $(CFLAGS)
$(BIN)/errors.o: $(SRC)/errors.c $(LIB)/errors.h
	gcc -o $(BIN)/errors.o -c $(SRC)/errors.c $(CFLAGS)
$(BIN)/town.o: $(SRC)/town.c $(LIB)/town.h
	gcc -o $(BIN)/town.o -c $(SRC)/town.c $(CFLAGS)
$(BIN)/tour.o: $(SRC)/tour.c $(LIB)/tour.h $(BIN)/town.o
	gcc -o $(BIN)/tour.o -c $(SRC)/tour.c $(CFLAGS)
$(BIN)/instance.o: $(SRC)/instance.c $(LIB)/instance.h $(BIN)/town.o
	gcc -o $(BIN)/instance.o -c $(SRC)/instance.c $(CFLAGS)

# Tests unitaires de util.c
$(BIN)/mainUnitTests.o: $(TEST)/mainUnitTests.c
	gcc -o $(BIN)/mainUnitTests.o -c $(TEST)/mainUnitTests.c
$(BIN)/testUtil.o: $(TEST)/testUtil.c
	gcc -o $(BIN)/testUtil.o -c $(TEST)/testUtil.c
$(BIN)/fctTestUnitaire.o: $(TEST)/fctTestUnitaire.c
	gcc -o $(BIN)/fctTestUnitaire.o -c $(TEST)/fctTestUnitaire.c
unitTests: $(BIN)/mainUnitTests.o $(BIN)/testUtil.o $(BIN)/fctTestUnitaire.o $(BIN)/util.o $(BIN)/tour.o
	gcc -o unitTests $(BIN)/mainUnitTests.o $(BIN)/testUtil.o $(BIN)/fctTestUnitaire.o $(BIN)/util.o $(BIN)/tour.o

clean:
	rm -rfv $(BIN)/*.o

all: $(EXE) 

tarball: 
	tar -jcvf travellingSalesman.tar.bz2 ./$(BIN) ./$(TEST) ./$(EXE) ./$(LIB) ./$(SRC) makefile
