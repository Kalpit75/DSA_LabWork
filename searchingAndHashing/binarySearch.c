#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Print current state
        printf("Checking element at index %d, value = %d\n", mid, arr[mid]);

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // Target not found
    return -1;
}

// Main function
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    
    printf("Enter the element you want to search: ");
    scanf("%d", &target);
    
    printf("Searching for %d\n", target);
    
    int result = binarySearch(arr, 0, n - 1, target);
    if (result == -1)
        printf("Element not present in array\n");
    else
        printf("Element found at index %d\n", result);
    return 0;
}