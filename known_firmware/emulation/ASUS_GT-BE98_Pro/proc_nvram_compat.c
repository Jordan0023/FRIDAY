#define _GNU_SOURCE
#include <dlfcn.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/*
 * Ubuntu's current cross toolchain binds dlsym to GLIBC_2.34 by default.
 * Asuswrt's ARM userspace exports the original GLIBC_2.4 symbol, so request
 * that ABI explicitly to keep this preload helper compatible with the stock
 * dynamic loader.
 */
__asm__(".symver dlsym,dlsym@GLIBC_2.4");

static const char *redirect(const char *path)
{
    static __thread char mapped[512];
    const char *suffix = NULL;
    const char *base = NULL;

    if (path && strncmp(path, "/proc/nvram/", 12) == 0) {
        suffix = path + 12;
        base = "/run/proc-nvram/";
    } else if (path && strncmp(path, "/proc/environment/", 18) == 0) {
        suffix = path + 18;
        base = "/run/proc-environment/";
    }
    if (!suffix)
        return path;
    snprintf(mapped, sizeof(mapped), "%s%s", base, suffix);
    return mapped;
}

int open(const char *path, int flags, ...)
{
    static int (*real_open)(const char *, int, ...) = NULL;
    mode_t mode = 0;
    if (!real_open)
        real_open = dlsym(RTLD_NEXT, "open");
    if (flags & O_CREAT) {
        va_list ap;
        va_start(ap, flags);
        mode = va_arg(ap, mode_t);
        va_end(ap);
        return real_open(redirect(path), flags, mode);
    }
    return real_open(redirect(path), flags);
}

int open64(const char *path, int flags, ...)
{
    static int (*real_open64)(const char *, int, ...) = NULL;
    mode_t mode = 0;
    if (!real_open64)
        real_open64 = dlsym(RTLD_NEXT, "open64");
    if (flags & O_CREAT) {
        va_list ap;
        va_start(ap, flags);
        mode = va_arg(ap, mode_t);
        va_end(ap);
        return real_open64(redirect(path), flags, mode);
    }
    return real_open64(redirect(path), flags);
}

FILE *fopen(const char *path, const char *mode)
{
    static FILE *(*real_fopen)(const char *, const char *) = NULL;
    if (!real_fopen)
        real_fopen = dlsym(RTLD_NEXT, "fopen");
    return real_fopen(redirect(path), mode);
}

FILE *fopen64(const char *path, const char *mode)
{
    static FILE *(*real_fopen64)(const char *, const char *) = NULL;
    if (!real_fopen64)
        real_fopen64 = dlsym(RTLD_NEXT, "fopen64");
    return real_fopen64(redirect(path), mode);
}
