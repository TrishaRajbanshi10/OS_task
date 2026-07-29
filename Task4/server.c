#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, client_socket;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(server_fd < 0)
    {
        printf("Socket creation failed.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Bind failed.\n");
        return 1;
    }

    listen(server_fd, 5);

    printf("=====================================\n");
    printf(" Server Started\n");
    printf(" Listening on Port %d\n", PORT);
    printf("=====================================\n");

    client_socket = accept(server_fd, (struct sockaddr *)&server_addr, &addr_len);

    if(client_socket < 0)
    {
        printf("Connection failed.\n");
        return 1;
    }

    printf("Client connected successfully.\n");

    recv(client_socket, buffer, BUFFER_SIZE, 0);

    printf("Client Message : %s\n", buffer);

    send(client_socket,
         "Message received successfully.",
         strlen("Message received successfully."),
         0);

    close(client_socket);
    close(server_fd);

    return 0;
}
