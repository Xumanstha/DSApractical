#include <stdio.h>

void linearSearch(int arr[], int size, int target) {
    int found = 0; // Flag to indicate if the element is found

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d.\n", target, i);
            found = 1; // Set the flag
            break; // Exit the loop as we found the element
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    linearSearch(arr, size, target);

    return 0;
}
