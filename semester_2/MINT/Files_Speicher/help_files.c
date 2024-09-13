#include <stdio.h>

int countWords();

 struct word{

        int count;
        char word[50];
    };

int main(){


    return 0;
}


int countWords(){

    FILE *txtFile = NULL;
    txtFile=fopen("lore_ipsum.txt","r");

    if(txtFile==NULL){
        printf("failed to open file!");
        return 1;
    }

    char string[100];
    char c;
    while((c=fgetc(txtFile)!=EOF)){

        while(c!= 32||c!='\n'){

            for(int i=0;i<100;i++){
                string[i]=c;
                
            }
        }
    }


    close(txtFile);
}