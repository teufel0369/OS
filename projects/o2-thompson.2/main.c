/**********************************************************************
* Author: Chris Thompson
* Project Name: o2-thompson.2
* Project Desc: The goal of this project is to simulate
*               the writing of logs using shared memory
*               and concurrent processes.
* Initial Commit: 30 January 2018
* Github Repo: https://github.com/teufel0369/OS.git
**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/shm.h>
#include <limits.h>
#include <stdbool.h>
#include "common.h"

/* prototypes */
void print_usage_statement(void);

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @param       argv    array of arguments
 * @returns     0 if it runs correctly.
 **************************************************/
int main(int argc, const char* argv[]) {

    Buffer sharedMemory[5];
    Buffer* sharedMem = &sharedMemory;
    pid_t producer;
    pid_t consumer;
    char** testArgs = NULL;
    char* delim = " \n";
    const char* lineOfText[100];
    int status;
    int k;
    int numConsumers;
    int processCount;
    int i;

    /* check the number of arguments */
    if(argc != 3) {
        perror("\n[-]ERROR: Incorrect number of arguments");
        print_usage_statement();
        exit(EXIT_FAILURE);
    }

    /* get the arguments from getopt */
    while ((k = getopt (argc, argv, "n:")) != -1) {
        switch(k){
            case 'n':
                numConsumers = atoi(optarg);
                break;

            default:
                numConsumers = 10;
                break;
        }
    }

    /* Register the signal handler for SIGINT and SIG_ERR events */
    registerSignalHandler();

    if((producer = fork()) < 0) {
        perror("[-]ERROR: MASTER failed to fork PRODUCER");
        exit(EXIT_FAILURE);
    } else if (producer == 0){
        whoAmI(producer);
    }

    for(i = 0; i < numConsumers; i++) {
        if((consumer = fork()) < 0) {
            perror("[-]ERROR: MASTER failed to fork CONSUMER");
            exit(EXIT_FAILURE);

        } else {
            whoAmI(consumer);
            break;
        }
    }


    while(r_wait(NULL) > 0); /* wait for all remaining children to finish execution */
}


/*************************************************!
 * @function    print_usage_statement
 * @abstract    Prints error and usage statement
 **************************************************/
void print_usage_statement() {
    char* error = "\n\n[-]Error: You supplied an incorrect number of arguments.";
    char* usage = "\n[-]Usage: master -n NUMBER < file.data";
    perror(error);
    perror(usage);
}
