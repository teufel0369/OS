#include <getopt.h>
#include <stdlib.h>
#include "common.h"

/*************************************************!
 * @function    main
 * @abstract    orchestrates the madness
 * @param       argc    number of arguments.
 * @param       argv    array of arguments
 * @returns     0 if it runs correctly.
 **************************************************/
int main(int argc, const char* argv[]) {
    int pid;
    int c;

    /* get the arguments from getopt */
    while ((c = getopt(argc, argv, "ni")) != -1) {
        switch (c) {
            case 'i':
                pid = atoi(optarg);
                break;
            default:
                break;
        }
    }
}

/****************************************************************!
 * @function    consumerLog
 *
 * @abstract    logs any info from the producer to the log file
 *
 * @param       fp  file pointer
 * @param       sharedMemory  shared memory pointer
 *
 * @returns     array of structs if ran successfully
 ****************************************************************/
void consumerLog(FILE* fp, int pid, char* message) {
    if((fp = fopen("/consumer.log", "w")) == NULL) {
        perror("[-]ERROR: Failed to open the PRODUCER log file");
    } else {
        fprintf(fp, message);
    }
}