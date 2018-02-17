
#pragma once
#ifndef create_h
#define create_h

#define MAX_PROCESSES 20
#define DEFAULT_NUM_CONSUMERS 10
#define BUFFER_KEY_1 1
#define BUFFER_KEY_2 2
#define BUFFER_KEY_3 3
#define BUFFER_KEY_4 4
#define BUFFER_KEY_5 5
#define BUFFER_SIZE 50

#include  <stdio.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>

typedef struct SharedMemoryBuffers {
    int bufferSize;
    char buffer_1[50];
    char buffer_2[50];
    char buffer_3[50];
    char buffer_4[50];
    char buffer_5[50];

} Buffers;

int whoAmI(pid_t);
void free_makeargv(char**);
int makeargv(const char*, const char*, char***);
pid_t r_wait(int* stat_loc);
int detachAndRemove(int, void*);
void signalHandler(int, pid_t*, int, Buffers*, int);
pid_t* spawnConsumers(int, pid_t*);

#endif /* create_h */
