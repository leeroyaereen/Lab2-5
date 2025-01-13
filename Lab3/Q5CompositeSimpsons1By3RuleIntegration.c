#include <stdio.h>

// Define the function to be integrated
float function(float x) {
    return x * x; // Example: f(x) = x^2
}

// Composite Simpson's 1/3 Rule implementation
float compositeSimpsonsRule(float a, float b, int n) {
    // Ensure the number of subintervals is even
    if (n % 2 != 0) {
        printf("Number of subintervals (n) must be even.\n");
        return -1;
    }

    float h = (b - a) / n; // Step size
    float sum = function(a) + function(b); // Initialize sum with f(a) and f(b)
    float x;
    int i;

    // Compute the sum of function values for odd and even indices
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * function(x); // Multiply even terms by 2
        } else {
            sum += 4 * function(x); // Multiply odd terms by 4
        }
    }

    // Apply Simpson's 1/3 Rule formula
    return (h / 3) * sum;
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

    // Calculate the integral using Composite Simpson's 1/3 Rule
    result = compositeSimpsonsRule(a, b, n);

    // Check for errors and display the result
    if (result != -1) {
        printf("\nThe approximate value of the integral is: %f\n", result);
    }

    return 0;
}

