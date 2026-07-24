/* Minimal libc-free ARM SSDP client used only inside the isolated guest. */
typedef unsigned int u32;
typedef unsigned short u16;

struct sockaddr_in {
    u16 family;
    u16 port;
    u32 address;
    unsigned char zero[8];
};

struct pollfd {
    int fd;
    short events;
    short revents;
};

static long call3(long number, long a, long b, long c)
{
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    register long r7 __asm__("r7") = number;
    __asm__ volatile("svc 0" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "memory");
    return r0;
}

static long call6(long number, long a, long b, long c, long d, long e, long f)
{
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    register long r3 __asm__("r3") = d;
    register long r4 __asm__("r4") = e;
    register long r5 __asm__("r5") = f;
    register long r7 __asm__("r7") = number;
    __asm__ volatile(
        "svc 0"
        : "+r"(r0)
        : "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5), "r"(r7)
        : "memory"
    );
    return r0;
}

void _start(void)
{
    static const char packet[] =
        "M-SEARCH * HTTP/1.1\r\n"
        "HOST: 239.255.255.250:1900\r\n"
        "MAN: \"ssdp:discover\"\r\n"
        "MX: 1\r\n"
        "ST: ssdp:all\r\n\r\n";
    static char response[8192];
    /* 239.255.255.250, in network byte order as laid out on little-endian ARM. */
    struct sockaddr_in target = {2, 0x6c07, 0xfaffffef, {0}};
    struct pollfd ready;
    long fd = call3(281, 2, 2, 0); /* socket(AF_INET, SOCK_DGRAM, 0) */
    long length;

    if (fd >= 0) {
        call6(290, fd, (long) packet, sizeof(packet) - 1, 0, (long) &target, sizeof(target));
        ready.fd = (int) fd;
        ready.events = 1;
        ready.revents = 0;
        if (call3(168, (long) &ready, 1, 5000) > 0) {
            length = call6(292, fd, (long) response, sizeof(response), 0, 0, 0);
            if (length > 0) {
                call3(4, 1, (long) response, length);
            }
        }
    }
    call3(1, 0, 0, 0);
    for (;;) {}
}
