#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char text[100];

    printf("===== File Management =====\n\n");

    file = fopen("student.txt", "w");

    if(file == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter your name: ");
    fgets(text, sizeof(text), stdin);

    fprintf(file, "%s", text);

    fclose(file);

    printf("\nData successfully written to file.\n");

    file = fopen("student.txt", "r");

    if(file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nContents of File:\n");

    while(fgets(text, sizeof(text), file))
    {
        printf("%s", text);
    }

    fclose(file);

    return 0;
}
