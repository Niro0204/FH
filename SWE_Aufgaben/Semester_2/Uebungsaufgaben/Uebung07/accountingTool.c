#include <stdio.h>
#include <stdlib.h>

node createNode();

typedef struct buchung{

    float soll;
    float haben;
    char kommentar[100];
    float betrag;
    
} buchung;

typedef struct node{

    buchung;
    node* next;

} node;


int main(){

    

    return 0;
}

node* createNode(){

    node* newNode = malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"malloc failed");
    }

    newNode->value = data;
    newNode->next = NULL;

    return newNode;
}