#include <stdio.h>

// Define the function to be integrated
float function(float x) {
    return x * x; // Example: f(x) = x^2
}

// Trapezoidal Rule implementation
float trapezoidalRule(float a, float b, int n) {
    float h = (b - a) / n; // Step size
    float sum = 0;
    float x;
    int i;

    // Calculate the sum of f(x) at the boundaries
    sum = function(a) + function(b);

    // Calculate the sum of f(x) for interior points
    for (i = 1; i < n; i++) {
        x = a + i * h;
        sum += 2 * function(x);
    }

    // Apply the trapezoidal rule formula
    return (h / 2) * sum;
}

int main() {
    float a, b; // Limits of integration
    int n;      // Number of intervals
    float result;

    // Input the limits of integration and number of intervals
    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);

    // Calculate the integral using the trapezoidal rule
    result = trapezoidalRule(a, b, n);

    // Output the result
    printf("\nThe approximate value of the integral is: %f\n", result);

    return 0;
}

