#include <stdio.h>
#include <math.h>

void gaussJordan(int n, float matrix[n][n+1]) {
    int i, j, k;
    float ratio;

    // Convert to reduced row echelon form
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1
        if (matrix[i][i] == 0) {
            printf("Mathematical Error: Division by zero.\n");
            return;
        }

        for (j = 0; j < n + 1; j++) {
            matrix[i][j] /= matrix[i][i];
        }

        // Make the other elements in the column 0
        for (k = 0; k < n; k++) {
            if (k != i) {
                ratio = matrix[k][i];
                for (j = 0; j < n + 1; j++) {
                    matrix[k][j] -= ratio * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int n, i, j;

    // Input number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Declare augmented matrix
    float matrix[n][n + 1];

    // Input augmented matrix
    printf("Enter the augmented matrix row by row (each row with %d elements):\n", n + 1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Perform Gauss-Jordan elimination
    gaussJordan(n, matrix);

    // Print the solution
    printf("\nSolution of the system:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, matrix[i][n]);
    }

    return 0;
}

