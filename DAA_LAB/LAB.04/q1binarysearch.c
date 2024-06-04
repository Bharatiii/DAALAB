/*q1.Write a program in C to implement Binary search to give the position of
first appearance of the element being searched.
(i) Input:
Enter size of array: 10
Enter elements of the array:
7 9 2 11 19 17 12 5 7 12
Enter element to be searched: 12
Output:
12 found at position 7.
*/

#include <stdio.h>

int binarySearchFirst(int arr[], int size, int target) {
    int left = 0, right = size - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Move left to find the first appearance
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int size1, target1;
    printf("Enter size of array: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter elements of the array:\n");
    //read elements of array 
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    //input elements to be searched
    printf("Enter element to be searched: ");
    scanf("%d", &target1);

    int position1 = binarySearchFirst(arr1, size1, target1);

    if (position1 != -1) {
        printf("%d found at position %d.\n", target1, position1 + 1);
    } else {
        printf("%d not found in the array.\n", target1);
    }



    //(PART.02)
    //searching from a file
    FILE *file = fopen("q1_file.txt", "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    int size2, target2;
    fscanf(file, "%d", &size2);

    int arr2[size2];
    //read elements of array from the file
    for (int i = 0; i < size2; i++) {
        fscanf(file, "%d", &arr2[i]);
    }

    printf("\n");
    printf("Now, Searching from file............. \n");

    //input elements to be searched from the file
    printf("Enter element to be searched: ");
    scanf("%d", &target2);

    int position2 = binarySearchFirst(arr2, size2, target2);

    if (position2 != -1) {
        printf("%d found at position %d.\n", target2, position2 + 1);
    } else {
        printf("%d not found in the file.\n", target2);
    }
    //close the file
    fclose(file);

    return 0;
}