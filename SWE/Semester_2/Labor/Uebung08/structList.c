#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personData{

    char firstName[20];
    char lastName[20];
    
} person;

typedef struct node{

    person p; 
    struct node* next;

} node;



node* createNode(node*);
node* deleteNode(int,node*);
void printList(node*);

int main() {
    node* head = NULL;
    int choice;

    do {
        printf("\n1. Add a new person\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createNode(head);
                break;
            case 2:
                printf("\nLinked List:\n");
                printList(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 3);

    // Freigeben des allokierten Speichers
    node* current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}



node* createNode(node* head) {
    char fName[20];
    char lName[20];

    printf("Enter first Name: ");
    scanf("%19s", fName);

    printf("Enter last name: ");
    scanf("%19s", lName);

    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "malloc failed");
        return NULL;
    }

    //werte für newNode zuweisen
    strcpy(newNode->p.firstName, fName);
    strcpy(newNode->p.lastName, lName);
    newNode->next = NULL;

    //überprüfen ob es das erste element der liste ist
    if (head == NULL) {
        head = newNode;

    //durch liste traversieren bis das letzte element gefunden ist
    } else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return head;
}


void printList(node* current){

    while(current!=NULL){

        printf("First name: %s\n", current->p.firstName);
        printf("Last name: %s\n\n", current->p.lastName);
        current=current->next;
    }

}

//node* deleteNode(node* )