#include <stdio.h>

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main(){
    int input,twoCompliment;

    printf("Enter a Number To Find the 2's compliment : ");
    scanf("%d",&input);
    printf("The int is : %d\n",input);

    twoCompliment = ~input + 1;

    printf("The Binary compliment is : ");
    printBinary(twoCompliment);

    return 0;
}