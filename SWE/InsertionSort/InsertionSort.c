// includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// globals
#define ELEMENTS 10

// functions
void print_arr(int arr[]);
void insertionSort(int arr[]);

int main()
{
    int arr[ELEMENTS];
    
    printf("Zahlen für Array eingeben (MAX 10): ");

    for(int i = 0; i<=9; i++){

        scanf("%d", &arr[i]);

    }

    printf("Unsorted Array: \n");
    print_arr(arr);

    insertionSort(arr);

    printf("Sorted Array: \n");
    print_arr(arr);

    return 0;
}

/*
=======================================================================
print array
=======================================================================
*/
void print_arr(int arr[])
{
    for (int i = 0; i < ELEMENTS; i++)
    {
        printf("|%d| ", arr[i]);
    }
    printf("\n");
}

/*
=======================================================================
sort the array
=======================================================================
*/
void insertionSort(int arr[])
{
    int element = 0;
    int sorted = 0;
    for (int i = 1; i < ELEMENTS; i++) // start loop at second element, because the first element is already "sorted"
    {
        element = arr[i]; // current element
        sorted = i - 1;   // already sorted element

        while (arr[sorted] > element) // loop goes through the already sorted part of the array
        {
            arr[sorted + 1] = arr[sorted]; // moves bigger elements 1 position to the right so there is space for the other element
            sorted--;                      // reduces sorted so the next element in the already sorted part can be checked
        }
        arr[sorted + 1] = element; // inserts element at the correct position
    }
}