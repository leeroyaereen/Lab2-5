#include <stdio.h>

// Define the function to be integrated
float function(float x) {
    return x * x; // Example: f(x) = x^2
}

// Composite Trapezoidal Rule implementation
float compositeTrapezoidal(float a, float b, int n) {
    float h = (b - a) / n; // Step size
    float sum = 0;
    float x;
    int i;

    // Calculate the sum of f(x) at the boundaries
    sum = function(a) + function(b);

    // Calculate the sum of f(x) at interior points
    for (i = 1; i < n; i++) {
        x = a + i * h;
        sum += 2 * function(x);
    }

    // Apply the composite trapezoidal rule formula
    return (h / 2) * sum;
}

int main() {
    float a, b; // Limits of integration
    int n;      // Number of subintervals
    float result;

    // Input the limits of integration and number of subintervals
    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Calculate the integral using the composite trapezoidal rule
    result = compositeTrapezoidal(a, b, n);

    // Output the result
    printf("\nThe approximate value of the integral is: %f\n", result);

    return 0;
}

