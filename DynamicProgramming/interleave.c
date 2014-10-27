/**********************************************************
 *
 *  Find if t = interleave(s1, s2);
 *
 *********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INTERLEAVE(i,j) interleave[(i) * (length_2 + 1) + (j)]

int isInterleave(const char *t, const char *s1, const char *s2) {
    int length_1 = strlen(s1);
    int length_2 = strlen(s2);
    int length_t = strlen(t);
    if (length_t != length_1 + length_2) 
        return 0;

    int *interleave = malloc(sizeof(int) * (length_1 + 1) * (length_2 + 1));
    INTERLEAVE(length_1, length_2) = 1;

    int match = 1;
    for(int i = length_1 - 1; i >= 0; --i) {
        if (match && s1[i] == t[length_t - length_1 + i]) {
            INTERLEAVE(i, length_2) = 1;
        } else {
            match = 0;
            INTERLEAVE(i, length_2) = 0;
        }
    }
            
    match = 1;
    for(int i = length_2 - 1; i >= 0; --i) {
        if (match && s2[i] == t[length_t - length_2 + i]) {
            INTERLEAVE(length_1, i) = 1;
        } else {
            match = 0;
            INTERLEAVE(length_1, i) = 0;
        }
    }

    for(int i = length_1 - 1; i >= 0; --i)
        for(int j = length_2 - 1; j >= 0; --j)
            INTERLEAVE(i, j) = ((t[i + j] == s1[i] && INTERLEAVE(i + 1, j)) ||
                                (t[i + j] == s2[j] && INTERLEAVE(i, j + 1)));

    return INTERLEAVE(0, 0);
}

typedef struct {
    char *t, *s1, *s2;
    int result;
} TestCase;

TestCase tests[] = {
    {"1234", "123", "123", 0},
    {"112233", "123", "123", 1},
    {"123456", "123456", "", 1},
    {"123456", "", "123456", 1},
    {"12345678", "1234", "5678", 1},
    {"12345678", "1233", "5678", 0}
};
  
#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        int result = isInterleave(tests[i].t, tests[i].s1, tests[i].s2);
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

