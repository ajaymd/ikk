#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) > (b) ? (b) : (a))

int recursion(int *input, int length, int *coins, int change) {
  if (change <= input[length - 1] && coins[change])
    return 1;

  int min = 1 + recursion(input, length, coins, change - 1); // Use the smallest coin
  for (int i = 1; i < length; ++i)
    if (change - input[i] >= 1)
      min = MIN(min, 1 + recursion(input, length, coins, change - input[i]));

  return min;
}

int dynamicProgramming(int *input, int length, int *coins, int change) {
  int *minCoins = malloc(sizeof(int) * (change + 1));

  for(int c = 1; c <= change; ++c) {  // c is the change of the recursion
    if (c < input[length - 1] && coins[c]) {
      minCoins[c] = 1;
      continue;
    }
    int min = 1 + minCoins[c - 1];
    for (int i = 1; i < length; ++i)
      if (c - input[i] >= 1)
        min = MIN(min, 1 + minCoins[c - input[i]]);
    minCoins[c] = min;
  }

  int min = minCoins[change];

  free(minCoins);

  return min;
}

int INPUT[] = {1, 3, 10, 25, 40};
int LENGTH = sizeof(INPUT) / sizeof(int);

int main() {
  int biggestCoin = INPUT[LENGTH - 1]; // A simple implementation of a set
  int* coins = malloc(sizeof(int) * (biggestCoin + 1));
  for(int i = 1; i <= biggestCoin; ++i)
    coins[i] = 0;
  for(int i = 0; i < LENGTH; ++i)
    coins[INPUT[i]] = 1;

  for (int i = 1; i < 60; ++i) {
    printf("%d ", i);
    printf("%d ", recursion(INPUT, LENGTH, coins, i));
    printf("%d\n", dynamicProgramming(INPUT, LENGTH, coins, i));
  }
  return 0;
}
    
