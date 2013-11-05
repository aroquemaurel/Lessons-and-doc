all: moncat compiler exo4

moncat: moncat.o afficher.o util.o erreur.o
	gcc moncat.o afficher.o util.o erreur.o -o moncat 

compiler: compiler.o
	gcc compiler.o -o compiler 

exo4: exo4.o
	gcc exo4.o -o exo4

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o
	rm moncat exo3 exo4
