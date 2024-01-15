#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct KundenDaten
{

    char Name[50];
    char Adresse[50];
    char telnum[20];
    int id;

} kunden;

int main()
{

    srand(time(NULL));
    kunden kunde[2];
    int length = sizeof(kunde) / sizeof(kunde[0]);

    for (int i = 0; i <= length - 1; i++)
    {

        printf("Kundenname %d: ", i + 1);
        scanf("%s", &kunde[i].Name);
        printf("Adresse: ");
        scanf("%s", &kunde[i].Adresse);
        printf("Telefonnummer: ");
        scanf("%s", &kunde[i].telnum);
        kunde[i].id = rand() % 10000;
        printf("Kunden-ID wurde generiert\n\n");
    }

    printf("--------------------------\n\n Kunden:\n\n");
    printf("Kunde 1:\n Name: %s\n Adresse: %s\n Telefonnummer: %s\n Kunden-ID: %d\n\n", kunde[0].Name, kunde[0].Adresse, kunde[0].telnum, kunde[0].id);
    printf("Kunde 2:\n Name: %s\n Adresse: %s\n Telefonnummer: %s\n Kunden-ID: %d\n\n", kunde[1].Name, kunde[1].Adresse, kunde[1].telnum, kunde[1].id);
    return 0;
}