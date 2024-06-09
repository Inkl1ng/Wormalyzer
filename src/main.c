#include <stdio.h>
#include <stdlib.h>
#include "app.h"

int main(int argc, char* argv[])
{
	// init_app();

	// run_app();
	
	// close_app();
	FILE *file = fopen(ASSET_PATH "/#osu-path.txt", "r");
	printf("%s\n", ASSET_PATH "/#osu-path.txt", "r");
	if (file == NULL)
	{
		printf("failed to load in file!\n");
		return EXIT_FAILURE;
	}

	char buf[100];
	fgets(buf, sizeof(buf), file);
	printf("%s\n", buf);

	return 0;
}
