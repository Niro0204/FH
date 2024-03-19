// includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 20

// functions
void print();
void enqueue(int x);
void dequeue();
void first();
int isEmpty();
int length();
int size();
void reset();

// globals
int queue[MAX_SIZE];
int front, rear = -1;

int main()
{
    // Checking if the queue is empty
    if (isEmpty() == 1)
        printf("The queue is empty\n");

    // Assigning elements to the queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(55);

    // print queue
    print();

    // Printing the first element of the queue
    first();

    // Printing the size of the queue
    printf("Length: %d\n\n", length());

    // dequeue the elements
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    // reset();

    // Printing new size of the queue
    printf("New Length: %d\n", length());

    // Printing the queue
    print();
    return 0;
}

/*
=======================================================================
print the current queue if it contains elements
=======================================================================
*/
void print()
{
    // If the queue is already empty
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        // A variable to help in iteration through the queue.
        int i = 0;
        printf("\nQueue:\n");

        // Printing all the elements of the queue
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

/*
=======================================================================
enqueue first element
=======================================================================
*/
void enqueue(int x)
{
    if (rear == MAX_SIZE - 1)
    {
        "Queue is full!";
    }
    else
    {
        if (front == -1)
        {
            front = 0; // update front postion
        }
        rear++;          // new rear position
        queue[rear] = x; // insert new element at the back
    }
}

/*
=======================================================================
dequeue first element -> FIFO
=======================================================================
*/
void dequeue()
{
    printf("Dequeueing element.\n");
    if (isEmpty())
    {
        "Queue is empty";
    }
    else
    {
        front++;

        // when last item got dequeued -> reset queue
        if (front > rear)
        {
            reset();
        }
    }
}

/*
=======================================================================
print first element
=======================================================================
*/
void first()
{
    if (!isEmpty())
    {
        printf("\nFirst Element: %d\n", queue[front]);
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

/*
=======================================================================
check if queue is empty
=======================================================================
*/
int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
=======================================================================
return length of queue
=======================================================================
*/
int length()
{
    // If the queue is empty, return 0
    if (isEmpty() == 1)
    {
        return 0;
    }
    // The number of items in the queue is the difference between front and rear
    return rear - front + 1;
}

/*
=======================================================================
print max size of queue
=======================================================================
*/
int size()
{
    return MAX_SIZE;
}

/*
=======================================================================
reset queue
=======================================================================
*/
void reset()
{
    front = -1;
    rear = -1;
}