#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void *x, const void *y);

int main()
{

    // qsort(arr, n, size, comparefunc);
    // int comparefunc(const void* x, const void* y)

    float arr[10];
    int laenge = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    printf("Bitte geben sie bis zu 10 positive Zahlen ein: \n");

    for (int i = 0; i < 10; i++)
    {

        float num = 0;
        scanf("%f", &num);
        if (num < 0)
        {
            break;
        }
        arr[i] = num;
        count++;
    }

    printf("------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%.2f\n", arr[i]);
    }

    printf("----------------\n\n");

    qsort(arr, count, sizeof(float), comparefunc);

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%.2f\n", arr[i]);
    }

    return 0;
}

int comparefunc(const void *x, const void *y)
{

    int xc = *(int *)x;

    int yc = *(int *)y;

    return xc - yc;
}
