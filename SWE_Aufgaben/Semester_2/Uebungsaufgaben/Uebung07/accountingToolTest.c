#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur für eine Buchung
typedef struct {
    float soll;
    float haben;
    char kommentar[100];
    float betrag;
} buchung;

// Struktur für einen Knoten in der Liste
typedef struct node {
    buchung data;
    struct node* next;
    struct node* prev;
} node;

// Struktur für den Header der Liste
typedef struct header {
    int count;
    node* first;
    node* last;
} header;

// Globale Variable für den Header der Liste
header listHeader = {0, NULL, NULL};

// Prototypen der Funktionen
node* createNode(buchung);
void addNode(buchung);
void printList();
void printNode(char[]);
void saveToFile(char[]);
void loadFromFile(char[]);
buchung newBooking();
void deleteNodeAny(char[]);


int main(int argc, char* argv[]) {


    int choice = 0;

    if (argc < 2) {
        fprintf(stderr, "Es wurde kein Dateiname übergeben!");
        exit(1);
    }

    char* fileName = argv[argc - 1];

    printf("1. Neuen Buchungssatz einfügen\n"
           "2. Buchungssatz löschen\n"
           "3. Buchungssatz suchen\n"
           "4. Alle Buchungssätze ausgeben\n"
           "5. Bestimmten Buchungssatz löschen\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addNode(newBooking());
            break;
        case 2:
            deleteNodeAny("");
            break;
        // Weitere Fälle für andere Funktionen
    }

    loadFromFile(fileName);
    printNode("ich bin arm");
    printList();
    saveToFile(fileName);

    return 0;
}

// Funktion zum Erstellen eines neuen Knotens mit einer Buchung
node* createNode(buchung data) {
    // Speicherplatz für den neuen Knoten reservieren
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "Speicherzuweisung fehlgeschlagen");
        exit(1);
    }

    // Daten der Buchung in den Knoten kopieren
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Funktion zum Hinzufügen eines Knotens zur Liste
void addNode(buchung data) {
    // Neuen Knoten erstellen
    node* newNode = createNode(data);

    // Überprüfen, ob die Liste leer ist
    if (listHeader.first == NULL) {
        listHeader.first = newNode;
        tail = newNode;
    } else {
        // Neuen Knoten an das Ende der Liste hängen
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// Funktion zum Ausgeben aller Buchungen in der Liste
void printList() {
    // Aktuellen Knoten auf den Kopf der Liste setzen
    node* current = head;

    // Solange es noch Knoten in der Liste gibt
    while (current != NULL) {
        // Buchungsdaten ausgeben
        printf("Betrag: %.2f€\n"
               "Soll: %.2f€\n"
               "Haben: %.2f€\n"
               "Text: %s\n\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
        // Zum nächsten Knoten gehen
        current = current->next;
    }
}

// Funktion zum Ausgeben einer bestimmten Buchung
void printNode(char text[]) {
    int printed = 0;
    // Aktuellen Knoten auf den Kopf der Liste setzen
    node* current = head;
    // Solange es noch Knoten in der Liste gibt
    while (current != NULL) {
        // Wenn der Kommentar übereinstimmt, Buchungsdaten ausgeben
        if (strcmp(text, current->data.kommentar) == 0) {
            printf("Betrag: %.2f€\n"
               "Soll: %.2f€\n"
               "Haben: %.2f€\n"
               "Text: %s\n\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
            printed++;
        }
        // Zum nächsten Knoten gehen
        current = current->next;
    }
    // Wenn keine Buchung gefunden wurde, entsprechende Meldung ausgeben
    if (printed == 0) {
        printf("Keine Einträge gefunden");
    }
}

// Funktion zum Speichern der Buchungen in einer Datei
void saveToFile(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei zum Schreiben.\n");
        return;
    }

    // Aktuellen Knoten auf den Kopf der Liste setzen
    node *current = head;
    // Solange es noch Knoten in der Liste gibt
    while (current != NULL) {
        // Buchungsdaten in die Datei schreiben
        fprintf(file, "%.2f, %.2f, %.2f, %s\n", current->data.betrag, current->data.soll, current->data.haben, current->data.kommentar);
        // Zum nächsten Knoten gehen
        current = current->next;
    }

    fclose(file);
}

// Funktion zum Laden der Buchungen aus einer Datei
void loadFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei zum Lesen.\n");
        return;
    }

    // Temporäre Variable für das Einlesen einer Buchung
    buchung data;
    // Solange noch Buchungen in der Datei vorhanden sind
    while (fscanf(file, "%f,%f,%f,%[^\n]", &data.betrag, &data.soll, &data.haben, data.kommentar) == 4) {
        // Neue Buchung zur Liste hinzufügen
        addNode(data);
    }

    fclose(file);
}

// Funktion zum Löschen eines Knotens mit einem bestimmten Kommentar
void deleteNodeAny(char searchedText[]) {
    node* current = head;
    node* prevcurrent = NULL;
    node* temp = NULL;

    // Solange es noch Knoten in der Liste gibt
    while (current != NULL) {
        // Wenn der Kommentar des aktuellen Knotens mit dem gesuchten Text übereinstimmt
        if (strcmp(current->data.kommentar, searchedText) == 0) {
            // Informationen über den aktuellen und den vorherigen Knoten speichern
            temp = current;
            prevcurrent = current->prev;
        }
}
}