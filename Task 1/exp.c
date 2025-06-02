#include <stdio.h>

double exponential(double x, int terms) {
    double result = 1.0;
    double term = 1.0;

    for (int n = 1; n < terms; n++) {
        term *= x / n;
        result += term;
    }

    return result;
}

int main() {
    double x;
    int terms = 200;

    printf("Enter the value of x for exp(x): ");
    scanf("%lf", &x);

    double result = exponential(x, terms);

    if (result > 1e6)
        printf("exp(%.2f) ≈ %.15e\n", x, result);
    else
        printf("exp(%.2f) ≈ %.15f\n", x, result);

    return 0;
}

