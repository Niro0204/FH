#include <stdio.h>

#define MAX_SIZE 5


void push(int);
int pop();
void show();

int stack[MAX_SIZE];
int top = -1;



int main() 
{
    
    int choice=0, item;

    do
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show\n");
        printf("4. Top\n");    
        printf("5. Reset\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
      

        switch (choice)
        {
            case 1:

                printf("Enter the element to be pushed: ");
                scanf("%d", &item);
                push(item);
                
                break;

            case 2:

                item = pop();

                printf("Popped item: %d\n", item);

                break;

            case 3:

                show();

                break;

            case 4:

                if (top == -1) 
                {
                    printf("\nStack is empty\n");
                } 
                else 
                {
                    printf("Top element is: %d\n", stack[top]);
                }
                break;

            case 5:
            
                top = -1;
                break;

            case 9:

                printf("\nExiting from app.\n");

                break;
            default:

                printf("\nInvalid choice, please try again.\n");
                
                break;
        }
    }while (choice != 9);
    return 0;
}


void push(int item) 
{
    if (top == MAX_SIZE - 1) 
    {
        printf("Stack is full\n");
    } 
    else {
        stack[++top] = item;
    }
}

int pop() 
{
    if (top == -1) 
    {
        printf("Stack is empty\n");
        return -1;
    } 
    else 
    {
        return stack[top--];
    }
}

void show(){

     if(top == -1) 
        {
            printf("\nStack is empty\n");
        } 
    else 
        {
            printf("Stack elements are:\n\n");
            printf("---\n");
                for (int i = top; i >= 0; i--)
                {
                    if(i == top)
                    {
                         printf("%d (TOP)\n", stack[i]);
                    }     
                    else
                    {
                     printf("%d\n", stack[i]);
                    }
                    
                }
            printf("---\n");
        }
}