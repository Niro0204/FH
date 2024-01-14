#include <stdio.h>

#define SIZE 5 

void enqueue(int element);
int dequeue();
void show();


int queue[SIZE];
int front = -1;
int rear = -1;



int main()
{
    int choice;
    int element = 0;

    while (1)
    {

        printf("Choose an operation for the queue: \n");
        printf("enqueue [1]\ndequeue [2]\nfirst [3]\nshow [9]\nexit [0]\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Number to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;

        case 2:

            dequeue();
            break;

        case 3:

            printf("%d\n", queue[front]);
            break;

        case 9:

            show();
            break;

        case 0:

            return 0;
        }
    }

    return 0;
}


void enqueue(int element)
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == SIZE - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = element;
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }

    int element = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    return element;
}

void show()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]); // print the last element
    }
}