//including libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a max inventory size
#define MAX_SIZE 100

//declaring functions
void get_fileAlbums();
void add_album();
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
album albums[MAX_SIZE];
int albumCount=0; //counts albums when read into stack and keeps track of number

int main(){

    get_fileAlbums();

    int choice;

     printf("Welcome to the second hand Venyl shelf!\n\n");
    
    do{
        choice=0;
        char c;

        printf("What do you want to do? \n\n");

        //giving user possible options and asking for input
        printf("1. search titel\n2. search interpreter\n3. search release year\n4. Sort by something\n5. Add album\n6. Exit\n");
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
                printf("1. year descending\n2. year ascending\n3. titel alphabetical\n4. titel alphabetical descending \n");
                scanf("%d",&newChoice);

                //opens new menu to choose sorting style
                switch(newChoice){

                    case 1:
                        qsort(albums,MAX_SIZE,sizeof(album),descending_year);  //sorting decending year with qsort
                        print_allAlbum();
                        break;

                    case 2:
                        qsort(albums,MAX_SIZE,sizeof(album),ascending_year); //sorting ascending year with qsort
                        print_allAlbum();
                        break;
                    
                    case 3:
                        qsort(albums,MAX_SIZE,sizeof(album),descending_title); //sorting decending title with qsort
                        print_allAlbum();
                        break;
                    case 4:
                        qsort(albums,MAX_SIZE,sizeof(album),ascending_title); //sorting ascending title with qsort
                        print_allAlbum();
                        break;
                    default:
                        printf("invalid choice!");
                        break;
                }
            case 5:
                add_album();
                break;
            
            case 6:
                printf("exiting!");
                break;

            default: 
                printf("invalid choice!");
                choice=0;
        }
    }while(choice!=6); //break the loop when choice=5

    return 0;
}

//reads all albums saved in File into the albums stack
void get_fileAlbums() {
    FILE *file = fopen("music.txt", "r");

    if (file == NULL) {
        printf("Error opening file %s\n", file);
        exit(1);
    }

    //using format specifiers to read data correctly (help from stack overflow)
    while (fscanf(file, "%49[^,], %49[^,], %d, %29[^\n]%*c",albums[albumCount].title, albums[albumCount].interpreter,
                                                            &albums[albumCount].year, albums[albumCount].condition) == 4){

        albumCount++; //increasing albumCount for every album loaded from file

        //checking if there are too many albums in file
        if (albumCount >= MAX_SIZE) {
            printf("too many albums in file\n");
            break;
        }
    }

    fclose(file);
}

//function to print a album with handed over index  
void print_album(int index){

    printf("\n______________________\n");
    printf("\nTitle: %s\nInterpreter: %s\nYear: %d\nCondition: %s\n",albums[index].title,albums[index].interpreter,albums[index].year,albums[index].condition);
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

        if(strcmp(albums[j].title,input)==0){
            print_album(j);
            found++;    
        }
    }

    //checks if the search was succescfull (also gives possibility to print number of search results)
    if(found==0){
        printf("no match for \"%s\"\n",input);
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
        if(strcmp(albums[j].interpreter,input)==0){
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

    //asking user for input
    printf("enter release year: ");
    scanf("%d",&input);

    // Loop through the albums array to find albums with the matching year
    for(int i=0; i < MAX_SIZE;i++){

        if(albums[i].year == input){
            print_album(i);
            found++;
        }
    }

    //checking for results
    if(found==0){
        printf("no matches for \"%d\"",input);
    }

}

//prints all albums in array
void print_allAlbum(){

    for(int i=0;i<MAX_SIZE;i++){

        if(albums[i].year != 0){
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

//qsort title descending
int descending_title(const void *a,const void *b){

    album *albumA = (album *)a;
    album *albumB = (album *)b;
    return strcmp(albumB->title, albumA->title);
}

//qsort title ascending
int ascending_title(const void *a, const void *b){
    
    album *albumA = (album *)a;
    album *albumB = (album *)b;
    return strcmp(albumA->title, albumB->title);
}

//adding album to temp album array and to file 
void add_album() {

    //checking if the file ist already full
    if (albumCount >= MAX_SIZE) {
        printf("Maximum number of albums reached.\n");
        return;
    }

    //opening file in append mode to add a new album
    FILE *file = fopen("music.txt", "a");
    if (file == NULL) {
        printf("Error opening file %s\n", file);
        return;
    }

    
    printf("Adding a new album:\n");

    //asking for album information and saving it in array and file 
    printf("Enter title: ");
    scanf(" %49[^\n]", albums[albumCount].title); //adds the new information to array
    fprintf(file, "%s, ", albums[albumCount].title); //adds the new information to file

    printf("Enter interpreter: ");
    scanf(" %49[^\n]", albums[albumCount].interpreter); 
    fprintf(file, "%s, ", albums[albumCount].interpreter);

    printf("Enter year: ");
    scanf("%d", &albums[albumCount].year);
    fprintf(file, "%d, ", albums[albumCount].year);

    printf("Enter condition: ");
    scanf(" %29[^\n]", albums[albumCount].condition); 
    fprintf(file, "%s\n", albums[albumCount].condition);

    //closing file
    fclose(file);

    //incrementing album count to keep track
    albumCount++; 
}