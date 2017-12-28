/**********************************************************
 *
 *  Find the Magic Index
 *
 *********************************************************/
#include <stdio.h>

int findMagicIndexRecursion(int *array, int low, int high) {
    int middle = (low + high) / 2;
    if (array[middle] == middle)
        return middle;
    if (array[middle] > middle)
        return findMagicIndexRecursion(array, low, middle - 1);
    return findMagicIndexRecursion(array, middle + 1, high);
}

int findMagicIndex(int *array, int n) {
    return findMagicIndexRecursion(array, 0, n - 1);
}

typedef struct {
    int *input, size, result;
} TestCase;

int arr0[] = {0};
int arr1[] = {0, 2, 3, 4, 5};
int arr2[] = {-1, 0, 1, 2, 4};
int arr3[] = {-1, 1, 7, 8, 9};

TestCase tests[] = {
    {arr0, 1, 0},
    {arr1, 5, 0},
    {arr2, 5, 4},
    {arr3, 5, 1}
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        result = findMagicIndex(tests[i].input, tests[i].size);
        if (result != tests[i].result) {
            printf("Error: test case %d. Expected %d got %d.\n",
                i, tests[i].result, result);
            errors++;
        } 
    }

    if (errors)
        printf("Got %d errors\n", errors);
    else
        printf("Good work\n");
} 
