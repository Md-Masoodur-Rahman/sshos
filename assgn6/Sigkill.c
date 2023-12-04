#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void signal_handler(int signo) {
    if (signo == SIGKILL) {
        printf("Child: Received SIGKILL signal.\n");
    }
}

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent process (PID %d) is running.\n", getpid());
        signal(SIGKILL, signal_handler); // Install signal handler for SIGKILL
        sleep(10); // Parent sleeps for a while
        printf("Parent process is done sleeping.\n");
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID %d) is running.\n", getpid());
        kill(getppid(), SIGKILL); // Send SIGKILL signal to the parent
        printf("Child process is done.\n");
    } else {
        perror("Error: Fork failed\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
