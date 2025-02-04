//

#include <stdio.h>

// Function to calculate factorial using recursion
long long factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}
int main() {
    int n;  
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number is not defined.\n");
    } else {
        long long result = factorial(n);
        printf("Factorial of %d is %lld\n", n, result);
    }

    return 0;
}
