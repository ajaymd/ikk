/**********************************************************
 *
 *  String Matching
 *
 *********************************************************/
#include <stdio.h>

int stringMatching(const char *r, const char *s) {
    if (*r == '\0') 
        return *s == '\0';
    if (*(r + 1) == '*')
        return (stringMatching(r + 2, s) ||
            (*s != '\0' && (*s == *r || *r == '.') && stringMatching(r, s + 1)));
    if (*s == *r || (*r == '.' && *s != '\0'))
        return stringMatching(r + 1, s + 1);

    return 0;
}

typedef struct {
    char *r, *s;
    int result;
} TestCase;

#define TEST_CASE(r, s, res) {r, s, res}

TestCase tests[] = {
    TEST_CASE("yuval", "yuval", 1),
    TEST_CASE("yuval", "yuva", 0),
    TEST_CASE("yuv", "yuval", 0),
    TEST_CASE("", "yuval", 0),
    TEST_CASE("yuval", "", 0),
    TEST_CASE(".....", "yuval", 1),
    TEST_CASE("yuvb*al", "yuval", 1),
    TEST_CASE(".*", "yuval", 1),
    TEST_CASE("a*b*c*yuval.*a*b*c*", "yuval", 1),
    TEST_CASE("a*abc", "aaaabc", 1)
};

#define NUMBER_OF_TESTS sizeof(tests) / sizeof(TestCase)

int main() {
    int result;
    int errors = 0;
    for(int i = 0; i < NUMBER_OF_TESTS; ++i) {
        result = stringMatching(tests[i].r, tests[i].s);
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
