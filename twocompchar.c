#include <stdio.h>

int multiply(char var1[], char var2[]){
	return 0;
}

int main(){
	char bin1[32];
	char bin2[32];
	printf("give me two binary numbers to multiply\n");
	printf("I will express the answer in two's complement\n");
	printf("what is the first binary number?\n");
	scanf("%s", &bin1);
	printf("what is the second binary number?\n");
	scanf("%s", &bin2);
	printf("%d", multiply(bin1,bin2));
}



