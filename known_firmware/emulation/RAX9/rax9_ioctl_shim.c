/*
 * Minimal hardware-compatibility shim for the isolated RAX9 MiniUPnPd lab.
 *
 * The vendor daemon initializes an embedded WPS component before opening its
 * UPnP listener. That component issues a MediaTek private wireless ioctl
 * (0x8be1) which cannot succeed on the lab's synthetic interface. Returning
 * success for that hardware-only request lets the genuine network parser run.
 *
 * This shim is intentionally narrow: every other ioctl is forwarded to the
 * real libc implementation.
 */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define RAX9_MTK_WPS_IOCTL 0x8be1UL

typedef int (*ioctl_fn)(int, unsigned long, ...);
typedef int (*setsockopt_fn)(int, int, int, const void *, socklen_t);

int ioctl(int fd, unsigned long request, ...)
{
    static ioctl_fn real_ioctl;
    va_list ap;
    void *argument;

    va_start(ap, request);
    argument = va_arg(ap, void *);
    va_end(ap);

    if (request == RAX9_MTK_WPS_IOCTL)
        return 0;

    if (!real_ioctl)
        real_ioctl = (ioctl_fn)dlsym(RTLD_NEXT, "ioctl");

    return real_ioctl(fd, request, argument);
}

int setsockopt(int fd, int level, int option, const void *value,
               socklen_t length)
{
    static setsockopt_fn real_setsockopt;

    /*
     * QEMU user mode cannot translate the daemon's MIPS IP_MULTICAST_IF
     * request in this container. SSDP announcements are irrelevant to the
     * loopback HTTP-parser test, so allow only that option to proceed.
     */
    if (level == IPPROTO_IP && option == IP_MULTICAST_IF)
        return 0;

    if (!real_setsockopt)
        real_setsockopt = (setsockopt_fn)dlsym(RTLD_NEXT, "setsockopt");

    return real_setsockopt(fd, level, option, value, length);
}
