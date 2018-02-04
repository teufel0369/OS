#ifndef create_h
#define create_h

#include  <stdio.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>

void createProcesses(pid_t, char[], char**, char*, int, int);
void free_makeargv(char**);
int makeargv(const char*, const char*, char***);
pid_t r_wait(int* stat_loc);

#endif /* create_h */
