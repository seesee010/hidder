// src/code/all_cmds.c

#include "../lib/core.h"


int hidder_status(int argc, char **argv) {

    fprintf(stdout, "-- cmds/status: --\n");
    fprintf(stdout, "[DEBUG:] Currently not possible!");
    return 0;
}


int hidder_init(int argc, char **argv) {

    const char *filename = ".gitignore";

    if (filename == NULL) {
        return 1;
    }
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        return 1;
    }

    fprintf(file, ".hidder/*\n");

    fclose(file);
    return 0;
}