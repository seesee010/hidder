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