/******************************************************************************
 *
 *  Find best path in an MxN matrix. "Islands" are possible
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX(l, r)       ((l) > (r) ? (l) : (r))

int bestPathRecursion(int *array, int m, int n, int i, int j) {
    if (i == m - 1 && j == n -1) 
        return array[i * n + j];

    if (array[i * n + j] == -1) 
        return -1;

    int best_path;
    if (i == m - 1) {
        best_path = bestPathRecursion(array, m, n, i, j + 1);
        if (best_path == -1) 
            return -1;
        return array[i * n + j] + best_path;
    }

    if (j == n - 1) {
        best_path = bestPathRecursion(array, m, n, i + 1, j);
        if (best_path == -1) 
            return -1;
        return array[i * n + j] + best_path;
    }
    
    best_path = bestPathRecursion(array, m, n, i + 1, j);
    int down = best_path == -1 ? -1 : array[i * n + j] + best_path;
    best_path = bestPathRecursion(array, m, n, i, j + 1);
    int right = best_path == -1 ? -1 : array[i * n + j] + best_path;
    return MAX(down, right);
}

int bestPath(int *array, int m, int n) {
    return bestPathRecursion(array, m, n, 0, 0);     
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
int arr5[] = {-1};
int arr6[] = {1, 2, 3,
              4, 5, 6,
              7, -1, 9};
int arr7[] = {1, 2, 3,
              4, 5, -1,
              7, 8, 9};
int arr8[] = {2,  2,  1,  1, 1,
              1, -1,  1,  1, 1,
              1,  2, -1,  1, 1, 
              1,  1,  2, -1, 1,
              1,  1,  1,  2, 2};  
TestCase tests[] = {
    {9, 1, 1, arr1}, 
    {6, 1, 3, arr2}, 
    {6, 3, 1, arr2}, 
    {29, 3, 3, arr3}, 
    {18, 5, 5, arr4},
    {-1, 1, 1, arr5},
    {25, 3, 3, arr6},
    {29, 3, 3, arr7},
    {14, 5, 5, arr8} 
};  

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

void test() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        result = bestPath(tests[i].array, tests[i].m, tests[i].n);
        printf("%d\n", result);
        if (result != tests[i].result) {
            printf("Error: Best path of test case number %d is %d. Got %d instead\n",
                i, tests[i].result, result);
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
