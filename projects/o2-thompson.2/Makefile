CC=gcc
CFLAGS = -lrt -g -Wall

all: master producer consumer

master: main.o common.o
	$(CC) $(CFLAGS) -o proc_fan main.o common.o

main.o: main.c common.h
	$(CC) $(CFLAGS) -c main.c

producer: producer.o
	$(CC) $(CFLAGS) -o producer producer.o

producer.o: producer.c common.h
	$(CC) $(CFLAGS) -c producer.c

consumer: consumer.o
	$(CC) $(CGLAGS) -o consumer consumer.o

consumer.o: consumer.c common.h
	$(CC) $(CFLAGS) -c consumer.c

common.o: common.c common.h
	$(CC) $(CFLAGS) -c common.c

.PHONY: clean

clean:
	rm *.o master producer consumer

