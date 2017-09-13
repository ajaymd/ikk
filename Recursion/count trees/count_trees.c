#include <stdio.h>

int trees(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int sum = 2 * trees(n - 1);  // Processes (0,4) and (4,0) from the test-case above
  for (int i = 1; i < n - 1; ++i)
    sum += trees(i) * trees(n - 1 - i) ; // Processes (1,3), (2,2) and (3,1) from the test-case above
  return sum;
}

int main() {
  for (int i = 1; i < 7; ++i)
    printf ("%d\n", trees(i)); // Just an example until n = 6

  return 0;
}
