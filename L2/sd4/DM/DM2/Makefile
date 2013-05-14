exe: main.o arn.o arnPrive.o noeud.o
	gcc -o exe main.o arn.o arnPrive.o noeud.o

main.o: main.c
	gcc -c main.c

arn.o: arn.c arn.h arnPrive.o couleur.h
	gcc -c arn.c

noeud.o: noeud.c noeud.h couleur.h
	gcc -c noeud.c

arnPrive.o: arnPrive.c arnPrive.h couleur.h
	gcc -c arnPrive.c

dot: exe
	./scriptDot.sh arbreRougeNoir_dot/fichier
	
clean: 
	rm -v *.o
