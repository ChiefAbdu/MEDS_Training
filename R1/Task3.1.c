#include <stdio.h>

int main() {
    int x, y, result;

    printf("Enter first number (x): ");
    scanf("%d", &x);

    printf("Enter second number (y): ");
    scanf("%d", &y);

    __asm__(
        "addl %%ebx, %%eax;"     
        : "=a"(result)           
        : "a"(x), "b"(y)   
    );

    printf("Result of %d + %d = %d\n", x, y, result);

    return 0;
}
