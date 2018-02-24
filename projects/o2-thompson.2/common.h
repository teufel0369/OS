
#pragma once
#ifndef create_h
#define create_h

#define MAX_PROCESSES 20
#define DEFAULT_NUM_CONSUMERS 10
#define TEST_NUM_CONSUMERS 4
#define DEFAULT_NUM_BUFFERS 5
#define BUFFER_KEY_1 101
#define BUFFER_KEY_2 102
#define BUFFER_KEY_3 103
#define BUFFER_KEY_4 104
#define BUFFER_KEY_5 105
#define BUFFER_SIZE 50

#include  <stdio.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>
#include <stdbool.h>

typedef struct SharedMemory {
    char buffer[50];
    bool flag;
} Buffer;


int whoAmI(pid_t);
void free_makeargv(char**);
int makeargv(const char*, const char*, char***);
pid_t r_wait(int* stat_loc);
int detachAndRemove(int, void*);
void signalHandler(int, pid_t*, int, int);
pid_t* spawnConsumers(int, pid_t*);
Buffer* generateSharedMemory(int, Buffer*);


#endif /* create_h */
