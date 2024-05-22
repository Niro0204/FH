#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int id;

    id = fork();

    if (id == 0) {
        //child
        fprintf(stdout,"child (ID: %d) ended\n", id);
        exit(0); //exiting child
    } else {
        //parent
        fprintf(stdout,"parent (ID: %d) sleeps\n", id);
        fprintf(stdout,"child is now a zombie\n");
        sleep(10); // parent has to wait, meanwhile child is a zombie
        
        // waiting for child to end the zombie
        wait(NULL);
        fprintf(stdout,"zombie terminated");
    }

    return 0;
}
