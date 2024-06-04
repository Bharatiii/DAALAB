/*q4.Write a program to implement Linear search to give the position of
first appearance of the element being searched.
(i) Input:
Enter size of array: 10
Enter elements of the array:
7 9 2 11 19 17 12 5 7 12
Enter element to be searched: 15
Output:
15 not found.
(ii) Input: Read from a text file containing numbers.
Enter element to be searched: 1500
Output:
1500 not found.
*/

#include <stdio.h>

int linearSearchFirst(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the first appearance
        }
    }
    return -1; // Element not found
}

int main() {
    int size1, target1;
    printf("Enter size of array: ");
    scanf("%d", &size1);

    int arr1[size1];
    printf("Enter elements of the array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter element to be searched: ");
    scanf("%d", &target1);

    int position1 = linearSearchFirst(arr1, size1, target1);

    if (position1 != -1) {
        printf("%d found at position %d.\n", target1, position1 + 1);
    } else {
        printf("%d not found.\n", target1);
    }

    //searching from a file
    FILE *file = fopen("q2_file.txt", "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    int size2, target2;
    fscanf(file, "%d", &size2);

    int arr2[size2];
    for (int i = 0; i < size2; i++) {
        fscanf(file, "%d", &arr2[i]);
    }

    printf("\n");
    printf("Now, Searching from file............. \n");

    printf("Enter element to be searched: ");
    scanf("%d", &target2);

    int position2 = linearSearchFirst(arr2, size2, target2);

    if (position2 != -1) {
        printf("%d found at position %d.\n", target2, position2 + 1);
    } else {
        printf("%d not found in the file.\n", target2);
    }

    fclose(file);
    return 0;
}
