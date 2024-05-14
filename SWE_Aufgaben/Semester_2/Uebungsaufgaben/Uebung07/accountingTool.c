#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct buchung{

    float soll;
    float haben;
    float betrag;
    char kommentar[100];
    
} buchung;

typedef struct node{

    buchung data;
    struct node* next;
    struct node* prev;

} node;



node* head = NULL;
node* tail = NULL;
int listCount = 0;



node* createNode(buchung);
void addNode(buchung);
void printList();
void printNode();
void saveToFile();
void loadFromFile(char[]);
void deleteNode();
buchung newBooking();

int main(int argc, char* argv[]){

    //header->head = NULL;

    int choice = 0;

    if(argc<2){
        fprintf(stderr,"Es wurde kein Filename übergeben!");
        exit(1);
    }

    loadFromFile(argv[argc-1]);

    do{
        choice = 0;
        printf("1. Neuen Buchungssatz einfügen\n"
           "2. Buchungssatz löschen\n"
           "3. Buchungssatz suchen\n"
           "4. Alle Buchungssätze ausgeben\n"
           "5. Buchungssätze Speichern\n"
           "6. Programm Beenden\n\n");
    
        scanf("%d",&choice);

        switch(choice){

            case 1: 
                addNode(newBooking());
                break;
            case 2: 
                deleteNode();
                break;
            case 3:
                printNode();
                break;
            case 4:
                printList();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                printf("beenden..\n\n");
                return 0;

        }
    }while(choice!=6);

  
    saveToFile(argv[argc-1]);

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

    listCount++;

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

void printNode(){

    char text[100];
   
    printf("Kommentar der Buchung: ");
    scanf("%s",text);

    int printed = 0;
    //keeping track of current element
    node* current = head;
    //iterating trough list until end
    while(current != NULL){
        if(strcmp(text,current->data.kommentar)==0){
            printf("Betrag: %.2f€\n"
               "Soll: %.2f€\n"
               "Haben: %.2f€\n"
               "Text: %s\n\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
            printed++;
            break;
        }
        current = current->next;
    }

    if(printed == 0){
        printf("Keine Einträge gefunden");
    }
    
}

void saveToFile() {

    char filename[30];
    printf("Name der Datei: ");
    scanf("%s",filename);
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei zum Schreiben.\n");
        return;
    }

    node *current = head;
    while (current != NULL) {
        fprintf(file, "%.2f,%.2f,%.2f,%s\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
        current = current->next;
    }

    fclose(file);
}


void loadFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei zum Lesen.\n");
        return;
    }

    buchung data;
    while (fscanf(file, "%f,%f,%f,%[^\n]", &data.betrag, &data.soll, &data.haben, data.kommentar) == 4) {
        addNode(data);
    }

    fclose(file);
}

void deleteNode(){

    node* current = head;
    node* prevcurrent = NULL;
    node* temp = NULL;
    int count = 1;
    int toDelete = 0;

    printf("Nummer der Buchung: ");
    scanf("%d",&toDelete);

    while(current != NULL){
         //finding the node to delete
        if(count == toDelete){
            //saving information about current and previous node
            temp = current;
            prevcurrent = current ->prev;
    	    break;
        }

        current = current->next;
        count++;
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
    listCount--;

}

buchung newBooking(){

    buchung newbooking;
    char tempComment[100];

    
    printf("Soll: ");
    scanf("%f",&newbooking.soll);
    printf("Haben: ");
    scanf("%f",&newbooking.haben);
    printf("Betrag: ");
    scanf("%f",&newbooking.betrag);
    printf("Kommentar: ");
    scanf("%s",tempComment);
    strcpy(newbooking.kommentar,tempComment);


    return newbooking;
}
