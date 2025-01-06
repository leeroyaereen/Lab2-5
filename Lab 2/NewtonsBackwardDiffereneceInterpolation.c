#include <stdio.h>

void getData(float x[], float y[][100], int n);
void calculateDifferenceTable(float y[][100], int n);
float newtonBackwardInterpolation(float x[], float y[][100], int n, float xValue);
int factorial(int num);

void main() {
    int n;
    float x[100], y[100][100]; 
    float xValue, result;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    getData(x, y, n);

    printf("Enter the value of x to approximate: ");
    scanf("%f", &xValue);

    result = newtonBackwardInterpolation(x, y, n, xValue);

    printf("\nThe approximated functional value at x = %f is: %f\n", xValue, result);
}

void getData(float x[], float y[][100], int n) {
    int i;
    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);  
    }
}

void calculateDifferenceTable(float y[][100], int n) {
    int i, j;
    for (j = 1; j < n; j++) {  
        for (i = n - 1; i >= j; i--) { 
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }
}

int factorial(int num) {
    int i, fact = 1;
    for (i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

float newtonBackwardInterpolation(float x[], float y[][100], int n, float xValue) {
    float result = y[n - 1][0];  
    float h = x[1] - x[0];  
    float u = (xValue - x[n - 1]) / h;  
    float term = 1;  
    int i, j;

    calculateDifferenceTable(y, n);

    for (i = 1; i < n; i++) {
        term *= (u + (i - 1));  
        result += (term * y[n - 1][i]) / factorial(i); 
    }

    return result;
}

