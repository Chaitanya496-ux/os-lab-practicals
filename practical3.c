#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return EXIT_FAILURE;
    }

    if (pid == 0)
    {
        printf("Child process is running...\n");

        sleep(2);

        printf("Child process is terminating...\n");

        exit(10);
    }
    else
    {
        printf("Parent is waiting for child...\n");

        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child exited with status = %d\n",
                   WEXITSTATUS(status));
        }
        printf("Parent continues after child terminates.\n");
    }
    return EXIT_SUCCESS;
}