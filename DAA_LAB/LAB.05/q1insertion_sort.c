/* Write a program to implement Insertion sort on an array and count the
number of comparisons.
Input:
Enter size of array: 10
Enter elements of the array:
7 9 2 11 19 17 12 5 7 12
Output:
Sorted array is:
2 5 7 7 9 11 12 12 17 19
45 comparisons
*/

#include <stdio.h>

int insertionSort(int arr[], int n) {
    int comparisons = 0; // Initialize the comparison counter

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            comparisons++; // Increment comparison count
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    return comparisons;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comparison_count = insertionSort(arr, n);

    printf("Sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n%d comparisons\n", comparison_count);

    return 0;
}