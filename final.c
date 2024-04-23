#include <stdio.h>
#include <stdlib.h>

int sumFromFile(char *filename) {
    FILE *file = fopen(filename, "r");//used fopen instead of open
    int sum = 0;
    int num;//used to store current number from file
    
    if (file == NULL) {
        printf("Error: File not found\n");
        return -1;
    }

    while (fscanf(file,"%d", &num) != -1) {
        sum += num;
    }

    fclose(file);
    return sum;
}

//for test cases
int addNum(int a){
    FILE *file = fopen("numbers.txt", "a");
    fprintf(file, "\n");
    fprintf(file, "%d", a);
    fclose(file);
    return 0;
}


int main(){
    printf("Sum: %d\n", sumFromFile("numbers.txt"));
    addNum(9);
    printf("Sum after adding 9: %d\n", sumFromFile("numbers.txt"));
    addNum(-1);//adding a negative number works like subtracting
    printf("Sum after subtracting 1: %d\n", sumFromFile("numbers.txt"));
    return 0;
}






/*



*/