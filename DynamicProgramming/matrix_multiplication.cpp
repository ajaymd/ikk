#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

using namespace std;
/*
A1 A2 A3

A1 * (A2 A3)
(A1 A2) * A3

foo(p,1,1) + foo(p,2,3) + p*p*p
                   s e
foo(p,1,2) + foo(p,3,3) + p*
      s e

5 matrices
foo(1,1) + foo(2,5)
           foo(2,2) + foo(3,5)
           foo(2,3) + foo(4,5)

foo(1,2) + foo(3,5)
           foo(3,3) + foo(4,5)

foo(1,3)               + foo(4,5)
foo(1,1) + foo(2,3)
foo(1,2) + foo(3,3)
*/

int MM_rec(vector<int>& p, int s, int e) {
	if(s==e) return 0;
	if(e-s == 1) {
		return p[s-1]*p[s]*p[e];
	}
	int minval(INT_MAX);

	for(int i = s; i < e; i++) {
		int v = MM_rec(p,s,i) + MM_rec(p,i+1,e) + p[s-1] * p[i] * p[e];
		minval = min(minval, v);
	}
	return minval;
}

int MM_rec_memo(vector<int>& p, int s, int e, vector<vector<int>>& memo) {
	//cout << "s and e " << s << " " << e << endl;
	if(s==e) return 0;
	if(e-s == 1) {
		return p[s-1]*p[s]*p[e];
	}
	if(memo[s][e] != 0) return memo[s][e];

	int minval(INT_MAX);
	
	for(int k = s; k < e; k++) {
		int v = MM_rec_memo(p,s,k,memo) + MM_rec_memo(p,k+1,e,memo) + p[s-1] * p[k] * p[e];
		minval = min(minval, v);
	}

	memo[s][e] = minval;
	return minval;
}

int MM_dp(vector<int>& p) {
	//, int s, int e, vector<vector<int>>& memo) {
	vector<vector<int>> memo(p.size(),vector<int>(p.size(),0));

	for(int i = 1; i < p.size(); i++) {
		for( int s = 1; s < p.size()-i; s++) {
			int e = i + s;

			int minval(INT_MAX);
			for(int k = s; k < e; k++) {
				int v = memo[s][k] + memo[k+1][e] + p[s-1] * p[k] * p[e];
				minval = min(minval, v);
			}
			memo[s][e] = minval;
		}

	}
	return memo[1][p.size()-1];
}
/*
Catalan Numbers (number of trees) count(i) * count(n-i)

(A1) * (A2 ... A5)
(A1 A2) * (A3 ... A5)
(A1 A2 A3) * (A4 A5)
(A1 A2) * A3, A1* (A2 A3)

(A1 A2 A3 A4) * A5
A1 * (A2 A3 A4)
(A1 A2) * (A3 A4)
(A1 A2 A3) * A4

1,2 2,3 3,4 4,5
  1,3  2,4  3,5

1 2 i=1
2 3
3 4
4 5

1 3 i=2
2 4
3 5

1 4 i=3
2 5
*/


void test_mm(vector<int> x) {
	cout << "Recursion: " << MM_rec(x,1,x.size()-1) << endl;
	vector<vector<int>> memo(x.size(),vector<int>(x.size(),0));
	cout << "Memoization: " << MM_rec_memo(x,1,x.size()-1, memo) << endl;
	cout << "Bottom up: " << MM_dp(x) << endl;
	cout << " ----------------------- " << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> p = {10, 30, 5, 60};
	vector<int> p0 = {40, 20, 30, 10, 30};
	vector<int> p1 = {10, 20, 30, 40, 30};
	vector<int> p2 = {10, 20, 30};


	test_mm(p);
	test_mm(p0);
	test_mm(p1);
	test_mm(p2);


	return 0;
}
