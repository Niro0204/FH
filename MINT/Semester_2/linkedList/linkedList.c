#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int value;
    struct node* next;

} node;

node* createNode(int);
node* deleteNode(int,node*);
void printList(node*);

int main(){

    node *head=NULL;
    head=malloc(sizeof(node));

    


    return 0;
}

node* createNode(int data){

    node* newNode = malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"malloc failed");
    }

    newNode->value = data;
    newNode->next = NULL;

    return newNode;
}

void printList(node* current){

    while(current!=NULL){

        printf("%d ",current->value);
        current=current->next;
    }

}z