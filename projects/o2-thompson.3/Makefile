CC=gcc
CFLAGS = -g -Wall

all: master child

master: main.o shared.o
	$(CC) $(CFLAGS) -o master main.o shared.o

main.o: main.c shared.h
	$(CC) $(CFLAGS) -c main.c

child: child.o
	$(CC) $(CGLAGS) -o child child.o

child.o: child.c shared.h
	$(CC) $(CFLAGS) -c child.c

shared.o: shared.c shared.h
	$(CC) $(CFLAGS) -c shared.c

.PHONY: clean

clean:
	rm *.o master child

