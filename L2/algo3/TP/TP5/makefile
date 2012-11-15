main: main.o element.o pile.o
	gcc -o main main.o element.o pile.o

main.o: main.c element.h
	gcc -o main.o -c main.c

element.o: element.c element.h
	gcc -o element.o -c element.c

pile.o: pile.c pile.h
	gcc -o pile.o -c pile.c

clean:
	rm -rfv *.o

all: main
