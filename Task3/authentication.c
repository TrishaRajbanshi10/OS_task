#include <stdio.h>
#include <string.h>

int main()
{
    char username[30];
    char password[30];

    char correctUsername[] = "admin";
    char correctPassword[] = "password123";

    printf("===== User Authentication =====\n\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    if(strcmp(username, correctUsername) == 0 &&
       strcmp(password, correctPassword) == 0)
    {
        printf("\nLogin Successful!\n");
        printf("Welcome %s\n", username);
    }
    else
    {
        printf("\nLogin Failed!\n");
        printf("Invalid username or password.\n");
    }

    return 0;
}
