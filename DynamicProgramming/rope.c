#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int recursion(int ropeLength, int mustCut) {
  if (ropeLength == 1)
    return 1;

  int max = mustCut ? 0 : ropeLength;
  for (int i = 1; i < ropeLength; ++i)
    max = MAX(max, recursion(i, 0) * recursion(ropeLength - i, 0)); 

  return max;
}

int dynamicProgramming(ropeLength) {
  int *max = malloc(sizeof(int) * (ropeLength + 1));

  max[1] = 1;

  for(int j = 2; j <= ropeLength; ++j) { // j is the ropeLength on the recursion
    int m = (j == ropeLength ?  0 : j);
    for(int i = 1; i < j; ++i) // i has the same role as in the recursion 
      m = MAX(m, max[i] * max[j - i]);
    max[j] = m;
  }

  int result = max[ropeLength];

  free(max);

  return result;
}

int main() {
  int ropeLength = 13;
  printf("Recursion: %d\n", recursion(13, 1));
  printf("Dynamic Programming: %d\n", dynamicProgramming(13));
  return 0;
}
    
