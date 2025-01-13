#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define TOLERANCE 0.001

void powerMethod(int n, float matrix[n][n], float eigenVector[n]) {
    float tempVector[n], prevEigenValue = 0, eigenValue = 0;
    int i, j, iter = 0;

    // Initialize eigenvector with 1
    for (i = 0; i < n; i++) {
        eigenVector[i] = 1.0;
    }

    printf("\nIter\tEigenvalue\tError\n");

    do {
        // Multiply matrix by the current eigenvector
        for (i = 0; i < n; i++) {
            tempVector[i] = 0.0;
            for (j = 0; j < n; j++) {
                tempVector[i] += matrix[i][j] * eigenVector[j];
            }
        }

        // Find the largest value in the resulting vector (approximate eigenvalue)
        eigenValue = fabs(tempVector[0]);
        for (i = 1; i < n; i++) {
            if (fabs(tempVector[i]) > eigenValue) {
                eigenValue = fabs(tempVector[i]);
            }
        }

        // Normalize the resulting vector
        for (i = 0; i < n; i++) {
            eigenVector[i] = tempVector[i] / eigenValue;
        }

        // Calculate error
        float error = fabs(eigenValue - prevEigenValue);
        printf("%d\t%.4f\t\t%.4f\n", ++iter, eigenValue, error);

        // Check for convergence
        if (error < TOLERANCE) {
            break;
        }

        prevEigenValue = eigenValue;

        // Stop if iterations exceed the limit
        if (iter >= MAX_ITERATIONS) {
            printf("Maximum iterations reached. The method may not have converged.\n");
            break;
        }
    } while (1);

    printf("\nDominant Eigenvalue: %.4f\n", eigenValue);
    printf("Corresponding Eigenvector: ");
    for (i = 0; i < n; i++) {
        printf("%.4f ", eigenVector[i]);
    }
    printf("\n");
}

int main() {
    int n, i, j;

    // Input the size of the matrix
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    float matrix[n][n], eigenVector[n];

    // Input the matrix
    printf("Enter the elements of the matrix (row by row):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Solve using Power Method
    powerMethod(n, matrix, eigenVector);

    return 0;
}

