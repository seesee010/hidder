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