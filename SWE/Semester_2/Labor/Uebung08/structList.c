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
node* deleteNode(node*, char[]);
void printList(node*);

int main() {
    node* head = NULL;
    int choice;
    char deletName[20]; 

    do {
        printf("\n1. Add a new person\n");
        printf("2. Print list\n");
        printf("3. Delete Person\n");
        printf("4. Exit\n");
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
                printf("Enter last name from person you want to delete: ");
                scanf("%s",deletName);
                deleteNode(head,deletName);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 4);

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

    if(current==NULL){
        printf("L0ist is empty");
        exit(1);
    }

    while(current!=NULL){

        printf("First name: %s\n", current->p.firstName);
        printf("Last name: %s\n\n", current->p.lastName);
        current=current->next;
    }

}

node* deleteNode(node* head,char lastName[20]){

    // Falls die Liste leer ist
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    // Den zu löschenden Knoten finden und ihn aus der Liste entfernen
    node* current = head;
    node* prev = NULL;

    // Solange der aktuelle Knoten nicht NULL ist und der Nachname des aktuellen Knotens nicht dem zu löschenden Nachnamen entspricht
    while (current != NULL && strcmp(current->p.lastName, lastName) != 0) {
        prev = current;
        current = current->next;
    }

    // Wenn der zu löschende Knoten gefunden wurde
    if (current != NULL) {
        // Wenn der zu löschende Knoten der erste Knoten der Liste ist
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = current->next;
        }
        // Speicher freigeben
        free(current);
        printf("Node with last name '%s' deleted successfully.\n", lastName);
    } else {
        printf("Node with last name '%s' not found.\n", lastName);
    }

    return head;
}

