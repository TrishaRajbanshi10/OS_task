#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void showPermissions(char filename[])
{
    struct stat fileStat;

    if (stat(filename, &fileStat) == -1)
    {
        printf("\nFile does not exist.\n");
        return;
    }

    printf("\nCurrent Permissions of %s\n", filename);

    printf("Owner : ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x\n" : "-\n");

    printf("Group : ");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x\n" : "-\n");

    printf("Others: ");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x\n" : "-\n");
}

void makeReadOnly(char filename[])
{
    if(chmod(filename, 0444) == 0)
        printf("\nFile changed to READ ONLY.\n");
    else
        printf("\nError changing permission.\n");
}

void makeReadWrite(char filename[])
{
    if(chmod(filename, 0666) == 0)
        printf("\nFile changed to READ & WRITE.\n");
    else
        printf("\nError changing permission.\n");
}

int main()
{
    int choice;
    char filename[100];

    printf("===== File Permission Manager =====\n");

    printf("Enter filename: ");
    scanf("%s", filename);

    do
    {
        printf("\n1. View Permissions\n");
        printf("2. Make Read Only\n");
        printf("3. Make Read & Write\n");
        printf("4. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                showPermissions(filename);
                break;

            case 2:
                makeReadOnly(filename);
                break;

            case 3:
                makeReadWrite(filename);
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    }while(choice!=4);

    return 0;
}
