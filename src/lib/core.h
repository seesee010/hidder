/*
 * Copyright (C) 2026 seesee010
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "hash-map.h"

// All Func_cmd //

int hidder_init(int argc, char **argv);
int hidder_status(int argc, char **argv);

// all cmds //

typedef struct {
    const char *name;
    cmd_func func;
} cmd_define_t;

static const cmd_define_t ALL_CMDS[] = {
    {"init", hidder_init},
    {"status", hidder_status},
    {NULL, NULL} // termination
};