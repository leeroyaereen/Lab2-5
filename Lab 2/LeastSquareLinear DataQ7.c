#include <stdio.h>

// Function prototypes
void leastSquareApproximation(int n, float x[], float y[], float *a, float *b);

int main() {
    int i, n;
    float x[100], y[100], a = 0, b = 0;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Compute least square approximation
    leastSquareApproximation(n, x, y, &a, &b);

    // Print the result
    printf("\nThe equation of the best-fit line is: y = %.2f + %.2fx\n", a, b);

    return 0;
}

void leastSquareApproximation(int n, float x[], float y[], float *a, float *b) {
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    int i;

    // Calculate the sums
    for (i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate coefficients
    *b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    *a = (sumY - (*b) * sumX) / n;
}

