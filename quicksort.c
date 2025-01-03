#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a; // Temporarily store the value of *a
    *a = *b;       // Assign the value of *b to *a
    *b = temp;     // Assign the temporary value to *b
}

// Partition function to rearrange elements around the pivot
int partition(int num[], int low, int high)
{
    int pivot = num[high]; // Select the last element as the pivot
    int j = low - 1;       // Pointer for elements smaller than the pivot

    for (int k = low; k < high; k++) // Iterate through the array
    {
        if (num[k] <= pivot) // If the current element is <= pivot
        {
            j++;
            swap(&num[j], &num[k]); // Swap elements to place smaller element at the correct position
        }
    }

    swap(&num[j + 1], &num[high]); // Place the pivot in its correct position
    return (j + 1);                // Return the pivot index
}

// Quick Sort function
void quicksort(int numbers[], int low, int high)
{
    if (low < high) // Base condition: If the array has more than one element
    {
        int pivotIndex = partition(numbers, low, high); // Partition the array
        quicksort(numbers, low, pivotIndex - 1);        // Recursively sort elements before the pivot
        quicksort(numbers, pivotIndex + 1, high);       // Recursively sort elements after the pivot
    }
}

// Main function to test the Quick Sort implementation
int main()
{
    int arr[] = {6, 9, 4, 3, 1, 5};          // Array to be sorted
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    printf("Before sorting:\n"); //print the unsorted array
     for (int i = 0; i < size; i++) // Print the sorted array
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, size - 1); // Call the Quick Sort function

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) // Print the sorted array
    {
        printf("%d\t", arr[i]);
    }

    return 0; // End of the program
}
