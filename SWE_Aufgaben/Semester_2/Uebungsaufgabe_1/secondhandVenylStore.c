



//including libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a max inventory size
#define MAX_SIZE 100

//declaring functions
void print_album(int);
void search_title();
void search_interpreter();

//declaring struct
typedef struct Album{

    char title[50];
    char interpreter[50];
    int year;
    char condition[30];

} album;

//declaring an array to fill in the albums
album albums[MAX_SIZE];


int main(){

    //filling the array with data for demonstration
    //Album 1
    strcpy(albums[0].title,"Swimming");
    strcpy(albums[0].interpreter,"Mac Miller");
    albums[0].year=2018;
    strcpy(albums[0].condition,"like new");

    //Album 2
    strcpy(albums[1].title,"Ok Computer");
    strcpy(albums[1].interpreter,"Radiohead");
    albums[1].year=1997;
    strcpy(albums[1].condition,"used");

    //Album 3 
    strcpy(albums[2].title,"All Eyez On Me");
    strcpy(albums[2].interpreter,"2Pac");
    albums[2].year=2017;
    strcpy(albums[2].condition,"scratched");

    int choice=0;
    char c;
    //giving user possible options and asking for input
    printf("Welcome to the second hand Venyl shelf!\nWhat do you want to search for?\n\n");
    printf("1. Titel\n2. Interpreter\n3. Release year\n3. Sort by\n");
    scanf("%d",&choice); 

     while ((c = getchar()) != '\n' && c != EOF) {
        // Nichts tun, Zeichen verwerfen
    }

   
    //switching functions because of user input
    switch(choice){

        case 1:
            search_title();
            break;
        case 2:
            search_interpreter();
            break;

        default: 
            printf("invalid choice!");
            choice=0;
    }

    return 0;
}

//function to print a choosen album
void print_album(int index){

    printf("^\n\nTitle: %s\nInterpreter: %s\nYear: %d\nCondition: %s\n\n",albums[index].title,albums[index].interpreter,albums[index].year,albums[index].condition);

}

void search_title(){

    char input[50];
    char c;
    int i=0;
    int found=0;

    printf("Title: ");
    while ((c = getchar()) != '\n' && i < MAX_SIZE) {
     input[i++] = c;
    }
    input[i]='\0';

    for(int j=0;j<MAX_SIZE;j++){

        if(strcmp(albums[j].title,input)==0){
            print_album(j);
            found++;
        }
    }

    if(found==0){
        printf("no match for \"%s\"",input);
    }

}

void search_interpreter(){

    char input[50];
    char c;
    int i=0;
    int found=0;

    printf("Interpreter: ");
    while ((c = getchar()) != '\n' && i < MAX_SIZE) {
     input[i++] = c;
    }
    input[i]='\0';

    for(int j=0;j<MAX_SIZE;j++){

        if(strcmp(albums[j].interpreter,input)==0){
            print_album(j);
            found++;
        }
    }

    if(found==0){
        printf("no match for \"%s\"",input);
    }
}

