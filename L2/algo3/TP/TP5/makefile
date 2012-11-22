SRC=src/
LIB=lib/
BIN=bin/
CFLAGS= -Wall -g -I../   #on va chercher eventuellement des headers dans le dossier parent

main: $(BIN)main.o $(BIN)element.o $(BIN)pile.o
	gcc -o main $(SRC)main.o $(BIN)element.o $(BIN)pile.o $(CFLAGS)

$(BIN)main.o: $(SRC)main.c $(LIB)element.h
	gcc -o $(BIN)main.o -c $(SRC)/main.c $(CFLAGS)

$(BIN)element.o: $(SRC)element.c $(LIB)element.h
	gcc -o $(BIN)element.o -c $(SRC)element.c $(CFLAGS)

$(BIN)pile.o: $(SRC)pile.c $(LIB)pile.h
	gcc -o $(BIN)pile.o -c $(SRC)pile.c $(CFLAGS)

clean:
	rm -rfv $(BIN)*.o

all: main

