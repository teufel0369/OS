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
#include "common.h"

/* GLOBAL */
pid_t* pid;

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
    int c;
    int numConsumers;
    int processCount;

    if(argc != 3) {
        perror("\n\nproc_fan: ERROR: Incorrect number of arguments");
        print_usage_statement();
        exit(EXIT_FAILURE);
    }

    while ((c = getopt (argc, argv, "n:")) != -1) {
        switch(c){
            case 'n':
                numConsumers = atoi(optarg);
                break;

            default:
                print_usage_statement();
                exit(EXIT_FAILURE);
        }
    }

    const char* lineOfText[100];
    char** testArgs = NULL;
    char* delim = " \n";
    int status;


    pid = (pid_t *) malloc(sizeof(pid_t) * numConsumers);  /* allocate space for process fan */

    *pid = fork(); /* fork the producer */

    if(pid == 0) { /* if this is the producer (aka child process) */

        /* read in the text */
        while(fgets(lineOfText, MAX_CANON, stdin)){
            // Todo: read in text here and put in buffer. Allocate shared memory first.
        }

        pid = spawnConsumers(numConsumers, pid); /* spawn the process fan of consumers */

    } else if(pid < 0) {
        perror("[-]ERROR: MASTER process failed to fork the PRODUCER");
        exit(EXIT_FAILURE);
    }


}


/*************************************************!
 * @function    print_usage_statement
 * @abstract    Prints error and usage statement
 **************************************************/
void print_usage_statement() {
    char* error = "\n\nproc_fan: Error: You supplied an incorrect number of arguments.";
    char* usage = "\nUsage: master -n NUMBER < file.data";
    perror(error);
    perror(usage);
}
