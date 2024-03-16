/*****************************************************************************************************************

 Name: secondhandVenylStore

 Author: Nicolai Rothenhöfer

 Description: Ein C-Programm secondhandVinylStore, das das Second Hand Regal eines Plattenladens verwaltet.
              

 Datum: 13.03.2024

******************************************************************************************************************/



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
void search_year();
int descending_year(const void*,const void*);
int ascending_year(const void*,const void*);
int descending_title(const void*,const void*);
int ascending_title(const void*,const void*);
void print_SortedArray();
void print_allAlbum();

//declaring struct
typedef struct Album{

    char title[50];
    char interpreter[50];
    int year;
    char condition[30];

} album;

//declaring an array to fill in the albums
album shelf[MAX_SIZE];

int main(){

    //filling the array with data for demonstration
    //Album 1
    strcpy(shelf[0].title,"Swimming");
    strcpy(shelf[0].interpreter,"Mac Miller");
    shelf[0].year=2018;
    strcpy(shelf[0].condition,"like new");

    //Album 2
    strcpy(shelf[1].title,"Ok Computer");
    strcpy(shelf[1].interpreter,"Radiohead");
    shelf[1].year=1997;
    strcpy(shelf[1].condition,"used");

    //Album 3 
    strcpy(shelf[2].title,"All Eyez On Me");
    strcpy(shelf[2].interpreter,"2Pac");
    shelf[2].year=2017;
    strcpy(shelf[2].condition,"scratched");

    int choice;

     printf("Welcome to the second hand Venyl shelf!\nWhat do you want to search for?\n\n");
    
    do{
        choice=0;
        char c;

        //giving user possible options and asking for input
        printf("1. Titel\n2. Interpreter\n3. Release year\n4. Sort by\n5. Exit\n");
        scanf("%d",&choice); 

        // flush buffer (stack overflow)
        while ((c = getchar()) != '\n' && c != EOF) {}

    
        //switching functions because of user input
        switch(choice){

            case 1:
                search_title();
                break;
            case 2:
                search_interpreter();
                break;
            case 3:
                search_year();
                break;
            case 4:
                int newChoice = 0;
                printf("\n\n");
                printf("How do you want to sort?\n");
                printf("1. year descending\n2. year ascending\n3. titel alphabetical\n4. titel alphabetical descending\n5. Exit");
                scanf("%d",&newChoice);

                //opens new menu to choose sorting style
                switch(newChoice){

                    case 1:
                        qsort(shelf,MAX_SIZE,sizeof(album),descending_year);  //sorting with qsort
                        print_allAlbum();
                        break;

                    case 2:
                        qsort(shelf,MAX_SIZE,sizeof(album),ascending_year);
                        print_allAlbum();
                        break;
                    
                    case 3:
                        qsort(shelf,MAX_SIZE,sizeof(album),descending_title);
                        print_allAlbum();
                        break;
                    case 4:
                        qsort(shelf,MAX_SIZE,sizeof(album),ascending_title);
                        print_allAlbum();
                        break;
                    default:
                        printf("invalid choice!");
                        break;
                }
            
            case 5:
                printf("exiting!");
                break;

            default: 
                printf("invalid choice!");
                choice=0;
        }
    }while(choice!=5); //break the loop when choice=5

    return 0;
}

//function to print a album witch handed over index  
void print_album(int index){

    printf("\n______________________\n");
    printf("\nTitle: %s\nInterpreter: %s\nYear: %d\nCondition: %s\n",shelf[index].title,shelf[index].interpreter,shelf[index].year,shelf[index].condition);
    printf("______________________\n\n");
}

//searches in array for a given title
void search_title(){

    char input[50];
    char c; 
    int i=0;
    int found=0;

    printf("Title: ");
    while ((c = getchar()) != '\n' && i < MAX_SIZE) {  //reads letter for letter and writes it in input
     input[i++] = c;                                   //this way strcmp has no problem with blank spaces
    }

    input[i]='\0'; //string end sign to complete the string

     //loops trough array and compares titles with the input
     //if theres a match it prints the album with the current index
    for(int j=0;j<MAX_SIZE;j++){

        if(strcmp(shelf[j].title,input)==0){
            print_album(j);
            found++;    
        }
    }

    //checks if the search was succescfull (also gives possibility to print number of search results)
    if(found==0){
        printf("no match for \"%s\"",input);
    }

}

//searches in array for a given interpreter 
void search_interpreter(){

    char input[50];
    char c;
    int i=0;
    int found=0;

    printf("Interpreter: ");
    while ((c = getchar()) != '\n' && i < MAX_SIZE) {   //reads letter for letter and writes it in input
     input[i++] = c;                                    //this way strcmp has no problem with blank spaces
    }

    input[i]='\0'; //string end sign to complete the string

    for(int j=0;j<MAX_SIZE;j++){

        //loops trough array and compares interpreters with the input
        //if theres a match it prints the album with the current index
        if(strcmp(shelf[j].interpreter,input)==0){
            print_album(j);
            found++;
        }
    }

    //checks if the search was succescfull (also gives possibility to print number of search results)
    if(found==0){
        printf("no match for \"%s\"",input);
    }
}

void search_year(){

    int input=0;
    int found=0;

    printf("enter release year: ");
    scanf("%d",&input);

    for(int i=0; i < MAX_SIZE;i++){

        if(shelf[i].year == input){
            print_album(i);
            found++;
        }
    }

    if(found==0){
        printf("no matches for \"%d\"",input);
    }

}

void print_allAlbum(){

   // current_size(); //updating current size

    for(int i=0;i<MAX_SIZE;i++){

        if(shelf[i].year != 0){
        print_album(i);
        }
    }
}

//functions for qsort with help from stack overflow

//qsort descending
int descending_year(const void *a, const void *b){

    album *albumA = (album *)a;
    album *albumB = (album *)b;
    return albumB->year - albumA->year;
}

//qsort year ascending
int ascending_year(const void *a,const void *b){

    album *albumA = (album *)a;
    album *albumB = (album *)b;
    return albumA->year - albumB->year;
}

int descending_title(const void *a,const void *b){

    album *albumA = (album *)a;
    album *albumB = (album *)b;
    return strcmp(albumB->title, albumA->title);
}

int ascending_title(const void *a, const void *b){

    album *albumA = (album *)a;
    album *albumB = (album *)b;
    return strcmp(albumA->title, albumB->title);
}