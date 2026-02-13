/*
 * Copyright (C) 2026 seesee010
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

// src/code/main.c

#include "../lib/core.h"
#include "../lib/hash-map.h"

int main(int argc, char **argv) {

    register_all_commands();

    if (argc <= 1) {
        return hidder_status(0, NULL);
    }

    call_cmd(argv[1], argc - 2, argv + 2); 

    free_cmds();
    return 0;
}