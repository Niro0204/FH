


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

     // Check if the correct number of command-line arguments are provided
    if (argc != 4) {
        printf("man: <source File> <destination File> <word to blurr>\n");
        return 0;
    }

    // Open the source file for reading
    FILE *sourceF = fopen(argv[1], "r");
    if (sourceF == NULL) {
        printf("failed to open source file.\n");
        return 0;
    }

    // Open or create the destination file (append mode)
    FILE *destF = fopen(argv[2], "a");
    if (destF == NULL) {
        printf("failed to open destination file.\n");
        fclose(sourceF);
        return 0;
    }

    // Store the word to be blurred from command-line argument
    char *strg = argv[3];
    int wordlen = strlen(strg);

    int c;
    int i = 0;

     // Read characters from source file until EOF is reached
    while ((c = fgetc(sourceF)) != EOF) {

        // Check if the character matches the next character of the word to be blurred
        if (c == strg[i]) {
            i++;
            if (i == wordlen) {  //if all characters match, replace the word
                fputs("****", destF);
                i = 0;
            }
        } 
        else {
            if (i > 0) {   //if not all characters match, write the matched ones in the file
                fwrite(strg, sizeof(char), i, destF);
                i = 0;
            }

            //if there is no match at all, write characters into the File
            fputc(c, destF);
        }
    }

    //write any in strg remaining characters into file
    if (i > 0) {
        fwrite(strg, sizeof(char), i, destF);
    }

    //close both files
    fclose(sourceF);
    fclose(destF);

    //let the user know the program completed successfully
    printf("copied and anonymized successfully\n");

    return 0;
}