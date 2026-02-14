/*
 * Copyright (C) 2026 seesee010
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 */

// src/code/all_cmds.c

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif

#include "../lib/core.h"
#include "../lib/hash-map.h"

int hidder_status(int argc, char **argv) {

    fprintf(stdout, "\n-- cmds/status: --\n");
    fprintf(stdout, "[DEBUG:] Currently not possible!");
    return 0;
}


int hidder_init(int argc, char **argv) {

    printf("%s", argv[0]);

    if (argv[0] == "--force") {

        const char *filename = ".gitignore";

        if (filename == NULL) {
            return 1;
        }
        FILE *file = fopen(filename, "a");

        if (file == NULL) {
            fprintf(stdout, "\n-- cmds/init: --\n");
            fprintf(stdout, "[ERROR:] The right file could not been found!");  
            return 1;
        }

        fprintf(file, "\n.hidder/priv~a/*\n");

        fclose(file);
    }

    MKDIR(".hidder");

    MKDIR(".hidder/priv~a");
    MKDIR(".hidder/pub~a");

    FILE *file2 = fopen(".hidder/priv~a/keys.yaml", "a");
    fprintf(file2, "");
    fclose(file2);

    FILE *file3 = fopen(".hidder/pub~a/settings.yaml", "a");
    fprintf(file3, "");
    fclose(file3);

    return 0;
}

int hidder_add(int argc, char **argv) {

    if (argv[0] == NULL) {

        fprintf(stdout, "\n-- cmds/add: --\n");
        fprintf(stdout, "[ERROR:] Nothing to add!");  
        return 1;      
    }

    // add all
    else if (argv[0] == ".") {
        // not supported yet.
        fprintf(stdout, "\n-- cmds/add: --\n");
        fprintf(stdout, "[DEBUG:] Adding every file at once is not supported right now!");
        return 1;
    }

    // ..must be a filename by now...
    else {
        // return hidder_add_file(0, argv[0]);
    }

    return 0;
}

int hidder_help(int argc, char **argv) {

    fprintf(stdout, "\n[DEBUG:]");
    fprintf(stdout, "\nThis command is an additional cmd, from github (see: https://github.com/seesee010/hidder.git)\n");
    list_cmds();
}

int hidder_git(int argc, char **argv) {
    // add -> push - system: hide -> git push -> restore 
    
    return  hidder_push(0, NULL) | system("git push") | hidder_restore(0, NULL);
}

int hidder_push(int argc, char **argv) {
    return 0;
}

int hidder_restore(int argc, char **argv) {
    return 0;
}