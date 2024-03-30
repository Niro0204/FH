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

    head= createNode(1);
    head->next=createNode(2);
    head->next->next= createNode(3);

  

    printList(head);

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

node* deleteNode(int data,node* current){


    node* prev = NULL;

    // Suchen des zu löschenden Knotens
    while (current != NULL && current->value != data) {
        prev = current;
        current = current->next;
    }

    // Wenn der Knoten nicht gefunden wurde, beibehalten Sie die Liste unverändert
    if (current == NULL)
        return head;

    // Wenn der zu löschende Knoten der Kopf der Liste ist
    if (prev == NULL) {
        head = current->next;
        free(current);
        return head;
    }

    // Andernfalls aktualisieren Sie die Zeiger des Vorgängerknotens und löschen Sie den aktuellen Knoten
    prev->next = current->next;
    free(current);

    return head;
}

void printList(node* current){

    while(current!=NULL){

        printf("%d ",current->value);
        current=current->next;
    }

}