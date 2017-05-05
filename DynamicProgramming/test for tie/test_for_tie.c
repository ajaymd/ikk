/**********************************************************
 *
 *  Test if tie is possible
 *  
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>

int testTie(int *votes, int size) {
    int sum = 0;
    for(int state = 0; state < size; ++state) 
        sum += votes[state];
    printf("Sum: %d\n", sum);
    if (sum % 2 == 1)
        return 0;
    sum /= 2;

    int *scores = malloc(sizeof(int) * (sum + 1));
    for(int i = 0; i <= sum; i++)
        scores[i] = -1;

    for(int state = 0; state < size; state++) {
        int v = votes[state];
        for(int j = sum; j > votes[state]; --j) {
            if (scores[j] == -1 && scores[j - votes[state]] != -1)
                scores[j] = state;
        }
        scores[votes[state]] = state;
        if (scores[sum] != -1)
            break;
    }

    int result = 0;
    if (scores[sum] != -1) {
        result = 1;
        int state = scores[sum];
        for(int i = sum; i != 0; i -= votes[state]) {
            state = scores[i];
            printf("%d %d %d\n", state, votes[state], i);
        }
    }

    free(scores);
    return result;
}

int votes[] = {
    9, 3, 11, 6, 55, 9, 7, 3, 29, 16, 4, 4, 20, 11, 6, 6, 8,
    8, 4, 10, 11, 16, 10, 6, 10, 3, 5, 6, 4, 14, 5, 29, 15, 3,
    18, 7, 7, 20, 4, 9, 3, 11, 38, 6, 3, 13, 12, 5, 10, 3, 3
};

int main() {
    testTie(votes, sizeof(votes) / sizeof(int));
    return 0;
}
