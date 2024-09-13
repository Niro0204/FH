#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

    FILE *fp = fopen("test.txt", "w");

    fprintf(fp, "Hello World\n");
    fflush(fp); // flush the buffer for fork

    int id = fork();

    if (id == 0)
    {
        //child
        fprintf(fp, "hello from child");
        fclose(fp);
    }
    else if (id > 0)
    {
        //parent
        wait(NULL); //wait for child
        fprintf(fp, "hello from parent");
        fclose(fp);
    }

    return 0;
}