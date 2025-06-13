#include <stdio.h>

void print_binary(unsigned int n) {
    int bits = sizeof(n) * 8;
    int leading = 1;

    printf("Binary: ");
    for (int i = bits - 1; i >= 0; i--) {
        if ((n >> i) & 1) {
            printf("1");
            leading = 0;
        } else if (!leading) {
            printf("0");
        }
    }

    if (leading) {
        printf("0");
    }

    printf("\n");
}

int main() {
    unsigned int n, count = 0;

    printf("Enter a number: ");
    scanf("%u", &n);

    print_binary(n);

    if (n == 0) {
        printf("Trailing zeroes (decimal): %ld\n", sizeof(n) * 8);
        return 0;
    }

    while ((n & 1) == 0) {
        count++;
        n = n >> 1;
    }

    printf("Trailing zeroes (decimal): %d\n", count);
    return 0;
}
