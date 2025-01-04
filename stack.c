#include <stdio.h>
#define Max 5 // Define the maximum size of the stack

int peek = -1;  // The index of the top element in the stack, initialized to -1 (empty stack)
int Stack[Max]; // Array to store stack elements

// Function to check if the stack is full
int isFull()
{
    return peek == Max - 1; // Returns true if the stack is at maximum capacity
}

// Function to check if the stack is empty
int isEmpty()
{
    return peek == -1; // Returns true if no elements are in the stack
}

// Function to push an element onto the stack
void push(int value)
{
    if (isFull())
    {
        printf("Stack full\n"); // Stack overflow error
    }
    else
    {
        Stack[peek + 1] = value; // Place the value at the next position
        peek++;                  // Increment the top index
        printf("%d is pushed into stack\n", value);
    }
}

// Function to pop the top element from the stack
int pop()
{
    if (isEmpty())
    {
        printf("Stack Empty\n"); // Stack underflow error
        return -1;               // Return -1 to indicate failure
    }
    else
    {
        int value = Stack[peek--]; // Retrieve and decrement the top index
        return value;
    }
}

// Function to retrieve the top element without removing it
int Peek()
{
    if (isEmpty())
    {
        printf("The stack is empty\n");
        return -1; // Return -1 to indicate an empty stack
    }
    else
    {
        return Stack[peek]; // Return the top element
    }
}

// Main function with a menu-driven interface
int main()
{
    int choice, value; // Variables to store user input
    do
    {
        // Display menu options
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Push operation
            printf("Enter the number to push:\n");
            scanf("%d", &value);
            push(value);
            break;
        case 2: // Pop operation
            printf("Popped: %d\n", pop());
            break;
        case 3: // Peek operation
            printf("The peek value is: %d\n", Peek());
            break;
        case 4: // Exit the program
            break;
        default: // Handle invalid menu options
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4); // Repeat until the user chooses to exit

    return 0;
}
