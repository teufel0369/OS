#include <getopt.h>
#include <stdlib.h>
#include "common.h"

/* Declarations */
void producerLog(FILE*, int, char*);

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @param       argv    array of arguments
 * @returns     0 if it runs correctly.
 **************************************************/
int main(int argc, const char* argv[]) {
    int consumers;
    int pid;
    int c;

    /* get the arguments from getopt */
    while ((c = getopt (argc, argv, "ni")) != -1) {
        switch(c){
            case 'n':
                break;
            case 'i':
                pid = atoi(optarg);
                break;
            default:
                consumers = 3;
                break;
        }
    }
}

/****************************************************************!
 * @function    producerLog
 *
 * @abstract    logs any info from the producer to the log file
 *
 * @param       fp  file pointer
 * @param       sharedMemory  shared memory pointer
 *
 * @returns     array of structs if ran successfully
 ****************************************************************/
void producerLog(FILE* fp, int pid, char* message) {
    if((fp = fopen("/producer.log", "w")) == NULL) {
        perror("[-]ERROR: Failed to open the PRODUCER log file");
    } else {
        fprintf(fp, message);
    }
}