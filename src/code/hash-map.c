// src/code/hash-map.c

#include "../lib/hash-map.h"
#include "../lib/core.h"

cmd_entry_t *cmds = NULL;

void register_all_commands() {
    
    extern const cmd_define_t ALL_CMDS[];
    for (int i = 0; ALL_CMDS[i].name != NULL; i++) {
        add_cmd(ALL_CMDS[i].name, ALL_CMDS[i].func);
    }
}

int add_cmd(const char *name, cmd_func func) {

    if (name == NULL) {
        fprintf(stdout, "-- reach/ADD-CMD: --\n");
        fprintf(stderr, "[ERROR:] Invalid name!");
        return 1;
    }

    if (func == NULL) {
        fprintf(stdout, "-- reach/ADD-CMD: --\n");
        fprintf(stderr, "[ERROR:] Invalid func!");
        return 1;
    }

    cmd_entry_t *entry = malloc(sizeof(cmd_entry_t));
    entry->name = strdup(name);
    entry->func = func;

    HASH_ADD_KEYPTR(hh, cmds, entry->name, strlen(entry->name), entry);
    return 0;
}

int call_cmd(const char *name, int argc, char **argv) {

    if (name == NULL) {
        fprintf(stdout, "-- reach/CALL-CMD: --\n");
        fprintf(stderr, "[ERROR:] Invalid name!");
        return 1;
    }

    if (argc < 0) {
        fprintf(stdout, "-- reach/CALL-CMD: --\n");
        fprintf(stderr, "[ERROR:] Invalid argument size!");
        return 1;
    }

    cmd_entry_t *entry;
    HASH_FIND_STR(cmds, name, entry);

    if (!entry) {
        fprintf(stdout, "-- reach/CALL-CMD: --\n");
        fprintf(stderr, "[ERROR:] Unknown command!: %s\n", name);
        return 1;
    }

    return entry->func(argc, argv);
}

// Cleanup
void free_cmds() {

    cmd_entry_t *entry, *tmp;
    HASH_ITER(hh, cmds, entry, tmp) {

        HASH_DEL(cmds, entry);

        free((void*)entry->name);
        free(entry);
    }
}

// show all cmds
void list_cmds() {
    cmd_entry_t *entry, *tmp;

    fprintf(stdout, "-- reach/LIST-ALL: --\n");
    fprintf(stdout, "[DEBUG:] Available cmds:");
    HASH_ITER(hh, cmds, entry, tmp) {
        fprintf(stdout, " - %s\n", entry->name);
    }
}