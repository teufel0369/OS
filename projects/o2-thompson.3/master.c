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
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <time.h>
#include <string.h>
#include "shared.h"

/* GLOBAL DEFAULTS */
#define DEFAULT_NUM_CHILDREN 5
#define DEFAULT_FILENAME "data.out"
#define DEFAULT_TIME_OUT 20
#define TOTAL_PROCESSES 100

/* GLOBAL VARIABLES */
ProcessType* pid;
int numChildren;
int shmid;
int queueId;
SharedMemoryClockType *shm;
int nextNum;
int numTerminated = 0;
char filename[64];

/* DECLARATIONS */
void signalHandler(int);
int detachAndRemove(int, void*);
void displayHelp(int);
int getIndex(int);
void sendMessageToChild(int);
void receiveMessageFromChild(int);

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
    pid = (ProcessType* ) malloc(sizeof(ProcessType) * numChildren);

    /* create message queue */
    queueId = msgget(QUEUE_KEY, IPC_CREAT | 0600);

    /* create shared memory segment */
    if ((shmid = shmget(SHARED_MEM_KEY, sizeof(SharedMemoryClockType), IPC_CREAT | 0600)) < 0) {
        perror("[-]ERROR: Failed to create shared memory segment");
        exit(errno);
    }

    /* attach the shared memory segment */
    shm = shmat(shmid, NULL, 0);

    /* initialize shared memory */
    shm->seconds = 0;
    shm->nanoSeconds = 0;

    for (i = 0; i < numChildren; i++) {
        if((pid[i].actualPid = fork()) == 0) {
            printf("CHILD %d", getpid());
            exit(EXIT_SUCCESS);
        } else if(pid[i].actualPid < 0) {
            perror("failed to fork");
        } else if (pid[i].actualPid > 0) {
            printf("PPID: ", getpid());
            exit(EXIT_SUCCESS);
        }
    }

//    /* create the array of pid objects */
//    for (i = 0; i < numChildren; i++) {
//        pid[i].pidIndex = i + 1;
//        pid[i].actualPid = fork();
//
//        if (pid[i].actualPid == 0) {  /*if this is the child process*/
//            sprintf(childId, "%d", pid[i].pidIndex);
//            char* childId = (char*) &pid[i].pidIndex;
//            execl("child", ".//child", childId, NULL);  /*run the child executable*/
//            break;
//        }
//        else if (pid[i].actualPid < 0) {
//            perror("[-]ERROR: Failed to fork CHILD process\n");
//            exit(errno);
//        }
//    }

//    while (shm->seconds < 2 && numTerminated < TOTAL_PROCESSES) {
//        int i;
//        for(i = 0; i < numChildren; i++) {
//            if(pid[i].pidIndex != -1) { /* if this is not the parent */
//                sendMessageToChild(pid[i].pidIndex); /* send message to notify critical section is free */
//                receiveMessageFromChild(MASTER_ID);  /* receive WAIT for child to enter */
//                sendMessageToChild(pid[i].pidIndex); /* send ok to run */
//                receiveMessageFromChild(MASTER_ID); /* receive WAIT for child to unlock or terminate */
//            }
//        }
//    }

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
        detachAndRemove(shmid, shm); /* detach and remove all shared memory */
        msgctl(queueId, IPC_RMID, NULL); /* deallocate the message queue... kind of important to do */
        exit(EXIT_SUCCESS);
    }
}

/*************************************************!
 * @function    displayHelp
 * @abstract    displays a help message if the
 *              the flag is 1
 * @param       hflag
 **************************************************/
void displayHelp(int hflag) {
    if (hflag == 1) {
        printf("Options\n");
        printf("\t-h          : Display this message.\n");
        printf("\t-s x        : Set number of children to 'x'. Defaults to '%d'.\n", DEFAULT_NUM_CHILDREN);
        printf("\t-l filename : Set file to 'filename'. Defaults to '%s'.\n", DEFAULT_FILENAME);
        printf("\t-t z        : Set time (in seconds) before master terminates. Defaults to '%d'.\n", DEFAULT_TIME_OUT);
        exit(0);
    }
}

/*************************************************!
 * @function    getIndex
 * @abstract    get the index from the array of
 *              children.
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

/*************************************************!
 * @function    receiveMessageFromChild
 * @abstract    get the index from the array of
 *              children... it'll be useful
 * @param       pidIndex index of the pidIndex
 * @returns     actual index from the pid array
 **************************************************/
void receiveMessageFromChild(int messageType) {
    FILE *fp;
    MessageType message;
    static int messageSize = sizeof(MessageType) - sizeof(long); /* calculate the message size to receive */
    msgrcv(QUEUE_KEY, &message, messageSize, messageType, 0); /* receive the message */

    srand(time(NULL));
    int runtime = (rand() % 10001)+ 1;

    shm->nanoSeconds += runtime;
    if(shm->nanoSeconds > 1000000000){
        ++(shm->seconds);
        shm->nanoSeconds -= 1000000000;
    }

    if (message.isDone) {  /* if the message is done being received */
        int index = getIndex(message.childId); /* get the index of the child array to kill off later */

        kill(pid[index].actualPid, SIGINT); /* send the signal to kill the transmitting child  */
        int status;

        waitpid(pid[index].actualPid, &status, 0); /* wait for the process to finish */
        numTerminated++;

        if (nextNum <= TOTAL_PROCESSES) { /* if we haven't hit the max allowable processes */

            pid[index].pidIndex = nextNum++;
            pid[index].actualPid = fork(); /* fork another child and increment the index (not actual) */

            if (pid[index].actualPid == 0) {  /* if this is the child */
                char* childId = (char*) &pid[index].pidIndex;
                execl("/child", "./child", childId, NULL); /* execute */
            }
            else if (pid[index].actualPid < 0) {
                perror("[-]ERROR: Failed to fork CHILD process\n");
                exit(errno);
            } else {
                perror("I'm the parent");
            }
        }
        else {
            pid[index].pidIndex = -1; /* because we don't want to  */
        }

        /* print the message to file */
        fp = fopen(filename, "a");
        fprintf(fp, "MASTER: CHILD pid %d is terminating at my time %d.%d because it reached %d, which lived for time %d\n",
                message.childId, shm->seconds, shm->nanoSeconds, message.seconds, message.nanoSeconds);
        fclose(fp);
    }
}

/*************************************************!
 * @function    getIndex
 * @abstract    get the index from the array of
 *              children... it'll be useful
 * @param       pidIndex index of the pidIndex
 * @returns     actual index from the pid array
 **************************************************/
void sendMessageToChild(int messageType) {
    MessageType message;
    static int messageSize = sizeof(MessageType) - sizeof(long);
    message.messageType = messageType;
    msgsnd(queueId, &message, messageSize, 0);
}
