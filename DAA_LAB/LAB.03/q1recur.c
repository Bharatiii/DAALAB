/*Q1:Write a function recursiveMin(a, n) that recursively computes the
minimum value in the input array a and returns it. Initially, n = |a|.
recursiveMin(a, n) : a[0] if n==1
[base case]
min(a[n-1], recursiveMin(a, n-1))
[recursive definition]
Count the depth of recursion for input a of different sizes and record your observations below.
[Size of problem,]        [|a| Observed depth of recursion, drecur]         [Estimated parameter, c1 = drecur/|a|]
100
10000
1000000

Check if the value of estimated parameter c1 is stable or changing according to the input size.
Justify your observation.*/

#include <stdio.h>
#include <stdlib.h>

int mini(int a, int b)
{
    return a < b ? a : b;
}

int minRec(int arr[], int size, int *count)
{
    *count = *count + 1;
    if (size == 1)
        return arr[0];
    return mini(arr[size - 1], minRec(arr, size - 1, count));
}

int main()
{
    int arr[10000], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + rand() % 100 + 1;
    }

    printf("Input: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int recursiveDepth = 0;
    int min = minRec(arr, n, &recursiveDepth);
    printf("\n Minimum element in the array = %d ", min);
    printf("\n Recursive Depth of the recurive tree = % d", recursiveDepth);
}