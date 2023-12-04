#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Fork a child process
    pid_t pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // This is the child process
        printf("Child Process: PID=%d, Parent PID=%d\n", getpid(), getppid());
        printf("Child Process: Hello from the child!\n");
        exit(EXIT_SUCCESS);
    } else {
        // This is the parent process
        printf("Parent Process: PID=%d, Child PID=%d\n", getpid(), pid);

        // Wait for the child process to finish
        wait(NULL);

        printf("Parent Process: Child process has finished.\n");
    }

    return 0;
}
