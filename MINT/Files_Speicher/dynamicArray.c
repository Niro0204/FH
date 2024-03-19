#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int size=0;
    srand(time(NULL));

    printf("storage Slots: ");
    scanf("%d",&size);
    
    int *storage = NULL;
    storage = malloc(size * sizeof(int));
    
    
    if (storage == NULL) {

        printf("error\n");
        free(storage);
        return 0;
    }

    for(int i=0;i<size;i++){
        
        int randInt = rand()%101;
        storage[i]=randInt;
    }


    for (int i = 0; i < size; i++) {

        printf("%d\n", storage[i]);
    }

    free(storage);

    return 0; 
}
