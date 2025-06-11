#include <stdio.h>
#define INT_MAX 7
#define INT_MIN -8


int main(){
    int overflow = INT_MAX;
    int underflow = INT_MIN;

    printf("Initial Maximum Value : %d\n",overflow);

    overflow++;
    if (overflow > INT_MAX){
        overflow = INT_MIN;
        printf("After Adding 1 from Maximum Value : %d\n",overflow);
    }
    
    printf("Initial Minimum Value : %d\n",underflow);

    underflow--;
    if (underflow < INT_MIN){
        underflow = INT_MAX;
        printf("After Subtracting 1 from Minimum Value : %d\n",underflow);
    }

    return 0;
}