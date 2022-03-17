#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
void str_echo(int connfd, int port)
{
    int n, bufsize = 1024, len;
    char *buff = malloc(bufsize);
    struct sockaddr_in addr;
again:
    while ((n = recv(connfd, buff, bufsize, 0)) > 0)
    {
        
        fputs(buff, stdout);

        fgets(buff, bufsize, stdin);
        send(connfd, buff, n, 0);
    }
    if (n < 0)
        goto again;
}
int main()
{
    int listenfd, connfd, addrlen, pid;
    struct sockaddr_in address;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(15001);
    bind(listenfd, (struct sockaddr *)&address, sizeof(address));

    listen(listenfd, 3);

    for (;;)
    {
        addrlen = sizeof(struct sockaddr_in);
        connfd = accept(listenfd, (struct sockaddr *)&address, &addrlen);

        if ((pid = fork()) == 0)
        {
            close(listenfd);
            str_echo(connfd, address.sin_port);
            exit(0);
        }
        close(connfd);
    }
    return 0;
}
