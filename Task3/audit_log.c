#include <stdio.h>
#include <time.h>

int main()
{
    FILE *logFile;
    time_t currentTime;
    char *timeString;

    logFile = fopen("audit_log.txt", "a");

    if(logFile == NULL)
    {
        printf("Error opening audit log file.\n");
        return 1;
    }

    time(&currentTime);
    timeString = ctime(&currentTime);

    fprintf(logFile, "========== Audit Log ==========\n");
    fprintf(logFile, "Timestamp : %s", timeString);
    fprintf(logFile, "User      : admin\n");
    fprintf(logFile, "Action    : Login\n");
    fprintf(logFile, "Status    : Success\n\n");

    fclose(logFile);

    printf("===== Audit Log System =====\n\n");
    printf("Audit log recorded successfully.\n");

    return 0;
}
