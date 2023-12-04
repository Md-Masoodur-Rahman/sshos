#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define a semaphore
sem_t semaphore;

// Function representing the critical section
void *critical_section(void *arg) {
    // Wait for the semaphore to be available
    sem_wait(&semaphore);

    // Critical section
    printf("Thread %ld in critical section.\n", (long)arg);

    // Simulate some work
    sleep(2);

    // Release the semaphore
    sem_post(&semaphore);

    return NULL;
}

int main() {
    // Initialize the semaphore with an initial value of 1
    if (sem_init(&semaphore, 0, 1) == -1) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }

    // Create threads
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, critical_section, (void *)1) != 0 ||
        pthread_create(&thread2, NULL, critical_section, (void *)2) != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    // Wait for threads to finish
    if (pthread_join(thread1, NULL) != 0 || pthread_join(thread2, NULL) != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}
