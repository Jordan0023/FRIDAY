typedef unsigned char u_char;
typedef unsigned int uint32_t;
typedef unsigned int size_t;
struct timeval { int tv_sec, tv_usec; };
extern void *mmap(void *, size_t, int, int, int, int);
extern int mprotect(void *, size_t, int);
extern void *memset(void *, int, size_t);
extern char *getenv(const char *);
extern void _exit(int);
#define PROT_NONE 0
#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 0x20
typedef struct pcap pcap_t;
struct pcap_pkthdr { struct timeval ts; uint32_t caplen, len; };
struct bpf_program { unsigned int bf_len; void *bf_insns; };
typedef void (*pcap_handler)(u_char *, const struct pcap_pkthdr *, const u_char *);

pcap_t *pcap_open_live(const char *d, int s, int p, int t, char *e) { return (pcap_t *)1; }
int pcap_compile(pcap_t *p, struct bpf_program *b, const char *s, int o, uint32_t n) { return 0; }
int pcap_setfilter(pcap_t *p, struct bpf_program *b) { return 0; }
void pcap_breakloop(pcap_t *p) {}
char *pcap_geterr(pcap_t *p) { return "FRIDAY_SHIM"; }

int pcap_loop(pcap_t *p, int count, pcap_handler cb, u_char *user) {
    const int candidate = getenv("FRIDAY_DHCPSNIFF_CANDIDATE") != 0;
    const size_t pagesz = 4096;
    unsigned char *map = mmap(0, pagesz * 2, PROT_READ|PROT_WRITE,
                              MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    size_t caplen = candidate ? 282 : 283;
    unsigned char *pkt = map + pagesz - caplen;
    memset(pkt, 0, caplen);
    mprotect(map + pagesz, pagesz, PROT_NONE);
    pkt[12]=0x08; pkt[13]=0x00;       /* IPv4 */
    pkt[14]=0x45; pkt[23]=17;         /* IPv4, UDP */
    pkt[38]=candidate ? 0x05 : 0x00;
    pkt[39]=candidate ? 0xdc : 0xf9;  /* candidate 1500; control 249 */
    pkt[278]=0x63; pkt[279]=0x82; pkt[280]=0x53; pkt[281]=0x63;
    if (!candidate) pkt[282]=0xff;     /* DHCP END inside control capture */
    struct pcap_pkthdr h = {{0,0}, (uint32_t)caplen, (uint32_t)caplen};
    cb(user, &h, pkt);
    _exit(0);
    return 0;
}
