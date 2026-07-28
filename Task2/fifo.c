#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f;
    int pageFaults = 0;
    int index = 0;

    printf("===== FIFO Page Replacement =====\n\n");

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(int i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for(int i = 0; i < n; i++)
    {
        int found = 0;

        for(int j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frames[index] = pages[i];
            index = (index + 1) % f;
            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for(int j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults : %d\n", pageFaults);

    return 0;
}
