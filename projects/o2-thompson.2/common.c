#include "common.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include <signal.h>
#include <stdbool.h>

/*************************************************!
 * @function    free_makeargv
 *
 * @abstract    frees the memory of the arg array
 *              that was allocated by makeargv()
 *
 * @param       argv    number of arguments.
 * @citation    pg. 38 Unix Systems Programming
 *
 **************************************************/
void free_makeargv(char** argv){
    if(argv == NULL) { return; }
    if(*argv != NULL) { free(*argv); }
    free(argv);
}

/*************************************************!
 * @function    makeargv
 *
 * @abstract    orchestrates the madness
 *
 * @param       s            number of arguments
 * @param       delims       delimiters
 *
 * @returns     numTokens    number of tokens
 *
 * @citation    pg. 37 Unix Systems Programming
 **************************************************/
int makeargv(const char* s, const char* delims, char*** argvp) {
    int error;
    int i;
    int numTokens;
    const char* startNewString;
    char* t = NULL;
    
    if((s == NULL) || (delims == NULL) || (argvp == NULL)){
        errno = EINVAL;
        return -1;
    }
    
    *argvp = NULL;
    startNewString = s + strspn(s, delims); 
    
    if((t = malloc(strlen(startNewString) + 1)) == NULL) { return -1; }
    
    strcpy(t, startNewString);
    numTokens = 0;

    if(strtok(t, delims) != NULL){
        for(numTokens = 1; strtok(NULL, delims) != NULL; numTokens++);
    }
    
    // count the number of tokens in s
    if((*argvp = malloc((numTokens + 1) * sizeof(char*))) == NULL){
        error = errno;
        free(t);
        errno = error;
        return -1;
    }
    
    // insert pointers into the arg array
    if(numTokens == 0) {
        free(t);
    } else {
        strcpy(t, startNewString);
        **argvp = strtok(t, delims);
        
        for(i = 1; i < numTokens; i++){
            *((*argvp) + i) = strtok(NULL, delims);
        }
    }
    
    *((*argvp) + numTokens) = NULL; // final NULL pointer
    return numTokens;
}

/*************************************************!
 * @function    r_wait
 *
 * @abstract    waits but doesn't block
 *
 * @param       stat_loc    return status
 *
 * @citation    pg. 72 Unix Systems Programming
 **************************************************/
pid_t r_wait(int* stat_loc){
    int retval;
    
    while(((retval = wait(stat_loc)) == -1) && (errno == EINTR));
    return retval;
}

int whoAmI(pid_t pid){
    if(pid == 0) {
        printf("Child %d  My Parent is %d \n\n", getpid(), getppid());
    } else if(pid > 0){
        printf("Parent %d \n\n", getpid());
    }
    
    return 1;
}

/*************************************************!
 * @function    detachAndRemove
 *
 * @abstract    detaches the shared memory segment
 *              and then removes the shared memory
 *              segment specified by its ID
 *
 * @param       shmid    shared memory ID
 * @param       shmaddr  shared memory address
 *
 * @citation    pg. 528 Unix Systems Programming
 **************************************************/
int detachAndRemove(int shmid, void* shmaddr) {
    int error = 0;

    if(shmdt(shmaddr) == -1) {
        error = errno;
    }

    if((shmctl(shmid, IPC_RMID, NULL) == -1) && !error) {
        error = errno;
    }

    if(!error)
        return 0;

    return -1;
}

/*************************************************!
 * @function    signalHandler
 *
 * @abstract    signal handler that sends kill
 *              signal to all children, waits
 *              for them to terminate, and then
 *              frees up the shared memory
 *
 * @param       signal    signal received
 * @param       pid       process ID
 * @param       shMemId   shared memory ID
 * @param       shm       shared data structure
 **************************************************/
void signalHandler(int signal, pid_t* pid, int shMemId, int numProcesses) {
    int i, wait_status;

    if (signal == SIGINT || signal == SIGALRM) {
        if (signal == SIGINT)
            printf("MASTER detected SIGINT\n");
        else
            printf("MASTER detected SIGALRM\n");

        /* send the KILL signal to all processes */
        for (i = 0; i < numProcesses; i++) {
            kill(pid[i], SIGINT);
        }

        /* wait for remaining processes to finish */
        while (wait(&wait_status) > 0) { ; }

        /* Free other resources then exit */
        free(pid);
        detachAndRemove(shMemId, signal);
        exit(EXIT_SUCCESS);
    }
}

/****************************************************************!
 * @function    spawnConsumers
 *
 * @abstract    creates a process fan of consumers
 *
 * @param       numConsumers    number of processes to spawn
 * @param       pid             process ID pointer
 *
 * @returns     process fan if ran successfully
 ****************************************************************/
pid_t* spawnConsumers(int numConsumers, pid_t* pid) {
    int i;

    for (i = 0; i < numConsumers; i++) {
        pid[i] = fork();

        if(pid < 0) {
            perror("[-]ERROR: PRODUCER process failed to fork the CONSUMER process");
            exit(EXIT_FAILURE);
        }
    }

    return pid;
}

/****************************************************************!
 * @function    generateSharedMemory
 *
 * @abstract    creates an x number of sharedMemory
 *
 * @param       numBuffers    number of processes to spawn
 * @param       sharedMemory  shared memory pointer
 *
 * @returns     array of structs if ran successfully
 ****************************************************************/
Buffer* generateSharedMemory(int numBuffers, Buffer* sharedMemory) {
    int i = 0;
    int id;
    int key = 101;
    Buffer* buffer = NULL;

//    for(i = 0; i < numBuffers; i++) {
//
//        if((id = shmget(key, sizeof(Buffer), )))
//    }

    return buffer;
}