CC=gcc
CFLAGS = -g -Wall

all: master producer consumer

master: main.o create.o
	$(CC) $(CFLAGS) -o proc_fan main.o create.o

main.o: main.c create.h
	$(CC) $(CFLAGS) -c main.c

producer: producer.o
	$(CC) $(CFLAGS) -o producer producer.o

producer.o: producer.c create.h
	$(CC) $(CFLAGS) -c producer.c

consumer: consumer.o
	$(CC) $(CGLAGS) -o consumer consumer.o

consumer.o: consumer.c create.h
	$(CC) $(CFLAGS) -c consumer.c

create.o: create.c create.h
	$(CC) $(CFLAGS) -c create.c

.PHONY: clean

clean:
	rm *.o master producer consumer

