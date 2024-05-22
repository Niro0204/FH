#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    int id = fork();
    
    if(id == 0){ //if the id is 0 it is the child process
        int id2 = fork(); //child process gets forked again
        fprintf(stdout,"id2: %d\n", id2); //should be printed twice
    }
    else{
        fprintf(stdout,"id: %d\n", id); //should be printed only once
    }
    return 0;
}