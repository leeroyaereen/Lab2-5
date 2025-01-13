#include <stdio.h>
#include <math.h>

// Function prototypes
void leastSquarePolynomial(int n, float x[], float y[], int degree, float coefficients[]);

int main() {
    int n, degree, i;
    float x[100], y[100], coefficients[10];

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    // Input the data points
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Compute the polynomial coefficients
    leastSquarePolynomial(n, x, y, degree, coefficients);

    // Output the result
    printf("\nThe coefficients of the polynomial are:\n");
    for (i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: %.4f\n", i, coefficients[i]);
    }

    printf("\nThe best-fit polynomial is: y = ");
    for (i = 0; i <= degree; i++) {
        printf("%.4fx^%d ", coefficients[i], i);
        if (i < degree) printf("+ ");
    }
    printf("\n");

    return 0;
}

void leastSquarePolynomial(int n, float x[], float y[], int degree, float coefficients[]) {
    float matrix[10][11] = {0}; // Augmented matrix for normal equations
    int i, j, k;

    // Form the normal equations
    for (i = 0; i <= degree; i++) {
        for (j = 0; j <= degree; j++) {
            matrix[i][j] = 0;
            for (k = 0; k < n; k++) {
                matrix[i][j] += pow(x[k], i + j);
            }
        }
        matrix[i][degree + 1] = 0;
        for (k = 0; k < n; k++) {
            matrix[i][degree + 1] += y[k] * pow(x[k], i);
        }
    }

    // Solve the system of equations using Gaussian elimination
    for (i = 0; i <= degree; i++) {
        // Make the diagonal element 1
        float divisor = matrix[i][i];
        for (j = 0; j <= degree + 1; j++) {
            matrix[i][j] /= divisor;
        }

        // Make the elements below the diagonal 0
        for (k = i + 1; k <= degree; k++) {
            float factor = matrix[k][i];
            for (j = 0; j <= degree + 1; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back substitution
    for (i = degree; i >= 0; i--) {
        coefficients[i] = matrix[i][degree + 1];
        for (j = i + 1; j <= degree; j++) {
            coefficients[i] -= matrix[i][j] * coefficients[j];
        }
    }
}

