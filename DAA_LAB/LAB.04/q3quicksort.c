/*q3.Write a program to implement quicksort on an array and count the
number of comparisons.
Input:
Enter size of array: 10
Enter elements of the array:
7 9 2 11 19 17 12 5 7 12
Output:
Sorted array is:
2 5 7 7 9 11 12 12 17 19
26 comparisons*/

#include <stdio.h>

int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quicksort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);

        quicksort(arr, low, pi - 1, comparisons);
        quicksort(arr, pi + 1, high, comparisons);
    }
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int comparisons = 0;
    quicksort(arr, 0, size - 1, &comparisons);

    printf("Sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n%d comparisons\n", comparisons);

    return 0;
}