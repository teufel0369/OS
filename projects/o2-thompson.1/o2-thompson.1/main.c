/**********************************************************************
 * Author: Chris Thompson
 * Project Name: o2-thompson.1
 * Project Desc: Goal is to create a process fan with a variable
 *               number for an argument.
 * Initial Commit: 30 January 2018
 * Github Repo: https://github.com/teufel0369/OS
 **********************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "create.h"
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>

/* GLOBALS */
#define DEFAULT_LIMIT 5;

/* prototypes */
void print_usage_statement(void);

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @returns     0 if it runs correctly.
 **************************************************/
int main(int argc, const char* argv[]) {
    FILE* filePtr;
    
    
    int opt = 0;
    int pr_limit = DEFAULT_LIMIT;
    int pr_count = 1; // always start off with one child process

    
//     check the number of arguments supplied *** must uncomment on submission
//    if(argc != 5){
//        print_usage_statement();
//        exit(EXIT_FAILURE);
//    }
    
    
    // get the options from the argv array
    while((opt = getopt(argc, argv, ":n")) != -1){
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
    
    char testLine[100];
    char** testArgs = NULL;
    char* delim = "\n";
    int i = 0 ;
    pid_t childPid;

    /* NOTE: YOU DO NOT NEED TO READ FROM A FILE... You're reading from std input.... so just use fgets in a while loop. Don't check for !feof(fPtr).
             */
    
    while(fgets(testLine, MAX_CANON, stdin)){
        
        if(pr_count == pr_limit){
            fprintf(stderr, "Process %1d of %1d allowed", pr_count, pr_limit);
            perror("\n\nproc_fan: WARN: Hit maximum number of allowable processes");
            childPid = wait(NULL);
            pr_count -= 1;
            
        } else {
            
            childPid = fork();
            
            if(childPid == 0){
                whoAmI(childPid);
                if(makeargv(testLine, delim, &testArgs) == -1){
                    perror("\n\nproc_fan: ERROR: failed to construct argument array");

                } else {
                   // execvp(testArgs[0], &testArgs[0]);
                  // fprintf(stderr, "proc_fan: ERROR: Child %1ld failed to execute the command.",(long)getpid());
                 //  perror("");
                    free_makeargv(testArgs); /* free the memory allocated for making the argument array */
                }
                
                exit(1);
                
            } else if (childPid < 0) {
                perror("\n\nproc_fan: ERROR: You failed to fork!");
                
            } else {
                while((childPid = waitpid(-1, NULL, WNOHANG))){ /* check to see if any children finished and decrement */
                    if((childPid == -1) && (errno != EINTR)){
                        break;
                    }
                }
            }
        }
        
        while(r_wait(NULL) > 0); /* waiting for all the remaining child processes to finish */
    }
    
    return 0;
}

/*************************************************!
 * @function    print_usage_statement
 * @abstract    Prints error and usage statement
 **************************************************/
void print_usage_statement() {
    char* error = "proc_fan: Error: You supplied an incorrect number of arguments.\n";
    char* usage = "Usage: proc_fan -n NUMBER < file.data";
    perror(error);
    perror(usage);
}


