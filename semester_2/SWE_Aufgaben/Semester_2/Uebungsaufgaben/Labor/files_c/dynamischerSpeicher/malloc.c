#include <stdio.h>
#include <stdlib.h>

int main() {
   
    
    int *storage = NULL;
    storage = malloc(4 * sizeof(int));
    int size = (sizeof(storage)/sizeof(int));
    
    if (storage == NULL) {

        printf("error\n");
        return 0;
    }

    storage[0] = 10;
    storage[1] = 20;
    storage[2] = 30;
    storage[3] = 40;

    

    for (int i = 0; i < 4; i++) {

        printf("%d\n", storage[i]);
    }

    free(storage);

    return 0; 
}
