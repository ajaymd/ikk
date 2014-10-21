#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) > (b) ? (b) : (a))

int recursion(int *array, int length, int i) {
  if (i == length - 1) 
    return 0;

  int min = 1 + recursion(array, length, i + 1);
  for (int j = array[i]; j > 1; --j)
    if (i + j <= length - 1)
      min = MIN(min, 1 + recursion(array, length, i + j));

  return min;
}

int dynamicProgramming(int *array, int length) {
  int *minJumps = malloc(sizeof(int) * length);

  minJumps[length - 1] = 0;

  for(int i = length - 2; i >= 0; --i) {
    int min = 1 + minJumps[i + 1];
    for (int j = array[i]; j > 1; --j)
      if (i + j <= length - 1)
        min = MIN(min, 1 + minJumps[i + j]);
    minJumps[i] = min;
  }

  int min = minJumps[0];

  free(minJumps);

  return min;
}

int INPUT[] = {3, 4, 2, 4, 1, 1, 1, 20};
int LENGTH = sizeof(INPUT) / sizeof(int);

int main() {
  printf("Recursion: %d\n", recursion(INPUT, LENGTH, 0));
  printf("Dynamic Programming: %d\n", dynamicProgramming(INPUT, LENGTH));
  return 0;
}
    
