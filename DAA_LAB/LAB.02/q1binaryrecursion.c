/*Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. 
Store the binary value in a separate disc file. 

Note# Read the value of ‘n’, source file name and destination file name from command line arguments.
Display the decimal numbers and their equivalent binary numbers from the output file. 
Give the contents of the input disc file “inDec.dat” as 
30  75   2564  …
Contents of the output disc file “outBin.dat” as 
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100 
Terminal Input:
$gcc lab2q1.c -o lab2q1
$./lab2q1 150 inDec.dat outBin.dat

Output: Content of the first ‘n’ decimal and their equivalent binary numbers*/
#include <stdio.h>

void decimalToBinary(FILE *inFile, FILE *outFile, int n) {
    if (n == 0) return;

    int decimalNum;
    fscanf(inFile, "%d", &decimalNum);

    decimalToBinary(inFile, outFile, n - 1);

    int binary[2564];
    int index = 0;

    while (decimalNum > 0) {
        binary[index++] = decimalNum % 2;
        decimalNum /= 2;
    }

    for (int i = index - 1; i >= 0; i--) {
        fprintf(outFile, "%d", binary[i]);
    }

    fprintf(outFile, " ");
}

int main() {
    FILE *inFile, *outFile;
    int n;

    // Open input and output files
    inFile = fopen("input_q1.txt", "r");
    outFile = fopen("output_q1.txt", "w");

    if (inFile == NULL || outFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    printf("Enter the value of 'n': ");
    scanf("%d", &n);

    decimalToBinary(inFile, outFile, n);

    printf("Binary values for first %d decimal numbers have been written to output_q1.txt\n", n);

    // Close files
    fclose(inFile);
    fclose(outFile);

    return 0;
}