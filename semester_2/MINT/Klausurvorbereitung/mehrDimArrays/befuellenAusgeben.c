#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void diaNull(int arr[][]);
int main()
{

    int arr[10][10];

    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i <= 9; i++)
    {
        count1++;

        for (int j = 0; j <= 9; j++)
        {
            count2++;

            if (count1 == count2)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
                        }
        }
    }
    // diaNull(arr);

    return 0;
}

/*void diaNull(int arr[][])
{

    int count1;
    int count2;

    for (int i = 0; i <= 9; i++)
    {
        count1++;

        for (int j = 0; j <= 9; j++)
        {
            count2++;

            if (count1 == count2)
            {
                arr[i][j] = 1;
            }

            printf("%003d", arr[i][j]);
        }
    }
}*/