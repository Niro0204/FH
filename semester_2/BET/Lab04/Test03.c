#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int global = 10;

int main(int argc, char* argv[]){

    //some test data
    int num = 5;
    int arr[5] = {1,2,3,4,5};
    int *ptr = num;
    int id = fork();

    //changing variables in the child process
    if(id == 0){
        num = 0;
        arr[2] = 0;
        ptr = NULL;
        global = 2;
    }

    //parent and child print their variables
    fprintf(stdout,"id: %d\nnumber: %d\npointer: %p\nglobal: %d\n",id,num,ptr,global);
    for(int i = 0; i < 5; i++){
        fprintf(stdout,"%d",arr[i]);
    }
 
    fprintf(stdout,"\n");
    return 0;
}