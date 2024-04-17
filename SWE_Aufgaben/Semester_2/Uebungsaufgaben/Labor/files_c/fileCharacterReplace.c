#include <stdio.h>

int main(){

    FILE* fptr=NULL;
    fptr=fopen("text.txt","r+");

    if(fptr!=NULL){

        char c;
        char a;
        char r;

        printf("character to replace: ");
        c = getchar();
        getchar();
        printf("replacement character: ");
        r = getchar();

        while((a = fgetc(fptr))!=EOF){

            if(c==a){

                fseek(fptr,-1,SEEK_CUR);
                fputc(r,fptr); 
                //fseek(fptr,1,SEEK_CUR);
            }
        }
    }

    else {
        printf("failed to open file!\n");
    }

    fclose(fptr);

    return 0;
}