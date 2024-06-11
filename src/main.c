#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include "app.h"

int main(int argc, char* argv[])
{
	// user should only enter mapset id as for command line arguments
	if (argc != 2)
	{
		printf("Invalid number of arguments!\n");
		printf("Please only enter the mapset id.\n");
		return EXIT_FAILURE;
	}
	
	// get path to osu! directory and start searching in there for a matching
	// map set
	FILE *file = fopen(ASSET_PATH "/#osu-path.txt", "r");
	// if the user has a path longer than 256 characters than I have questions
	char osu_path[256];
	if (file == NULL)
	{
		printf("Failed to open file\n");
		return EXIT_FAILURE;
	}
	fgets(osu_path, 256, file);
	fclose(file);
	// I love that windows has to use a different slash direction
#ifdef _WIN32
	strcat(osu_path, "\\songs");
#else
	strcat(osu_path, "/songs");
#endif

	// check that the path is valid
	if (!DirectoryExists(osu_path))
	{
		printf("Invalid osu! directory");
		return EXIT_FAILURE;
	}

	FilePathList songs_dir = LoadDirectoryFiles(osu_path);

	// find the directory that matches with the mapset id
	char mapset_path[256] = "";
	strcpy(mapset_path, osu_path);
	
#ifdef _WIN32
	strcat(mapset_path, "\\");
#else
	strcat(mapset_path, "/");
#endif

	strcat(mapset_path, argv[1]);
	bool found_mapset = false;
	for (unsigned int i = 0; i < songs_dir.count; ++i)
	{
		if (strncmp(songs_dir.paths[i], mapset_path, strlen(mapset_path)) == 0)
		{
			printf("match\n");
			strcpy(mapset_path, songs_dir.paths[i]);
			found_mapset = true;
			break;
		}
	}

	if (!found_mapset)
	{
		printf("Could not find mapset\n");
		return EXIT_FAILURE;
	}

	/*
	init_app();

	run_app();
	
	close_app();
	*/

	return 0;
}
