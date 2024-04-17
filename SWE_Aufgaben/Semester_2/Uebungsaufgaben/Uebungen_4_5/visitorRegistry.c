#include <stdio.h>
#include <stdlib.h>

//using a struct for personal data of the visitors
typedef struct visitorData{

    char firstName[30];
    char lastName[30];
    int zipCode;

} visitorData;

//keeping track of the number of visitors
int size = 0;
visitorData *visitors = NULL;

void registerVisitor();
void printVisitors();

int main(){

    int choice = 0;
    visitors = malloc(sizeof(visitorData)); //allocating memory for first use of array
    if(visitors == NULL){
        fprintf(stderr,"Failed allocating memory");
        exit(1);
    }

    do{
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
    }while(choice != 3);

    return 0;
}

void registerVisitor(){

    visitors = realloc(visitors,(size+1)*sizeof(visitorData));
    if(visitors == NULL){
        fprintf(stderr,"Reallocating memory failed");
    }

    printf("Enter first Name: ");
    scanf("%s",visitors[size].firstName);
    printf("Enter last name: ");
    scanf("%s",visitors[size].lastName);
    printf("Enter zip code: ");
    scanf("%d",&visitors[size].zipCode);

    size++;

    printf("Regristration successful\n");
}

void printVisitors(){

    for(int i = 0; i <= size; i++){
        printf( "Visitor number: %d\n"
                "First name: %s\n"
                "Last name: %s\n"
                "Zip code: %d\n", 
                i, visitors[i].firstName, visitors[i].lastName, visitors[i].zipCode);
    }
}