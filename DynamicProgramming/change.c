#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) > (b) ? (b) : (a))

int recursion(int *coins, int length, int change) {
  if (change == 0)
    return 0;

  int min = change;
  for (int i = 0; i < length; ++i)
    if (change - coins[i] >= 0)
      min = MIN(min, 1 + recursion(coins, length, change - coins[i]));

  return min;
}

int dynamicProgramming(int *coins, int length, int change) {
  int minCoins[change + 1];

  minCoins[0] = 0;

  for (int c = 1; c <= change; ++c) {  // c is the change of the recursion
    int min = change;
    for (int i = 0; i < length; ++i)
      if (c - coins[i] >= 0)
        min = MIN(min, 1 + minCoins[c - coins[i]]);
    minCoins[c] = min;
  }

  return minCoins[change];
}

int COINS[] = {1, 3, 10, 25, 40};
int LENGTH = sizeof(COINS) / sizeof(int);

int main() {
  for (int change = 1; change < 60; ++change) {
    printf("%d ", change);
    printf("%d ", recursion(COINS, LENGTH, change));
    printf("%d\n", dynamicProgramming(COINS, LENGTH, change));
  }
  return 0;
}
