#include <stdio.h>

// Function to merge two sorted halves of the array
void sort(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0; // i tracks the left half, j tracks the right half
    int num = high - low + 1;        // Total number of elements in the current range
    int temp[num];                   // Temporary array to store merged elements

    // Merge the two halves into the temp array
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            temp[k++] = A[i++]; // Copy smaller element from left half
        }
        else
        {
            temp[k++] = A[j++]; // Copy smaller element from right half
        }
    }

    // Copy remaining elements from the left half, if any
    while (i <= mid)
    {
        temp[k++] = A[i++];
    }

    // Copy remaining elements from the right half, if any
    while (j <= high)
    {
        temp[k++] = A[j++];
    }

    // Copy the merged elements back to the original array
    for (int in = 0; in < num; in++)
    {
        A[low + in] = temp[in];
    }
}

// Recursive function to divide the array and sort its parts
void Merge(int Num[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2; // Find the middle point

        // Recursively divide and sort the left half
        Merge(Num, low, mid);

        // Recursively divide and sort the right half
        Merge(Num, mid + 1, high);

        // Merge the sorted halves
        sort(Num, low, mid, high);
    }
}

int main()
{
    // Input array
    int numbers[] = {1, 5, 3, 2, 6, 9, 8, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]); // Calculate the size of the array

    // Print the array before sorting
    printf("Array before sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", numbers[i]);
    }

    // Perform merge sort on the array
    Merge(numbers, 0, size - 1);

    // Print the array after sorting
    printf("\nArray after sorting:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", numbers[i]);
    }

    return 0;
}
