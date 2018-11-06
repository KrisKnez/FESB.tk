CC = gcc
CFLAGS = -Wall
TARGETS = citaj

default: citaj

citaj: citaj.o
	$(CC) $(CFLAGS) citaj.o -o citaj

citaj.o: citaj.c
	$(CC) $(CFLAGS) citaj.c -c

.c.o:
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -f $(TARGETS) *.o *~ a.out