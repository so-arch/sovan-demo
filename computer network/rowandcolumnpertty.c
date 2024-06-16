#include <stdio.h>

// Function to compute the parity bit for a row or column
int computeParity(int *array, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == 1) {
            count++;
        }
    }
    // Return 1 if count of 1s is odd, else 0 for even parity
    return (count % 2);
}

// Function to display the matrix with parity bits
void displayMatrixWithParity(int matrix[][101], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    int matrix[100][100];
    int parityMatrix[101][101]; // To store the original matrix with parity bits

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input the matrix elements
    printf("Enter the matrix elements (0 or 1):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            parityMatrix[i][j] = matrix[i][j];
        }
    }

    // Compute row parity bits
    for (int i = 0; i < rows; i++) {
        int rowParity = computeParity(matrix[i], cols);
        parityMatrix[i][cols] = rowParity; // Append row parity bit
    }

    // Compute column parity bits
    for (int j = 0; j < cols; j++) {
        int colArray[100];
        for (int i = 0; i < rows; i++) {
            colArray[i] = matrix[i][j];
        }
        int colParity = computeParity(colArray, rows);
        parityMatrix[rows][j] = colParity; // Append column parity bit
    }

    // Compute overall parity bit
    int overallArray[100];
    for (int i = 0; i < rows; i++) {
        overallArray[i] = parityMatrix[i][cols];
    }
    int overallParity = computeParity(overallArray, rows);
    parityMatrix[rows][cols] = overallParity;

    // Display the original matrix
    printf("\nOriginal matrix:\n");
    displayMatrixWithParity(parityMatrix, rows, cols);

    // Display the matrix with parity bits
    printf("\nMatrix with row and column parity bits:\n");
    displayMatrixWithParity(parityMatrix, rows + 1, cols + 1);

    return 0;
}
