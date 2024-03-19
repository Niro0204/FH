#include <stdio.h>

int main(){

    FILE * file = NULL;
    file = fopen("text.txt","a");

    if(file==NULL){
        printf("failed to open file");
        return 1;
    }

    char string[50];

    printf("Text: ");

    do{
        fgets(string,sizeof(string),stdin);

           for(int i=0;i<50;i++){

                if(string[0] == 27){
                    break;
                 }
            }

        fputs(string,file);

    }while(1==1);

    fclose(file);

    return 0;
}