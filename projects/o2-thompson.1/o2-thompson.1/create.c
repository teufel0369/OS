#include "create.h"
#include  <stdio.h>
#include <stdlib.h>
#include  <sys/wait.h>
#include  <sys/types.h>
#include  <unistd.h>
#include <errno.h>
#include <string.h>

/*************************************************!
 * @function    createProcesses
 * @abstract    creates N child processes
 * @param       childPid   blank child
 * @param       testLine   array for each line
 * @param       testArgs   pointer to argument array
 * @param       delim      delimiter for separating args
 * @param       pr_limit   limit for number of processes
 * @param       pr_count   active processes
 **************************************************/
void createProcesses(pid_t childPid, char testLine[], char** testArgs, char* delim, int pr_limit, int pr_count){
    int i;
    
    for(i = 1; i < pr_limit; i++){
        
        if((childPid = fork()) <= 0) { /* must test with pid <= 0, otherwise fork bomb */
            pr_count += 1;
            
            if(pr_count == pr_limit) {
                childPid = wait(NULL);
                pr_count -= 1;
            }
            
            break; /* break the child process out of the loop */
        }
    }
    
    if(makeargv(testLine, delim, &testArgs) == -1) {
        perror("proc_fan: ERROR: Failed to construct an argument array. Blew up at the makeargv function call in the main function.");
        
    } else {
        printf("\n%s printed by child %1ld", testArgs[0], (long) getpid()); // **** just for debugging
        
        execvp(testArgs[0], &testArgs[0]);
        
        fprintf(stderr, "proc_fan: ERROR: Child %1ld failed to execute the command. Parent has a process ID of %1ld",
                (long) getpid(), (long) getppid());
        perror("");
        
    }
    free_makeargv(testArgs); /* free the memory allocated for making the argument array */
}

/*************************************************!
 * @function    free_makeargv
 * @abstract    frees the memory of the arg array
 *              that was allocated by makeargv()
 * @param       argv    number of arguments.
 * @citation    pg. 38 Unix Systems Programming
 **************************************************/
void free_makeargv(char** argv){
    if(argv == NULL) { return; }
    if(*argv != NULL) { free(*argv); }
    free(argv);
}

/*************************************************!
 * @function    makeargv
 * @abstract    orchestrates the madness
 * @param       s            number of arguments
 * @param       delims       delimiters
 * @returns     numTokens    number of tokens
 * @citation    pg. 37 Unix Systems Programming
 **************************************************/
int makeargv(const char* s, const char* delims, char*** argvp) {
    int error;
    int i;
    int numTokens;
    const char* startNewString;
    char* t;
    
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
 * @abstract    waits but doesn't block
 * @param       stat_loc    return status
 * @citation    pg. 72 Unix Systems Programming
 **************************************************/
pid_t r_wait(int* stat_loc){
    int retval;
    
    while(((retval = wait(stat_loc)) == -1) && (errno == EINTR));
    return retval;
}

