#include <stdio.h>

int main(){
	char name[10];
	printf("What is your first name?");
	scanf("%9s",&name);
	printf("my name is %s", name);
	return 0;
}
