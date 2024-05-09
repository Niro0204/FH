#include <stdio.h>
#include <stdlib.h>

void addNode(buchung);


typedef struct buchung{

    float soll;
    float haben;
    char kommentar[100];
    float betrag;
    
} buchung;

typedef struct node{

    buchung value;
    node* next;
    node* prev;

} node;

typedef struct header{

    int count;
    node* first;
    node* last; 
} header;


int main(){

    

    return 0;
}

void addNode(buchung buchung){

    node* newNode = malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"malloc failed");
    }

    newNode->value = buchung;
    newNode->next = NULL;
    newNode->prev = 

    
}