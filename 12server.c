#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int sockfd,newsockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero( &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
    bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(sockfd, 10);
    newsockfd= accept(sockfd, (struct sockaddr*) NULL, NULL);
    while(1)
    {
        bzero( str, 100);
        read(newsockfd,str,100);
        printf("Echoing back - %s",str);
        write(newsockfd, str, strlen(str)+1);
    }
}
