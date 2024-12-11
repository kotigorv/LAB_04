#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

// Function to count the maximum number of consecutive zeros
int maxConsecutiveZeros(int arr[], int n) {
    int maxCount = 0, currentCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }
        else {
            currentCount = 0;
        }
    }

    return maxCount;
}

// Function to fill a chessboard pattern matrix
void fillChessboardMatrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 == 0) {
                matrix[i][j] = 1;
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Task 1
    int n;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxZeros = maxConsecutiveZeros(arr, n);
    printf("Maximum number of consecutive zeros: %d\n", maxZeros);

    free(arr); // Free allocated memory

    // Task 2
    int matrix[10][10];
    fillChessboardMatrix(matrix);

    printf("\nChessboard matrix:\n");
    printMatrix(matrix);

    return 0;
}