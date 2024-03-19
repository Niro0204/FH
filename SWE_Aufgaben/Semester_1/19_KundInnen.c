/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * Filename: uebung19_customerList.c
 * Author: David Schnoell
 * Date: 20_01_2024
 * Description:
 *      ein struct Kundinnen mit verschiednen Parametern wird definiert, eine beliebige anzahl an Kunden mittels eines Structpointerarrays angelegt und ausgegeben,
 *      anhand eines Char Array Parameters des struct Kundinnen (name bzw. adresse) wird eine Kopie des Structpointearray (kundenArraycopy) sortiert (Z-->A) und wieder ausgegeben
 *      zum Schluss wird dass nicht sortierte (auf Grund der Eingabe nach id sortiert) Strucpointerarray ausgegeben und der Speicherplaz freigegeben. 
 -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#define MAX_SIZE 10

//Definition der Struktur Kundinnen
struct  Kundinnen
{
    int id;
    char name[50];
    char email[50];
    char adresse[50];
    int hausnummer;
};


//Umwandlung der Groß in Kleinbuchstaben bei Name und Adresse, Übergabeparameter Zeiger auf ein struct Kundinnen
void mykleinbuchstaben(struct Kundinnen *kunde)
{  
    //Zugriff auf alle Elemenet des Chararrays Name solange nicht \0 im Übergebenen struct, und umwandlungn von groß in kleinbuchstaben
    for(int i=0; kunde->name[i]!='\0'; i++)
    {
        if('Z'>=kunde->name[i] && kunde->name[i] >='A')
        {
            kunde->name[i]=kunde->name[i]+('a'-'A');
        }        
    }
    //Zugriff auf alle Elemenet des Chararrays adresse solange nicht \0 im Übergebenen struct, und umwandlungn von groß in kleinbuchstaben
    for(int i=0; kunde->adresse[i]!='\0'; i++)
    {
        if('Z'>=kunde->adresse[i] && kunde->adresse[i] >='A')
        {
            kunde->adresse[i]=kunde->adresse[i]+('a'-'A');
        }        
    }
}



void mysortandprint(struct Kundinnen **kundenArray, int kundenanzahl) 
{

    //Deklaration der variable choice, des struct Kundinnen pointer "key" und struct Kundinnen pointerarray "kundenArraycopy"
    int choice;
    struct Kundinnen *key;
    struct Kundinnen *kundenArraycopy[kundenanzahl];

    //um das kundenArray bzw. dessen sortierung nicht zu verändern wird ein zweites pointerarray verwendet und alle positionen des kundenArray kopiert
    for(int l=0;l<kundenanzahl;l++)
    {
        kundenArraycopy[l]=kundenArray[l];
    }

    //Abfrage ob nach Namen oder Adresse sortiert werden soll
    printf("Nach was soll sortiert werden? Name(1) oder Adresse (2): ");
    scanf("%d",&choice);

    //Swicht zur überprüfung und ausführung der gewünschten sortierung des Pointerarrays kundenArraycopy und Ausgabe der structs auf die die sortierten pointer zeigen
    switch (choice)
    {
    case 1:

        //Inserstion sort nach struct Kundinnen element name
        for (int i = 1; i < kundenanzahl; i++) 
        {
            key = kundenArraycopy[i];
            int j = i - 1;

            // Vergleich  der Elemente(hier gewähltes element auf das Verglich wird  ist name) und Verschiebung der Elemente (=pointer auf die structs der Kundinnen im Pointerarray) , absteigend wurde als Z bis A verstanden, sollte dem nicht so sein muss in der while schleife die zweite bedinnnugn auf > 0 geändert werden
            while (j >= 0 && strcmp(kundenArraycopy[j]->name, key->name) < 0) {
                kundenArraycopy[j + 1] = kundenArraycopy[j];
                j = j - 1;
            }
            kundenArraycopy[j + 1] = key;
        }

        //sortierte Ausgabe
         printf("\nNach Namen sortierte (Z-->A) Kundinnen:\n");
        for (int i = 0; i < kundenanzahl; i++) 
        {
            printf("ID: %d, \tName: %s, \t\t\tEmail: %s, \t\t\tAdresse: %s %d\n", kundenArraycopy[i]->id, kundenArraycopy[i]->name, kundenArraycopy[i]->email, kundenArraycopy[i]->adresse, kundenArraycopy[i]->hausnummer);
        }
        break;

    case 2:

        //Inserstion sort nach struct Kundinnen element adresse
        for (int i = 1; i < kundenanzahl; i++) 
        {
            key = kundenArraycopy[i];
            int j = i - 1;

            // Vergleich und Verschiebung der Elemente, absteigend wurde als Z bis A verstanden, sollte dem nicht so sein muss in der while schleife die zweite bedinnnugn auf > 0 geändert werden
            while (j >= 0 && strcmp(kundenArraycopy[j]->adresse, key->adresse) < 0) {
                kundenArraycopy[j + 1] = kundenArraycopy[j];
                j = j - 1;
            }
            kundenArraycopy[j + 1] = key;
        }

        //sortierte Ausgabe
        printf("\nNach Adresse sortierte (Z-->A) Kundinnen:\n");
        for (int i = 0; i < kundenanzahl; i++) 
        {
            printf("ID: %d, \tName: %s, \t\t\tEmail: %s, \t\t\tAdresse: %s %d\n", kundenArraycopy[i]->id, kundenArraycopy[i]->name, kundenArraycopy[i]->email, kundenArraycopy[i]->adresse, kundenArraycopy[i]->hausnummer);
        }
        break;

    
    default:
        printf("\nFehlerhafte Eingabe!");
        break;
    }


}


int main()
{
    //Deklaration Variable
    int kundenanzahl=0;

    //Pointer Array mit MAX_SIZE stellen des structs Kundinnen
    struct Kundinnen *kundenArray[MAX_SIZE];

    //Speicher reservierung und Eingabe der Kundendaten, 
    for (int i = 0; i < MAX_SIZE; i++) 
    {
        //malloc gibt pointer zurück der mittels (struct Kundinnen *) zu einem zeiger des typs struct kundinnnen wird und an stelle i im kundenArray gespeichert wird
        kundenArray[i] = (struct Kundinnen *)malloc(sizeof(struct Kundinnen));

        //Eingabeauforderung mit Abbruchsmöglichkeit
        printf("\nBitte geben die den Kunden Namen ein (um keinen (weiteren)Kunden einzugenben '-'): ");
        scanf("%s",kundenArray[i]->name);

         //Abbruchüberprüfung 
        if(kundenArray[i]->name[0]=='-'){break;}

        //Resetliche Eingabeaufforderung
        printf("\nBitte geben die Emailadresse des Kunden ein: ");
        scanf("%s",kundenArray[i]->email);
        printf("\nBitte geben die Adresse des Kunden ein: ");
        scanf("%s",kundenArray[i]->adresse);     
        printf("\nBitte geben die Hausnummer des Kunden ein: ");
        scanf("%d",&kundenArray[i]->hausnummer);   
        kundenArray[i]->id = i + 1;  
        kundenanzahl++;
    }

    // Ausgabe der unsortierten bzw. nach id sortierten Kundinnen
    printf("\nUnsortierte bzw. nach ID Kundinnen:\n");
    for (int i = 0; i < kundenanzahl; i++) 
    {
        printf("ID: %d, \tVorname: %s, \t\t\tEmail: %s, \t\t\tAdresse: %s %d\n", kundenArray[i]->id, kundenArray[i]->name, kundenArray[i]->email, kundenArray[i]->adresse, kundenArray[i]->hausnummer);
    }

    //Aufruf der Funktion mykleinbuchstaben für jeden eingebenen kunden
    for(int i=0; i<kundenanzahl;i++)
    {
        mykleinbuchstaben(kundenArray[i]);
    }

    //Aufruf der Funktion mysortandprint, mit dem pointerarray und der int kundenanzahl als übergabeparameter, veränder das kundenArray nicht
    mysortandprint(kundenArray, kundenanzahl);
        

    // Ausgabe der unsortierten/nach id sortierten Kundinnen
    printf("\nUnsortierte bzw. nach ID Kundinnen:\n");
    for (int i = 0; i < kundenanzahl; i++) 
    {
        printf("ID: %d, \tVorname: %s, \t\t\tEmail: %s, \t\t\tAdresse: %s %d\n", kundenArray[i]->id, kundenArray[i]->name, kundenArray[i]->email, kundenArray[i]->adresse, kundenArray[i]->hausnummer);
    }

    // reserviertenspeicher freigeben 
    for (int i = 0; i < kundenanzahl; i++) 
    {
        free(kundenArray[i]);
    }


    return 0;
}