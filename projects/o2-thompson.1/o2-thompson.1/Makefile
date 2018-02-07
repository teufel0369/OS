CC=gcc
CFLAGS = -g -Wall

HEADERS=create.h
SOURCE=create.c main.c
OBJECTS=$(SOURCE:.c=.o)
EXECUTABLE=proc_fan

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c $(HEADERS)
$(CC) -c $(CFLAGS) $*.c -o $*.o

.PHONY: clean

clean:
rm *.o $(EXECUTABLE)

