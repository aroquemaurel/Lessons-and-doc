prg: file.o arbreGRB.o main.o
	gcc file.o arbreGRB.o main.o -o prg 

test: file.o arbreGRB.o test.o
	gcc file.o arbreGRB.o test.o -o test

file.o: file.c file.h
	gcc -c file.c

arbreGRB.o: arbreGRB.c arbreGRB.h
	gcc -c arbreGRB.c

main.o: main.c
	gcc -c main.c

test.o: test.c
	gcc -c test.c --std=c99
clean: 
	rm *o
