#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b)
{
    int temp = *a; // Store the value of *a temporarily
    *a = *b;       // Assign the value of *b to *a
    *b = temp;     // Assign the stored value in temp to *b
}

// Function to perform Bubble Sort on an array
void sort(int num[], int n)
{
    // Outer loop to control the number of passes
    for (int i = 0; i < n; i++)
    {
        // Inner loop to compare adjacent elements in the array
        for (int j = 0; j < n - 1 - i; j++) // n - 1 - i to exclude the sorted elements
        {
            if (num[j] > num[j + 1]) // Check if adjacent elements are out of order
            {
                // Swap the elements if they are in the wrong order
                swap(num + j, num + (j + 1));
            }
        }
    }
}

int main()
{
    
    // Initialize the array to be sorted
    int num[] = {2, 0, 3, 6, 4, 1, 5, 8};

    // Calculate the size of the array
    int n = sizeof(num) / sizeof(num[0]);
    // Printing the array before sorting
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", num[i]);
    }
    printf("\n");
    // Sort the array using Bubble Sort
    sort(num, n);

    // Print the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", num[i]);
    }

    return 0;
}
