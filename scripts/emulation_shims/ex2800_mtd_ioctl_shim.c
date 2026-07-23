/*
 * Minimal EX2800 MTD ioctl shim for user-mode emulation.
 *
 * The original logic daemon expects the MT7628 flash driver to implement
 * ioctl 0xc0104704. QEMU user mode forwards it to a regular file and returns
 * ENOSYS, which triggers logic.c's startup assertion.  Succeed only for that
 * hardware-specific request; do not emulate or alter any application IPC.
 */

#define EX2800_MTD_IOCTL 0xc0104704UL

int ioctl(int fd, unsigned long request, ...)
{
    (void)fd;

    if (request == EX2800_MTD_IOCTL)
        return 0;

    return -1;
}
