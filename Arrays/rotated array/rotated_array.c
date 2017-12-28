/**********************************************************
 *
 *   Find the Minimum in a Rotated Array
 *
 *********************************************************/
#include <stdio.h>

int findMinimumRecursion(int *array, int low, int high) {
    if (array[low] < array[high])
        return array[low];

    if (low == high)
        return array[low];

    int mid = (low + high) / 2;
    return array[mid] >= array[low]
        ? findMinimumRecursion(array, mid + 1, high)
        : findMinimumRecursion(array, low, mid);
}

int findMinimum(int *array, int n) {
    return findMinimumRecursion(array, 0, n - 1);
}

typedef struct {
    int *input, size, result;
} TestCase;

int arr0[] = {2, 1};
int arr1[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int arr2[] = {9, 10, 1, 2, 3, 4, 5, 6, 7, 8};
int arr3[] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
int arr4[] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
int arr5[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
int arr6[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
int arr7[] = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};
int arr8[] = {3, 4, 5, 6, 7, 8, 9, 10, 1, 2};
int arr9[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
int arr10[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr11[] = {1};

TestCase tests[] = {
    {arr0, 2, 1},
    {arr1, 10, 1},
    {arr2, 10, 1},
    {arr3, 10, 1},
    {arr4, 10, 1},
    {arr5, 10, 1},
    {arr6, 10, 1},
    {arr7, 10, 1},
    {arr8, 10, 1},
    {arr9, 10, 1},
    {arr10, 10, 1},
    {arr11, 1, 1}
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        result = findMinimum(tests[i].input, tests[i].size);
        if (result != tests[i].result) {
            printf("Error: minimum of test case number %d is %d. Got %d instead\n",
                i, tests[i].result, result);
            errors++;
        } 
    }

    if (errors)
        printf("Got %d errors\n", errors);
    else
        printf("Good work\n");
    return 0;
}
