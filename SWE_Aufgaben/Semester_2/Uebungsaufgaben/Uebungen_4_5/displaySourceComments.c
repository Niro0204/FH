/*****************************************************************************************************************

 Name: displaySourceComments.c

 Author: Nicolai Rothenhöfer

 Description: This program prints all comments from a given c-file either in a wanted file, or to stdout

 Datum: 15.04.2024

******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void printComments(FILE*,FILE*,bool);

int main(int argc, char* argv[]){

    //bool for checking if stream should be written in a file
    bool cpyCom = false;
    
    //setting sourceFile to last given argument
    FILE* sourceFile = NULL;
    sourceFile = fopen(argv[argc-1],"r");

    if(sourceFile == NULL){
        fprintf(stderr,"Failed to open source-file");
        return 0;
    }
    
    FILE* destFile = NULL;

    //checking if the stream should be written in a file
    for(int i = 0;i<argc;i++){
 
        if(strcmp(argv[i],"-c")==0 && i+1 < argc){      
            cpyCom = true;
            destFile = fopen(argv[++i],"w"); //destination ist the next argument after -c
            if(destFile == NULL){
                fprintf(stderr,"Failed to open destination-file");
                return 0;
            }
        }
    } 
  
    printComments(sourceFile,destFile,cpyCom);

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

void printComments(FILE* sourceFile, FILE* destFile, bool cpyCom){

    int currentChar;
    int nextChar;

    while((currentChar = getc(sourceFile)) != EOF){

        // checking if current character is a "/"
        if(currentChar == '/'){

            // reads the next character to check if it is a comment
            nextChar = getc(sourceFile);

            if(nextChar == '/'){

                // printing comment marker
                if(cpyCom){
                    fputc(currentChar, destFile);
                    fputc(nextChar, destFile);
                }
                else{
                    putchar(currentChar);
                    putchar(nextChar);
                }

                // found comment gets printed
                while((currentChar = getc(sourceFile)) != '\n' && currentChar != EOF){
                    if(cpyCom){
                        fputc(currentChar, destFile);
                    }
                    else{
                        putchar(currentChar);
                    }
                }

                // adding an endline character for readability
                if(cpyCom){
                    fputc('\n', destFile);
                }
                else{
                    putchar('\n');
                }
            }
            // if the next character is a "*", a multi-line comment is found
            else if(nextChar == '*'){

                // printing comment marker
                if(cpyCom){
                    fputc(currentChar, destFile);
                    fputc(nextChar, destFile);
                }
                else{
                    putchar(currentChar);
                    putchar(nextChar);
                }

                // printing multi-line comment
                while((currentChar = getc(sourceFile)) != EOF){

                    // checking if the current character is a "*"
                    if(currentChar == '*'){

                        // checking if the next character is a "/" to end comment
                        nextChar = getc(sourceFile);

                        if(nextChar == '/'){
                            // printing comment marker
                            if(cpyCom){
                                fputc(currentChar, destFile);
                                fputc(nextChar, destFile);
                            }
                            else{
                                putchar(currentChar);
                                putchar(nextChar);
                            }
                            break; // end of printing the multi-line comment
                        }
                        else{
                            // if the end is not reached, reseting the filepointer to previous position
                            ungetc(nextChar, sourceFile);
                        }
                    }

                    //printing the multi-line comment
                    if(cpyCom){
                        fputc(currentChar, destFile);
                    }
                    else{
                        putchar(currentChar);
                    }
                }
            }
            else{
                // if the next character is not part of the comment marker, it gets reseted
                ungetc(nextChar, sourceFile);
            }
        }
    }
}








