


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("man: <source File> <destination File> <word to blurr>\n");
        return 0;
    }

    FILE *sourceF = fopen(argv[1], "r");
    if (sourceF == NULL) {
        printf("failed to open source file.\n");
        return 0;
    }

    FILE *destF = fopen(argv[2], "a");
    if (destF == NULL) {
        printf("failed to open destination file.\n");
        fclose(sourceF);
        return 0;
    }

    char *strg = argv[3];
    int wordlen = strlen(strg);

    int c;
    int i = 0;

    while ((c = fgetc(sourceF)) != EOF) {
        if (c == strg[i]) {
            i++;
            if (i == wordlen) {
                fputs("****", destF);
                i = 0;
            }
        } else {
            if (i > 0) {
                fwrite(strg, sizeof(char), i, destF);
                i = 0;
            }
            fputc(c, destF);
        }
    }

    if (i > 0) {
        fwrite(strg, sizeof(char), i, destF);
    }

    fclose(sourceF);
    fclose(destF);

    printf("Anonymisierung abgeschlossen.\n");

    return 0;
}