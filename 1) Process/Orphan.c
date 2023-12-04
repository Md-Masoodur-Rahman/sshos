#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void create_orphan_process() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID %d) is sleeping for a while\n", getpid());
        sleep(5);
        printf("Parent process (PID %d) is done sleeping and exiting\n", getpid());
        // The parent exits, leaving the child as an orphan
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID %d) is running\n", getpid());
        printf("Child process (PID %d) is adopted by init (PID 1) after the parent exits\n", getpid());
        sleep(10);
        printf("Child process (PID %d) is done sleeping and exiting\n", getpid());
    } else {
        // Fork failed
        perror("Error: Fork failed\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    create_orphan_process();
    return 0;
}
