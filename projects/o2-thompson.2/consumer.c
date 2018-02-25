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
    int consumerIndex;
    int c;

    /* get the arguments from getopt */
    while ((c = getopt(argc, argv, "n")) != -1) {
        switch (c) {
            case 'n':
                consumerIndex = atoi(optarg);
                break;

            default:
                consumerIndex = TEST_NUM_CONSUMERS;
        }
    }
    return 0;
}