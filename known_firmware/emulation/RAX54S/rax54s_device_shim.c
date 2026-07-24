extern int __open(const char *path, int flags, ...);
extern int __open64(const char *path, int flags, ...);

static int emulated_fds[16];
static unsigned int emulated_count;

static int text_equal(const char *left, const char *right)
{
    while (*left != '\0' && *left == *right) {
        ++left;
        ++right;
    }
    return *left == *right;
}

static void remember_device(const char *path, int fd)
{
    if (fd >= 0 && emulated_count < 16U &&
        text_equal(path, "/dev/spiv6")) {
        emulated_fds[emulated_count++] = fd;
    }
}

static int is_emulated(int fd)
{
    unsigned int index;
    for (index = 0; index < emulated_count; ++index) {
        if (emulated_fds[index] == fd) {
            return 1;
        }
    }
    return 0;
}

int open(const char *path, int flags, ...)
{
    int fd;
    __builtin_va_list arguments;
    __builtin_va_start(arguments, flags);
    fd = __open(path, flags, __builtin_va_arg(arguments, unsigned int));
    __builtin_va_end(arguments);
    remember_device(path, fd);
    return fd;
}

int open64(const char *path, int flags, ...)
{
    int fd;
    __builtin_va_list arguments;
    __builtin_va_start(arguments, flags);
    fd = __open64(path, flags, __builtin_va_arg(arguments, unsigned int));
    __builtin_va_end(arguments);
    remember_device(path, fd);
    return fd;
}

static int emulate_ioctl(int fd, unsigned long request, void *argument)
{
    /*
     * ACOS NAT control requests use ioctl type 0x64.  Some firmware
     * libraries open the device through private libc entry points that do
     * not pass through the open/open64 bookkeeping above, so recognize the
     * narrowly scoped vendor request family as well.  Socket ioctls use the
     * distinct 0x89xx family and continue to reach the kernel.
     */
    if (is_emulated(fd) || (request & 0x0000ff00UL) == 0x00006400UL) {
        return 0;
    }
    register int r0 __asm__("r0") = fd;
    register unsigned long r1 __asm__("r1") = request;
    register void *r2 __asm__("r2") = argument;
    register unsigned long syscall_number __asm__("r7") = 54U;
    __asm__ volatile(
        "svc 0"
        : "+r"(r0)
        : "r"(r1), "r"(r2), "r"(syscall_number)
        : "memory"
    );
    return r0;
}

int ioctl(int fd, unsigned long request, ...)
{
    void *argument;
    __builtin_va_list arguments;
    __builtin_va_start(arguments, request);
    argument = __builtin_va_arg(arguments, void *);
    __builtin_va_end(arguments);
    return emulate_ioctl(fd, request, argument);
}

int __ioctl(int fd, unsigned long request, ...)
{
    void *argument;
    __builtin_va_list arguments;
    __builtin_va_start(arguments, request);
    argument = __builtin_va_arg(arguments, void *);
    __builtin_va_end(arguments);
    return emulate_ioctl(fd, request, argument);
}
