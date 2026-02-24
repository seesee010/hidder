/*
 * Copyright (C) 2026 seesee010
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#include "../lib/additional.h"
#include "../lib/core.h"

void getLineFromFile(char *filepath, char *out) {

    if (out == NULL) {
        fprintf(stderr, "[Error:] Can not change *out if it is NULL!\n");
        return;
    }

    if (filepath == NULL) {
        fprintf(stderr, "[Error:] Filepath is not set!\n");
        return;
    }

    FILE *file = fopen(filepath, "w+");
    fgets(out, 100, file);

    return;
}

int writeIntoFile(char *filepath, char *buffer, char *arg) {

    if (buffer == NULL) {
        return 1;
    }

    if (filepath == NULL) {
        return 1;
    }

    FILE *file = fopen(filepath, arg);

    if (file == NULL) {
        return 1;
    }

    char *nL = "";
    char *out;

    getLineFromFile(filepath, out);

    if (out != NULL) {
        nL = "\n";
    }

    fprintf(file, "%s%s", buffer, nL);
    fclose(file);
    return 0;
}