// Practical 5 — Implementation of Pipe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    pid_t pid;

    char message[] = "Graphic Era";
    char buffer[100];

    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return EXIT_FAILURE;
    }

    // Create child
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return EXIT_FAILURE;
    }

    // Child process
    if (pid == 0)
    {
        close(fd[0]);   // Child does not read

        write(fd[1], message, strlen(message) + 1);

        printf("Child wrote: %s\n", message);

        close(fd[1]);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    else
    {
        close(fd[1]);   // Parent does not write

        read(fd[0], buffer, sizeof(buffer));

        printf("Parent read: %s\n", buffer);

        close(fd[0]);

        wait(NULL);
    }

    return EXIT_SUCCESS;
}