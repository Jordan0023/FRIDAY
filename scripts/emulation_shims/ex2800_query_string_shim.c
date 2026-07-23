/*
 * EX2800 component-emulation compatibility shim.
 *
 * The shipping webupg CGI unconditionally calls
 * strdup(getenv("QUERY_STRING")) for an application/x-www-form-urlencoded
 * POST. Under the extracted mini_httpd/QEMU environment QUERY_STRING is
 * absent, producing an unrelated strlen(NULL) crash. Return an empty value
 * only for that missing CGI variable. Preserve normal environment semantics
 * for every other lookup without calling libc getenv recursively.
 */

extern char **environ;

static int same_name(const char *entry, const char *name)
{
    while (*name && *entry == *name) {
        entry++;
        name++;
    }
    return *name == '\0' && *entry == '=';
}

char *getenv(const char *name)
{
    char **item;
    unsigned int name_length = 0;

    if (name != 0) {
        while (name[name_length] != '\0')
            name_length++;
    }

    if (name != 0 && environ != 0) {
        for (item = environ; *item != 0; item++) {
            if (same_name(*item, name))
                return *item + name_length + 1;
        }
    }

    if (name != 0 &&
        name[0] == 'Q' && name[1] == 'U' && name[2] == 'E' &&
        name[3] == 'R' && name[4] == 'Y' && name[5] == '_' &&
        name[6] == 'S' && name[7] == 'T' && name[8] == 'R' &&
        name[9] == 'I' && name[10] == 'N' && name[11] == 'G' &&
        name[12] == '\0')
        return "";

    return 0;
}
