#include <stdio.h>

void printArgs(int,char**);
void printHelp();

int main(int argc, char *argv[]){

  if(argc<2){
    printHelp();
    return 0;
  }

  printArgs(argc,argv);
  return 0;
}

void printArgs(int argc, char* argv[]){

  fprintf(stdout,"number of arguments: %d\n",argc-1);
  for(int i = 0; i < argc; i++ ){
    fprintf(stdout,"%s\n",argv[i]);
  }
}

void printHelp(){

  fprintf(stdout,"Use of Program:\n\n"
                 "./listargs *list of arguments*\n"
                 "the number of arguments given has to be greater than zero!\n");
}
