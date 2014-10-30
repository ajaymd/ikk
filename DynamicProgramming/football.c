/**********************************************************
 *
 *  Football
 *
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>

int countCombinations(int score) {
    int *comb =  malloc(sizeof(int) * (score + 1));
    comb[1] = 0;
    comb[0] = comb[2] = comb[3] = comb[4] = 1;
    comb[5] = comb[6] =  2;
    comb[7] = 4;
    if (score <= 7)
        return comb[score];
    for(int i = 8; i <= score; ++i)
        comb[i] = comb[i - 7] + comb[i - 3] + comb[i - 2]; 
    
    int result = comb[score];
    free(comb);
    return result;
}

int main() {
    for(int i = 0; i < 20; ++i)
        printf("%d %d\n", i, countCombinations(i));

    return 0;
} 
