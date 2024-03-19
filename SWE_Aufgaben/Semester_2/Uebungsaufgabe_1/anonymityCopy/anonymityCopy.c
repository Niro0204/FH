#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]){

    FILE *sourceF = NULL;
    FILE *destF = NULL;

   /* char *source = argv[0];
    char *dest = argv[1];
    char *privWord = argv[2];*/
    
    //sourceF = fopen(source,"r");
    //destF = fopen(dest,"a");

    sourceF = fopen("sourceFile.txt","r");
    destF = fopen("destinationFile.txt","a");

    if(sourceF == NULL || destF == NULL){
        printf("failed to open file!");

        return 0;
    }

    char c;

    
    while((c=fgetc(sourceF))!=EOF){

        fputc(c,destF);
    }

    fclose(sourceF);
    fclose(destF);

    return 0;
}