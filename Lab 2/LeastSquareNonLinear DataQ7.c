#include <stdio.h>
#include <math.h>

// Function prototypes
void leastSquareNonLinear(int n, float x[], float y[], float *a, float *b);

int main() {
    int i, n;
    float x[100], y[100], a = 0, b = 0;

    // Input number of data points
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
    leastSquareNonLinear(n, x, y, &a, &b);

    // Print the result
    printf("\nThe equation of the best-fit curve is: y = %.4f * x^%.4f\n", a, b);

    return 0;
}

void leastSquareNonLinear(int n, float x[], float y[], float *a, float *b) {
    float sumLogX = 0, sumLogY = 0, sumLogXLogY = 0, sumLogX2 = 0;
    int i;

    // Transform x and y to their logarithmic values and calculate sums
    for (i = 0; i < n; i++) {
        float logX = log(x[i]);
        float logY = log(y[i]);

        sumLogX += logX;
        sumLogY += logY;
        sumLogXLogY += logX * logY;
        sumLogX2 += logX * logX;
    }

    // Calculate coefficients b and a (in logarithmic form)
    *b = (n * sumLogXLogY - sumLogX * sumLogY) / (n * sumLogX2 - sumLogX * sumLogX);
    float logA = (sumLogY - (*b) * sumLogX) / n;
    *a = exp(logA); // Convert log(a) back to a
}

