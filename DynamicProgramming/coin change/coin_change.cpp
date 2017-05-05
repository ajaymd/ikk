#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

using namespace std;

// recursive implementation
int
numOfCoins(vector<int>& c, int V) {

  if (V == 0) return 0;
  if (V < 0) return 0;

  int best(V + 1);

  for (auto i = 0 ; i < c.size(); i++) {
    if (V >= c[i]) {
      int x = numOfCoins(c, V - c[i]);
      best = min(best, 1 + x);
    }
  }
  return (best > V) ? 0 : best;

}

// dp implementation
int
numOfCoins_DP(vector<int>& c, int V) {
  vector<int> res(V + 1, -1);
  res[0] = 0;

  for (auto v = 1; v <= V; v++) {
    int best(INT_MAX);
    for (auto i = 0; i < c.size(); i++) {
      if (v >= c[i]) best = min(best, 1 + res[v - c[i]]);
    }
    res[v] = best;
  }

  return (res[V] > 0) ? res[V] : 0;
}


int
main()
{

  vector<int> c = {5, 10, 25};

  cout << "num of coins for 22: " << numOfCoins(c, 22) <<  " " << numOfCoins_DP(c, 22) << endl;
  cout << "num of coins for 30: " << numOfCoins(c, 30) <<  " " << numOfCoins_DP(c, 30) << endl;
  cout << "num of coins for 52: " << numOfCoins(c, 52) <<  " " << numOfCoins_DP(c, 52) << endl;
  cout << "num of coins for 65: " << numOfCoins(c, 65) <<  " " << numOfCoins_DP(c, 65) << endl;
  cout << "num of coins for 75: " << numOfCoins(c, 75) <<  " " << numOfCoins_DP(c, 75) << endl;
  cout << "num of coins for 100: " << numOfCoins(c, 100) <<  " " << numOfCoins_DP(c, 100) << endl;

  cout << " -------------------- " << endl;
  vector<int> t1 = {1, 2, 3};
  cout << "num of coins for 4: " << numOfCoins(t1, 4) <<  " " << numOfCoins_DP(t1, 4) << endl;
  cout << "num of coins for 7: " << numOfCoins(t1, 7) <<  " " << numOfCoins_DP(t1, 7) << endl;
  cout << "num of coins for 6: " << numOfCoins(t1, 6) <<  " " << numOfCoins_DP(t1, 6) << endl;

}
