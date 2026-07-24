#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * Host-architecture shebang interpreter for a disposable EW1200 rootfs.
 *
 * Linux invokes this program as:
 *   /qemu-ucode-wrapper /www/cgi-bin/luci [cgi arguments...]
 *
 * It preserves the CGI environment and stdin/stdout, then runs the firmware's
 * genuine MIPS ucode interpreter with the firmware's own modules and script.
 */
int
main(int argc, char **argv)
{
	char **qargv;
	int i;

	if (argc < 2) {
		fputs("missing CGI script path\n", stderr);
		return 64;
	}

	qargv = calloc((size_t)argc + 9, sizeof(*qargv));
	if (qargv == NULL) {
		perror("calloc");
		return 70;
	}

	qargv[0] = "/qemu-mipsel-static";
	qargv[1] = "-L";
	qargv[2] = "/";
	qargv[3] = "/usr/bin/ucode";
	qargv[4] = "-L";
	qargv[5] = "/usr/lib/ucode";
	qargv[6] = "-L";
	qargv[7] = "/usr/share/ucode";

	for (i = 1; i < argc; i++)
		qargv[i + 7] = argv[i];

	execv(qargv[0], qargv);
	fprintf(stderr, "execv(%s): %s\n", qargv[0], strerror(errno));
	return 70;
}
