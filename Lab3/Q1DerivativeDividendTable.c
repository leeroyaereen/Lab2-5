#include <stdio.h>

void calculateDividedDifference(float x[], float y[], float table[][100], int n);
float calculateDerivative(float x[], float table[][100], int n, float point);

int main() {
    int n, i, j;
    float x[100], y[100], table[100][100], point, derivative;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the data points
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Input the point to find the derivative
    printf("Enter the point at which to find the derivative: ");
    scanf("%f", &point);

    // Calculate the divided difference table
    calculateDividedDifference(x, y, table, n);

    // Calculate the derivative at the given point
    derivative = calculateDerivative(x, table, n, point);

    // Display the derivative
    printf("\nThe derivative of the function at x = %.4f is: %.4f\n", point, derivative);

    return 0;
}

void calculateDividedDifference(float x[], float y[], float table[][100], int n) {
    int i, j;

    // Initialize the first column of the table with y values
    for (i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

    // Compute the divided differences
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Display the divided difference table (optional)
    printf("\nDivided Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.4f", i, x[i]);
        for (j = 0; j < n - i; j++) {
            printf("\t%.4f", table[i][j]);
        }
        printf("\n");
    }
}

float calculateDerivative(float x[], float table[][100], int n, float point) {
    float derivative = 0;
    float term = 1;
    int i;

    // Compute the derivative using the divided difference table
    for (i = 1; i < n; i++) {
        term *= (point - x[i - 1]); // Compute the product (x - x0)(x - x1)...(x - xk-1)
        derivative += table[0][i] * term;
    }

    return derivative;
}

