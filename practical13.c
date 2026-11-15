#include <stdio.h>

int main()
{
    int n, f, i, j;
    int pages[50], frames[20], time[20];
    int faults = 0, counter = 0;
    int found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        found = 0;
        counter++;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                time[j] = counter;
                break;
            }
        }

        if (found == 0)
        {
            pos = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                min = time[0];
                pos = 0;

                for (j = 1; j < f; j++)
                {
                    if (time[j] < min)
                    {
                        min = time[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            time[pos] = counter;
            faults++;
        }

        printf("\nPage %d: ", pages[i]);

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if (found == 0)
            printf("Page Fault");
        else
            printf("Page Hit");
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}