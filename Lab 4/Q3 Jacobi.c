#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define TOLERANCE 0.001

void jacobiMethod(int n, float a[n][n], float b[n], float x[n]) {
    float newX[n];
    float error;
    int i, j, iter = 0;

    // Initialize newX array to 0
    for (i = 0; i < n; i++) {
        newX[i] = 0.0;
    }

    printf("\nIter\t");
    for (i = 0; i < n; i++) {
        printf("x[%d]\t", i + 1);
    }
    printf("Error\n");

    do {
        error = 0.0;

        // Perform iteration
        for (i = 0; i < n; i++) {
            newX[i] = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    newX[i] -= a[i][j] * x[j];
                }
            }
            newX[i] /= a[i][i];
        }

        // Calculate error and update x values
        for (i = 0; i < n; i++) {
            error = fmax(error, fabs(newX[i] - x[i]));
            x[i] = newX[i];
        }

        // Print current iteration
        printf("%d\t", ++iter);
        for (i = 0; i < n; i++) {
            printf("%.4f\t", x[i]);
        }
        printf("%.4f\n", error);

        // Check for maximum iterations
        if (iter >= MAX_ITERATIONS) {
            printf("\nMaximum iterations reached.\n");
            break;
        }
    } while (error > TOLERANCE);
}

int main() {
    int n, i, j;

    // Input the number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float a[n][n], b[n], x[n];

    // Input the coefficients of the matrix
    printf("Enter the coefficients of the matrix (a[i][j]):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Input the right-hand side vector
    printf("Enter the right-hand side vector (b[i]):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    // Initialize the solution vector
    printf("Enter initial guesses for the solution (x[i]):\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    // Solve using Jacobi Method
    jacobiMethod(n, a, b, x);

    // Display the final solution
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }

    return 0;
}

