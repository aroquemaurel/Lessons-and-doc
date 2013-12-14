all: exo1 exo2 exo2_sigaction exo3 mailer

exo1: exo1.o
	gcc exo1.o -o exo1 

exo2: exo2.o
	gcc exo2.o -o exo2

exo2_sigaction: exo2_sigaction.o
	gcc exo2_sigaction.o -o exo2_sigaction

exo3: exo3.o
	gcc exo3.o -o exo3 

mailer: mailer.o
	gcc mailer.o -o mailer
	
%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm *.o
	rm exo1 exo2 exo2_sigaction exo3 
