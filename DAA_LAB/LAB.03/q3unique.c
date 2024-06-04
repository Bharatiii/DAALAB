/*To find distinct integers in an array.
Write a function unique(a) that returns an array of unique elements in input array a. Run the
function on inputs of following sizes and count the number of basic operations.
[Size of problem,|a|]   [Observed number of basic operations during execution,nop]    [Estimated parameter,c1 = nop/|a|2]
100
10000
1000000
Check if the value of estimated parameter c1 is stable or changing according to the input size.
Justify your observation.*/

#include <stdio.h>
#include <stdlib.h>

int* unique(int a[], int n, int* resultSize, int* basicOperations) {
    int* uniqueArray = (int*)malloc(n * sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        int isUnique = 1;

        for (int j = 0; j < count; j++) {
            (*basicOperations)++;
            if (a[i] == uniqueArray[j]) {
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            uniqueArray[count] = a[i];
            count++;
        }
    }

    *resultSize = count;
    return uniqueArray;
}

int main() {
    int numInputSizes;
    printf("Enter the number of input sizes: ");
    scanf("%d", &numInputSizes);

    for (int i = 0; i < numInputSizes; i++) {
        int n;
        printf("Enter the size of input array %d: ", i + 1);
        scanf("%d", &n);

        int* a = (int*)malloc(n * sizeof(int));

        printf("Enter %d elements for input array %d:\n", n, i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }

        int basicOps = 0;
        int resultSize = 0;
        int* uniqueElements = unique(a, n, &resultSize, &basicOps);

        printf("Unique elements for input array %d:", i + 1);
        for (int j = 0; j < resultSize; j++) {
            printf(" %d", uniqueElements[j]);
        }
        printf("\n");
        printf("Input size: %d, Basic operations: %d\n", n, basicOps);

        free(a);
        free(uniqueElements);
    }

    return 0;
}