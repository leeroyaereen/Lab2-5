#include <stdio.h>

void getData(float x[], float y[], int n);
void calculateCubicSpline(float x[], float y[], float a[], float b[], float c[], float d[], int n);
float cubicSplineInterpolation(float x[], float a[], float b[], float c[], float d[], int n, float xValue);

void main() {
    int n; 
    float x[100], y[100]; 
    float a[100], b[100], c[100], d[100];  
    float xValue, result;
   
    printf("Enter the number of data points: ");
    scanf("%d", &n);
   
    getData(x, y, n);
   
    printf("Enter the value of x to approximate: ");
    scanf("%f", &xValue);
   
    calculateCubicSpline(x, y, a, b, c, d, n);
   
    result = cubicSplineInterpolation(x, a, b, c, d, n, xValue);

    printf("\nThe approximated functional value at x = %f is: %f\n", xValue, result);
}

void getData(float x[], float y[], int n) {
    int i;
    printf("Enter the data points (x, y):\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }
}
void calculateCubicSpline(float x[], float y[], float a[], float b[], float c[], float d[], int n) {
    float h[100], alpha[100], l[100], mu[100], z[100];
    int i;

    for (i = 0; i < n - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }
    for (i = 1; i < n - 1; i++) {
        alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;
    for (i = 1; i < n - 1; i++) {
        l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }
    l[n - 1] = 1;
    z[n - 1] = 0;
    c[n - 1] = 0;

    for (i = n - 2; i >= 0; i--) {
        c[i] = z[i] - mu[i] * c[i + 1];
        b[i] = (y[i + 1] - y[i]) / h[i] - h[i] * (c[i + 1] + 2 * c[i]) / 3;
        d[i] = (c[i + 1] - c[i]) / (3 * h[i]);
        a[i] = y[i];
    }
}

float cubicSplineInterpolation(float x[], float a[], float b[], float c[], float d[], int n, float xValue) {
    int i;
    float result;

    for (i = 0; i < n - 1; i++) {
        if (xValue >= x[i] && xValue <= x[i + 1]) {
            break;
        }
    }

    float dx = xValue - x[i];
    result = a[i] + b[i] * dx + c[i] * dx * dx + d[i] * dx * dx * dx;

    return result;
}

