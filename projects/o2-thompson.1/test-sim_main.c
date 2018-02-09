#include <stdlib.h>
#include <stdio.h>

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @returns     0 if it runs correctly.
 **************************************************/
int main(int argc, const char* argv[]) {

    int i = 0;
    int numIterations = 0;
    int sleepTime = 0;

    sleepTime = atoi(argv[1]);
    numIterations = atoi(argv[2]);

    for(i = 0; i < numIterations; i++){
        sleep((int)sleepTime);
        fprintf(stderr, "\nPID %1ld PPID %1ld ran testsim %1d %1d ", (long)getpid(), (long)getppid(), sleepTime, numIterations);
        perror("");

    }

    return 0;
}

