#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    const char *script = argc > 1 ? argv[1] : "/www/unauth.cgi";
    setenv("SCRIPT_FILENAME", script, 1);

    execl(
        "/qemu-arm-static",
        "qemu-arm-static",
        "-E",
        "LD_PRELOAD=/lib/rax78_popen_shim.so:/lib/rax36s_web_shim.so",
        "/usr/sbin/net-cgi",
        "-f",
        script,
        (char *)0
    );
    return 127;
}
