#include <stdio.h>

// Recursive function to perform linear search
int linearSearchRecursive(int arr[], int target, int index, int size) {
    // Base case: If index exceeds array size, return -1 (element not found)
    if (index >= size) {
        printf("Element not present in array\n");
        return -1;
    }
    
    // Print the current element being checked
    printf("Checking element at index %d, value = %d\n", index, arr[index]);
    
    // If the current element matches the target, return the index
    if (arr[index] == target) {
        printf("Element found at index %d\n", index);
        return index;
    }
    
    // Recursive call to search in the remaining array
    return linearSearchRecursive(arr, target, index + 1, size);
}

// Main function
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element you want to search: ");
    scanf("%d", &target);

    printf("Searching for %d\n", target);

    int result = linearSearchRecursive(arr, target, 0, size);
    
    return 0;
}
