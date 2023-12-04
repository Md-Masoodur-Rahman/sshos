#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signo) {
    if (signo == SIGSTOP) {
        printf("Received SIGSTOP signal. Process is paused.\n");
        // You can perform additional actions before the process is paused
    }
}

int main() {
    // Install signal handler for SIGSTOP
    if (signal(SIGSTOP, signal_handler) == SIG_ERR) {
        perror("Error: Unable to register signal handler");
        exit(EXIT_FAILURE);
    }

    printf("Process (PID %d) is running.\n", getpid());

    // Simulate some work
    while (1) {
        sleep(1);
        printf("Working...\n");
    }

    return 0;  // This line will never be reached due to the infinite loop
}
