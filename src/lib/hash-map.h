/*
 * Copyright (C) 2026 seesee010
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

#pragma once

#include <string.h>
#include "../vendor/uthash.h"

typedef int (*cmd_func)(int argc, char **argv);

typedef struct {
    const char *name;
    cmd_func func;
    UT_hash_handle hh;
} cmd_entry_t;

extern cmd_entry_t *cmds;

void register_all_commands();

// additional core func //

int call_cmd(const char *name, int argc, char **argv);
int add_cmd(const char *name, cmd_func func);
void free_cmds();
void list_cmds();