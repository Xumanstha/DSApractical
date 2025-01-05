#include <stdio.h>

void binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int found = 0; // Flag to indicate if the element is found

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid index

        if (arr[mid] == target) {
            printf("Element %d found at index %d.\n", target, mid);
            found = 1;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1; // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    binarySearch(arr, size, target);

    return 0;
}
