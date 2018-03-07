#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/shm.h>
#include<sys/msg.h>
#include <time.h>
#include "shared.h"

/* GLOBALS */
int childId;
int shmid;
int queueId;
SharedMemoryClock *shm;

/* DECLARATIONS */
void signalHandler(int signo);
void sendMessageToMaster(int messageType, int isDone);
void receiveMessageFromMaster(int messageType);

/*******************************************************!
 * @function    main
 * @abstract    Orchestrates the madness
 * @param       argc
 * @param       argv
 * @returns     0 if ran successfully
 *******************************************************/
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "[-]ERROR: CHILD is missing process number.\n");
        exit(EXIT_FAILURE);
    }
    childId = atoi(argv[1]);

    /* register signal handler for SIGINT */
    if (signal(SIGINT, signalHandler) == SIG_ERR) {
        perror("[-]ERROR: Failed to catch SIGTERM.\n");
        exit(errno);
    }

    /* set up the message queue */
    queueId = msgget(QUEUE_KEY, 0600);

    /* access the shared memory segment */
    if ((shmid = shmget(SHARED_MEM_KEY, sizeof(SharedMemoryClock), 0600)) < 0) {
        perror("[-]ERROR: Failed to create shared memory segment.");
        exit(errno);
    }

    /* attach the shared memory */
    shm = shmat(shmid, NULL, 0);

    srand(time(NULL));
    int runTime = (rand() % 100000)+ 1;
    int timeElapsed = 0;
    while(1) {
        receiveMessageFromMaster(childId); /* receive message from master to indicate permission to enter critical section */
        int startCriticalSection = shm->seconds * 1000000000 + shm->nanoSeconds; /* start the clock */
        sendMessageToMaster(MASTER_ID, 0); /* insert the message into the message queue */

        receiveMessageFromMaster(childId); /* removes a message from the message queue */
        int endCriticalSectionTime = shm->seconds * 1000000000 + shm->nanoSeconds; /* stop the clock */
        timeElapsed += endCriticalSectionTime - startCriticalSection; /* calculate the time elapsed */
        int isDone = (timeElapsed > runTime) ? 1 : 0;
        printf("CHILD %d Seconds: %d\tNano: %d\n", childId, shm->seconds, shm->nanoSeconds);
        sendMessageToMaster(MASTER_ID, isDone); /* insert status update into the message queue */
    }
    return 0;
}

/*******************************************************!
 * @function    signalHandler
 * @abstract    signal handler for child processes;
 *              really just an empty handler to exit to
 *              exit successfully
 * @param       signo signal number received
 *******************************************************/
void signalHandler(int signo) {
    exit(EXIT_SUCCESS);
}

/*******************************************************!
 * @function    sendMessage
 * @abstract    inserts a message into the message queue
 * @param       messageType
 * @param       isDone
 *******************************************************/
void sendMessageToMaster(int messageType, int isDone) {
    Message message;
    static int messageSize = sizeof(Message) - sizeof(long); /* calculate the size of the message to send */
    message.messageType = messageType;
    message.childId = childId;
    message.isDone = isDone;
    message.seconds = shm->seconds;
    message.nanoSeconds = shm->nanoSeconds;

    msgsnd(queueId, &message, messageSize, 0); /* insert the message into the message queue */
}

/*******************************************************!
 * @function    receiveMessage
 * @abstract    removes a message from the message queue
 * @param       messageType
 *******************************************************/
void receiveMessageFromMaster(int messageType) {
    Message message;
    static int messageSize = sizeof(Message) - sizeof(long); /* calculate the size of the message to pull */
    msgrcv(queueId, &message, messageSize, messageType, 0); /* pull the message from the message queue */
}