
#include <stdio.h>
#include <string.h>

int main()
{
    // Variablen
    char inputString[1000];

    // Eingabe
    printf("Geben Sie einen Satz in Kleinbuchstaben ein: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Verarbeitung
    int length = strlen(inputString); // Länge des Strings um zu erkennen wann der "Satz" aus ist

    for (int i = 0; i < length; i++)
    {
        // Überprüfen ob String nur Kleinbuchstaben beinhaltet
        if (inputString[i] >= 'a' && inputString[i] <= 'z')
        {
            // Wenn das so ist werden Klein-/ in Großbuchstaben umgewandelt (32 wegen ASCII Tabelle)
            inputString[i] -= 32;
        }
        else
        {
            printf("Ungültiger Satz!");
            return 0;
        }
    }

    // Ausgabe
    printf("%s", inputString);
    return 0;
}
