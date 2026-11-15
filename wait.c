#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int nums[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    pid_t pid = fork();
    if(pid < 0)
    {
        printf("Fork failed\n");
        return EXIT_FAILURE;
    }
    if(pid == 0)
    {
        int oddsum = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 != 0)
            {
                oddsum = oddsum + nums[i];
            }
        }
        printf("Child: Odd sum = %d\n", oddsum);
    }
    else
    {
        wait(NULL);
        int evensum = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
            {
                evensum = evensum + nums[i];
            }
        }
        printf("Parent: Even sum = %d\n", evensum);
    }
    return EXIT_SUCCESS;
}