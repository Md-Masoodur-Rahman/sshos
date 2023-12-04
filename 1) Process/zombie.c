#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void create_zombie_process() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID %d) created child process (PID %d)\n", getpid(), pid);
        sleep(5);  // Parent sleeps for a while, giving child time to exit

        // The parent process does not wait for the child, causing it to become a zombie
        printf("Parent process (PID %d) exiting without waiting for the child\n", getpid());
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID %d) starting and exiting immediately\n", getpid());
        // Simulate some work
        sleep(2);
        // Child exits
        exit(0);
    } else {
        // Fork failed
        perror("Error: Fork failed\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    create_zombie_process();
    return 0;
}
