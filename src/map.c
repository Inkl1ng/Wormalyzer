#include "map.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>

// songs_length is length of path to songs directory
// id_path is a string with only the numbers after the song directory path
// mapset_path is a path in the songs directory
bool check_mapset_dir(size_t songs_length, char *id_path, char *mapset_path)
{
        size_t i = songs_length;
        while (i < strlen(id_path)) {
                if (id_path[i] != mapset_path[i])
                        return false;
                ++i;
        }

        // if the mapset has an id of 243 but the user is searcing for mapset
        // 2 the program will get past the previous loop so this is needed to
        // make sure that something like that doesn't happen
        if (mapset_path[i] != ' ')
                return false;

        return true;
}

bool load_map(char *mapset_id)
{

        // get path to osu! directory and start searching in there for a matching
        // map set
        FILE *file = fopen(ASSET_PATH "/#osu-path.txt", "r");
        // if the user has a path longer than 256 characters than I have questions
        char path[256];
        if (file == NULL) {
                printf("Failed to open file\n");
                return false;
        }
        // get the path to the user's osu! directory
        fgets(path, 256, file);
        fclose(file);

#ifdef _WIN32
        strcat(path, "\\songs");
#else
        strcat(path, "/songs");
#endif

        // check that the path to the songs directory is valid
        if (!DirectoryExists(path)) {
                printf("Invalid osu! directory");
                return false;
        }

        FilePathList songs_dir = LoadDirectoryFiles(path);
    
#ifdef _WIN32
        strcat(path, "\\");
#else
        strcat(path, "/");
#endif

        // length of the full path to the songs directory "(...)/osu!/songs/"
        size_t path_length = strlen(path);
        // by now path contains the full path to the songs directory and
        // the mapset id that the user is looking for
        // eg. [songs path]/292301
        strcat(path, mapset_id);
        bool found_mapset = false;

        for (size_t i = 0; i < songs_dir.count; ++i) {
                if (check_mapset_dir(path_length, path, songs_dir.paths[i])) {
                        found_mapset = true;
                        break;
                }
        }

        if (!found_mapset) {
                printf("Could not find mapset\n");
                return false;
        }

        return true;
}
