#include <stdio.h>

// Function prototypes
void getData(float x[], float y[], int n);
float lagrangeInterpolation(float x[], float y[], int n, float xValue);

void main() {
    
    int n;
    float x[100], y[100];  
    float xValue, result;

   
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    
    getData(x, y, n);

    
    printf("Enter the value of x to approximate: ");
    scanf("%f", &xValue);

    
    result = lagrangeInterpolation(x, y, n, xValue);

   
    printf("\nThe approximated functional value at x = %f is: %f\n", xValue, result);
}


void getData(float x[], float y[], int n) {
    printf("Enter the data points (x, y):\n");
    int i ;
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }
}


float lagrangeInterpolation(float x[], float y[], int n, float xValue) {
    float result = 0;  
	int i, j;
    
    for (i = 0; i < n; i++) {
        float term = y[i];
        for ( j = 0; j < n; j++) {
            if (j != i) {
                term *= (xValue - x[j]) / (x[i] - x[j]);  
            }
        }
        result += term; 
    }

    return result;
}

