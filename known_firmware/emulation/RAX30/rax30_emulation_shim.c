/*
 * Hardware-bound flash geometry used only by the isolated full-system lab.
 * Real firmware obtains this value from /dev/brcmboard; QEMU's virt machine
 * has no Broadcom board driver, so provide a conservative 128 KiB config area.
 */
unsigned int bcmImg_getRealConfigFlashSize(void)
{
    return 128U * 1024U;
}

unsigned int bcmImg_getConfigFlashSize(void)
{
    return bcmImg_getRealConfigFlashSize();
}

/*
 * QEMU user networking presents loopback-forwarded clients to the guest as
 * 10.0.2.2.  The vendor SOAP daemon permits LAN clients by comparing the peer
 * address to the address returned here (not by applying the returned mask).
 */
int cmsNet_getLanInfo(
    const char *interface_name,
    unsigned int *lan_address,
    unsigned int *lan_mask
)
{
    (void) interface_name;
    if (lan_address != 0) {
        *lan_address = 0x0202000aU;
    }
    if (lan_mask != 0) {
        *lan_mask = 0x00ffffffU;
    }
    return 0;
}

/*
 * With SSK intentionally absent, the vendor daemon can retain a stale CMS
 * messaging descriptor in one of its select sets.  glibc rejects the entire
 * set with EBADF, leaving the SOAP accept loop spinning.  Remove only closed
 * descriptors before delegating to glibc's real implementation.
 */
typedef struct {
    unsigned long bits[1024U / (8U * sizeof(unsigned long))];
} rax30_fd_set;

struct rax30_timeval {
    long tv_sec;
    long tv_usec;
};

extern int fcntl(int fd, int command, ...);
extern int open(const char *path, int flags, ...);
extern int close(int fd);
extern long write(int fd, const void *buffer, unsigned long count);
extern char *strstr(const char *haystack, const char *needle);
extern int __libc_system(const char *command);
extern void *_IO_popen(const char *command, const char *mode);
extern void *_IO_fopen(const char *path, const char *mode);
extern int sigaction(int signal_number, const void *action, void *old_action);
extern void _exit(int status);
extern int __select(
    int nfds,
    rax30_fd_set *readfds,
    rax30_fd_set *writefds,
    rax30_fd_set *exceptfds,
    struct rax30_timeval *timeout
);

#ifdef FRIDAY_TRACE_FATAL
typedef struct {
    unsigned long trap_no, error_code, oldmask;
    unsigned long arm_r0, arm_r1, arm_r2, arm_r3;
    unsigned long arm_r4, arm_r5, arm_r6, arm_r7;
    unsigned long arm_r8, arm_r9, arm_r10;
    unsigned long arm_fp, arm_ip, arm_sp, arm_lr, arm_pc;
    unsigned long arm_cpsr, fault_address;
} friday_arm_sigcontext;

typedef struct {
    unsigned long flags;
    void *link;
    void *stack_sp;
    int stack_flags;
    unsigned long stack_size;
    friday_arm_sigcontext machine;
} friday_arm_ucontext;

typedef struct {
    void (*handler)(int, void *, void *);
    unsigned long mask[32];
    unsigned long flags;
    void (*restorer)(void);
} friday_sigaction;

static void write_hex32(int fd, unsigned long value)
{
    static const char hexadecimal[] = "0123456789abcdef";
    unsigned int shift;
    char digit;

    for (shift = 28U; shift < 32U; shift -= 4U) {
        digit = hexadecimal[(value >> shift) & 0xfU];
        write(fd, &digit, 1U);
        if (shift == 0U) {
            break;
        }
    }
}

static void friday_fatal_handler(int signal_number, void *info, void *context)
{
    friday_arm_ucontext *state = (friday_arm_ucontext *)context;
    int fd = open("/dev/console", 1);
    (void)info;

    if (fd >= 0) {
        write(fd, "FRIDAY_RAX29_FATAL signal=0x", 28U);
        write_hex32(fd, (unsigned long)signal_number);
        write(fd, " pc=0x", 6U);
        write_hex32(fd, state->machine.arm_pc);
        write(fd, " lr=0x", 6U);
        write_hex32(fd, state->machine.arm_lr);
        write(fd, " sp=0x", 6U);
        write_hex32(fd, state->machine.arm_sp);
        write(fd, " fault=0x", 9U);
        write_hex32(fd, state->machine.fault_address);
        write(fd, " r0=0x", 6U);
        write_hex32(fd, state->machine.arm_r0);
        write(fd, " r1=0x", 6U);
        write_hex32(fd, state->machine.arm_r1);
        write(fd, " r2=0x", 6U);
        write_hex32(fd, state->machine.arm_r2);
        write(fd, " r3=0x", 6U);
        write_hex32(fd, state->machine.arm_r3);
        write(fd, "\n", 1U);
        close(fd);
    }
    _exit(128 + signal_number);
}

__attribute__((constructor))
static void friday_install_fatal_handler(void)
{
    friday_sigaction action;
    unsigned int index;
    unsigned char *raw = (unsigned char *)&action;

    for (index = 0; index < sizeof(action); ++index) {
        raw[index] = 0;
    }
    action.handler = friday_fatal_handler;
    action.flags = 4U; /* SA_SIGINFO */
    sigaction(11, &action, 0); /* SIGSEGV */
    sigaction(7, &action, 0);  /* SIGBUS */
    sigaction(6, &action, 0);  /* SIGABRT */
}
#endif

/*
 * Trace long copies in the disposable lab without changing strcpy semantics.
 * The UPnP binary has two call sites that allocate 32-byte destinations; this
 * tells us whether an unauthenticated request can drive a source beyond that
 * boundary before we attempt any crash-inducing probe.
 */
#ifndef FRIDAY_DISABLE_STRCPY
char *strcpy(char *destination, const char *source)
{
    unsigned long length = 0;
    unsigned long index;
    unsigned long caller;
    unsigned int shift;
    int fd;
    static int reporting;
    static const char marker[] = "FRIDAY_RAX30_LONG_STRCPY caller=0x";
    static const char length_marker[] = " length=0x";
    static const char hexadecimal[] = "0123456789abcdef";
    char digit;

    while (source[length] != '\0') {
        ++length;
    }
    if (length > 127U && !reporting) {
        reporting = 1;
        fd = open("/dev/console", 1);
        if (fd >= 0) {
            write(fd, marker, sizeof(marker) - 1U);
            caller = (unsigned long)__builtin_return_address(0);
            for (shift = 28U; shift < 32U; shift -= 4U) {
                digit = hexadecimal[(caller >> shift) & 0xfU];
                write(fd, &digit, 1U);
                if (shift == 0U) {
                    break;
                }
            }
            write(fd, length_marker, sizeof(length_marker) - 1U);
            for (shift = 28U; shift < 32U; shift -= 4U) {
                digit = hexadecimal[(length >> shift) & 0xfU];
                write(fd, &digit, 1U);
                if (shift == 0U) {
                    break;
                }
            }
            write(fd, "\n", 1U);
            close(fd);
        }
        reporting = 0;
    }
    for (index = 0; index <= length; ++index) {
        destination[index] = source[index];
    }
    return destination;
}
#endif

static unsigned long shim_strlen(const char *text)
{
    unsigned long length = 0;
    while (text[length] != '\0') {
        ++length;
    }
    return length;
}

static void report_marker_sink(const char *kind, const char *command)
{
    int fd;
    static const char marker[] = "FRIDAY_RAX30_RCE_MARKER";
    static const char prefix[] = "FRIDAY_RAX30_RCE_SINK=";
    static const char separator[] = " command=";

    if (command == 0 || strstr(command, marker) == 0) {
        return;
    }
    fd = open("/dev/console", 1);
    if (fd < 0) {
        return;
    }
    write(fd, prefix, sizeof(prefix) - 1U);
    write(fd, kind, shim_strlen(kind));
    write(fd, separator, sizeof(separator) - 1U);
    write(fd, command, shim_strlen(command));
    write(fd, "\n", 1U);
    close(fd);
}

int system(const char *command)
{
    report_marker_sink("system", command);
    return __libc_system(command);
}

void *popen(const char *command, const char *mode)
{
    report_marker_sink("popen", command);
    return _IO_popen(command, mode);
}

void *fopen(const char *path, const char *mode)
{
    report_marker_sink("fopen", path);
    return _IO_fopen(path, mode);
}

static void clear_closed_fds(int nfds, rax30_fd_set *set)
{
    int fd;

    if (set == 0) {
        return;
    }
    for (fd = 0; fd < nfds; ++fd) {
        unsigned long mask = 1UL << ((unsigned int) fd & 31U);
        unsigned int word = (unsigned int) fd >> 5;
        if ((set->bits[word] & mask) != 0 && fcntl(fd, 1) < 0) {
            set->bits[word] &= ~mask;
        }
    }
}

int select(
    int nfds,
    rax30_fd_set *readfds,
    rax30_fd_set *writefds,
    rax30_fd_set *exceptfds,
    struct rax30_timeval *timeout
)
{
    clear_closed_fds(nfds, readfds);
    clear_closed_fds(nfds, writefds);
    clear_closed_fds(nfds, exceptfds);
    return __select(nfds, readfds, writefds, exceptfds, timeout);
}
