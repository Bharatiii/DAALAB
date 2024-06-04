//Write a program to find out the second smallest and second largest element stored in an array of n integers. 

#include <stdio.h>

// Function to find the second smallest and second largest elements
void find_second_smallest_and_largest(int arr[], int n) {
    if (n < 2) {
        printf("Array size should be at least 2.\n");
        return;
    }

    int smallest = (arr[0] < arr[1]) ? arr[0] : arr[1];
    int second_smallest = (arr[0] < arr[1]) ? arr[1] : arr[0];
    int largest = (arr[0] > arr[1]) ? arr[0] : arr[1];
    int second_largest = (arr[0] > arr[1]) ? arr[1] : arr[0];

    for (int i = 2; i < n; i++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < second_smallest) {
            second_smallest = arr[i];
        }

        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest) {
            second_largest = arr[i];
        }
    }

    printf("Second smallest element: %d\n", second_smallest);
    printf("Second largest element: %d\n", second_largest);
}

int main() {
    int n;
    printf("Enter the number of integers in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    find_second_smallest_and_largest(arr, n);

    return 0;
}