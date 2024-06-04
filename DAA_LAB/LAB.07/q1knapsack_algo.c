//knapsack_algorithm
/*Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having members value and weight. Apply heap sort technique
to sort the items in non-increasing order, according to their value/weight.
Input:
Enter the number of items: 3
Enter the Value of item : 27 , 14, 26
Enter the weight of item : 16, 12, 13
Enter the capacity of knapsack:18
Output:
Item No Value Weight Amount to be taken
1 26.000000 13.000000 1.000000
2 27.000000 16.000000 0.312500
3 14.000000 12.000000 0.000000
Maximum profit: 34.437500*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent items
struct ITEM {
    int value;
    int weight;
    double ratio; // Value-to-weight ratio
};

// Function to swap two items
void swap(struct ITEM* a, struct ITEM* b) {
    struct ITEM temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify operation on a max heap
void maxHeapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].ratio > arr[largest].ratio)
        largest = left;

    if (right < n && arr[right].ratio > arr[largest].ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Function to perform heap sort on items based on value-to-weight ratio
void heapSort(struct ITEM arr[], int n) {
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract items one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Function to find the maximum profit using Fractional Knapsack
double fractionalKnapsack(struct ITEM arr[], int n, int capacity) {
    heapSort(arr, n); // Sort items in non-increasing order of value-to-weight ratio

    double maxProfit = 0.0;
    int currentWeight = 0;

    printf("Item No   Value     Weight   Amount to be taken\n");

    for (int i = 0; i < n; i++) {
        double fraction = 1.0; // Fraction of the item to take by default

        if (currentWeight + arr[i].weight > capacity) {
            fraction = (double)(capacity - currentWeight) / arr[i].weight;
        }

        double itemProfit = arr[i].value * fraction;
        currentWeight += arr[i].weight;

        printf("%d.        %d         %d          %.6lf\n", i + 1, arr[i].value, arr[i].weight, fraction);

        maxProfit += itemProfit;

        if (currentWeight >= capacity)
            break;
    }

    return maxProfit;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the Value of item %d: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %.6lf\n", maxProfit);

    return 0;
}