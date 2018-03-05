/**********************************************************************
* Author: Chris Thompson
* Project Name: o2-thompson.2
* Project Desc: The goal of this project is to simulate
*               the writing of logs using shared memory
*               and concurrent processes.
* Initial Commit: March 3rd, 2018
* Github Repo: https://github.com/teufel0369/OS.git
**********************************************************************/

#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <memory.h>
#include "shared.h"

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @param       argv    array of arguments
 * @returns     0 if it runs correctly.
 **************************************************/

int main(int argc, const char* argv[]) {

    int i, waitStatus, numSeconds;
    char slave_id[3];
    char *svalue = NULL;
    char *lvalue = NULL;
    char *tvalue = NULL;
    int c;

    opterr = 0;

    // Process command line options
    while ((c = getopt (argc, argv, "hs:l:t:")) != -1) {
        switch (c) {
            case 'h':
                displayHelpOptions();
                break;
            case 's':
                svalue = optarg;
                break;
            case 'l':
                lvalue = optarg;
                break;
            case 't':
                tvalue = optarg;
                break;
            case '?':
                if (optopt == 's' || optopt == 'l' || optopt == 't')
                    fprintf (stderr, "[-]ERROR: Option -%c requires an argument.\n", optopt);
                else
                    fprintf (stderr, "[-]ERROR: Unknown option character '%c'.\n", optopt);
                return 1;
            default:
                abort();
        }
    }

    // Set parameters
    maxChildren = (svalue == NULL) ? DEFAULT_MAX_CHILDREN : atoi(svalue);
    numSeconds = (tvalue == NULL) ? DEFAULT_TIMER_SECS : atoi(tvalue);
    if (lvalue == NULL)
        strcpy(filename, DEFAULT_FILENAME);
    else
        strcpy(filename, lvalue);

    /* allocate space for array of Processes */
    pid = (Process *) malloc(sizeof(Process) * maxChildren);

    /* register signal handler for SIGINT */
    if (signal(SIGINT, masterSignalHandler) == SIG_ERR) {
        perror("Error: Couldn't catch SIGINT\n");
        exit(errno);
    }

    /*  */
    if (signal(SIGALRM, masterSignalHandler) == SIG_ERR) {
        perror("Error: Couldn't catch SIGALRM\n");
        exit(errno);
    }
    alarm(numSeconds);
}