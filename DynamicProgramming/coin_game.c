/**********************************************************
 *
 *  Coin Game
 *
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define getMax(i, j) max[i * length + j]

int maxWin(int *coins, int length) {
    int *max = malloc(sizeof(int) * length * length);
    // getMax(i, j) my best win if we start with the coins i to j 
    // on the table

    // At the end of the game he takes the last coin
    for(int i = 0; i < length; ++i)
        getMax(i,i) = -1 * coins[i];
    
    for(int i = 1; i < length; ++i) {
        // Go over the diagonal that starts with (0, i).
        // So i + 1 coins are left 
        for(int start = 0, end = i; end < length; ++start, ++end) {
            if (i % 2) { // My Turn
                getMax(start, end)
                    // MAX because I want to win
                    // Take the first coin on the table
                    = MAX(coins[start] + getMax(start + 1, end),
                    // Take the last coin on the table
                          coins[end] + getMax(start, end - 1));
            } else { // His turn
                getMax(start, end)
                    // MIN because he wants mw to lose
                    // He takes the first coin on the table
                    = MIN(-1 * coins[start] + getMax(start + 1, end),
                    // he takes the last coin on the table
                          -1 * coins[end] + getMax(start, end - 1));
            }
        }
    }

    int result = getMax(0, length - 1);
    free(max);
    return result;
}

typedef struct {
    int *array, length, result;
} TestCase;

int arr0[] = {1, 5};
int arr1[] = {1, 2, 3, 4, 5, 6};
int arr2[] = {100, 1000, 1, 1};

TestCase tests[] = {
    {arr0, 2, 4},
    {arr1, 6, 3},
    {arr2, 4, 900}
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int result = maxWin(tests[i].array, tests[i].length);
        if (result != tests[i].result) {
            printf("Error: test case number %d returned %d. Expected %d\n",
                i + 1, result, tests[i].result);
            errors++;
        } 
    }

    if (errors)
        printf("Got %d errors\n", errors);
    else
        printf("Good work\n");
    return 0;
} 
