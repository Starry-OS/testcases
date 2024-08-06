#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdbool.h>

#define PORT 12345

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void test_multi_bind(bool is_reuse) {
    int sock1, sock2;
    int enable = 1;
    struct sockaddr_in addr;

    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sock1, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    addr.sin_port = htons(PORT);
    if (bind(sock1, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        error("Bind failed");
    }

    sock2 = socket(AF_INET, SOCK_STREAM, 0);
    if (is_reuse) {
        setsockopt(sock2, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    }
    if (bind(sock2, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        error("ERROR on binding second socket");
    }
    printf("Both sockets bound successfully to port %d\n", PORT);
    close(sock1);
    close(sock2);
}

int main() {
    bool is_reuse = false;       // 同时测试true和false两种情况在Starry中显示比较混乱，因此手动设置打开或关闭SO_REUSEADDR
    test_multi_bind(is_reuse);
    return 0;
}