#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;

int main(int argc, char *argv[]){


    if(argc < 3){
        fprintf(stderr,"not enough parameters given");
        fprintf(stdout,"usage:\n./threadsTest <number to count to> <number of counting threads>");
    }

    int numThreads = atoi(argv[argc-1]);
    int check;
    fprintf(stdout,"creating %d threads...", numThreads);

    for(int i = 0; i <= numThreads; i++){

        check = pthread_create();
    }


    return 0;
}

