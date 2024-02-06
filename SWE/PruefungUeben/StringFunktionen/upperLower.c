#include <stdio.h>

int toUpper(char str[]);
int toLower(char str[]);

int main(){

char str[10];

    printf("geben sie einen string ein:");
    scanf("%s",str);
   
    int countUp=toUpper(str);

    printf("New Upper String: %s\n",str);
    printf("Changes: %d\n\n",countUp);

    int countLow=toLower(str);

    printf("New Lower String: %s\n",str);
    printf("Changes: %d\n",countLow);
    
   
    return 0;
}

int toLower(char str[]){

    int count=0;

        for(int i=0;i<=9;i++){

            if(str[i]>=65 && str[i]<=90){

                str[i]=str[i]+32;
                count++;
            }
            else if(str[i]==0){

                break;
            }
            else{

                str[i]=str[i];
            }


        }


    return count;
}


int toUpper(char str[]){

    int count = 0;
    for(int i=0; i<=9;i++){

        if(str[i]>=97){

            str[i]=str[i]-32;
            count++;
        }
        else if (str[i]==0){

            break;
        }
        else{
            str[i]=str[i];
        }
   

    }

    

    return count;
}