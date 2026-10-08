//Practical 4 — Orphan and Zombie Process
//Part A — Orphan Process
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
        printf("Child before parent termination\n");

        printf("PID = %d, PPID = %d\n",
               (int)getpid(),
               (int)getppid());

        sleep(5);

        printf("Child after parent termination\n");

        printf("PID = %d, PPID = %d\n",
               (int)getpid(),
               (int)getppid());
    }
    else
    {
        printf("Parent PID = %d\n", (int)getpid());
        printf("Parent is terminating.\n");

        exit(EXIT_SUCCESS);
    }

    return EXIT_SUCCESS;
}