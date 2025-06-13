#include "Task4Header.h"

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int result = add(a, b);
    printf("The sum of %d and %d is %d\n", a, b, result);

    return 0;
}