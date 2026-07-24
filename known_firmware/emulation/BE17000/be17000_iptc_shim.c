/*
 * Minimal libiptc compatibility shim for the isolated BE17000 parser lab.
 *
 * The emulated daemon has no external network and must never alter host
 * firewall state. These symbols satisfy its startup bookkeeping while leaving
 * the genuine firmware HTTP, SOAP, and MiniXML code untouched.
 */

static int fake_handle;

void *iptc_init(const char *table)
{
    (void)table;
    return &fake_handle;
}

int iptc_is_chain(const char *chain, const void *handle)
{
    (void)chain;
    (void)handle;
    return 1;
}

int iptc_commit(void *handle)
{
    (void)handle;
    return 1;
}

void iptc_free(void *handle)
{
    (void)handle;
}

const char *iptc_strerror(int error)
{
    (void)error;
    return "BE17000 isolated firewall emulation";
}

const void *iptc_first_rule(const char *chain, void *handle)
{
    (void)chain;
    (void)handle;
    return (void *)0;
}

const void *iptc_next_rule(const void *previous, void *handle)
{
    (void)previous;
    (void)handle;
    return (void *)0;
}

const char *iptc_get_target(const void *entry, void *handle)
{
    (void)entry;
    (void)handle;
    return "";
}

int iptc_append_entry(const char *chain, const void *entry, void *handle)
{
    (void)chain;
    (void)entry;
    (void)handle;
    return 1;
}

int iptc_replace_entry(const char *chain, const void *entry, unsigned int number, void *handle)
{
    (void)chain;
    (void)entry;
    (void)number;
    (void)handle;
    return 1;
}

int iptc_delete_num_entry(const char *chain, unsigned int number, void *handle)
{
    (void)chain;
    (void)number;
    (void)handle;
    return 1;
}

/*
 * qemu-user on this host returns ENOPROTOOPT for the firmware's ARM
 * IP_MULTICAST_IF option layout. The lab is network-disabled, so acknowledge
 * socket options and retain the daemon's real bind/listen/recv/send behavior.
 */
int setsockopt(int fd, int level, int option, const void *value, unsigned int length)
{
    (void)fd;
    (void)level;
    (void)option;
    (void)value;
    (void)length;
    return 0;
}
