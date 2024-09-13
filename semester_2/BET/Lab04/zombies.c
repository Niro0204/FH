#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_zombies> <number_of_seconds>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_zombies = atoi(argv[1]); // Convert command line argument to integer
    int num_seconds = atoi(argv[2]);

    if (num_zombies <= 0) {
        fprintf(stderr, "Number of zombies must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    printf("Creating %d zombies for %d seconds...\n", num_zombies, num_seconds);

    for (int i = 0; i < num_zombies; ++i) {
        int pid = fork();

        if (pid < 0) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            printf("Zombie process %d created.\n", i + 1);
            exit(EXIT_SUCCESS); // Exit the child process immediately
        }
    }

    // Sleep to allow zombies to remain
    sleep(num_seconds);

    // Parent process waits for child processes to prevent zombies from being reaped immediately
    for (int i = 0; i < num_zombies; ++i) {
        wait(NULL);
    }

    printf("All zombie processes have been created and terminated.\n");

    return 0;
}
