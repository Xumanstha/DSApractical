#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b)
{
  int temp = *a; // Store the value of *a temporarily
  *a = *b;       // Assign the value of *b to *a
  *b = temp;     // Assign the stored value in temp to *b
}

int main()
{
  // Initialize an array to be sorted
  int num[] = {2, 0, 3, 6, 4, 1, 5, 8};
  
  // Calculate the size of the array
  int n = sizeof(num) / sizeof(num[0]);

  // Print the array before sorting
  printf("Before sort:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", num[i]);
  }
  printf("\n");

  // Selection Sort Algorithm
  for (int i = 0; i < n; i++) 
  {
    int minindex = i; // Assume the current index has the smallest element

    // Find the index of the smallest element in the unsorted portion of the array
    for (int j = i + 1; j < n; j++)
    {
      if (num[minindex] > num[j]) // Compare current smallest with the element at index j
      {
        minindex = j; // Update the index of the smallest element
      }
    }

    // Swap the smallest element found with the first element of the unsorted portion
    swap(num + i, num + minindex);
  }

  // Print the array after sorting
  printf("After sort:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", num[i]);
  }
  printf("\n");

  return 0;
}
