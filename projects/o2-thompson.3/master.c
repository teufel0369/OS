/**********************************************************************
* Author: Chris Thompson
* Project Name: o2-thompson.2
* Project Desc: The goal of this project demonstrate shared memory and
*               message passing utilizing message queues.
* Initial Commit: 4 March 2018
* Github Repo: https://github.com/teufel0369/OS.git
**********************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include "shared.h"

/* GLOBAL DEFAULTS */
#define DEFAULT_NUM_CHILDREN 5
#define DEFAULT_FILENAME "data.out"
#define DEFAULT_TIME_OUT 20
#define TOTAL_PROCESSES 100

/* DECLARATIONS */
void signalHandler(int);
int detachAndRemove(int, void*);
void displayHelp(int;
int getIndex(int);

/* GLOBAL VARIABLES */
Process *pid;
int numChildren;
int shmid;
int queueId;
SharedMemoryClock *shm;
int nextNum;
int numTerminated = 0;
char filename[64];

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @param       argv    array of arguments
 * @returns     0 if it runs correctly.
 **************************************************/
int main (int argc, char **argv) {
    nextNum = 0;
    int i, waitStatus, timeoutSeconds;
    char childId[3];
    int hflag = 0;
    char *sVal = NULL;
    char *lvalue = NULL; /* because evidently lval, lVal, and lValue are all reserved by other libraries in use ??? */
    char *tVal = NULL;
    int c;

    opterr = 0;

    while ((c = getopt (argc, argv, "hs:l:t:")) != -1) {
        switch (c) {

            case 'h':
                hflag = 1;
                displayHelp(hflag);
                break;
            case 's':
                sVal = optarg;
                break;
            case 'l':
                lvalue = optarg;
                break;
            case 't':
                tVal = optarg;
                break;
            case '?':
                if (optopt == 's' || optopt == 'l' || optopt == 't')
                    fprintf (stderr, "[-]ERROR: Option -%c requires an argument.\n", optopt);
                else
                    fprintf (stderr, "[-]ERROR: Unknown Option! '%c'.\n", optopt);
                return 1;
            default:
                abort();
        }
    }

    /* check the values for null case and assign the defaults otherwise */
    numChildren = (sVal == NULL) ? DEFAULT_NUM_CHILDREN : atoi(sVal);
    timeoutSeconds = (tVal == NULL) ? DEFAULT_TIME_OUT : atoi(tVal);
    lvalue == NULL ? strcpy(filename, DEFAULT_FILENAME) : strcpy(filename, lvalue);

    /* register signal handler SIGINT */
    if (signal(SIGINT, signalHandler) == SIG_ERR) {
        perror("[-]ERROR: Failed to catch SIGINT\n");
        exit(errno);
    }

    /* register signal handler SIGALRM */
    if (signal(SIGALRM, signalHandler) == SIG_ERR) {
        perror("[-]ERROR: Failed to catch SIGALRM\n");
        exit(errno);
    }
    alarm(timeoutSeconds);

    /* Next pid index */
    nextNum = numChildren + 1;

    /* allocate space for pid array */
    pid = (Process *) malloc(sizeof(Process) * numChildren);

    /* create message queue */
    queueId = msgget(QUEUE_KEY, IPC_CREAT | 0600);

    /* create shared memory segment */
    if ((shmid = shmget(SHARED_MEM_KEY, sizeof(SharedMemoryClock), IPC_CREAT | 0600)) < 0) {
        perror("[-]ERROR: Failed to create shared memory segment");
        exit(errno);
    }

    /* attach the shared memory segment */
    shm = shmat(shmid, NULL, 0);

    /* initialize shared memory */
    shm->seconds = 0;
    shm->nanoSeconds = 0;

    /* create the array of pid objects */
    for (i = 0; i < numChildren; i++) {
        pid[i].pidIndex = i + 1;
        pid[i].actualPid = fork();

        if (pid[i].actualPid == 0) { /* if this is the child process */
            sprintf(childId, "%d", pid[i].pidIndex);
            execl("./child", "./child", childId, NULL); /* run the child executable */
        }
        else if (pid[i].actualPid < 0) {
            perror("[-]ERROR: Failed to fork CHILD process\n");
            exit(errno);
        }

    }

    /* Todo: add in critical section tomorrow. allocate some time for debugging.
     */

     /* kill all child processes */
    for (i = 0; i < numChildren; i++) {
        kill(pid[i].actualPid, SIGINT);
    }

    /* wait for all remaining children */
    while (wait(&waitStatus) > 0) { ; }

    if(shm->seconds >= 2)
        printf("[-]MASTER: TERMINATION --> shared clock exceeded 2 seconds\n");
    if (numTerminated >= TOTAL_PROCESSES)
        printf("[-]MASTER: TERMINATION -->  %d processes executed\n", TOTAL_PROCESSES);

    /* free up the remaining resources and detach and remove all shared memory. */
    free(pid);
    detachAndRemove(shmid, shm);
    msgctl(queueId, IPC_RMID, NULL);

    return 0;
}

/*************************************************!
 * @function    detachAndRemove
 * @abstract
 * @param       pidIndex index of the pidIndex
 * @returns     actual index from the pid array
 * @cite        Unix Systems Programming Pg. 528
 **************************************************/
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

/*******************************************************!
 * @function    signalHandler
 * @abstract    performs all necessary signal handling
 *
 * @param       pidIndex index of the pidIndex
 * @returns     actual index from the pid array
 *******************************************************/
void signalHandler(int signo) {
    int i, wait_status;

    if (signo == SIGINT || signo == SIGALRM) {
        signo == SIGINT ? printf("[-]WARN: SIGINT detected by MASTER.\n") :
        printf("[-]WARN: SIGALRM detected by MASTER.\n");

        /* sendMessage signal to all childs */
        for (i = 0; i < numChildren; i++) {
            kill(pid[i].actualPid, SIGINT);
        }

        /* Wait for all child processes to finish */
        while (wait(&wait_status) > 0) { ; }

        /* free other resources then exit */
        free(pid);
        detachAndRemove(shmid, shm);
        msgctl(queueId, IPC_RMID, NULL);
        exit(EXIT_SUCCESS);
    }
}

/*************************************************!
 * @function    getIndex
 * @abstract    displays a help message if the
 *              the flag is 1
 * @param       hflag
 **************************************************/
void displayHelp(int hflag) {
    if (hflag == 1) {
        printf("Options\n");
        printf("\t-h          : Display this message.\n");
        printf("\t-s x        : Set max slave to 'x'. Defaults to '%d'.\n", DEFAULT_NUM_CHILDREN);
        printf("\t-l filename : Set file to 'filename'. Defaults to '%s'.\n", DEFAULT_FILENAME);
        printf("\t-t z        : Set time (in seconds) before master terminates. Defaults to '%d'.\n", DEFAULT_TIME_OUT);
        exit(0);
    }
}

/*************************************************!
 * @function    getIndex
 * @abstract    get the index from the array of
 *              children... it'll be useful
 * @param       pidIndex index of the pidIndex
 * @returns     actual index from the pid array
 **************************************************/
int getIndex(int pidIndex) {
    int i;
    for(i = 0; i < numChildren; i++)
        if(pid[i].pidIndex == pidIndex)
            return i;

    return -1;
}