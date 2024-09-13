#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void addWord(WordCount *wordCounts, char *word, int *numWords) {
    for (int i = 0; i < *numWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }

    strcpy(wordCounts[*numWords].word, word);
    wordCounts[*numWords].count = 1;
    (*numWords)++;
}

void printMostCommonWords(WordCount *wordCounts, int numWords, int numMostCommon) {
    printf("Die %d am häufigsten vorkommenden Wörter und ihre Häufigkeiten sind:\n", numMostCommon);
    for (int i = 0; i < numMostCommon && i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int compare(const void *a, const void *b) {
    const WordCount *wordCountA = (const WordCount *)a;
    const WordCount *wordCountB = (const WordCount *)b;
    return (wordCountB->count - wordCountA->count);
}

int main() {
    char filename[100];
    printf("Geben Sie den Dateinamen ein: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Die Datei wurde nicht gefunden.\n");
        return 1;
    }

    WordCount wordCounts[1000];  // Annahme: Die maximale Anzahl von Wörtern ist 1000
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        addWord(wordCounts, word, &numWords);
    }

    fclose(file);

    // Sortieren der Wörter nach Häufigkeit
    qsort(wordCounts, numWords, sizeof(WordCount), compare);

    int numMostCommon = 10;  // Anzahl der am häufigsten vorkommenden Wörter
    printMostCommonWords(wordCounts, numWords, numMostCommon);

    return 0;
}