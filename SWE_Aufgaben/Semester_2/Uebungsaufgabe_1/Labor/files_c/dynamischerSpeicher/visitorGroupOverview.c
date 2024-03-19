#include <stdio.h>
#include <stdlib.h>

int main() {

    int numVis = 0;
   
    printf("number of Visitors: ");
    scanf("%d",&numVis);

    int *name = NULL;
    int *visitors = NULL;

    name = malloc(15*sizeof(char));
    visitors = malloc(numVis*sizeof(name));
    
    if (name == NULL || visitors == NULL) {

        printf("error\n");
        return 0;
    }

    
    char c;
    int j;


    for (int i = 0; i < numVis; i++) {

        printf("Name:");
        for(j=0;j<15;j++){

            name[j] = getchar();
        }

        name[j]=='\0';

        visitors[i]=name;

        j=0;
    }


    for(int i=0;i<numVis;i++){

        printf("%s",visitors[i]);
    } 


    free(name);
    free(visitors);

    return 0; 
}
