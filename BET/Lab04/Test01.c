#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    fork(); //splits main process into parent and child
    fork(); //splits main and child again

    fprintf(stdout,"Hello World\n");//all four processes should print this
    
    return 0;
}