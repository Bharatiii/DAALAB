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

int recursiveMin(int a[], int n, int *recursionDepth) 
{
    (*recursionDepth)++;
    //When the function is called, it increments the value pointed to by recursionDepth. 
    //This is done to keep track of how the recursion goes.
    if (n == 1) 
    //one element in the array. here the function simply returns the value of the single element a[0] as it is the minimum.
    {
        return a[0];
    } 
    //In the recursive case, the function calculates the minimum of the remaining subarray 
    else 
    {
        int minOfRest = recursiveMin(a, n - 1, recursionDepth);
        return (a[n - 1] < minOfRest) ? a[n - 1] : minOfRest; //// it compares the last element of the array a[n - 1] with the minimum value calculated from the subarray.
    }
}

int main() {
    int arr[100];    // Replace with different array sizes
    int n = sizeof(arr) / sizeof(arr[0]); // calculates the number of elements in the array
    int recursionDepth = 0;

    int minVal = recursiveMin(arr, n, &recursionDepth);

    printf("The minimum value in the array is: %d\n", minVal);
    printf("Recursion Depth: %d\n", recursionDepth);

    return 0;
}