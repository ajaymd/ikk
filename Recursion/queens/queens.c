/******************************************************************************
 *
 *  Print all solutions to the N queens problem
 *
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void queensRecursion(int n, int *array, int i) {
    if (i == n) {
        for(int j = 0; j < n; ++j)
            printf("+-");
        printf("+\n");
        for(int k = 0; k < n; ++k) {
            for(int j = 0; j < n; ++j) 
                printf("|%c", array[j] == k ? '*' : ' ');
            printf("|\n");
            for(int j = 0; j < n; ++j)
                printf("+-");
            printf("+\n");
        }
        printf("\n");
         
        return;
    }

    for(int j = 0; j < n; ++j) {
        array[i] = j;
        int k;
        for(k = 0; k < i; ++k) {
            if (array[k] == array[i])
                break;
            if (array[k] - array[i] == k - i)
                break;
            if (array[k] - array[i] == i - k)
                break;
        }
        if (k != i)
            continue;
        queensRecursion(n, array, i + 1);
    } 
}

void queens(int n) {
    int *array = malloc(n * sizeof(int));
    queensRecursion(n, array, 0);
    free(array);
}

int main(int argc, char **argv) {
    queens(atoi(argv[1]));
    return 0;
} 

  
