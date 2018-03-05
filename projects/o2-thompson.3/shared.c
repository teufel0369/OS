#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include "shared.h"

void displayHelpOptions() {
    printf("Options\n");
    printf("\t-h          : Display this message.\n");
    printf("\t-s x        : Set max slave to 'x'. Defaults to '%d'.\n", DEFAULT_MAX_CHILDREN);
    printf("\t-l filename : Set file to 'filename'. Defaults to '%s'.\n", DEFAULT_FILENAME);
    printf("\t-t z        : Set time (in seconds) before master terminates. Defaults to '%d'.\n", DEFAULT_TIMER_SECS);
    exit(0);
}

// detachandremove function from textbook example 15.11
int detachAndRemove(int shmid, void *shmaddr) {
    int error = 0;

    if (shmdt(shmaddr) == -1)
        error = errno;
    if ((shmctl(shmid, IPC_RMID, NULL) == -1) && !error)
        error = errno;
    if (!error)
        return 0;
    errno = error;
    return -1;
}

void masterSignalHandler(int signo) {
    int i, wait_status;

    if (signo == SIGINT || signo == SIGALRM) {
        if (signo == SIGINT)
            printf("Master senses SIGINT\n");
        else
            printf("Master senses SIGALRM\n");

        // Send signal to all slaves
        for (i = 0; i < maxChildren; i++) {
            kill(pid[i].literal, SIGINT);
        }

        // Wait for all slave processes to finish
        while (wait(&wait_status) > 0) { ; }

        // Free other resources then exit
        free(pid);
        detachAndRemove(shmid, shm);
        msgctl(qid, IPC_RMID, NULL);
        exit(0);
    }
}
