/*
 * Fixed-query popen substitute for the isolated RAX78 web lab.
 *
 * It exists only because qemu-arm user mode cannot recursively exec the
 * firmware shell without binfmt_misc.  Unknown commands return an empty,
 * successful stream; no command is executed.
 */
typedef struct FridayFile FILE;

extern FILE *tmpfile(void);
extern FILE *fopen(const char *, const char *);
extern int fputs(const char *, FILE *);
extern void rewind(FILE *);
extern int fclose(FILE *);

static int same(const char *left, const char *right)
{
    if (left == 0 || right == 0) return 0;
    while (*left != '\0' && *left == *right) {
        ++left;
        ++right;
    }
    return *left == *right;
}

FILE *popen(const char *command, const char *type)
{
    FILE *stream;
    const char *answer = "";

    (void)type;
    if (same(command, "part_dev language")) answer = "/dev/mtd0\n";
    else if (same(command, "part_dev pot")) answer = "/dev/mtd1\n";
    else if (same(command, "part_dev firmware")) answer = "/dev/mtd3\n";
    else if (same(command, "part_dev image")) answer = "/dev/mtd3\n";

    stream = tmpfile();
    if (stream == 0) return 0;
    fputs(answer, stream);
    rewind(stream);
    return stream;
}

int pclose(FILE *stream)
{
    return fclose(stream);
}

int system(const char *command)
{
    FILE *log = fopen("/tmp/rax78_system_calls.log", "a");
    if (log != 0) {
        fputs(command != 0 ? command : "(null)", log);
        fputs("\n", log);
        fclose(log);
    }
    return 0;
}
