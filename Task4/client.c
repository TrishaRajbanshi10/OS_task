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

    char username[50];
    char password[50];
    char credentials[100];

    char message[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(client_socket < 0)
    {
        perror("Socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(client_socket,
               (struct sockaddr *)&server_addr,
               sizeof(server_addr)) < 0)
    {
        perror("Connect");
        return 1;
    }

    printf("===== Client Login =====\n\n");

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    sprintf(credentials, "%s %s", username, password);

    send(client_socket,
         credentials,
         strlen(credentials) + 1,
         0);

    memset(buffer, 0, sizeof(buffer));

    recv(client_socket,
         buffer,
         sizeof(buffer),
         0);

    printf("\n%s\n", buffer);

    if(strcmp(buffer, "Authentication Successful") != 0)
    {
        close(client_socket);
        return 0;
    }

    getchar();

    printf("\nEnter message: ");

    fgets(message,
          sizeof(message),
          stdin);

    send(client_socket,
         message,
         strlen(message) + 1,
         0);

    memset(buffer, 0, sizeof(buffer));

    recv(client_socket,
         buffer,
         sizeof(buffer),
         0);

    printf("\nServer Response: %s\n",
           buffer);

    close(client_socket);

    return 0;
}
