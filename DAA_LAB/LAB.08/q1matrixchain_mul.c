//matrixchain_multiplication
/* Aim of the experiment: Write a program to implement the matrix chain multiplication
problem using M-table & S-table to find optimal parenthesization of a matrix-chain product.
Print the number of scalar multiplications required for the given input.
Note# Dimensions of the matrices can be inputted as a sequence and maintained using dynamic
memory allocation.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to print the optimal parenthesization
void pParenthesis(int **S, int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        pParenthesis(S, i, S[i][j]);
        pParenthesis(S, S[i][j] + 1, j);
        printf(")");
    }
}

// Function to find the minimum number of scalar multiplications using recursion
int matrixChainOrder(int p[], int n, int **M, int **S) {
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }
    //p is dimension of matrix and n is no. of matrices
    //M stores the minimum no. of scalar multiplication. 

    printf("Optimal Parenthesization: ");
    pParenthesis(S, 1, n - 1);
    printf("\n");

    return M[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dims[n];
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &dims[i]);
    }

    // Allocate memory for M-table and S-table
    int **M = (int **)malloc((n + 1) * sizeof(int *));
    int **S = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        M[i] = (int *)malloc((n + 1) * sizeof(int));
        S[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    int minMultiplications = matrixChainOrder(dims, n, M, S);
    printf("Minimum scalar multiplications: %d\n", minMultiplications);

    // Free dynamically allocated memory
    for (int i = 0; i <= n; i++) {
        free(M[i]);
        free(S[i]);
    }
    free(M);
    free(S);

    return 0;
}