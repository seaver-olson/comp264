#include <stdio.h>

/*

pseudo code testing 
main()
	num1, num2: int 
	product: function mulitply(num1, num2)
		prints the product of num1 and num2 in twos complement

multiply()
	num1, num2: int
	product: int
		mutliply num1 and num2 using the shift and add method
		returns the product in twos complement

*/

int multiply(int num1, int num2){
	int product = 0;//product is 0 if num2 is 0
	/*
	i did look up this method of multiplying binary numbers by shifting and adding however I wrote the code myself and am able to explain it
	The loop checks each bit of num2 and if it is 1 it adds num1 which is shifted to the left by the number of bits that have been checked
	Then num2 is shifted to the right by 1 to check the next bit until num2 runs out of bits to check
	*/
	while (num2>0){
		if (num2%2 != 0){
			product += num1;
		}

		num1 = num1 << 1;//multiplies num1 by 2
		num2 = num2 >> 1;//divides num2 by 2
	}
	
	return product;
}

int main(){
	int bin1, bin2;
	printf("Enter a binary number: ");
	scanf("%d", &bin1);
	printf("Enter another binary number: ");
	scanf("%d", &bin2);
	printf("The two's complement of %d * %d is %u\n", bin1, bin2,multiply(bin1, bin2));
	return 0;
}