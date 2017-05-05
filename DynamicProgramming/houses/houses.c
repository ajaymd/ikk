#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int INPUT[] = {18, 4, 1, 20};
int LENGTH = sizeof(INPUT) / sizeof(int);

int recursiveMaxGain(int *array, int length, int i, int allowedToSelect) {
  if (i == length - 1) 
    return allowedToSelect ? array[i] : 0;

  int max0 = recursiveMaxGain(array, length, i + 1, 0);
  int max1 = recursiveMaxGain(array, length, i + 1, 1);

  return allowedToSelect ? MAX(array[i] + max0, max1) : max1;
}

int dynamicProgramming(int *array, int length) {
  int allowed[length];
  int notAllowed[length];

  allowed[length - 1] = array[length - 1];
  notAllowed[length - 1] = 0;

  for(int i = length - 2; i >= 0; --i) {
    allowed[i] = MAX(array[i] + notAllowed[i + 1], allowed[i + 1]);
    notAllowed[i] = allowed[i + 1];
  }

  return allowed[0];
}

int main() {
  printf("Recursion: %d\n", recursiveMaxGain(INPUT, LENGTH, 0, 1));
  printf("Dynamic Programming: %d\n", dynamicProgramming(INPUT, LENGTH));
  return 0;
}
    
