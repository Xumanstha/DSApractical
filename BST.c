#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;               // Data stored in the node
    struct Node* left;      // Pointer to the left child
    struct Node* right;     // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {                     // If the tree is empty, create a new node
        return createNode(value);
    }

    if (value < root->data) {               // If the value is less than the root, insert in the left subtree
        root->left = insert(root->left, value);
    } else if (value > root->data) {        // If the value is greater than the root, insert in the right subtree
        root->right = insert(root->right, value);
    }

    return root;                            // Return the (unchanged) root pointer
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) { // If the root is NULL or the value is found
        return root;
    }

    if (value < root->data) {               // If the value is less than the root, search in the left subtree
        return search(root->left, value);
    } else {                                // If the value is greater than the root, search in the right subtree
        return search(root->right, value);
    }
}

// Function to perform an in-order traversal of the BST (left-root-right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);        // Traverse the left subtree
        printf("%d ", root->data);          // Print the current node's data
        inorderTraversal(root->right);      // Traverse the right subtree
    }
}

// Main function
int main() {
    struct Node* root = NULL;               // Initialize an empty BST
    int choice, value;

    while (1) {
        printf("\n1. Insert a node\n2. Search for a value\n3. Display BST (In-order)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value); // Insert the value into the BST
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct Node* result = search(root, value); // Search for the value
                if (result != NULL) {
                    printf("Value %d found in the BST.\n", value);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;
            case 3:
                printf("In-order traversal of the BST: ");
                inorderTraversal(root);     // Display the BST in in-order
                printf("\n");
                break;
            case 4:
                exit(0);                   // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}