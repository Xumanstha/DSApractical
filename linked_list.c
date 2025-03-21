#include <stdio.h>
#include <malloc.h>

// Define a structure for a node in the singly linked list
typedef struct Node
{
    int data;          // Data stored in the node
    struct Node *next; // Pointer to the next node
} Node;

// Initialize the head of the list as NULL (empty list)
Node *head = NULL;

// Function to insert a node at the beginning of the list
void InsertAtBeginning(int value)
{
    Node *node = malloc(sizeof(Node)); // Allocate memory for the new node
    node->data = value;                // Set the data of the new node
    if (head == NULL)                  // Check if the list is empty
    {
        node->next = NULL; // If empty, the new node points to NULL
        head = node;       // Make the new node the head
        printf("Number inserted:%d\n", value);
    }
    else
    {
        node->next = head; // Point the new node to the current head
        head = node;       // Update the head to the new node
        printf("Number inserted:%d\n", value);
    }
}

// Function to insert a node at the end of the list
void InsertAtLast(int value)
{
    Node *node = malloc(sizeof(Node)); // Allocate memory for the new node
    node->data = value;                // Set the data of the new node
    node->next = NULL;                 // New node's next pointer is NULL
    if (head == NULL)                  // Check if the list is empty
    {
        head = node; // If empty, the new node becomes the head
        printf("Number inserted:%d\n", value);
    }
    else
    {
        Node *temp = head;         // Temporary pointer to traverse the list
        while (temp->next != NULL) // Traverse until the last node
        {
            temp = temp->next;
        }
        temp->next = node; // Set the last node's next to the new node
        printf("Number inserted:%d\n", value);
    }
}

// Function to insert a node at a specific position
void InsertAtX(int value, int loc)
{
    Node *node = malloc(sizeof(Node)); // Allocate memory for the new node
    node->data = value;                // Set the data of the new node
    int k;
    if (loc == 0) // If inserting at the beginning
    {
        node->next = head; // Point the new node to the current head
        head = node;       // Update the head to the new node
        printf("Number inserted:%d\n", value);
        return;
    }
    Node *temp = head;        // Temporary pointer to traverse the list
    for (k = 1; k < loc; k++) // Traverse to the (loc - 1)th node
    {
        if (temp == NULL) // If location is invalid (out of bounds)
        {
            printf("Invalid Location\n");
            free(node); // Free the allocated memory
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) // Check if location is invalid
    {
        printf("Invalid location\n");
        free(node); // Free the allocated memory
        return;
    }
    node->next = temp->next; // Point the new node to the next node
    temp->next = node;       // Update the (loc - 1)th node to point to the new node
    printf("Number inserted:%d\n", value);
}

// Function to traverse and print the list
void traverse(Node *start)
{
    Node *temp = start;  // Start traversing from the given node
    while (temp != NULL) // Continue until the end of the list
    {
        printf("%d\t", temp->data); // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    printf("\n"); // Print a newline after traversing
}

// Function to delete a node from the beginning of the list
void DeleteAtBeginning()
{
    Node *temp;
    if (head == NULL) // Check if the list is empty
    {
        printf("The list is empty\n");
    }
    else
    {
        temp = head;       // Temporary pointer to the current head
        head = head->next; // Update the head to the next node
        free(temp);        // Free the memory of the deleted node
    }
}

// Main function to demonstrate the singly linked list operations
int main()
{
    int choice, value, position;
    do
    {
        printf("1.Insert At Beginning\n2.Insert At Last\n3.Insert At specific position\n4.Delete At beginning\n5.Display List\n6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to add to List:");
            scanf("%d", &value);
            InsertAtBeginning(value);
            break;
        case 2:
            printf("Enter the number to add to List:");
            scanf("%d", &value);
            InsertAtLast(value);
            break;
        case 3:
            printf("Enter the number to add to List with specific position:");
            scanf("%d%d", &value, &position);
            InsertAtX(value, position);
            break;
        case 4:
            DeleteAtBeginning();
            break;
        case 5:
            traverse(head);
            break;
        case 6:
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
