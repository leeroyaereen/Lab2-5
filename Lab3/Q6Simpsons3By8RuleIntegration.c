#include <stdio.h>

// Define the function to be integrated
float function(float x) {
    return x * x; 
}

float simpsonsThreeEighthsRule(float a, float b, int n) {
    if (n % 3 != 0) {
        printf("Number of subintervals (n) must be a multiple of 3.\n");
        return -1;
    }

    float h = (b - a) / n;
    float sum = function(a) + function(b); 
    float x;
    int i;

    // Compute the sum of function values for intermediate points
    for (i = 1; i < n; i++) {
        x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * function(x); 
        } else {
            sum += 3 * function(x); 
        }
    }

    // Apply Simpson's 3/8 Rule formula
    return (3 * h / 8) * sum;
}

int main() {
    float a, b; 
    int n;      
    float result;

    // Input the limits of integration and number of subintervals
    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    // Calculate the integral using Simpson's 3/8 Rule
    result = simpsonsThreeEighthsRule(a, b, n);

    // Check for errors and display the result
    if (result != -1) {
        printf("\nThe approximate value of the integral is: %f\n", result);
    }

    return 0;
}

