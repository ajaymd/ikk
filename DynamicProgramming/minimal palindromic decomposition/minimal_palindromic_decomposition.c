/**********************************************************
 *
 *  Find Minimal Palindromic Decomposition
 *
 *********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(i, j)   ((i) < (j) ? (i) : (j))

int findMinimalPalindromicDecomposition(const char *string) {
    int length = strlen(string);

    // isPalindrom[i][j] == 1 iff substring(string, i, j) is a palindrome
    char *isPalindrom = malloc(length * length);
    for(int i = length - 1; i >= 0; --i) {
        for(int j = i; j < length; ++j) {
            isPalindrom[i * length + j] = 0;

            if (string[i] != string[j])
                continue;

            if ((j - i <= 1) || isPalindrom[(i + 1) * length + (j - 1)])
                isPalindrom[i * length + j] = 1;
        }
    }   

    int *minimumPalindromicDecomposition = malloc(sizeof(int) * length);
    for(int i = length - 1; i >= 0; --i) {
        int min = length;
        for(int j = i; j < length; ++j) {
            if (isPalindrom[i * length + j])
                min = j + 1 == length ? 1 : MIN(min, 1 + minimumPalindromicDecomposition[j + 1]);
        }
        minimumPalindromicDecomposition[i] = min;
    }
    
    free(isPalindrom);
    int result = minimumPalindromicDecomposition[0]; 
    free(minimumPalindromicDecomposition);
    return result;
}

typedef struct {
    char *string;
    int result;
} TestCase;

TestCase tests[] = {
    {"1234", 4},        // 1|2|3|4
    {"11234", 4},       // 11|2|3|4
    {"1211213121", 2}   //121|1213121
};
  
#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int result = findMinimalPalindromicDecomposition(tests[i].string);
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
