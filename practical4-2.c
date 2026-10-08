//Part B — Zombie Process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }
    if (pid == 0)
    {
        printf("Child terminating...\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Parent sleeping for 20 seconds...\n");
        sleep(20);
    }
    return EXIT_SUCCESS;
}