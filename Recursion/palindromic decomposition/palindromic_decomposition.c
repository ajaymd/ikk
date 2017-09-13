/******************************************************************************
 *
 *  Palindromic Decomposition
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(const char *begin, const char *end) {
    if (begin >= end)
        return 1;
    return *begin == *end && isPalindrome(begin + 1, end - 1); 
}

void palindromicDecompositionRecursion(const char *string, char *decomposition, char *write) {
    if (*string == '\0') {
        *write = '\0';
        printf("%s\n", decomposition);
        return;
    }
    
    for(const char *end = string; *end != '\0'; end++) {
        if (isPalindrome(string, end)) {
            char *w = write;
            for(const char *j = string; j <= end ; ++j)
                *w++ = *j;
            *w++ = '|';
            palindromicDecompositionRecursion(end + 1, decomposition, w);
        }    
    }
}

void palindromicDecomposition(const char *string) {
    char *decomposition = malloc(2 * strlen(string) + 1);
    palindromicDecompositionRecursion(string, decomposition, decomposition);
    free(decomposition);
}

int main(int argc, char **argv) {
    palindromicDecomposition(argv[1]);
    return 0;
} 
