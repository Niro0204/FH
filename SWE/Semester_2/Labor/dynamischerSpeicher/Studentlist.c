#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

   typedef struct Studentlist
    {
        char name[30];
        int age;

    } student;


    student *storage = NULL;
    storage = malloc(sizeof(student));
    
    student student1;
    strcpy(student1.name,"Nico");
    student1.age = 20;

    storage = (student*)realloc(storage, 2*sizeof(student));
           
    student student2;
    strcpy(student2.name,"Sebi");
    student2.age = 390;

    printf("name1: %s\nage1: %d\n\n",student1.name,student1.age);
    printf("name2: %s\nage2: %d\n\n",student2.name,student2.age);

    return 0;
}