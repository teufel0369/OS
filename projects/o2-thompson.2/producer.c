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
    int numConsumers;
    int c;

    /* get the arguments from getopt */
    while ((c = getopt (argc, argv, "n")) != -1) {
        switch(c){
            case 'n':
                numConsumers = atoi(optarg);
                break;

            default:
                numConsumers = TEST_NUM_CONSUMERS;
        }
    }
}