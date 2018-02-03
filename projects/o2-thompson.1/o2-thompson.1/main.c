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

// GLOBALS (if any)

// prototypes
void print_usage_statement(void);

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @returns     0 if it runs correctly.
 **************************************************/
int main(int argc, const char* argv[]) {
    FILE* filePtr;
    char testData[10000];
    int opt = 0;
    int pr_limit = 0;
    int pr_count = 0;
    
    // open the file
    filePtr = fopen(argv[4], "r");
    if(filePtr == NULL){
        perror("proc_fan: Error: Failed to open the file");
        exit(EXIT_FAILURE);
    }
    
    // check the number of arguments supplied
    if(argc != 5){
        print_usage_statement();
        exit(EXIT_FAILURE);
    }
    
    // get the options from the argv array
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
    
    // read in the file of test data
    // feof checks the end of the file
    while(!feof(filePtr)) {
        
    
    // 1) if pr_count = pr_limit, 'wait' for a chid to finish and decrement
        
        // if we can read in the file
        if(fgets(testData, MAX_CANON, filePtr)) {
            
            
        /*
           2) read an line and execute program corresponding to that command line by
              forking a child process (fork, makeargv, execvp)
         
           3) increment pr_count to track the number of active children processes
        */
        }
        
        /*
         4) Check to see if any of the children processes have finished
            - 'waitpid' with 'WNOHANG' option
         
         5) Decrement pr_count for each completed child
    
        */
    }
    
    /*
     6) After EOF, wait for all the remaining children processes to finish
        with 'wait' and then exit with EXIT_SUCCESS
    */
    
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
