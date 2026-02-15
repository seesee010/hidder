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

int writeIntoFile(char *filename, char *buffer, char *arg) {

    if (buffer == NULL) {
        return 1;
    }

    if (filename == NULL) {
        return 1;
    }

    FILE *file = fopen(filename, arg);

    if (file == NULL) {
        return 1;
    }

    fprintf(file, "%s\n", buffer);
    fclose(file);
    return 0;
}