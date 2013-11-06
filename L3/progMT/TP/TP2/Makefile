all: moncat compiler monps 

moncat: moncat.o afficher.o util.o erreur.o
	gcc moncat.o afficher.o util.o erreur.o -o moncat 

compiler: compiler.o
	gcc compiler.o -o compiler 

monps: monps.o
	gcc monps.o -o monps 

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o
	rm moncat compiler monps 
