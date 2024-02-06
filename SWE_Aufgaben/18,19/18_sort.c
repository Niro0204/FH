/*****************************************************************************************************************

 Name: 18_sort

 Author: Nicolai Rothenhöfer

 Description: Dieses Programm generiert ein zufälliges Integer Array mit zuvor gewählter Größe, 
              sortiert dieses aufsteigend und gibt es wieder aus.

 Datum: 21.02.2024

******************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void sort(int,int[]);


int main(){


    srand(time(NULL));  //Seed für zufällige Zahlen
    int size=0;
   
   

    printf("Size: ");
    scanf("%d", &size);  //einlesen der gewünschten Array Größe


    int nums[size]; //anlegen des Arrays

    //befüllen des Arrays mit zufälligen Zahlen 
    for(int i=0;i<=size-1;i++){

        nums[i]=rand()%100;

    }

    //ausgeben des unsortierten Arrays
    for(int i=0;i<=size-1;i++){

        printf("%d ",nums[i]);

    }

    printf("\n\n");

    //größe des Arrays und das Array selbst werden der Sorteierfunktion übergeben
    sort(size,nums);

    //ausgeben des sortierten Arrays
    for(int i=0;i<=size-1;i++){

        printf("%d ",nums[i]);

    }



    return 0;
}


//Sortierfunktion durch Insertion-Sort
void sort(int size,int nums[]){

  
    int element=0;
    int sorted=0;

    for(int i=1; i<size;i++){ //sortieren startet bei element 1, da 0 al sortiert betrachtet wird

        element=nums[i]; //zu sortierendes element
        sorted=i-1; //kennzeichnet sortierten Bereich

        while(element<nums[sorted]){  //vergleicht derzeitiges element mit sortiertem bereich

            nums[sorted+1]=nums[sorted]; //rückt elemente eine Position weiter um Platz zu machen
            sorted--;

        }

        nums[sorted+1]=element; //element wird an passendem Platz eingesetzt
    }
}