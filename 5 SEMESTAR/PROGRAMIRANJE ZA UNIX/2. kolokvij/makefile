CC = gcc
CFLAGS = -Wall
TARGETS = pokreni

default: pokreni

pokreni: pokreni.o
	$(CC) $(CFLAGS) pokreni.o -o pokreni

pokreni.o: pokreni.c
	$(CC) $(CFLAGS) pokreni.c -c

.c.o:
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(TARGETS) *.o *~ a.out