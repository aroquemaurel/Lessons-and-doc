all: exe1 exe2 exe3

exe1: erreur.o 1.o
	gcc -o exe1 erreur.o 1.o 

exe2: erreur.o 2.o
	gcc -o exe2 erreur.o 2.o 

exe3: erreur.o 3.o util.o
	gcc -o exe3 erreur.o 3.o util.o

1.o: 1.c erreur.o
	gcc -c 1.c

2.o: 2.c erreur.o
	gcc -c 2.c

3.o: 3.c erreur.o
	gcc -c 3.c

erreur.o:erreur.c erreur.h
	gcc -c erreur.c

util.o:util.c util.h

clean: 
	rm -v *.o
	rm -v exe*
