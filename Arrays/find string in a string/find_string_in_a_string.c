/**********************************************************
 *
 *  Find the string s in a string t
 *
 *********************************************************/
#include <stdio.h>
#include <string.h>

int powers[50];

void init() {
    powers[0] = 1;
    for(int i = 1; i < 50; ++i) 
        powers[i] = (powers[i - 1] * 26) % 31; 
}

int calculateRollingHash(const char *string, int length) {
    int hash = 0;
    for(int i = length - 1; i >= 0; --i) 
        hash = (hash + powers[length - 1 - i] * (string[i] - 'a')) % 31;
    return hash;   
}

int updateRollingHash(int length, int hash, char left, char right) {
    hash -= (left - 'a') * powers[length - 1];
    hash = (hash * 26 + (right - 'a')) % 31;
    return hash >= 0 ? hash : hash + 31;
}

int findString(const char *s, const char *t) {
    int s_length = strlen(s);
    int t_length = strlen(t);
    if (s_length > t_length)
        return -1;
    int target_hash = calculateRollingHash(s, s_length);
    int rolling_hash = calculateRollingHash(t, s_length);
    int i = 0;
    do {
        if (target_hash == rolling_hash) {
            int j;
            for(j = 0; j < s_length; ++j)
                if (t[i + j] != s[j])
                    break;
            if (j == s_length)
                return i; 
        }
        rolling_hash = updateRollingHash(s_length, rolling_hash, t[i], t[i + s_length]); 
    } while(++i + s_length <= t_length);
    return -1;
}

typedef struct {
    char *s, *t;
    int result;
} TestCase;

#define TEST_CASE(s, t, res) {s, t, res}

TestCase tests[] = {
    TEST_CASE("yuval", "yuval", 0),
    TEST_CASE("yuv", "yuval", 0),
    TEST_CASE("u", "yuval", 1),
    TEST_CASE("l", "yuval", 4),
    TEST_CASE("uva", "yuval", 1),
    TEST_CASE("val", "yuval", 2),
    TEST_CASE("yuvall", "yuval", -1),
    TEST_CASE("yub", "yuval", -1),
    TEST_CASE("yu", "zzzaaaaa", -1)
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    init();
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        result = findString(tests[i].s, tests[i].t);
        if (result != tests[i].result) {
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
