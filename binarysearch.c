#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int middle =(left + right) / 2;
        
        // Check if target is present at middle
        if (arr[middle] == target) {
            return middle;
        }
        
        // If target is greater, ignore the left half
        if (arr[middle] < target) {
            left = middle + 1;
        } else {
            // If target is smaller, ignore the right half
            right = middle - 1;
        }
    }
    
    // If target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2,3,8,9,10,23,32,56,78};
    int target = 32;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in array\n");
    }
    
    return 0;
}
