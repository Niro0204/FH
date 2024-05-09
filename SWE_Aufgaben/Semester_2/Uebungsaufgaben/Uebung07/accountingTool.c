#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct buchung{

    float soll;
    float haben;
    char kommentar[100];
    float betrag;
    
} buchung;

typedef struct node{

    buchung data;
    struct node* next;
    struct node* prev;

} node;

node* head = NULL;
node* tail = NULL;

/*typedef struct header{

    int count;
    node* first;
    node* last; 

} header;*/

node* createNode(buchung);
void addNode(buchung);
void printList();
void printNode(char[]);

int main(){

    buchung test;
    buchung test2;

    test.betrag = 50;
    test.haben = 12;
    test.soll = 30;
    strcpy(test.kommentar,"ich bin arm");

    test2.betrag = 10;
    test2.haben = 2;
    test2.soll = 3;
    strcpy(test2.kommentar,"ich bin ärmer");

    addNode(test);
    addNode(test2);
    printNode("ich bin arm");
    printList();

    return 0;
}

node* createNode(buchung data){

    //creating a node pointer to the new node
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"malloc failed");
    }

    //assigning given data to node, leaving next and privious empty to add the node later to the list
    newNode->data.betrag = data.betrag;
    newNode->data.haben = data.haben;
    newNode->data.soll = data.soll;
    strcpy(newNode->data.kommentar,data.kommentar);
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void addNode(buchung data){
    
    //creating new node
    node* newNode = createNode(data);

    //checking if list is empty
    if(tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->prev = tail; //new node points to old tail
        tail->next = newNode; //old tails next points to new node
        tail = newNode; //new node is now the tail
    }

}

void printList(){

    //keeping track of current element
    node* current = head;
    //iterating trough list until end
    while(current != NULL){
        printf("Betrag: %.2f€\n"
               "Soll: %.2f€\n"
               "Haben: %.2f€\n"
               "Text: %s\n\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
        current = current->next;
    }

}

void printNode(char text[]){

    //keeping track of current element
    node* current = head;
    //iterating trough list until end
    while(current != NULL){
        if(strcmp(text,current->data.kommentar)==0){
            printf("Betrag: %.2f€\n"
               "Soll: %.2f€\n"
               "Haben: %.2f€\n"
               "Text: %s\n\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
        }
        current = current->next;
    }
    
}