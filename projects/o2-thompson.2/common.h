#ifndef create_h
#define create_h

#include  <stdio.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>
#include <stdbool.h>

typedef struct SharedMemory {
    char buffer[50];
    int flag;
    int sharedMemoryId;
    key_t key;

} Buffer;

int whoAmI(pid_t);
void free_makeargv(char**);
int makeargv(const char*, const char*, char***);
pid_t r_wait(int* stat_loc);
int detachAndRemove(int, void*);
void signalHandler(int, pid_t*, int, int);
pid_t* spawnConsumers(int, pid_t*);
Buffer * generateSharedMemory(int, Buffer[]);
void registerSignalHandler();


#endif /* create_h */
