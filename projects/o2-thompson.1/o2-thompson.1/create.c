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
 * @param       numProcesses  number of processes
 **************************************************/
void createProcesses(int numProcesses){
    pid_t child;
    int i = 0;
    
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
