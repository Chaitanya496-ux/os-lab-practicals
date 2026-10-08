//Practical 2 — Parent/Child Computation
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 100

int main(void)
{
    int a[MAX];
    int n, i;
    pid_t pid;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid array size.\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d elements: ", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    else if (pid == 0)
    {
        int evenSum = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                evenSum += a[i];
        }

        printf("Child: Sum of even numbers = %d\n",
               evenSum);

        exit(EXIT_SUCCESS);
    }

    else
    {
        int oddSum = 0;

        wait(NULL);

        for (i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
                oddSum += a[i];
        }

        printf("Parent: Sum of odd numbers = %d\n",
               oddSum);
    }

    return EXIT_SUCCESS;
}