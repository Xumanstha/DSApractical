#include <stdio.h>
#define size 5 // Define the maximum size of the queue

// Global variables for queue and priority queue
int front = -1;
int rear = -1;
int queue[size];    // Array to store queue elements
int Priority[size]; // Array to store priority of queue elements

// Function to check if the queue is full
int isFull()
{
    return (rear + 1) % size == front; // Check circular queue condition
    // Alternative check: return rear == size-1;
}

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if the queue is empty
int isEmpty()
{
    return rear == -1; // Queue is empty if rear is -1
}

// Function to enqueue an element with a priority
void enqueue(int value, int p)
{
    int i, j;
    if (isFull())
    {
        printf("Queue is full\n"); // Inform the user that the queue is full
    }
    else
    {
        // Initialize front if the queue is empty
        if (rear == -1)
        {
            front = 0;
        }
        // Insert the new element at the rear of the queue
        rear = (rear + 1) % size;
        queue[rear] = value;
        Priority[rear] = p;

        // Rearrange elements based on priority
        i = rear;
        j = rear;
        i = i - 1; // Start comparison from the previous element
        while (p < Priority[i])
        {
            swap(Priority + i, Priority + j); // Swap priorities
            swap(queue + i, queue + j);       // Swap corresponding values
            j = i;
            i = i - 1;
            p = Priority[j]; // Update current priority
        };
        printf("Enqueued:%d\n", value); // Inform the user of successful enqueue
    }
}

// Function to dequeue the element with the highest priority
int dequeue()
{
    if (isEmpty())
    {
        printf("The queue is empty\n"); // Inform the user that the queue is empty
        return -1;                      // Return -1 for an empty queue
    }
    else
    {
        int element = queue[front]; // Get the front element

        // Adjust front and rear pointers
        if (front == rear)
        {
            front = -1; // Reset the queue if it becomes empty
            rear = -1;
        }
        else
        {
            front = (front + 1) % size; // Move the front pointer
        }
        return element; // Return the dequeued element
    }
}

// Function to display the elements of the queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n"); // Inform the user that the queue is empty
    }
    else
    {
        int i;
        // Loop through the queue using circular logic
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d\t", queue[i]); // Print each element
        }
        printf("%d", queue[i]); // Print the last element
        printf("\n");
    }
}

int main()
{
    int choose;       // Variable to store user choice
    int value, prior; // Variables to store value and priority for enqueue
    do
    {
        // Display menu options
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choose); // Read the user's choice
        switch (choose)
        {
        case 1:
            printf("Enter the number to enqueue and priority also:\n");
            scanf("%d%d", &value, &prior); // Read the value and priority
            enqueue(value, prior);         // Call the enqueue function
            break;
        case 2:
            printf("Dequeued: %d\n", dequeue()); // Call the dequeue function
            break;
        case 3:
            display(); // Call the display function to print the queue
            break;
        case 4:
            break; // Exit the program
        default:
            printf("Invalid choice:\n"); // Handle invalid menu choices
        }
    } while (choose != 4); // Repeat until the user chooses to exit
    return 0; // End of the program
}
