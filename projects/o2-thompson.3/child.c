#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include "shared.h"

/* GLOBALS */
int childId;
int shmid;
int queueId;
SharedMemoryClock *shm;

/* DECLARATIONS */
void signalHandler(int signo);
void sendMessage(int messageType, int isDone);
void receive(int mtype);

/*******************************************************!
 * @function    main
 * @abstract    Orchestrates the madness
 * @param       argc
 * @param       argv
 * @returns     0 if ran successfully
 *******************************************************/
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "[-]ERROR: Missing process number.\n");
        exit(EXIT_FAILURE);
    }
    childId = atoi(argv[1]);

    /* register signal handler for SIGINT */
    if (signal(SIGINT, signalHandler) == SIG_ERR) {
        perror("[-]ERROR: Failed to catch SIGTERM.\n");
        exit(errno);
    }

    /* get the message queue */
    queueId = msgget(QUEUE_KEY, 0600);

    /* access the shared memory segment */
    if ((shmid = shmget(SHARED_MEM_KEY, sizeof(SharedMemoryClock), 0600)) < 0) {
        perror("Error: shmget");
        exit(errno);
    }

    /* attach the shared memory */
    shm = shmat(shmid, NULL, 0);

    /* Todo: add in critical section. allocate some time for debugging */

    return 0;
}

/*******************************************************!
 * @function    signalHandler
 * @abstract    signal handler for child processes
 * @param       signo signal number received
 *******************************************************/
void signalHandler(int signo) {
    exit(EXIT_SUCCESS);
}

/*******************************************************!
 * @function    sendMessage
 * @abstract    inserts a message into the messae queue
 * @param       messageType
 * @param       isDone
 *******************************************************/
void sendMessage(int messageType, int isDone) {
    Message message;
    static int msgs = sizeof(Message) - sizeof(long);
    message.messageType = messageType;
    message.childId = childId;
    message.isDone = isDone;
    message.seconds = shm->seconds;
    message.nanoSeconds = shm->nanoSeconds;

    msgsnd(queueId, &message, msgs, 0);
}

/*******************************************************!
 * @function    receiveMessage
 * @abstract    removes a message from the message queue
 * @param       messageType
 *******************************************************/
void receiveMessage(int messageType) {
    Message message;
    static int msgs = sizeof(Message) - sizeof(long);
    msgrcv(queueId, &message, msgs, messageType, 0);
}