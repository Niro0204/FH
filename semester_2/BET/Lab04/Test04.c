#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]){

    int *ptr = malloc(sizeof(int));
    *ptr = 10;

    int id = fork();

    if (id == 0)
    {
        //child
        printf("child: %d\n", *ptr);
        *ptr = 0;
        printf("child new: %d\n", *ptr);
    }
    else 
    {
        //parent
        printf("parent: %d\n", *ptr);
        *ptr = 1;
        printf("parent new: %d\n", *ptr);
    }

    free(ptr);

    return 0;
}