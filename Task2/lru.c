#include <stdio.h>

int main()
{
    int pages[50], frames[10], recent[10];
    int n, f;
    int pageFaults = 0;
    int time = 0;

    printf("===== LRU Page Replacement =====\n\n");

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter page reference string:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(int i = 0; i < f; i++)
    {
        frames[i] = -1;
        recent[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for(int i = 0; i < n; i++)
    {
        int found = 0;

        for(int j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                recent[j] = ++time;
                break;
            }
        }

        if(!found)
        {
            int position = 0;

            for(int j = 1; j < f; j++)
            {
                if(recent[j] < recent[position])
                    position = j;
            }

            frames[position] = pages[i];
            recent[position] = ++time;
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
