#include <stdio.h>

int main(){

    FILE * file = NULL;
    file = fopen("text.txt","r");

    if(file==NULL){
        printf("failed to open file");
        return 1;
    }

    char string[50];

    while(fgets(string,sizeof(string),file)!=NULL){

        printf("%s",string);

    }

    fclose(file);

    return 0;
}