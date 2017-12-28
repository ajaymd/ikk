/******************************************************************************
 *
 *  Write a function that returns the n-th element in a Fibonacci series
 *
 *****************************************************************************/
#include <stdio.h>

long fibonacci(int n) {
    if (n == 0 || n == 1) 
        return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i -2];
    return fib[n];
}

int main() {
   printf("fibonacci(45) == %ld\n", fibonacci(45));
   return 0;
} 

