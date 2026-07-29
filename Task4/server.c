#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *arg)
{
    int client_socket = *(int *)arg;
    free(arg);

    char buffer[BUFFER_SIZE];

    recv(client_socket, buffer, sizeof(buffer), 0);

    char username[50];
    char password[50];

    sscanf(buffer, "%49s %49s", username, password);

    if(strcmp(username, "admin") != 0 ||
       strcmp(password, "password123") != 0)
    {
        send(client_socket,
             "Authentication Failed",
             21,
             0);

        close(client_socket);
        pthread_exit(NULL);
    }

    send(client_socket,
         "Authentication Successful",
         26,
         0);

    memset(buffer, 0, sizeof(buffer));

    recv(client_socket, buffer, sizeof(buffer), 0);

    if(strlen(buffer) == 0)
    {
        send(client_socket,
             "Invalid Message",
             15,
             0);
    }
    else
    {
        printf("\nClient Message: %s\n", buffer);

        send(client_socket,
             "Message received successfully.",
             30,
             0);
    }

    close(client_socket);

    pthread_exit(NULL);
}

int main()
{
    int server_fd;

    struct sockaddr_in server_addr;

    server_fd = socket(AF_INET,
                       SOCK_STREAM,
                       0);

    if(server_fd < 0)
    {
        perror("Socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd,
         (struct sockaddr *)&server_addr,
         sizeof(server_addr));

    listen(server_fd, 5);

    printf("===================================\n");
    printf(" Secure Multi-threaded Server\n");
    printf(" Listening on Port %d\n", PORT);
    printf("===================================\n");

    while(1)
    {
        int *client_socket = malloc(sizeof(int));

        socklen_t addr_len = sizeof(server_addr);

        *client_socket =
            accept(server_fd,
                   (struct sockaddr *)&server_addr,
                   &addr_len);

        pthread_t tid;

        pthread_create(&tid,
                       NULL,
                       handle_client,
                       client_socket);

        pthread_detach(tid);
    }

    close(server_fd);

    return 0;
}
