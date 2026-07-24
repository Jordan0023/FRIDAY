typedef __builtin_va_list va_list;
typedef struct rs700_file FILE;

extern FILE *fopen(const char *path, const char *mode);
extern int fclose(FILE *stream);
extern int fprintf(FILE *stream, const char *format, ...);
extern int vsnprintf(char *buffer, unsigned long size, const char *format,
                     va_list arguments);

#define va_start(arguments, last) __builtin_va_start(arguments, last)
#define va_end(arguments) __builtin_va_end(arguments)
#define NULL ((void *)0)

static void log_call(const char *sink, const char *command)
{
    FILE *fp = fopen("/tmp/rs700_command_calls.log", "a");

    if (fp == NULL)
        return;
    fprintf(fp, "%s\t%s\n", sink, command != NULL ? command : "(null)");
    fclose(fp);
}

int shared_util_doSystem(const char *format, ...)
{
    char command[8192];
    va_list arguments;

    va_start(arguments, format);
    vsnprintf(command, sizeof(command), format, arguments);
    va_end(arguments);
    command[sizeof(command) - 1] = '\0';
    log_call("shared_util_doSystem", command);
    return 0;
}

int shared_nat_pf_rule_add_dynamic_rule(void)
{
    log_call("shared_nat_pf_rule_add_dynamic_rule", "forced-success");
    return 0;
}

int system(const char *command)
{
    log_call("system", command);
    return 0;
}

FILE *popen(const char *command, const char *mode)
{
    (void)mode;
    log_call("popen", command);
    return NULL;
}
