#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        // Print the current element being checked
        printf("Checking element at index %d, value = %d\n", i, arr[i]);
        // If target is found, return the index
        if (arr[i] == target)
            return i;
    }
    // If target is not found, return -1
    return -1;
}

// Main function
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element you want to search: ");
    scanf("%d", &target);

    printf("Searching for %d\n", target);

    int result = linearSearch(arr, size, target);
    if (result == -1)
        printf("Element not present in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
