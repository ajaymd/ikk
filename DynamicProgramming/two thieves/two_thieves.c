#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(n) ((n) >= 0 ? (n) : -1 * (n))

int minDiff(int *array, int length) {
    int sum = 0;
    for(int i = 0; i < length; ++i)
        sum += array[i];
    printf("Sum: %d\n", sum); 

    int *take = malloc(sizeof(int) * length);
    int *dontTake = malloc(sizeof(int) * length);

    take[0] = array[0];
    dontTake[0] = -1 * array[0];

    for(int i = 0; i < length; ++i) {
        take[i] = ABS(take[i - 1] + array[i]) < ABS(dontTake[i - 1] + array[i]) ?
                    take[i - 1] + array[i] : dontTake[i - 1] + array[i];
        dontTake[i] = ABS(take[i - 1] - array[i]) < ABS(dontTake[i - 1] - array[i]) ?
                    take[i - 1] - array[i] : dontTake[i - 1] - array[i];
    }

    int min = MIN(ABS(take[length - 1]), ABS(dontTake[length - 1]));

  free(allowed);
  free(notAllowed);
}

int main() {
  printf("Recursion: %d\n", recursiveMaxGain(INPUT, LENGTH, 0, 1));
  printf("Dynamic Programming: %d\n", dynamicProgramming(INPUT, LENGTH));
  return 0;
}
    
