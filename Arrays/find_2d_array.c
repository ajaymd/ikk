/**********************************************************
 *
 *  Find a number in a sorted 2D array
 *
 *********************************************************/
#include <stdio.h>

int findIn2DArray(const int *array, int height, int width, int target, int *row, int *column) {
    int top_row = 0;
    int right_column = width - 1;
    while(right_column >= 0 && height - 1 >= top_row) {
        int entry = array[top_row * width + right_column];
        if (entry == target) {
            *row = top_row;
            *column = right_column;
            return 1;
        } 
        if (entry > target)
            right_column--;
        else
            top_row++;
    }
    *row = *column = -1;
    return 0;
}

typedef struct {
    int target, row, column, result;
} TestCase;

int array[] = {
     1,  2,  3,  4,  5,
     2,  7,  8,  9, 10,
     3, 12, 13, 14, 15,
     3, 14, 13, 15, 15,
     3, 15, 16, 20, 21
};

TestCase tests[] = {
    {0, -1, -1, 0},
    {1, 0, 0, 1},
    {2, 0, 1, 1},
    {5, 0, 4, 1},
    {6, -1, -1, 0},
    {7, 1, 1, 1},
    {21, 4, 4, 1},
    {22, -1, -1, 0}
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int row; int column;
        int result = findIn2DArray(array, 5, 5, tests[i].target, &row, &column);
        if (result != tests[i].result || row != tests[i].row || column != tests[i].column) {
            printf("Error: result of test case number %d is %d. Got %d instead\n",
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
