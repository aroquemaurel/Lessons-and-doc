#makefile pile 
CC=gcc
OPT=-Wall -g
EXEC=hanoi 
all : $(EXEC)
#compile elt_pile
elt_pile.o: elt_pile.c
	$(CC) -o elt_pile.o -c elt_pile.c $(OPT)
#compile pile
pile.o: pile.c
	$(CC) -o pile.o -c pile.c $(OPT)

#compile main
main.o : main.c
	$(CC) -o main.o -c main.c $(OPT)

plateau.o : plateau.c
	$(CC) -o plateau.o -c plateau.c $(OPT)

#link elt_pile,pile et main

$(EXEC): elt_pile.o pile.o main.o plateau.o
	$(CC) elt_pile.o pile.o main.o plateau.o -o $(EXEC)

clean:
	rm -rf *.o *.exe *.out $(EXEC)

