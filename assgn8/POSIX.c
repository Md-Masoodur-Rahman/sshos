#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function that will be executed by the child thread
void *childThreadFunction(void *arg) {
    printf("Child thread is executing\n");

    // Simulate some work in the child thread
    for (int i = 0; i < 5; ++i) {
        printf("Child thread: %d\n", i);
    }

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Declare a variable of type pthread_t to store the thread ID
    pthread_t childThread;

    // Create a new thread
    int threadCreationResult = pthread_create(&childThread, NULL, childThreadFunction, NULL);

    // Check if the thread creation was successful
    if (threadCreationResult != 0) {
        fprintf(stderr, "Error creating thread: %d\n", threadCreationResult);
        exit(EXIT_FAILURE);
    }

    printf("Main thread is waiting for the child thread to complete\n");

    // Wait for the child thread to complete
    int threadJoinResult = pthread_join(childThread, NULL);

    // Check if the thread join was successful
    if (threadJoinResult != 0) {
        fprintf(stderr, "Error joining thread: %d\n", threadJoinResult);
        exit(EXIT_FAILURE);
    }

    printf("Child thread has completed, and the main thread is exiting\n");

    // Exit the main thread
    pthread_exit(NULL);
}
