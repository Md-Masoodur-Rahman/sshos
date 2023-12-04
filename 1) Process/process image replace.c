#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("This is the original process.\n");

    // Fork to create a new process
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("This is the child process.\n");

        // Replace the child process image with a new one (e.g., ls command)
        execlp("ls", "ls", "-l", NULL);

        // If execlp fails
        perror("Error: execlp");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        // Wait for the child to finish
        wait(NULL);

        printf("Back to the parent process.\n");
    } else {
        // Fork failed
        perror("Error: fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}
