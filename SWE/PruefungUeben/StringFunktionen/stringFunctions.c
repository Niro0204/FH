/*
=======================================================================
program name: myStringFunctions.c
author: Sebastian Maier
program content: Fügen Sie Ihrem Programm aus Übungsaufgabe 13
die Funktionen mystrncat und mystrstr hinzu. Recherchieren Sie dazu,
was die beiden Funktionen strncat und strstr aus string.h tun und
programmieren Sie deren Funktionalität nach.
date: 06.12.2023
=======================================================================
*/

// includes
#include <stdio.h>

// Functions
void my_strcmp(char[], char[]);
void my_strcpy(char[], char[]);
void my_strcat(char[], char[], char[]);
void palindrome_check(char[]);
void my_strncat(char[], char[], char[], int);
void my_strstr(char[], char[]);
int my_strlen(char[]);

int main()
{
    // Variablen
    char s1[30];
    char s2[30];
    char s3[60]; // for strcat
    char s4[60]; // for strstr
    int n = 0;

    // Eingabe
    printf("\nErster Name: ");
    scanf("%s", s1);

    printf("Zweiter Name: ");
    scanf("%s", s2);

    printf("Lange fuer Strncat: ");
    scanf("%d", &n);

    printf("Stringkette fuer Strstr: ");
    scanf(" %[^\n]", s4); // %[^\n] liest Leerzeichen mit ein -> liest bis Zeilenende

    printf("\n");

    // Funktionsaufrufe und Ausgabe
    my_strcmp(s1, s2);
    my_strcat(s1, s2, s3);
    my_strncat(s1, s2, s3, n); // vor strcpy, da sonst beide strings gleich sind
    my_strcpy(s1, s2);
    palindrome_check(s1);
    my_strstr(s4, s1);

    printf("\n");

    return 0;
}

/*
=======================================================================
my_strcmp
=======================================================================
*/
void my_strcmp(char s1[], char s2[])
{
    int result = 0;
    int s1_len = my_strlen(s1);

    printf("|Strcmp:| \t|");
    // for Schleife geht davon aus, dass der erste String länger ist als der zweite
    for (int i = 0; i < s1_len; i++)
    {
        if (s1[i] == s2[i])
        {
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    if (result == 0)
    {
        printf("Strings sind gleich.\n");
    }
    else
    {
        printf("Strings sind nicht gleich.\n");
    }
}

/*
=======================================================================
my_strcat
=======================================================================
*/
void my_strcat(char src[], char app[], char dest[])
{
    int src_len = my_strlen(src);
    int i = 0;

    printf("|Strcat:| \t|");
    // Kopieren des Inhalts von source in destination
    for (i = 0; i < src_len; i++)
    {
        dest[i] = src[i];
    }

    // Anhängen von append an destination
    int j = 0;
    while (app[j] != '\0')
    {
        dest[i] = app[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    printf("%s\n", dest);
}

/*
=======================================================================
my_strcpy
=======================================================================
*/
void my_strcpy(char src[], char dest[])
{
    int i = 0;
    // Kopiere Zeichen von src nach dest, bis das Null-Zeichen erreicht wird
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    printf("|Strcpy:| \t|String 1: %s -- String 2: %s\n", src, dest);
}

/*
=======================================================================
palindrome_check
=======================================================================
*/

void palindrome_check(char s[])
{
    int start = 0;
    int end = my_strlen(s) - 1;
    int result = 0;

    printf("|Pldrom:| \t|");
    while (end > start)
    {
        // Wenn s[0] != s[9] kann es schon kein Palindrom mehr sein
        if (s[start++] != s[end--]) // String wird von vorne nach hinten und von hinten nach vorne untersucht
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    // Ausgabe
    if (result == 0)
    {
        printf("String 1 ist ein Palindrom\n");
    }
    else
    {
        printf("String 1 ist kein Palindrom\n");
    }
}

/*
=======================================================================
my_strncat
=======================================================================
*/
void my_strncat(char src[], char app[], char dest[], int n)
{
    int src_len = my_strlen(src);
    int i = 0;

    printf("|Strnct:| \t|");

    // Kopieren des Inhalts von source in destination
    for (i = 0; i < src_len; i++)
    {
        dest[i] = src[i];
    }

    // Anhängen von append an destination
    int j = 0;
    while (app[j] != '\0' && j < n)
    {
        dest[i] = app[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    printf("%s\n", dest);
}

/*
=======================================================================
my_strstr
=======================================================================
*/
void my_strstr(char big[], char small[])
{
    int big_len = my_strlen(big);
    int small_len = my_strlen(small);
    int result = 0;

    printf("|Strstr:| \t|");
    // Hauptstring durchlaufen (big_len-small_len, weil das die maximale Länge ist wo kleiner string anfangen kann)
    for (int i = 0; i <= big_len - small_len; i++)
    {
        // Überprüfe, ob der Teilstring ab der aktuellen Position übereinstimmt
        int j; // i für Position in großem String und j in kleinem String
        for (j = 0; j < small_len; j++)
        {
            if (big[i + j] != small[j])
            {
                result = 1; // res für ausgabe
                break;      // Bricht die "j" for schleife ab, weil ein nicht übereinstimmendes zeichen gefunden wurde
            }
        }

        if (j == small_len) // prüfen ob wirklich jedes zeichen im small mit jedem im big verglichen wurde
        {
            // Die Schleife wurde vollständig durchlaufen, d. h. alle Zeichen stimmen überein
            result = 0; // res für ausgabe
            printf("'%s' wurde in '%s' gefunden, an Position %d.\n", small, big, i);
            break; // Breche die äußere Schleife ab, da der kleine String gefunden wurde
        }
    }

    if (result == 1)
    {
        printf("'%s' wurde in '%s' nicht gefunden.\n", small, big);
    }
}

/*
=======================================================================
my_strlen
=======================================================================
*/
int my_strlen(char s1[])
{
    int result = 0;

    // bis Stringende loopen
    for (int i = 0; s1[i] != '\0'; i++)
    {
        result++;
    }
    return result;
}