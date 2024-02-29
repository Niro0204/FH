



//including libraries
#include <stdio.h>
#include <stdlib.h>

//defining a max inventory size
#define MAX_SIZE 100

//declaring functions
void search_title();

//declaring struct
typedef struct Album{

    char title[50];
    char interpreter[50];
    int year;
    char condition[30];

} album;

//declaring an array to fill in the albums
album albums[MAX_SIZE];

//filling the array with data for demonstration


int main(){

    int choice=0;

    //giving user possible options and asking for input
    printf("Welcome to the second hand Venyl shelf!\nWhat do you want to search for?\n\n");
    printf("1. Titel\n2. Interpreter\n3. Release year\n3. Sort by\n");
    scanf("%d",&choice); 
   
    //switching functions because of user input
    switch(choice){

        default: 
            printf("invalid choice!");
            choice=0;
    }

    return 0;
}

hallo
