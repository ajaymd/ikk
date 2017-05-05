/******************************************************************************
 *
 *  Print all the "words" of a phone number
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *key_pad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printWordsRecursion(const char *number, int length, int read, char *word, int write) {
    if (read == length) {
        if (*word != '\0')
            printf("%s\n", word);
        return;
    }
    
    int digit = number[read] - '0';
    const char *letters = key_pad[digit];
    int letters_length = strlen(letters);

    if (letters_length == 0) {
        printWordsRecursion(number, length, read + 1, word, write);
        return;
    }

    for(int j = 0; j < letters_length; ++j) {
        word[write] = letters[j];
        printWordsRecursion(number, length, read + 1, word, write + 1);
    } 
}

void printWords(const char *number) {
    int length = strlen(number);
    char *word = malloc((length + 1) * sizeof(char));
    for(int i = 0; i <= length; ++i) 
        word[i] = '\0';
    printWordsRecursion(number, length, 0, word, 0);
    free(word);
}

int main(int argc, char **argv) {
    printWords(argv[1]);
    return 0;
} 
