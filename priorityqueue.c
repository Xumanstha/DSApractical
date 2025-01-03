#include <stdio.h>
#define size 5
int front = -1;
int rear = -1;
int queue[size];
int Priority[size];
int isFull()
{
    return (rear + 1) % size == front;
    // return rear == size-1;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int isEmpty()
{
    return rear == -1;
}
void enqueue(int value, int p)
{
    int i, j;
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        if (rear == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = value;
        Priority[rear] = p;
        i = rear;
        j = rear;
        i = i - 1;
        while (p < Priority[i])
        {
            swap(Priority + i, Priority + j);
            swap(queue + i, queue + j);
            j = i;
            i = i - 1;
            p = Priority[j];
        };
        printf("Enqueued:%d\n", value);
    }
}
int dequeue()
{
    if (isEmpty())
    {
        printf("the queue is empty");
        return -1;
    }
    else
    {
        int element = queue[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return element;
    }
}
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d\t", queue[i]);
        }
        printf("%d", queue[i]);
        printf("\n");
    }
}
int main()
{
    // enqueue(78, 5);
    // enqueue(50, 3);
    // dequeue();
    // enqueue(60, 4);
    // enqueue(29, 2);
    // dequeue();
    // enqueue(3, 6);

    // enqueue(38, 6);
    // printf("Queue according to priority:\n");
    // display();
    int choose;       // Variable to store user choice
    int value, prior; // Variable to store the value to enqueue or dequeue
    do
    {
        // Display menu options
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choose); // Read the user's choice
        switch (choose)
        {
        case 1:
            printf("Enter the number to enqueue and priority also:\n");
            scanf("%d%d", &value, &prior); // Read the value to enqueue
            enqueue(value, prior);         // Call enqueue function
            // printf("%d\t%d\n", front, rear); // Print the current front and rear indices
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue()); // Call dequeue function and print dequeued value
            // printf("%d\t%d\n", front, rear);     // Print the current front and rear indices
            break;
        case 3:
            display(); // Call display function to print the queue
            // printf("%d\t%d\n", front, rear); // Print the current front and rear indices
            break;
        case 4:
            break; // Exit the program
        default:
            printf("Invalid choice:\n"); // Handle invalid menu choices
        }
    } while (choose != 4); // Repeat until the user chooses to exit
    return 0; // End of the program
}