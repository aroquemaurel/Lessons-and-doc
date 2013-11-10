all: client 

client: client.o util.o
	gcc client.o util.o -o client

client.o: client.c
	gcc -c client.c

util.o: util.c util.h
	gcc -c util.c

clean:
	rm *.o client 
