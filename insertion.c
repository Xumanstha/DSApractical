#include <stdio.h>

int main()
{
    int key;                                   // Variable to store the current element to be inserted
    int num[] = {9, 7, 5, 8, 10, 11, 1, 4, 2}; // Array to be sorted

    // Calculate the size of the array
    int size = sizeof(num) / sizeof(num[0]);

    // Print the array before sorting
    printf("Before sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", num[i]);
    }
    printf("\n");

    // Insertion Sort Algorithm
    for (int i = 1; i < size; i++) // Start from the second element
    {
        key = num[i];  // Store the current element
        int j = i - 1; // Initialize `j` to the index before `i`

        // Shift elements of the sorted part that are greater than `key` to the right
        while (key < num[j] && j >= 0)
        {
            num[j + 1] = num[j]; // Move the element one position to the right
            j--;                 // Move to the previous element
        }

        // Place `key` in its correct position
        num[j + 1] = key;
    }

    // Print the array after sorting
    printf("After sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", num[i]);
    }

    return 0;
}
