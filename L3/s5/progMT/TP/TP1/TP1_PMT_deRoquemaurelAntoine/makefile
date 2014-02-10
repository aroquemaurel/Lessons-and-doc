all: exe1 exe2 exe3

exe1: erreur.o exo1.o
	gcc -o exe1 erreur.o exo1.o 

exe2: erreur.o exo2.o
	gcc -o exe2 erreur.o exo2.o 

exe3: erreur.o exo3_myShell.o util.o
	gcc -o exe3 erreur.o exo3_myShell.o util.o

exo1.o: exo1.c erreur.o
	gcc -c exo1.c

exo2.o: exo2.c erreur.o
	gcc -c exo2.c

exo3_myShell.o: exo3_myShell.c erreur.o
	gcc -c exo3_myShell.c

erreur.o:erreur.c erreur.h
	gcc -c erreur.c

util.o:util.c util.h

clean: 
	rm -v *.o
	rm -v exe*
