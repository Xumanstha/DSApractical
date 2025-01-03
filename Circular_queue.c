#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full
int isFull()
{
    return (front + 1) % SIZE == rear;
}

// Check if the queue is empty
int isEmpty()
{
    return front == -1;
}

// Enqueue an element into the circular queue
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty())
    { // If the queue is empty
        front = rear = 0;
    }
    else
    {
        front = (front + 1) % SIZE;
    }

    queue[front] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element from the circular queue
int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return -1; // Indicate empty queue
    }

    int value = queue[rear];

    if (front == rear)
    { // Queue becomes empty after dequeue
        front = rear = -1;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    printf("Dequeued: %d\n", value);
    return value;
}

int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7); // Queue becomes full here
    enqueue(8); // Attempt to enqueue into a full queue

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue becomes empty here
    dequeue(); // Attempt to dequeue from an empty queue

    enqueue(9);
    enqueue(10);

    return 0;
}