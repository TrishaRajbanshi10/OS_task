#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket < 0)
    {
        printf("Socket creation failed.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(client_socket,
               (struct sockaddr *)&server_addr,
               sizeof(server_addr)) < 0)
    {
        printf("Connection failed.\n");
        return 1;
    }

    printf("=====================================\n");
    printf(" Connected to Server\n");
    printf("=====================================\n\n");

    printf("Enter your message: ");
    fgets(message, BUFFER_SIZE, stdin);

    send(client_socket, message, strlen(message), 0);

    recv(client_socket, buffer, BUFFER_SIZE, 0);

    printf("\nServer Response: %s\n", buffer);

    close(client_socket);

    return 0;
}
