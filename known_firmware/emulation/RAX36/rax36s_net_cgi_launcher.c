#include <unistd.h>

int main(void)
{
    execl(
        "/qemu-arm-static",
        "qemu-arm-static",
        "-E",
        "LD_PRELOAD=/lib/rax36s_web_shim.so",
        "/usr/sbin/net-cgi",
        (char *)0
    );
    return 127;
}
