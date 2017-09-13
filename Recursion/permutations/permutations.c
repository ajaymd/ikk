/******************************************************************************
 *
 *  Print all permutations of length n
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void printPermutationsRecursion(int n, int *array, int i) {
    if (i == n) {
        for(int j = 0; j < n; ++j)
            printf("%d ", array[j]);
        printf("\n");
        return;
    }

    for(int j = i; j < n; ++j) {
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
        printPermutationsRecursion(n, array, i + 1);
        array[i] = array[j];
        array[j] = tmp;
    } 
}

void printPermutations(int n) {
    int *array = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i)
        array[i] = i + 1;
    printPermutationsRecursion(n, array, 0);
    free(array);
}

int main(int argc, char **argv) {
    printPermutations(atoi(argv[1]));
    return 0;
} 

  
