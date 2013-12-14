all: client httpServer

client: client.o util.o
	gcc client.o util.o -o client

httpServer: 
	javac httpserver/*.java 

client.o: client.c
	gcc -c client.c
	
util.o: util.c
	gcc -c util.c

clean:
	rm *.o client
	rm httpserver/*class
