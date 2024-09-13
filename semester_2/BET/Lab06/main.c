#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//Definition der Funktionen
void* countUp(void* countNum);
void countCheck(int);

//Deklaration und Initialisierung von Variablen
int count = 0;
int count2 = 0;
pthread_mutex_t countMutex = PTHREAD_MUTEX_INITIALIZER;
int useMutex = 0;

//main-Funktion
int main(int argc, char *argv[]){
    //Überprüfen ob genügend Parameter
    if(argc < 4){
        fprintf(stderr,"not enough parameters given\n");
        fprintf(stdout,"usage:\n./threadsTest <number to count to> <number of counting threads> <use mutex (0 or 1)>\n");
        exit(EXIT_FAILURE);
    }
    //Speichern der übergebenen Parameter in Variablen
    int numThreads = atoi(argv[argc-2]);
    int countNum = atoi(argv[argc-3]);
    useMutex = atoi(argv[argc-1]);

    pthread_t threads[numThreads];
    int check;
    //Thread-Erstellung und Ausgabe
    for(int i = 0; i < numThreads; i++){
        check = pthread_create(&threads[i], NULL, countUp, (void*) &countNum);
        if(check != 0){
            fprintf(stderr,"failed to create thread number: %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    fprintf(stdout,"creating %d threads...\n", numThreads);

    //Aufruf der checkCount-Funktion und Ausgabe der Ergebnisse
    countCheck(countNum);
    fprintf(stdout,"Thread count: %d\n",count);
    fprintf(stdout,"Check count: %d\n",count2);

    return 0;
}
//wird von Threads verwendet, um die Zahl zu zählen
void* countUp(void* countNum){
    int *countTo = (int*)countNum;
    //wenn useMutex auf 1 gesetzt ist, wird ein Mutex verwendet,
    //um sicheren Threads Zugriff zu gewährleisten
    if (useMutex) {
        while(1){
            pthread_mutex_lock(&countMutex); 
            if(count >= *countTo){
                pthread_mutex_unlock(&countMutex); 
                break;
            }
            count++; 
            pthread_mutex_unlock(&countMutex); 
        }
    } else {
        while(count < *countTo){
            count++; 
        }
    }

    return NULL;
}

//uses one thread to count to wanted number for comparison
void countCheck(int countTo){
    while(count2 < countTo){
        count2++;
    }
}