/*
 * Native subprocess surrogate for the isolated RAX78 user-mode web lab.
 *
 * qemu-arm cannot recursively exec the firmware's ARM /bin/sh without a host
 * binfmt handler.  net-cgi uses fixed `part_dev` queries during startup, so
 * answer only those queries and reject every other shell command.  This keeps
 * request parsing and dispatch in the genuine net-cgi while preventing lab
 * command side effects.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char *command = argc >= 3 && strcmp(argv[1], "-c") == 0
        ? argv[2]
        : "";

    if (strcmp(command, "part_dev language") == 0) {
        puts("English");
        return 0;
    }
    if (strcmp(command, "part_dev pot") == 0) {
        puts("1");
        return 0;
    }
    if (strcmp(command, "part_dev firmware") == 0) {
        puts("1.0.20.174");
        return 0;
    }
    if (strcmp(command, "part_dev image") == 0) {
        puts("RAX78-V1.0.20.174.img");
        return 0;
    }
    return 126;
}
