/******************************************************************************
 *
 *  Find best path in an MxN matrix
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX(l, r)       ((l) > (r) ? (l) : (r))

int bestPath(int *array, int m, int n) {
    int *bp = malloc(sizeof(int) * m * n);
    bp[m * n - 1] = array[m * n -1];
    for(int j = n - 2; j >= 0; --j)
        bp[(m - 1) * n + j] = array[(m - 1) * n + j] + bp[(m - 1) * n + j + 1];
    for(int i = m - 2; i >= 0; --i) {
        bp[i * n + (n - 1)] = array[i * n + (n - 1)] + bp[(i + 1) * n + (n - 1)];
        for(int j = n - 2; j >= 0; --j) {
            int right = array[i * n + j] + bp[i * n + j + 1];
            int down  = array[i * n + j] + bp[(i + 1) * n + j];
            bp[i * n + j] = MAX(down, right);
        }
    }
    int result = bp[0];    
    free(bp);    
    return result;
}
        
typedef struct {
    int result, m, n;
    int *array;
} TestCase;

int arr1[] = {9};
int arr2[] = {1, 2, 3};
int arr3[] = {1, 2, 3,
              4, 5, 6,
              7, 8, 9};
int arr4[] = {2, 2, 1, 1, 1,
              1, 2, 1, 1, 1,
              1, 2, 2, 1, 1, 
              1, 1, 2, 2, 1,
              1, 1, 1, 2, 2};  
TestCase tests[] = {
    {9, 1, 1, arr1}, 
    {6, 1, 3, arr2}, 
    {6, 3, 1, arr2}, 
    {29, 3, 3, arr3}, 
    {18, 5, 5, arr4} 
};  

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int result = bestPath(tests[i].array, tests[i].m, tests[i].n);
        if (result != tests[i].result) {
            printf("Error: Best path of test case number %d is %d. Got %d instead\n",
                i + 1, tests[i].result, result);
            errors++;
        } 
    }

    if (errors)
        printf("Got %d errors\n", errors);
    else
        printf("Good work\n");
    return 0;
} 
