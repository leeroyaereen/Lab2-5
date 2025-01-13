#include <stdio.h>
#include <math.h>

void gaussElimination(int n, float matrix[n][n+1], float solution[n]) {
    int i, j, k;
    float ratio;

    // Forward Elimination
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (matrix[i][i] == 0) {
                printf("Mathematical Error: Division by zero.\n");
                return;
            }
            ratio = matrix[j][i] / matrix[i][i];
            for (k = 0; k < n + 1; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    // Back Substitution
    for (i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
}

int main() {
    int n, i, j;

    // Input number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Declare augmented matrix and solution array
    float matrix[n][n + 1], solution[n];

    // Input augmented matrix
    printf("Enter the augmented matrix row by row (each row with %d elements):\n", n + 1);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Perform Gauss Elimination
    gaussElimination(n, matrix, solution);

    // Print the solution
    printf("\nSolution of the system:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, solution[i]);
    }

    return 0;
}

