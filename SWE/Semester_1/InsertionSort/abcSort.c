#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sort(int,char[]);

int main(){

    int size = 10;
    char str[size];

    printf("String: ");
    scanf("%s",str);

    sort(size,str);

    printf("Sorted: %s",str);


    return 0;
}

void sort(int size,char str[]){

    int element=0;
    int sorted=0;

    for(int i=1;i<size;i++){

        element=str[i];
        sorted=i-1;

        while(element<str[sorted] && str[i]!=0){

            str[sorted+1]=str[sorted];
            sorted--;

        }

        str[sorted+1]=element;

    }

}