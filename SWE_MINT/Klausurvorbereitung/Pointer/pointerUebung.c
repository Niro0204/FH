#include <stdio.h>

void strStar(char arr[]);

int main()
{
    char strg[] = "hallo";

    printf("String: %s", strg);
    printf("\n\n");

    strStar(strg);

    return 0;
}

void strStar(char arr[])
{

    for (int i = 0; i <= 5; i++)
    {

        if (i % 2 == 0)
        {
            arr[i] = '*';
        }

        printf("%c", arr[i]);
    }
}