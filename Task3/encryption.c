#include <stdio.h>

void encryptDecrypt(char *inputFile, char *outputFile, char key)
{
    FILE *input;
    FILE *output;

    char ch;

    input = fopen(inputFile, "r");

    if(input == NULL)
    {
        printf("Unable to open input file.\n");
        return;
    }


    output = fopen(outputFile, "w");

    if(output == NULL)
    {
        printf("Unable to create output file.\n");
        fclose(input);
        return;
    }


    while((ch = fgetc(input)) != EOF)
    {
        ch = ch ^ key;

        fputc(ch, output);
    }


    fclose(input);
    fclose(output);
}


int main()
{
    char filename[50];
    char encryptedFile[50];

    char key = 'K';


    printf("===== File Encryption System =====\n\n");


    printf("Enter file name to encrypt: ");
    scanf("%s", filename);


    printf("Enter encrypted file name: ");
    scanf("%s", encryptedFile);


    encryptDecrypt(filename, encryptedFile, key);


    printf("\nFile encrypted successfully.\n");


    return 0;
}
