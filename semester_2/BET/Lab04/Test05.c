#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int *ptr;

    int id = fork();

    if (id == 0)
    {
        // child
        ptr = malloc(sizeof(int));
        *ptr = 10;
        printf("child: %d\n", *ptr);
    }
    else 
    {
        // parent
        ptr = malloc(sizeof(int));
        *ptr = 15;
        printf("parent: %d\n", *ptr);
    }

    free(ptr);

    return 0;
}