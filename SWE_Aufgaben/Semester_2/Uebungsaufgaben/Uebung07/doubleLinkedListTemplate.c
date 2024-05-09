#include <stdio.h>
#include <stdlib.h>

//node template
typedef struct node{

    int data;
    struct node* next;
    struct node* prev;

} node;

//creating pointers to head and tail of list
node* head = NULL;
node* tail = NULL;

node* createNode(int);
void addNodeHead(int);
void addNodeTail(int);
void deleteNodeHead();
void deleteNodeTail();
void deleteNodeAny(int);
void printList();

int main(){

    addNodeHead(1);
    addNodeTail(2);
    addNodeTail(3);
    printList();
    deleteNodeHead();
    deleteNodeTail();
    printList();
    addNodeHead(1);
    addNodeTail(3);
    deleteNodeAny(2);
    printList();
    


    return 0;
}

node* createNode(int data){

    //creating a node pointer to the new node
    node* newNode = malloc(sizeof(node));
    if(newNode == NULL){
        fprintf(stderr,"malloc failed");
    }

    //assigning given data to node, leaving next and privious empty to add the node later to the list
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void addNodeHead(int data){

    //creating a new node
    node* newNode = createNode(data);

    //checking if the list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head; //inserting at the front so the new nodes next has to point to old head
        head->prev = newNode; //old heads prev now points to new node
        head = newNode; //setting the new head
    }
}

void addNodeTail(int data){
    
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

void deleteNodeHead(){

    //checking if the List is empty
    if(head == NULL){
        printf("List is empty!");
        return;
    }

    //temporary saving head to free later
    node* temp = head;

    //checking if there is just one element in list
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        //second element is now the head
        head = head->next;
        head->prev = NULL;
    }

    free(temp);

}

void deleteNodeTail(){

    //checking if the list is empty
    if(tail == NULL){
        printf("List is empty!");
        return;
    }
    //temporary saving tail to free later
    node* temp = tail;

    //checking if there is just one element in list
    if(tail == head){
        head = NULL;
        tail = NULL;
    }
    else{
        //second last element is now the tail
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

void deleteNodeAny(int data){

    node* current = head;
    node* prevcurrent = NULL;
    node* temp = NULL;

    while(current != NULL){
         //finding the node to delete
        if(current->data == data){
            //saving information about current and previous node
            temp = current;
            prevcurrent = current ->prev;
    	    break;
        }

        current = current->next;
    }

    //checking if a node was found
    if(temp == NULL){
        printf("Could not find element\n");
        return;
    }

    //checking if the found node is the first element
    if(prevcurrent != NULL){
        //bridge to the element after out temp
        prevcurrent->next = temp->next;
    }
    else{
        //if it is the first element the second is now the head
        head = temp->next;
    }

    //updating the prev pointer from next element
    if(temp->next != NULL){
        temp->next->prev = prevcurrent;
    }

    free(temp);

}

void printList(){

    //keeping track of current element
    node* current = head;
    //iterating trough list until end
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }

}