#include <stdio.h>
#include <malloc.h>

// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data;               // Data stored in the node
    struct Node *prev;      // Pointer to the previous node
    struct Node *next;      // Pointer to the next node
} node;

// Global pointers to the start and end of the list
node* start = NULL;
node* last = NULL;

// Function to insert a node at the beginning of the list
void Insert_At_Beginning(int num) {
    node* ptr = (node*)malloc(sizeof(node)); // Allocate memory for the new node
    ptr->data = num;                         // Set the data of the new node

    if (start == NULL) {                     // If the list is empty
        ptr->prev = ptr->next = NULL;        // Set prev and next pointers to NULL
        last = start = ptr;                  // Update start and last to point to the new node
        printf("Number inserted: %d\n", num);
    } else {                                 // If the list is not empty
        ptr->prev = NULL;                    // New node's prev points to NULL
        ptr->next = start;                   // New node's next points to the current start
        start->prev = ptr;                   // Current start's prev points to the new node
        start = ptr;                         // Update start to point to the new node
        printf("Number inserted: %d\n", num);
    }
}

// Function to insert a node at the end of the list
void Insert_At_Last(int num) {
    node* ptr = (node*)malloc(sizeof(node)); // Allocate memory for the new node
    ptr->data = num;                         // Set the data of the new node

    if (last == NULL) {                      // If the list is empty
        ptr->prev = ptr->next = NULL;        // Set prev and next pointers to NULL
        start = last = ptr;                  // Update start and last to point to the new node
        printf("Number inserted: %d\n", num);
    } else {                                 // If the list is not empty
        ptr->next = NULL;                    // New node's next points to NULL
        ptr->prev = last;                    // New node's prev points to the current last
        last->next = ptr;                    // Current last's next points to the new node
        last = ptr;                          // Update last to point to the new node
        printf("Number inserted: %d\n", num);
    }
}

// Function to delete a node from the beginning of the list
void Delete_At_Beginning() {
    node *ptr;
    if (start == NULL) {                     // If the list is empty
        printf("The List is Empty\n");
        return;
    } else if (start->next == NULL) {       // If there is only one node in the list
        ptr = start;
        start = last = NULL;                // Set start and last to NULL
    } else {                                // If there are multiple nodes
        ptr = start;
        start = start->next;                // Move start to the next node
        start->prev = NULL;                // Set the new start's prev to NULL
    }
    free(ptr);                              // Free the memory of the deleted node
}

// Function to delete a node at a specific position in the list
void Delete_At_X(int loc) {
    if (start == NULL) {                    // If the list is empty
        printf("The List is Empty\n");
        return;
    }

    node *temp = start;
    if (loc == 0) {                         // If deleting the first node
        start = start->next;                // Move start to the next node
        if (start != NULL)
            start->prev = NULL;             // Set the new start's prev to NULL
        else
            last = NULL;                    // If the list becomes empty, set last to NULL
        free(temp);                         // Free the memory of the deleted node
        printf("Node at position %d deleted\n", loc);
        return;
    }

    // Traverse to the node at the specified position
    for (int i = 0; i < loc; i++) {
        if (temp == NULL) {                 // If the position is invalid
            printf("Invalid Location\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {                     // If the position is invalid
        printf("Invalid Location\n");
        return;
    }

    // Adjust the pointers of the neighboring nodes
    if (temp->prev != NULL)
        temp->prev->next = temp->next;     // Update the previous node's next pointer
    if (temp->next != NULL)
        temp->next->prev = temp->prev;     // Update the next node's prev pointer
    if (temp == last)                      // If deleting the last node
        last = temp->prev;                 // Update last to point to the previous node

    free(temp);                            // Free the memory of the deleted node
    printf("Node at position %d deleted\n", loc);
}

// Function to insert a node at a specific position in the list
void Insert_At_X(int value, int loc) {
    node* newnode = malloc(sizeof(node));  // Allocate memory for the new node
    newnode->data = value;                 // Set the data of the new node

    if (loc == 0) {                        // If inserting at the beginning
        newnode->next = start;             // New node's next points to the current start
        start = newnode;                   // Update start to point to the new node
        printf("Number inserted: %d\n", value);
        return;
    }

    node *temp = start;
    // Traverse to the node just before the specified position
    for (int k = 1; k < loc; k++) {
        if (temp == NULL) {                // If the position is invalid
            printf("Invalid Location\n");
            free(newnode);                 // Free the allocated memory
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {                    // If the position is invalid
        printf("Invalid location\n");
        free(newnode);                     // Free the allocated memory
        return;
    }

    // Insert the new node at the specified position
    newnode->next = temp->next;           // New node's next points to the next node
    temp->next = newnode;                 // Previous node's next points to the new node
    printf("Number inserted: %d\n", value);
}

// Function to traverse and display the list
void Traverse(node *head) {
    node *temp = start;                    // Start from the beginning of the list
    while (temp != NULL) {                 // Traverse until the end of the list
        printf("%d\t", temp->data);       // Print the data of the current node
        temp = temp->next;                // Move to the next node
    }
    printf("\n");
}

// Main function to interact with the user
int main() {
    int choice, value, position;
    do {
        // Display the menu
        printf("1. Insert At Beginning\n2. Insert At Last\n3. Insert At specific position\n4. Delete At beginning\n5. Delete At specific position\n6. Display List\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to add to List: ");
                scanf("%d", &value);
                Insert_At_Beginning(value);
                break;
            case 2:
                printf("Enter the number to add to List: ");
                scanf("%d", &value);
                Insert_At_Last(value);
                break;
            case 3:
                printf("Enter the number to add to List with specific position: ");
                scanf("%d%d", &value, &position);
                Insert_At_X(value, position);
                break;
            case 4:
                Delete_At_Beginning();
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                Delete_At_X(position);
                break;
            case 6:
                Traverse(start);
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 7);

    return 0;
}