/**********************************************************************
 * Author: Chris Thompson
 * Project Name: o2-thompson.1
 * Project Desc: Goal is to create a process fan with a variable
 *               number for an argument that reads a command or piped
 *               file from standard input.
 * Initial Commit: 30 January 2018
 * Github Repo: https://github.com/teufel0369/OS.git
 **********************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "create.h"
#include <limits.h>
#include <errno.h>

/* GLOBALS */
#define DEFAULT_LIMIT 5;

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
    
    int opt = 0;
    int pr_limit = 0;
    int pr_count = 1; /* always start off with one child process */

    
    /* check the number of arguments supplied *** must uncomment on submission */
    if(argc != 3){
        perror("\n\nproc_fan: ERROR: Incorrect number of arguments");
        print_usage_statement();
        exit(EXIT_FAILURE);
    }

    
     /*get the options from the argv array*/
    while((opt = getopt(argc, argv, "n:")) != -1){
        switch(opt){
            case 'n':
                pr_limit = atoi(optarg);
                break;
            default:
                print_usage_statement();
                exit(EXIT_FAILURE);
        }

        if(pr_limit == -1){
            print_usage_statement();
            exit(EXIT_FAILURE);
        }
    }

    const char* testLine[100];
    char** testArgs = NULL;
    char* delim = " \n";
    pid_t childPid;
    int status;
    pid_t returnPid;
    
    while(fgets(testLine, MAX_CANON, stdin)){
        childPid = fork(); /* fork some processes */
        pr_count += 1;

        /*  If pr_count is pr_limit, wait for a child to a child to finish and decrement pr_count */
        if(pr_count == pr_limit) {
            r_wait((pid_t )0);
            pr_count -= 1;
        }
        
        if(childPid == 0) { /* if this is the child process */
            if(makeargv(testLine, delim, &testArgs) == -1){
                perror("\n\nproc_fan: ERROR: failed to construct argument array");

            } else {

                /* let the child process execute the test arguments */
                if(execvp(testArgs[0], &testArgs[0])){
                    free_makeargv(testArgs);
                    exit(EXIT_SUCCESS);

                } else {
                    perror("\n\nproc_fan: ERROR: Failed to exec");
                    free_makeargv(testArgs);
                    exit(EXIT_FAILURE);
                }
            }
            exit(EXIT_FAILURE); /* Fall through for when makeargv fails */

        } else if(childPid < 0) { /* An error happened while trying to fork */
            perror("\n\nproc_fan: ERROR: You failed to fork!");
            free_makeargv(testArgs);

        } else if(childPid == (waitpid(-1, &status, WNOHANG))) { /* check to see if any child finished */
            pr_count -= 1;
            printf("\n\nProcess Count: %1d", pr_count);
        }
    }

    while(r_wait(NULL) > 0);  /* waiting for all the remaining child processes to finish */
    
    return 0;
}

/*************************************************!
 * @function    print_usage_statement
 * @abstract    Prints error and usage statement
 **************************************************/
void print_usage_statement() {
    char* error = "\n\nproc_fan: Error: You supplied an incorrect number of arguments.";
    char* usage = "\nUsage: proc_fan -n NUMBER < file.data";
    perror(error);
    perror(usage);
}


