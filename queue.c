#include <stdio.h>
#define Maxsize 5 // Define the maximum size of the circular queue

int queue[Maxsize]; // Array to hold the queue elements
int front = -1;     // Index of the front element of the queue
int rear = -1;      // Index of the rear element of the queue

// Function to check if the queue is full
int isFull()
{
    return (rear + 1) % Maxsize == front; // Queue is full if rear is one step behind front (circularly)
}

// Function to check if the queue is empty
int isEmpty()
{
    return front == -1; // Queue is empty if front is -1
}

// Function to add an element to the queue
void enqueue(int n)
{
    if (isFull()) // Check if the queue is full
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        if (isEmpty()) // If the queue is empty, initialize front to 0
        {
            front = 0;
        }
        rear = (rear + 1) % Maxsize; // Move rear to the next position circularly
        queue[rear] = n;             // Add the element to the queue
        printf("Enqueued:%d\n", n);  // Print the enqueued value
    }
}

// Function to remove an element from the queue
int dequeue()
{
    if (isEmpty()) // Check if the queue is empty
    {
        printf("The queue is empty\n");
        return -1;
    }
    else
    {
        int value = queue[front]; // Store the value at the front
        if (front == rear)        // If there's only one element, reset the queue
        {
            front = -1;
            rear = -1;
        }
        else // Otherwise, move front to the next position circularly
        {
            front = (front + 1) % Maxsize;
        }
        return value; // Return the dequeued value
    }
}

// Function to display the elements of the queue
void display()
{
    if (isEmpty()) // Check if the queue is empty
    {
        printf("The queue is empty\n");
    }
    else
    {
        int i;
        // Iterate from front to rear circularly and print elements
        for (i = front; i != rear; i = (i + 1) % Maxsize)
        {
            printf("%d\t", queue[i]);
        }
        printf("%d", queue[i]); // Print the last element (rear)
        printf("\n");
    }
}

int main()
{
    int choose; // Variable to store user choice
    int value;  // Variable to store the value to enqueue or dequeue
    do
    {
        // Display menu options
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choose); // Read the user's choice
        switch (choose)
        {
        case 1:
            printf("Enter the number to enqueue:\n");
            scanf("%d", &value);             // Read the value to enqueue
            enqueue(value);                  // Call enqueue function
            printf("%d\t%d\n", front, rear); // Print the current front and rear indices
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue()); // Call dequeue function and print dequeued value
            printf("%d\t%d\n", front, rear);     // Print the current front and rear indices
            break;
        case 3:
            display();                       // Call display function to print the queue
            printf("%d\t%d\n", front, rear); // Print the current front and rear indices
            break;
        case 4:
            break; // Exit the program
        default:
            printf("Invalid choice:\n"); // Handle invalid menu choices
        }
    } while (choose != 4); // Repeat until the user chooses to exit
    return 0; // End of the program
}
