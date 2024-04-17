#include <stdio.h>
#include <stdlib.h>

//using a struct for personal data of the visitors
typedef struct visitorData{

    char firstName[30];
    char lastName[30];
    int plz;

} visitorData;

//keeping track of the number of visitors
int size = 0;
visitorData *visitors = NULL;

void registerVisitor();
void printVisitors();

int main(){

    int choice = 0;
    visitors = malloc(sizeof(visitorData)); //allocating memory for first use of array

    //little menu for user
    printf( "1. Register a new Visitor\n"
            "2. Show list of all visitors\n"
            "3. exit\n");

    scanf("%d",&choice);

    //calling the wanted functions
    switch (choice){

        case 1:
            registerVisitor();
            break;
        case 2:
            printVisitors();
        case 3:
            printf("Exiting!");
            break;
    }


    return 0;
}

void registerVisitor(){

    
}