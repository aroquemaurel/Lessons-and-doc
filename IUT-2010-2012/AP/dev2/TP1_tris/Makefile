usage:
	@echo
	@echo taper \"make all\" pour compiler tous les tris
	@echo ou
	@echo taper \"make triBulles\" pour compiler le tri a bulles
	@echo taper \"make triPivot\" pour compiler le tri rapide
	@echo taper \"make triShell\" pour compiler le tri Shell
	@echo

all: triBulles triPivot triShell

triBulles: triBulles.o tableau.o
	g++ -c triBulles.C tableau.C ; g++ -o triBulles triBulles.o tableau.o

triBulles.o: triBulles.C tableau.h
	g++ -c -g triBulles.C

triPivot: triPivot.o tableau.o
	g++ -c triPivot.C tableau.C ; g++ -o triPivot triPivot.o tableau.o

triPivot.o: triPivot.C tableau.h
	g++ -c -g triPivot.C

triShell: triShell.o tableau.o
	g++ -c triShell.C tableau.C ; g++ -o triShell triShell.o tableau.o

triShell.o: triShell.C tableau.h
	g++ -c -g triShell.C

triSelection: triSelection.o tableau.o
	g++ -c triSelection.C tableau.C ; g++ -o triSelection triSelection.o tableau.o

triSelection.o: triSelection.C tableau.h
	g++ -c -g triSelection.C

tableau.o: tableau.C tableau.h
	g++ -c -g tableau.C

clean:
	rm -f *.o triBulles triPivot triShell

