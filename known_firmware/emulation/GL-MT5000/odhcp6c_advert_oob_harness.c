/*
 * Local sanitizer regression harness for OpenWrt odhcp6c commit 53f07e90.
 *
 * This contains no networking code and cannot transmit DHCPv6. It models the
 * exact faulty Advertise call boundary fixed upstream by b6f0c70.
 */
#include <stdint.h>
#include <stdlib.h>

#define dhcpv6_for_each_option(start, end, otype, olen, odata)              \
    for (uint8_t *_o = (uint8_t *)(start);                                  \
         _o + 4 <= (uint8_t *)(end) &&                                      \
         ((otype) = _o[0] << 8 | _o[1]) &&                                  \
         ((odata) = (void *)&_o[4]) &&                                      \
         ((olen) = _o[2] << 8 | _o[3]) + (odata) <= (uint8_t *)(end);       \
         _o += 4 + (olen))

struct dhcpv6_ia_hdr {
    uint16_t type;
    uint16_t len;
    uint32_t iaid;
    uint32_t t1;
    uint32_t t2;
};

static void parse_ia(void *opt, void *end)
{
    struct dhcpv6_ia_hdr *header = opt;
    uint16_t option_type, option_length;
    uint8_t *option_data;

    dhcpv6_for_each_option(
        &header[1], end, option_type, option_length, option_data) {
        (void)option_data;
    }
}

int main(int argc, char **argv)
{
    struct dhcpv6_ia_hdr *ia = calloc(1, sizeof(*ia));
    if (!ia)
        return 2;

    /*
     * Faulty 2021 Advertise path:
     *   odata + olen + sizeof(*ia_hdr)
     * With an empty IA at the end of a packet, this extends the parser's end
     * pointer 16 bytes beyond the allocation.
     */
    if (argc == 2 && argv[1][0] == 'f')
        parse_ia(ia, (uint8_t *)ia + sizeof(*ia));
    else
        parse_ia(ia, (uint8_t *)ia + sizeof(*ia) + sizeof(*ia));
    free(ia);
    return 0;
}
