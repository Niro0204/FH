/*****************************************************************************************************************
 
 Name: myQueue2

 Author: Nicolai Rothenhöfer

 Description: Beispielhafte ausprogrammierung einer Queue mithilfe eines Arrays

 Datum: 28.12.2023

******************************************************************************************************************/


#include <stdio.h>

//definiert SIZE als integer 
#define SIZE 5

//deklaration der verwendeten Funktionen
void enqueue(int);
int dequeue();
void show();
int head();
int tail();
void reset();

//globale Variablen für Definierung der Queue
int queue[SIZE];
int front = -1;
int rear = -1;


int main (int argc, char * argv[])
{

        int choice, item, check;
        do
        {
             // Menü für Queue-Operationen
            printf("\nQueue Operations:\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Head\n");
            printf("5. Tail\n");
            printf("6. Reset\n");
            printf("7. Exit\n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);
          
            switch (choice)
            {
            case 1:

                // Hinzufügen eines Elements zur Queue
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                enqueue(item);

                break;
                
            case 2:

                // Entfernen eines Elements aus der Queue
                item = dequeue();
                if (item != -1)
                {
                    printf("\nDequed item is: %d\n", item);
                }
                break;

            case 3:
                 // Anzeigen der Elemente in der Queue
                show();
                break;

            case 4:

                // Anzeigen des ersten Elements in der Queue (Head)
                item = head();
                if (item != -1)
                {
                    printf("\nHead item is: %d\n", item);
                }
                break;

            case 5:

                // Anzeigen des letzten Elements in der Queue (Tail)
                item = tail();
                if (item != -1)
                {
                    printf("\nTail item is: %d\n", item);
                }
                break;

            case 6:

                // Zurücksetzen der Queue
                reset();
                break;

            case 7:

                 // Beenden des Programms
                printf("\n\nExiting from app.\n");
                reset();
                break;

            default:
                // Ungültige Eingabe
                printf("\nInvalid choice\n");
        }
    } while (choice != 7);
    return 0;
}

// Funktion zum Hinzufügen eines Elements zur Queue
void enqueue(int item)
{
    if ((rear + 1) % SIZE == front)
    {
        // Überprüfung, ob die Queue voll ist
        printf("\nQueue is full\n");
    }
    else
    {
        if (front == -1)
        {
            // Initialisierung des Front-Index, wenn die Queue leer war
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
    }
}

// Funktion zum Entfernen eines Elements aus der Queue
int dequeue()
{
    int item;
    if (front == -1)
    {
        // Überprüfung, ob die Queue leer ist
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
         // Entnahme des Elements aus der Queue
        item = queue[front];
        if (front == rear)
        {
            // Zurücksetzen der Queue, wenn nur ein Element vorhanden war
            front = -1;
            rear = -1;
        }
        else
        {
            // Aktualisierung des Front-Index
            front = (front + 1) % SIZE;
        }
        return item;
    }
}

// Funktion zum Anzeigen der Elemente in der Queue
void show()
{
    int i;
    if (front == -1)
    {
        // Überprüfung, ob die Queue leer ist
        printf("\nQueue is empty\n");
    }
    else
    {
        // Anzeigen der Elemente in der Queue
        printf("Queue: ");
        for (i = rear; i != front; i = (i - 1 + SIZE) % SIZE)
        {
            if(i == rear)
                printf("(T) %d -> ", queue[i]);
            else if((i % SIZE) != front)
                printf("%d -> ", queue[i]);
        }
        printf("%d (H)", queue[front]);
        printf("\n");
    }
}

// Funktion, um das erste Element in der Queue zu erhalten
int head()
{
    if (front == -1)
    {
        // Überprüfung, ob die Queue leer ist
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        // Rückgabe des ersten Elements in der Queue
        return queue[front];
    }
}

// Funktion, um das letzte Element in der Queue zu erhalten
int tail()
{
    if (rear == -1)
    {
        // Überprüfung, ob die Queue leer ist
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        // Rückgabe des letzten Elements in der Queue
        return queue[rear];
    }
}

// Funktion zum Zurücksetzen der Queue
void reset()
{
    // Zurücksetzen der Queue-Indizes
    front = -1;
    rear = -1;
}
