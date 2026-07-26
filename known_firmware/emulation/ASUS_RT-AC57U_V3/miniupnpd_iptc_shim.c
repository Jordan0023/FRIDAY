/*
 * Isolated MiniUPnPd parser-lab shim.
 *
 * It replaces firewall bookkeeping only. No packet parsing, HTTP, SOAP, GENA,
 * or daemon control flow is changed.
 */
#include <stddef.h>

static unsigned char handle_storage;

void *iptc_init(const char *table) {
    (void)table;
    return &handle_storage;
}

int iptc_is_chain(const char *chain, const void *handle) {
    (void)chain;
    (void)handle;
    return 1;
}

int iptc_commit(void *handle) {
    (void)handle;
    return 1;
}

const void *iptc_first_rule(const char *chain, void *handle) {
    (void)chain;
    (void)handle;
    return NULL;
}

const void *iptc_next_rule(const void *previous, void *handle) {
    (void)previous;
    (void)handle;
    return NULL;
}

const char *iptc_get_target(const void *entry, void *handle) {
    (void)entry;
    (void)handle;
    return "";
}

int iptc_append_entry(const char *chain, const void *entry, void *handle) {
    (void)chain;
    (void)entry;
    (void)handle;
    return 1;
}

int iptc_replace_entry(const char *chain, const void *entry, unsigned index,
                       void *handle) {
    (void)chain;
    (void)entry;
    (void)index;
    (void)handle;
    return 1;
}

int iptc_delete_num_entry(const char *chain, unsigned index, void *handle) {
    (void)chain;
    (void)index;
    (void)handle;
    return 1;
}

void iptc_free(void *handle) {
    (void)handle;
}

const char *iptc_strerror(int error) {
    (void)error;
    return "isolated parser lab";
}

/*
 * QEMU user mode cannot translate this firmware's MIPS multicast-interface
 * setsockopt correctly. The lab does not exercise SSDP transmission, so make
 * socket-option bookkeeping a no-op while retaining real socket/bind/listen,
 * accept, recv, and send behavior.
 */
int setsockopt(int fd, int level, int option, const void *value, unsigned length) {
    (void)fd;
    (void)level;
    (void)option;
    (void)value;
    (void)length;
    return 0;
}
