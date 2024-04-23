#include <stdio.h>

int multiply(int a, int b);

int main() {
    int bin1, bin2;

    printf("Enter a binary number: ");
    scanf("%d", &bin1);

    printf("Enter another binary number: ");
    scanf("%d", &bin2);

    printf("The product of %d * %d in binary is %d\n", bin1, bin2, multiply(bin1, bin2));

    return 0;
}

int multiply(int a, int b){
    //using recursion to multiply the two numbers
    if (b == 0){
        return 0;
    }
    else if (b > 0){
        return a + multiply(a, b-1);
    }
    else if (b < 0){
        return -a + multiply(a, b+1);
    }
    else{
        return 0;
    }
}