#include <stdio.h>

#define SIZE 5

void enqueue(int);
int dequeue();
void show();
int head();
int tail();
void reset();

int queue[SIZE];
int front = -1;
int rear = -1;


int main (int argc, char * argv[])
{

        int choice, item, check;
        do
        {
            printf("\nQueue Operations:\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Head\n");
            printf("5. Tail\n");
            printf("6. Reset\n");
            printf("7. Exit\n");
            printf("Enter your choice: \n");
            scanf("%d", &choice);
          
            switch (choice)
            {
            case 1:

                printf("Enter the item to insert: ");
                scanf("%d", &item);
                enqueue(item);

                break;
                
            case 2:
                item = dequeue();
                if (item != -1)
                {
                    printf("\nDequed item is: %d\n", item);
                }
                break;
            case 3:
                show();
                break;
            case 4:
                item = head();
                if (item != -1)
                {
                    printf("\nHead item is: %d\n", item);
                }
                break;
            case 5:
                item = tail();
                if (item != -1)
                {
                    printf("\nTail item is: %d\n", item);
                }
                break;
            case 6:
                reset();
                break;
            case 7:
                printf("\n\nExiting from app.\n");
                reset();
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 7);
    return 0;
}

void enqueue(int item)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
    }
}

int dequeue()
{
    int item;
    if (front == -1)
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        return item;
    }
}

void show()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Queue: ");
        for (i = rear; i != front; i = (i - 1 + SIZE) % SIZE)
        {
            if(i == rear)
                printf("(T) %d -> ", queue[i]);
            else if((i % SIZE) != front)
                printf("%d -> ", queue[i]);
        }
        printf("%d (H)", queue[front]);
        printf("\n");
    }
}

int head()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

int tail()
{
    if (rear == -1)
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
    {
        return queue[rear];
    }
}

void reset()
{
    front = -1;
    rear = -1;
}
