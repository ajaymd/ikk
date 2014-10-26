/**********************************************************
 *
 *   Pick Days to Buy and Sell a Stock
 *
 *********************************************************/
#include <stdio.h>

int findMaxProfit(int *array, int size, int *best_buy_day, int *best_sell_day) {
    int buy_day, sell_day, lowest_buy_day, max_profit;
    buy_day = sell_day = lowest_buy_day = max_profit = 0;

    for(int i = 1; i < size; ++i) {
        if (array[i] < array[buy_day]) {
            lowest_buy_day = i;
            continue;
        }

        if (array[i] - array[lowest_buy_day] > max_profit) {
            buy_day = lowest_buy_day;      
            sell_day = i;
            max_profit = array[sell_day] - array[buy_day];
        }
    }
    *best_buy_day = buy_day;
    *best_sell_day = sell_day;
    return max_profit; 
}

typedef struct {
    int *input, size, result;
} TestCase;

int arr0[] = {2, 1};
int arr1[] = {1, 2, 3, -2, 4, -6, -5};

TestCase tests[] = {
    {arr0, 2, 0},
    {arr1 ,7, 6},
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int best_buy_day, best_sell_day;
        result = findMaxProfit(tests[i].input, tests[i].size, &best_buy_day, &best_sell_day);
        if (result != tests[i].result) {
            printf("Error: result of test case number %d is %d. Got %d instead\n",
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
