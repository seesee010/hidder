/*
 * Copyright (C) 2026 seesee010
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

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