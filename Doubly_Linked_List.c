#include <stdio.h>
#include <malloc.h>
typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} node;
node* start=NULL;
node* last=NULL;
void Insert_At_Beginning(int num)
{
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=num;
    if(start==NULL)
    {
        ptr->prev=ptr->next=NULL;
        last=start=ptr;
        printf("Number inserted:%d\n", num);
    }
    else{
        ptr->prev=NULL;
        ptr->next=start;
        start->prev=ptr;
        start=ptr;
        printf("Number inserted:%d\n", num);
    }
}
void Insert_At_Last(int num)
{
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=num;
    if(last==NULL)
    {
        ptr->prev=ptr->next=NULL;
        start=last=ptr;
        printf("Number inserted:%d\n", num);
    }
    else{
        ptr->next=NULL;
        ptr->prev=last;
        last->next=ptr;
        last=ptr;
        printf("Number inserted:%d\n", num);
    }
}
void Delete_At_Beginning()
{
    node *ptr;
    if(start==NULL)
    {
        printf("The List is Empty\n");
        return;
    }
    else if(start->next==NULL)
    {
        ptr=start;
        start=last=NULL;
    }
    else{
        ptr=start;
        start=start->next;
        start->prev=NULL;
    }
    free(ptr);
}
void Insert_At_X(int value,int loc)
{
    node* newnode = malloc(sizeof(node)); // Allocate memory for the new node
    newnode->data = value;                // Set the data of the new node
    int k;
    if (loc == 0) // If inserting at the beginning
    {
        newnode->next = start; // Point the new node to the current head
        start = newnode;       // Update the head to the new node
        printf("Number inserted:%d\n", value);
        return;
    }
    node *temp = start;        // Temporary pointer to traverse the list
    for (k = 1; k < loc; k++) // Traverse to the (loc - 1)th node
    {
        if (temp == NULL) // If location is invalid (out of bounds)
        {
            printf("Invalid Location\n");
            free(newnode); // Free the allocated memory
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) // Check if location is invalid
    {
        printf("Invalid location\n");
        free(newnode); // Free the allocated memory
        return;
    }
    newnode->next = temp->next; // Point the new node to the next node
    temp->next = newnode;       // Update the (loc - 1)th node to point to the new node
    printf("Number inserted:%d\n", value);

}
void Traverse(node *head)
{
    node *temp = start;  // Start traversing from the given node
    while (temp != NULL) // Continue until the end of the list
    {
        printf("%d\t", temp->data); // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    printf("\n");

}
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
            Insert_At_Beginning(value);
            break;
        case 2:
            printf("Enter the number to add to List:");
            scanf("%d", &value);
            Insert_At_Last(value);
            break;
        case 3:
            printf("Enter the number to add to List with specific position:");
            scanf("%d%d", &value, &position);
            Insert_At_X(value, position);
            break;
        case 4:
            Delete_At_Beginning();
            break;
        case 5:
            Traverse(start);
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
