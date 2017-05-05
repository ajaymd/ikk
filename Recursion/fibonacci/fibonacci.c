/******************************************************************************
 *
 *  Write a function that returns the n-th element in a Fibonacci series
 *
 *****************************************************************************/
#include <stdio.h>

long fibonacci(int n) {
    if (n == 0 || n == 1) 
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

typedef struct {
    int n, fib;
} TestCase;

TestCase tests[] = {{0, 0}, {1, 1}, {2, 1}, {10, 55}};  
#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

void test() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        result = fibonacci(tests[i].n);
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
}

int main() {
    test();
    return 0;
} 

  
