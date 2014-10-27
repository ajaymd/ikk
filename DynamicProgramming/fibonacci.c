/******************************************************************************
 *
 *  Write a function that returns the n-th element in a Fibonacci series
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

long fibonacci(int n) {
    if (n == 0 || n == 1) 
        return n;
    int *fib = malloc(sizeof(int) * (n + 1));
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i -2];
    int result = fib[n];
    free(fib);
    return result;
}

typedef struct {
    int n, fib;
} TestCase;

TestCase tests[] = {{0, 0}, {1, 1}, {2, 1}, {10, 55}};  

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int result = fibonacci(tests[i].n);
        if (result != tests[i].fib) {
            printf("Error: fibonacci(%d) == %d. Got %d instead\n",
                tests[i].n, tests[i].fib, result);
            errors++;
        } 
    }

    if (errors)
        printf("Got %d errors\n", errors);
    else
        printf("Good work\n");
    return 0;
} 

