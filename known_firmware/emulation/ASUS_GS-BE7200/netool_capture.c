#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/var/run/netool_socket"
#define CAPTURE_PATH "/www/images/netool_capture.png"

int main(void)
{
    int server;
    struct sockaddr_un address;

    unlink(SOCKET_PATH);
    server = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server < 0)
        return 1;
    memset(&address, 0, sizeof(address));
    address.sun_family = AF_UNIX;
    snprintf(address.sun_path, sizeof(address.sun_path), "%s", SOCKET_PATH);
    if (bind(server, (struct sockaddr *)&address, sizeof(address)) < 0)
        return 2;
    chmod(SOCKET_PATH, 0666);
    if (listen(server, 8) < 0)
        return 3;

    for (;;) {
        unsigned char request[0x148];
        size_t used = 0;
        int client = accept(server, NULL, NULL);
        if (client < 0)
            continue;
        while (used < sizeof(request)) {
            ssize_t count = read(client, request + used, sizeof(request) - used);
            if (count <= 0)
                break;
            used += (size_t)count;
        }
        close(client);
        if (used != 0) {
            int output = open(CAPTURE_PATH, O_WRONLY | O_CREAT | O_APPEND, 0666);
            if (output >= 0) {
                write(output, &used, sizeof(used));
                write(output, request, used);
                close(output);
            }
        }
    }
}
