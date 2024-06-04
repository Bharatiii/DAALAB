//heapsort_lab.06

#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array at a specific index
void heapify(int arr[], int n, int index, int minHeap) {
    int largest = index; // Assume the current index is the largest/smallest

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (minHeap) {
        if (leftChild < n && arr[leftChild] < arr[largest])
            largest = leftChild;
        if (rightChild < n && arr[rightChild] < arr[largest])
            largest = rightChild;
    } else {
        if (leftChild < n && arr[leftChild] > arr[largest])
            largest = leftChild;
        if (rightChild < n && arr[rightChild] > arr[largest])
            largest = rightChild;
    }

    if (largest != index) {
        swap(&arr[index], &arr[largest]);
        heapify(arr, n, largest, minHeap);
    }
}

// Function to build a max/min heap from an array
void buildHeap(int arr[], int n, int minHeap) {
    int startIdx = (n / 2) - 1; // Start from the last non-leaf node

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i, minHeap);
    }
}

// Function to print the elements of the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array separated by commas: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minHeap = 1; // Start with a min-heap at level 0
    buildHeap(arr, n, minHeap);

    printf("Output: ");
    printArray(arr, n);

    return 0;
}