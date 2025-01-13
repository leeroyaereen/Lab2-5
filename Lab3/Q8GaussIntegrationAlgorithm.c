#include <stdio.h>
#include <math.h>

// Define the function to be integrated
float function(float x) {
    return x * x; // Example: f(x) = x^2
}

// Gauss-Legendre 2-point quadrature
float gaussLegendreTwoPoint(float a, float b) {
    // Weights and points for 2-point rule
    float weights[2] = {1.0, 1.0};
    float points[2] = {-0.5773502692, 0.5773502692}; // ±1/v3
    
    float sum = 0;
    float midpoint = (a + b) / 2.0;
    float halfLength = (b - a) / 2.0;
    int i;

    // Compute integration
    for (i = 0; i < 2; i++) {
        float x = midpoint + halfLength * points[i];
        sum += weights[i] * function(x);
    }

    return halfLength * sum;
}

// Gauss-Legendre 3-point quadrature
float gaussLegendreThreePoint(float a, float b) {
    // Weights and points for 3-point rule
    float weights[3] = {0.555555556, 0.888888889, 0.555555556};
    float points[3] = {-0.7745966692, 0.0, 0.7745966692}; // ±v3/5, 0
    
    float sum = 0;
    float midpoint = (a + b) / 2.0;
    float halfLength = (b - a) / 2.0;
    int i;

    // Compute integration
    for (i = 0; i < 3; i++) {
        float x = midpoint + halfLength * points[i];
        sum += weights[i] * function(x);
    }

    return halfLength * sum;
}

int main() {
    float a, b; // Integration limits
    int choice;
    float result;

    // Input the limits of integration
    printf("Enter the lower limit of integration (a): ");
    scanf("%f", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%f", &b);

    // Choose the Gauss quadrature rule
    printf("\nChoose the Gauss Quadrature Rule:\n");
    printf("1. Gauss-Legendre 2-Point Rule\n");
    printf("2. Gauss-Legendre 3-Point Rule\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Perform integration based on choice
    if (choice == 1) {
        result = gaussLegendreTwoPoint(a, b);
        printf("\nThe approximate value of the integral using 2-point rule is: %f\n", result);
    } else if (choice == 2) {
        result = gaussLegendreThreePoint(a, b);
        printf("\nThe approximate value of the integral using 3-point rule is: %f\n", result);
    } else {
        printf("\nInvalid choice. Please select either 1 or 2.\n");
    }

    return 0;
}

