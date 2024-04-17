#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double amean(int len1,int len2,int[len1][len2]);

int main(){

int len1=0;
int len2=0;
double arith=0;


printf("len1: ");
scanf("%d",&len1);

printf("len2: ");
scanf("%d",&len2);

int nums[len1][len2];

for(int i=0;i<=len1-1;i++)
{
    for(int j=0;j<=len2-1;j++)
    {

        printf("num[%d][%d]:",i,j);
        scanf("%d",&nums[i][j]);

    }

}

printf("\n\n");

for(int i=0;i<=len1-1;i++)
{
    for(int j=0;j<=len2-1;j++)
    {

        printf("%d ",nums[i][j]);
        

    }

printf("\n");
}

    arith=amean(len1,len2,nums);
    printf("Arithmetisches Mittel: %lf",arith);

    return 0;

}

double amean(int len1, int len2,int nums[len1][len2]){

//int count=0;
int sum=0;
int arith=0;

    for(int i=0;i<=len1-1;i++){

        for(int j=0;j<=len2-1;j++){

                sum+=nums[i][j];
                //count++;

        }

    }

arith=sum/(len1*len2);

return arith;
}