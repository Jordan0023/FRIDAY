/*
 * Flash-only substitution for the isolated RAX36 datalib service.
 *
 * A failed initial read makes the genuine daemon load its compiled factory
 * defaults. Writes are acknowledged because the VM has no router MTD device.
 * Datalib IPC, parsing, state transitions, and config persistence remain real.
 */
int dni_mtd_read(const char *device, void *buffer, unsigned int length)
{
    (void)device;
    (void)buffer;
    (void)length;
    return -1;
}

int dni_mtd_write(const char *device, ...)
{
    (void)device;
    return 0;
}
