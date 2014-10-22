FLAGS=--std=c99 -pedantic

all: v1 v3 v4

v1: exo1.c
	gcc exo1.c -o v1 $(FLAGS)

v3: exo1-3.c
	gcc exo1-3.c -o v3 $(FLAGS)

v4: exo1-4.c
	gcc exo1-4.c -o v4 $(FLAGS)

clean:
	rm v1 v3 v4
