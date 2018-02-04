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
    int pr_limit = 0;
    int pr_count = 0;
    int i;
    
    char* testFile = "/Users/magnificentbastard/OS-Projects/OS/projects/o2-thompson.1/o2-thompson.1/testing.data";
    
    // open the file *** remember to change back to argv[4]
    filePtr = fopen(testFile, "r");
    if(filePtr == NULL){
        perror("proc_fan: ERROR: Failed to open the file");
        exit(EXIT_FAILURE);
    }
    
    // check the number of arguments supplied *** must uncomment on submission
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
    char** testArgs;
    char* delim = "\n";
    pid_t childPid;
    
    
    // read in the file of test data
    // feof checks the end of the file
    while(!feof(filePtr)) {
        
        // if we can read in the file
        if(fgets(testLine, MAX_CANON, filePtr)) {
            printf("%s", testLine); // test print data
            
            createProcesses(childPid, testLine, testArgs, delim, pr_limit, pr_count); /* create the processes and execute the arguments */
        }
    }
    
    while(r_wait(NULL) > 0); /* waiting for all the remaining child processes to finish */
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
