#include <stdio.h>

double sqrt_binary_search(double n, double precision) {
    if (n < 0) {
        printf("Negative input not allowed.\n");
        return -1;
    }
    if (n == 0 || n == 1)
        return n;

    double low = 0, high = n;
    if (n < 1) high = 1;  // For inputs between 0 and 1

    double mid;

    while ((high - low) > precision) {
        mid = (low + high) / 2;
        if (mid * mid < n)
            low = mid;
        else
            high = mid;
    }

    return (low + high) / 2;
}

int main() {
    double num, precision;

    printf("Enter a number to find its square root: ");
    scanf("%lf", &num);

    printf("Enter the desired precision (e.g., 0.000001): ");
    scanf("%lf", &precision);

    double result = sqrt_binary_search(num, precision);
    if (result != -1)
        printf("Square root of %.6f is approximately %.6f\n", num, result);

    return 0;
}

