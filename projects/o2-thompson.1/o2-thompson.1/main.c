/**********************************************************************
 * Author: Chris Thompson
 * Project Name: o2-thompson.1
 * Project Desc: Goal is to create a process fan with a variable
 *               number for an argument that reads a command or piped
 *               file from standard input.
 * Initial Commit: 30 January 2018
 * Github Repo: https://github.com/teufel0369/OS
 **********************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "create.h"
#include <limits.h>

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
    int pr_limit = DEFAULT_LIMIT;
    int pr_count = 1; // always start off with one child process

    
    /* check the number of arguments supplied *** must uncomment on submission */
   /* if(argc != 3){
        perror("proc_fan: ERROR: Incorrect number of arguments");
        print_usage_statement();
        exit(EXIT_FAILURE);
    }*/

    
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

    const char* testLine[100]; /* **** NOTE: When this migrates to hoare, it may blow up because of this **** */
    char** testArgs = NULL;
    char* delim = "\n";
    pid_t childPid;
    
    while(fgets(testLine, MAX_CANON, stdin)){
        childPid = fork(); /* fork some processes */
        
        /*  If pr_count is pr_limit, wait for a child to a child to finish and decrement pr_count */
        if(pr_count == pr_limit) {
            perror("\n\nproc_fan: WARN: Hit maximum number of allowable processes");
            r_wait(NULL);
            pr_count -= 1;
        }

        pr_count += 1;
        
        if(childPid == 0) { /* if this is the child process */
            if(makeargv(testLine, delim, &testArgs) == -1){
                perror("\n\nproc_fan: ERROR: failed to construct argument array");
                exit(EXIT_FAILURE); /* Fall through for when makeargv fails */

            } else {
                whoAmI(childPid);
                sleep(1);
                fprintf(stderr, "%s printed by Child %1ld. Forked from Parent %1ld \n\n", testArgs[0], (long)getpid(), (long)getppid());
//                free_makeargv(testArgs);
//                exit(EXIT_SUCCESS);

                if(execvp(testArgs[0], &testArgs[0])){
                    perror("proc_fan: ERROR: Failed to exec");
                    free_makeargv(testArgs);
                    exit(EXIT_SUCCESS);

                } else {
                    fprintf(stderr, "proc_fan: ERROR: Child %1ld failed to execute the command.",(long)getpid());
                    perror("");
                    free_makeargv(testArgs);
                    exit(EXIT_FAILURE);
                }
            }

        } else if(childPid < 0) { /* An error happened while trying to fork */
            perror("\n\nproc_fan: ERROR: You failed to fork!");
            free_makeargv(testArgs);
            
        } else {  /* This is the parent */
            if(waitpid(-1, NULL, WNOHANG)){
                pr_count -= 1;
            }
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
    char* error = "proc_fan: Error: You supplied an incorrect number of arguments.\n";
    char* usage = "Usage: proc_fan -n NUMBER < file.data";
    perror(error);
    perror(usage);
}


