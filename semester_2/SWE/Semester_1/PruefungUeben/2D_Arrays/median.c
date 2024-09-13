#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void sort(int,int[]);
float median(int,int[]);

int main(){

    srand(time(NULL));
    int size=0;
    float medi=0;
   

    printf("Size: ");
    scanf("%d", &size);
    fflush(stdin);

    int nums[size];

    for(int i=0;i<=size-1;i++){

        nums[i]=rand()%100;

    }

    for(int i=0;i<=size-1;i++){

        printf("%d ",nums[i]);

    }

    printf("\n\n");

    sort(size,nums);

    for(int i=0;i<=size-1;i++){

        printf("%d ",nums[i]);

    }

    int rlsize=sizeof(nums)/sizeof(int);
    medi=median(rlsize,nums);
    printf("\nMedian: %f",medi);


    return 0;
}



void sort(int size,int nums[]){

  
    int element=0;
    int sorted=0;

    for(int i=1; i<size;i++){

        element=nums[i];
        sorted=i-1;

        while(element<nums[sorted]){

            nums[sorted+1]=nums[sorted];
            sorted--;

        }

        nums[sorted+1]=element;
    }



}

float median(int rlsize,int nums[]){

   
    float medi=0;

    if(rlsize%2!=0){

        medi=nums[(rlsize)/2];

    }
    else{

        float medi1=nums[(rlsize-1)/2];
        float medi2=nums[(rlsize+1)/2];
        medi=(medi1+medi2)/2;

    }

    return medi;

}