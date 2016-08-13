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
<<<<<<< HEAD
  int biggestCoin = INPUT[LENGTH - 1]; // A simple implementation of a set
  int* coins = (int*)malloc(sizeof(int) * (biggestCoin + 1));
  for(int i = 1; i <= biggestCoin; ++i)
    coins[i] = 0;
  for(int i = 0; i < LENGTH; ++i)
    coins[INPUT[i]] = 1;

  for (int i = 1; i < 60; ++i) {
    printf("%d ", i);
    printf("%d ", recursion(INPUT, LENGTH, coins, i));
    printf("%d\n", dynamicProgramming(INPUT, LENGTH, coins, i));
=======
  for (int change = 1; change < 60; ++change) {
    printf("%d ", change);
    printf("%d ", recursion(COINS, LENGTH, change));
    printf("%d\n", dynamicProgramming(COINS, LENGTH, change));
>>>>>>> aeea9572610c1d246a5c342fc86e038df1a71ef2
  }
  return 0;
}
    
