#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);

int main() {
    int rows = 2, cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1;
        }
    }

    printMatrix(matrix, rows, cols);
    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}