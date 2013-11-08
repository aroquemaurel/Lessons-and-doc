all: client server

client: client.o util.o
	gcc client.o util.o -o client

server: server.o
	gcc server.o -o sever

client.o: client.c
	gcc -c client.c

server.o: server.c util.o
	gcc -c server.c

util.o: util.c util.h
	gcc -c util.c

clean:
	rm *.o client server
