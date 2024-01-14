/*****************************************************************************************************************
 
 Name: myStack

 Author: Nicolai Rothenhöfer

 Description: Beispielhafte ausprogrammierung eines Stacks mithilfe eines Arrays

 Datum: 28.12.2023

******************************************************************************************************************/



//includierungen
#include <stdio.h>

//definiert MAY_SIZE als fixen integer Wert
#define MAX_SIZE 5

//verwendete Funktionen
void push(int);
int pop();
void show();

//globale Variablen 
int stack[MAX_SIZE];
int top = -1;


int main() 
{
    
    int choice=0, item; // Variablen für Auswahl und übergabe/ergebnis der funktionen

    do
    {
        //Auswahlmöglichkeiten werden ausgegeben
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show\n");
        printf("4. Top\n");    
        printf("5. Reset\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice); // einlesen der Wahl für switch
      

        switch (choice)
        {
            case 1:

                printf("Enter the element to be pushed: ");
                scanf("%d", &item); // einlesen des hinzuzufügenden elements
                push(item); //funktionsaufruf
                
                break;

            case 2:

                item = pop(); // Rückgabewert von funktion übernehmen und ausgeben

                printf("Popped item: %d\n", item);

                break;

            case 3:

                show();

                break;

            case 4:
                        
                 // Überprüfung ob Stack leer ist, sonst ausgabe       
                if (top == -1) 
                {
                    printf("\nStack is empty\n");
                } 
                else 
                {
                    printf("Top element is: %d\n", stack[top]);
                }
                break;

            case 5:

                // zurücksetzens des Stacks 
                top = -1;
                break;

            case 9:

                printf("\nExiting from app.\n");

                break;
            default:

                printf("\nInvalid choice, please try again.\n");
                
                break;
        }
    }while (choice != 9); //Bedingung um aus der Schleife auszubrechen
    return 0;
}

//funktion um ein Element hinzuzufügen
void push(int item) 
{
    //Wenn nicht voll wird der Wert as Stelle des nächsten Indexes hinzugefügt 
    if (top == MAX_SIZE - 1) 
    {
        printf("Stack is full\n");
    } 
    else {
        stack[++top] = item;
    }
}

//Funktion um ein Element zu entfernen
int pop() 
{
    //Wenn Stack nicht leer wird der Top-Index verringert
    if (top == -1) 
    {
        printf("Stack is empty\n");
        return -1;
    } 
    else 
    {
        return stack[top--];
    }
}

//Funktion um alle Elemente auszugeben ohne sie zu entfernen
void show(){


    // wenn Stack nicht leer wird rückwerts durch den Stack geloopt um alle Elemente in der richtigen Reihenfolge auszugeben
     if(top == -1) 
        {
            printf("\nStack is empty\n");
        } 
    else 
        {
            printf("Stack elements are:\n\n");
            printf("---\n");
                for (int i = top; i >= 0; i--)
                {
                    if(i == top)
                    {
                         printf("%d (TOP)\n", stack[i]);
                    }     
                    else
                    {
                     printf("%d\n", stack[i]);
                    }
                    
                }
            printf("---\n");
        }
}