/*
 * Minimal libc-free ARM packet injector for the isolated AP120C hwsim lab.
 * It sends one bounded radiotap + 802.11 management-frame test case per run.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

#define AF_PACKET 17
#define SOCK_RAW 3
#define ETH_P_ALL 0x0003
#define SIOCGIFINDEX 0x8933

struct sockaddr_ll {
	u16 family;
	u16 protocol;
	int ifindex;
	u16 hatype;
	u8 pkttype;
	u8 halen;
	u8 address[8];
};

struct ifreq {
	char name[16];
	int ifindex;
	char padding[20];
};

static long syscall3(long n, long a, long b, long c)
{
	register long r7 __asm__("r7") = n;
	register long r0 __asm__("r0") = a;
	register long r1 __asm__("r1") = b;
	register long r2 __asm__("r2") = c;
	__asm__ volatile("svc 0" : "+r"(r0) : "r"(r7), "r"(r1), "r"(r2) : "memory");
	return r0;
}

static long syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	register long r7 __asm__("r7") = n;
	register long r0 __asm__("r0") = a;
	register long r1 __asm__("r1") = b;
	register long r2 __asm__("r2") = c;
	register long r3 __asm__("r3") = d;
	register long r4 __asm__("r4") = e;
	register long r5 __asm__("r5") = f;
	__asm__ volatile("svc 0" : "+r"(r0) :
		"r"(r7), "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5) : "memory");
	return r0;
}

static u16 be16(u16 value)
{
	return (u16)((value << 8) | (value >> 8));
}

static int decimal(const char *value)
{
	int result = 0;
	while (*value >= '0' && *value <= '9')
		result = result * 10 + (*value++ - '0');
	return result;
}

static void copy(u8 *to, const u8 *from, int length)
{
	while (length--)
		*to++ = *from++;
}

__attribute__((used)) void *memset(void *destination, int value, unsigned long length)
{
	u8 *output = destination;
	while (length--)
		*output++ = (u8)value;
	return destination;
}

static int inject(int test)
{
	static const u8 radiotap[8] = {0, 0, 8, 0, 0, 0, 0, 0};
	static const u8 broadcast[6] = {255, 255, 255, 255, 255, 255};
	static const u8 ap[6] = {2, 0, 0, 0, 0, 0};
	static const u8 station[6] = {2, 0, 0, 0, 1, 0};
	static const u8 bodies[][24] = {
		{0},                                      /* empty association body */
		{0, 0},                                   /* empty association */
		{0, 0, 0, 0},                             /* short authentication */
		{0, 0, 0, 0, 0, 0},                       /* auth algorithm/status edge */
		{1, 0, 0, 0},                             /* short probe request IE */
		{0x7f, 0xff, 0xff, 0xff},                 /* unknown action */
		{0, 0},                                   /* short deauthentication */
		{0, 0},                                   /* short disassociation */
		{0xdd, 0xff, 0, 1, 2, 3},                 /* oversized vendor IE */
		{0, 0xff, 0},                              /* oversized SSID IE */
	};
	static const u8 subtypes[] = {
		0x00, 0x00, 0xb0, 0xb0, 0x40, 0xd0, 0xc0, 0xa0, 0x00, 0x40
	};
	u8 frame[1600];
	struct ifreq request = {{0}, 0, {0}};
	struct sockaddr_ll target = {0};
	int fd, length, body_length, i;

	if (test < 0 || test >= 10)
		return 2;
	fd = (int)syscall3(281, AF_PACKET, SOCK_RAW, be16(ETH_P_ALL));
	if (fd < 0)
		return 3;
	request.name[0] = 'm'; request.name[1] = 'o'; request.name[2] = 'n';
	request.name[3] = '0';
	if (syscall3(54, fd, SIOCGIFINDEX, (long)&request) < 0)
		return 4;
	target.family = AF_PACKET;
	target.protocol = be16(ETH_P_ALL);
	target.ifindex = request.ifindex;
	if (syscall3(282, fd, (long)&target, sizeof(target)) < 0)
		return 5;

	copy(frame, radiotap, 8);
	frame[8] = subtypes[test];
	frame[9] = 0;
	frame[10] = frame[11] = 0;
	copy(frame + 12, test == 4 ? broadcast : ap, 6);
	copy(frame + 18, station, 6);
	copy(frame + 24, ap, 6);
	frame[30] = frame[31] = 0;
	body_length = test == 0 ? 0 : (test == 8 ? 6 : (test == 9 ? 3 :
		(test == 3 ? 6 : (test == 2 ? 4 : (test == 4 || test == 5 ? 4 : 2)))));
	copy(frame + 32, bodies[test], body_length);
	length = 32 + body_length;
	if (test == 8) {
		for (i = length; i < 512; i++)
			frame[i] = (u8)i;
		length = 512;
	}
	if (syscall6(290, fd, (long)frame, length, 0,
		     (long)&target, sizeof(target)) < 0)
		return 6;
	return 0;
}

__attribute__((used)) int main(int argc, char **argv)
{
	return argc == 2 ? inject(decimal(argv[1])) : 1;
}

__attribute__((naked, noreturn)) void _start(void)
{
	__asm__ volatile(
		"ldr r0, [sp]\n"
		"add r1, sp, #4\n"
		"bl main\n"
		"mov r7, #1\n"
		"svc 0\n");
}
