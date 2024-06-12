#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "map.h"

int main(int argc, char* argv[])
{
        // user should only enter mapset id as for command line arguments
        if (argc != 2) {
                printf("Invalid number of arguments!\n");
                printf("Please only enter the mapset id.\n");
                return EXIT_FAILURE;
        }

        if (!load_map(argv[1]))
                return EXIT_FAILURE;
        else
                printf("worked!\n");

        /*
        init_app();

        run_app();

        close_app();
        */

        return 0;
}
