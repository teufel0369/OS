
#pragma once
#ifndef create_h
#define create_h

#define MAX_PROCESSES 20
#define DEFAULT_CONSUMERS 10
#define shm_key 24331


#include  <stdio.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>

typedef struct SharedMemory {
    int bufferSize;
    char buffer_1[50];
    char buffer_2[50];
    char buffer_3[50];
    char buffer_4[50];
    char buffer_5[50];

} sharedMemory;

int whoAmI(pid_t);
void free_makeargv(char**);
int makeargv(const char*, const char*, char***);
pid_t r_wait(int* stat_loc);
int detachAndRemove(int, void*);
void signalHandler(int, pid_t*, int, sharedMemory*, int);
pid_t* spawnConsumers(int, pid_t*);

#endif /* create_h */
