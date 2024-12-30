#include <stdio.h>
int main() {
    int num;
    unsigned long long factorial = 1;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("The factorial of %d is %llu\n", num, factorial);
    }
    return 0;
}