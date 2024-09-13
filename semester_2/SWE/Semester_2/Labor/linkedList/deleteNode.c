#include <stdio.h>
#include <stdlib.h>


typedef struct node{

    int value;
    struct node* next;

} node;

node* createNode(int,node*);
node* deleteNode(int,node*);
void printList(node*);



int main(){

    node* head=NULL;
    int input = 0;

    
    /*head= createNode(1);
    head->next=createNode(2);
    head->next->next= createNode(3);
    */

   while(input != -1){

        printf("value: ");
        scanf("%d",input);

        if(input==-1){
            break;
        }

        node* newNode = malloc(sizeof(node));
        if(newNode == NULL){
            fprintf(stderr,"malloc failed");
        }

        newNode->value = input;
        newNode->next = NULL;
        
        if(head==NULL){
            head = newNode;
        }
        else{
            node* current = head;

            while(current->next != NULL){
            current = current->next;

        }

        current->next = newNode;
        }

   }
  

    printList(head);

    return 0;
}

/*node* createNode(int data,node* head){

    node* newNode = malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"malloc failed");
    }

    newNode->value = data;
    newNode->next = NULL;
    
    if(head==NULL){
        head = newNode;
    }
    else{
        node* current = head;

        while(current->next != NULL){
        current = current->next;

    }

    current->next = newNode;
    }
    
    return newNode;
}*/

void deleteNode(node** head_ref, int value)
{
    node* current = *head_ref;
    node* previous = NULL;

    // If head node itself holds the value to be deleted
    if (current != NULL && current->value == value)
    {
        *head_ref = current->next; // Changed head
        free(current); // free old head
        return;
    }

    // search for the value
    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    // If value was not present in linked list
    if (current == NULL) return;

    // Unlink the node from linked list
    previous->next = current->next;

    free(current);  // Free memory
}




void printList(node* current){

    while(current!=NULL){

        printf("%d ",current->value);
        current=current->next;
    }

}

node* deleteNode(int value,node* head){




}