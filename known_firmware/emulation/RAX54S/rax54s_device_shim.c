extern int __open(const char *path, int flags, ...);
extern int __open64(const char *path, int flags, ...);
extern int close(int fd);
extern long write(int fd, const void *buffer, unsigned long count);

static void write_hex32(int fd, unsigned long value)
{
    static const char digits[] = "0123456789abcdef";
    unsigned int shift;
    char digit;
    for (shift = 28U; shift < 32U; shift -= 4U) {
        digit = digits[(value >> shift) & 15U];
        write(fd, &digit, 1U);
        if (shift == 0U) {
            break;
        }
    }
}

/*
 * The real implementation walks the hardware NAT table through
 * /dev/acos_nat_cli before httpd creates its listeners.  Returning successful
 * empty ioctl results cannot terminate that walk because the driver also
 * supplies its end-of-table state in the output structure.  The isolated lab
 * starts with no NAT rules, so model the operation at its public API boundary
 * as an already-empty table.
 */
int agApi_clear_nat_for_httpd(void)
{
    return 0;
}

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
    static unsigned long traced_requests[128];
    static unsigned int traced_count;
    /*
     * ACOS NAT control requests use ioctl type 0x64.  Some firmware
     * libraries open the device through private libc entry points that do
     * not pass through the open/open64 bookkeeping above, so recognize the
     * narrowly scoped vendor request family as well.  Socket ioctls use the
     * distinct 0x89xx family and continue to reach the kernel.
     */
    if (is_emulated(fd) || (request & 0x0000ff00UL) == 0x00006400UL) {
        unsigned int trace_index;
        int seen = 0;
        for (trace_index = 0; trace_index < traced_count; ++trace_index) {
            if (traced_requests[trace_index] == request) {
                seen = 1;
                break;
            }
        }
        if (!seen && traced_count < 128U) {
            unsigned long *words = (unsigned long *)argument;
            int console = __open("/dev/console", 1);
            traced_requests[traced_count++] = request;
            if (console >= 0) {
                write(console, "FRIDAY_RAX54S_IOCTL req=0x", 26U);
                write_hex32(console, request);
                write(console, " caller=0x", 10U);
                write_hex32(console, (unsigned long)__builtin_return_address(1));
                if ((unsigned long)argument >= 4096U &&
                    (unsigned long)argument < 0xc0000000U) {
                    write(console, " words=", 7U);
                    write_hex32(console, words[0]);
                    write(console, ",", 1U);
                    write_hex32(console, words[1]);
                    write(console, ",", 1U);
                    write_hex32(console, words[2]);
                    write(console, ",", 1U);
                    write_hex32(console, words[3]);
                }
                write(console, "\n", 1U);
                close(console);
            }
        }
        /*
         * /dev/spiv6 is a write-style notification device, so acknowledge it.
         * The 0x64 vendor family includes NAT/firewall table queries and
         * deletes.  This lab has an empty table: reporting success without
         * mutating a kernel table makes httpd's cleanup loops run forever.
         * Failure is the driver's end/not-found indication used to terminate
         * those loops.
         */
        if (is_emulated(fd) || (request >> 24) == 0x5aUL) {
            return 0;
        }
        return -1;
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
