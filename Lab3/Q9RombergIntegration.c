#include <stdio.h>
#include <math.h>

// Define the function to integrate
float function(float x) {
    return 1 / (1 + x * x); // Example: f(x) = 1 / (1 + x^2)
}

// Trapezoidal rule
float trapezoidal(float a, float b, int n) {
    float h = (b - a) / n;
    float sum = function(a) + function(b);
    int i;
    
    for (i = 1; i < n; i++) {
        sum += 2 * function(a + i * h);
    }
    
    return (h / 2) * sum;
}

// Romberg integration
float rombergIntegration(float a, float b, int maxOrder) {
    float R[maxOrder][maxOrder];
    int i, j;

    // First column of Romberg table (Trapezoidal rule)
    for (i = 0; i < maxOrder; i++) {
        R[i][0] = trapezoidal(a, b, pow(2, i));
    }

    // Fill the rest of the Romberg table
    for (j = 1; j < maxOrder; j++) {
        for (i = j; i < maxOrder; i++) {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    // Display the Romberg table
    printf("\nRomberg Table:\n");
    for (i = 0; i < maxOrder; i++) {
        for (j = 0; j <= i; j++) {
            printf("%f\t", R[i][j]);
        }
        printf("\n");
    }

    // Return the most accurate estimate
    return R[maxOrder - 1][maxOrder - 1];
}

int main() {
    float a, b; // Limits of integration
    int maxOrder; // Maximum order of Romberg integration
    float result;

    // Input limits of integration
    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);

    // Input maximum order of Romberg integration
    printf("Enter the maximum order of Romberg integration: ");
    scanf("%d", &maxOrder);

    // Perform Romberg integration
    result = rombergIntegration(a, b, maxOrder);

    // Display the result
    printf("\nThe approximate value of the integral is: %f\n", result);

    return 0;
}

