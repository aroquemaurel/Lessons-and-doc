CFLAGS=-Wall

tests: pileDynamique.o pileStatique.o pileStatique.o tests.o pileMixte.o
	gcc -o tests pileDynamique.o pileStatique.o pileMixte.o tests.o ${CFLAGS}

pileDynamique.o: pileDynamique.c pileDynamique.h
	gcc -c pileDynamique.c ${CFLAGS}
	
pileStatique.o: pileStatique.c pileStatique.h
	gcc -c pileStatique.c ${CFLAGS}
	
pileMixte.o: pileMixte.c pileMixte.h
	gcc -c pileMixte.c ${CFLAGS}

tests.o: tests.c
	gcc -c tests.c ${CFLAGS}

clean: 
	rm *o
	rm tests

all: clean tests

