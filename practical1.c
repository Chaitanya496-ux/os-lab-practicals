//Practical 1 — Demonstration of fork() System Call
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    printf("LINUX\n");

    return EXIT_SUCCESS;
}