CC=gcc
CFLAGS = -g -Wall

all: proc_fan testsim

proc_fan: main.o create.o
	$(CC) $(CFLAGS) -o proc_fan main.o create.o

main.o: main.c create.h
	$(CC) $(CFLAGS) -c main.c

create.o: create.c create.h
	$(CC) $(CFLAGS) -c create.c

testsim: test-sim_main.o
	$(CC) $(CFLAGS) -o testsim test-sim_main.o

test-sim_main.o: test-sim_main.c
	$(CC) $(CFLAGS) -c test-sim_main.c

.PHONY: clean

clean:
	rm *.o proc_fan testsim

