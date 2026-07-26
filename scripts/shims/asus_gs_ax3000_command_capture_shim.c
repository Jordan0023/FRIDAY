/*
 * Command capture for the isolated GS-AX3000 upload lab.
 * Prevents extraction/removal commands from mutating the disposable root so
 * the multipart staging file can be inspected after the request.
 */

extern int open(const char *path, int flags, ...);
extern int close(int fd);
extern int write(int fd, const void *buffer, unsigned count);

static unsigned capture_length(const char *text)
{
    unsigned length = 0;
    if (!text)
        return 0;
    while (text[length])
        length++;
    return length;
}

int system(const char *command)
{
    int fd = open("/tmp/gsax3000-command-capture.log",
                  1 | 64 | 1024, 0600);
    if (fd >= 0) {
        write(fd, command, capture_length(command));
        write(fd, "\n", 1);
        close(fd);
    }
    return 0;
}
