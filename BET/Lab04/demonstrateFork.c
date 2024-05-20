
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int globalVar = 0;  // Globale Variable

void demonstrateFork() {
    int localVar = 0;  // Lokale Variable
    int *dynamicVar = malloc(sizeof(int));  // Dynamisch allokierte Variable
    *dynamicVar = 0;

    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Kindprozess
        globalVar++;
        localVar++;
        (*dynamicVar)++;
        dprintf(fd, "Kindprozess: globalVar = %d, localVar = %d, dynamicVar = %d\n", globalVar, localVar, *dynamicVar);

        int *childAlloc = malloc(sizeof(int));  // Dynamische Allokation im Kindprozess
        *childAlloc = 100;
        printf("Kindprozess: childAlloc = %d\n", *childAlloc);

        close(fd);
        free(childAlloc);  // Freigeben des im Kindprozess allokierten Speichers
        exit(0);
    } else {
        // Elternprozess
        wait(NULL);  // Warten auf den Kindprozess
        dprintf(fd, "Elternprozess: globalVar = %d, localVar = %d, dynamicVar = %d\n", globalVar, localVar, *dynamicVar);

        int *parentAlloc = malloc(sizeof(int));  // Dynamische Allokation im Elternprozess
        *parentAlloc = 200;
        printf("Elternprozess: parentAlloc = %d\n", *parentAlloc);

        close(fd);
        free(parentAlloc);  // Freigeben des im Elternprozess allokierten Speichers
    }

    free(dynamicVar);  // Freigeben des ursprünglich allokierten Speichers
}

int main() {
    demonstrateFork();
    return 0;
}