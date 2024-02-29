#include <stdio.h>


int sstack[10][5];
int top=0;

int spush(int[5]);
int spop(int[5]);

int main(){



    return 0;
}

int spush(int nums[5]){

    int res=-1;

    if(top==10){

        printf("stack is full");
        return res;
    }

    for(int i;i<5;i++){

        sstack[top][i]=nums[i];

    }

    top++;

    int res=top;

    return res;

}

int spop(int nums[]){

    int res=-1;

    if(top==0){
        printf("Stack is empty");
        return res;
    }

    for(int i=0;i<5;i++){

        nums[i]=sstack[top-1][i];

    }

    top--;
    res=top-1;

    return res;


}