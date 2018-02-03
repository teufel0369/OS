#ifndef create_h
#define create_h

#include  <stdio.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>

void createProcesses(int);
void free_makeargv(char**);
int makeargv(const char*, const char*, char***);

#endif /* create_h */
